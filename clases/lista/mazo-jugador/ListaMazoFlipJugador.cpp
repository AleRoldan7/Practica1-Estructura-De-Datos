//
// Created by alejandro on 18/2/26.
//

#include "ListaMazoFlipJugador.h"
#include <iostream>
#include <stdexcept>
using namespace std;

#include "../../../utils/UtilColorCarta.h"

ListaMazoFlipJugador::ListaMazoFlipJugador() {
    head = nullptr;
    cantidad = 0;
}

ListaMazoFlipJugador::~ListaMazoFlipJugador() {

    while (head != nullptr) {
        NodoManoFlip* aux = head;
        head = head->getSiguiente();
        delete aux;
    }
}

bool ListaMazoFlipJugador::ordenar(CartaFlip a, CartaFlip b) {

    Carta ladoA = a.getCartaActual();
    Carta ladoB = b.getCartaActual();

    if (ladoA.getColor() != ladoB.getColor())
        return ladoA.getColor() < ladoB.getColor();

    if (ladoA.getTipo() != ladoB.getTipo())
        return ladoA.getTipo() < ladoB.getTipo();

    return ladoA.getValor() < ladoB.getValor();
}

void ListaMazoFlipJugador::insertarOrdenado(const CartaFlip& carta) {

    NodoManoFlip* nuevo = new NodoManoFlip(carta);

    if (head == nullptr || ordenar(carta, head->getCartaFlip())) {

        nuevo->setSiguiente(head);
        head = nuevo;

    } else {

        NodoManoFlip* actual = head;

        while (actual->getSiguiente() != nullptr &&
               !ordenar(carta, actual->getSiguiente()->getCartaFlip())) {

            actual = actual->getSiguiente();
               }

        nuevo->setSiguiente( actual->getSiguiente());
        actual->setSiguiente(nuevo);
    }

    cantidad++;
}

CartaFlip ListaMazoFlipJugador::obtenerCartaFlip(int posicion) {

    if (posicion < 0 || posicion >= cantidad) {
        throw std::out_of_range("Posicion invalida");
    }

    NodoManoFlip* actual = head;

    for (int i = 0; i < posicion; i++) {
        actual = actual->getSiguiente();
    }

    return actual->getCartaFlip();
}

void ListaMazoFlipJugador::eliminarCartaFlip(int posicionCarta) {

    if (!head) return;

    if (posicionCarta == 0) {
        NodoManoFlip* aux = head;
        head = head->getSiguiente();
        delete aux;
    } else {
        NodoManoFlip* actual = head;

        for (int i = 0; i < posicionCarta - 1; i++) {
            actual = actual->getSiguiente();
        }

        NodoManoFlip* aux = actual->getSiguiente();
        actual->setSiguiente(aux->getSiguiente());
        delete aux;
    }

    cantidad--;
}

int ListaMazoFlipJugador::sizeMazoFlipJugador() {
    return cantidad;
}

void ListaMazoFlipJugador::mostrarConIndices(bool modoOscuro) const {
    if (cantidad == 0) {
        cout << "   (mano vacía)"<<endl;
        return;
    }

    cout << " "<<endl;

    NodoManoFlip* actual = head;
    int indice = 0;

    while (actual != nullptr) {
        CartaFlip cartaFlip = actual->getCartaFlip();
        Carta carta = cartaFlip.getCartaActual();

        cout << "[" << indice << "]  ";

        cout << "┌─────────┐ "<<endl;

        cout << "│ ";

        if (carta.getTipo() == CARTA_NUMERO) {
            cout << carta.getValor() << "       ";
        } else {
            std::string accion;
            switch (carta.getValor()) {
                case TOMA_1:      accion = "+1";     break;
                case TOMA_6:      accion = "+6";     break;
                case SALTO:       accion = "SALTO";  break;
                case SALTO_TODOS: accion = "TODOS";  break;
                case REVERSE:     accion = "REV";    break;
                case FLIP:        accion = "FLIP";   break;
                case CAMBIA_COLOR: accion = "COMODIN"; break;
                case COLOR_ETERNO: accion = "COLOR"; break;
                default:          accion = "???";
            }
            cout << accion << std::string(8 - accion.length(), ' ');
        }

        cout << "│\n";
        cout << "│         │\n";
        cout << "│  " << colorCartaString(carta.getColor()) << "  │\n";
        cout << "│         │\n";
        cout << "└─────────┘\n\n";

        actual = actual->getSiguiente();
        indice++;
    }
}