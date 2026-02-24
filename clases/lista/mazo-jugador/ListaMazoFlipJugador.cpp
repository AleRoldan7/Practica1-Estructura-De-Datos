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

    Carta ladoA = a.getCartaActual(ladoOscuro);
    Carta ladoB = b.getCartaActual(ladoOscuro);

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
        cout << "(mano vacía)\n";
        return;
    }

    const int cartasPorPagina = 3;
    int totalPaginas = (cantidad + cartasPorPagina - 1) / cartasPorPagina;
    int paginaActual = 0;

    while (true) {

        int inicio = paginaActual * cartasPorPagina;
        int fin = min(inicio + cartasPorPagina, cantidad);

        vector<vector<string>> cartasVisuales;

        NodoManoFlip* actual = head;
        int indice = 0;

        while (actual != nullptr && indice < fin) {

            if (indice >= inicio) {

                CartaFlip cf = actual->getCartaFlip();
                cartasVisuales.push_back(cf.lineaHorizontalFlip());
            }

            actual = actual->getSiguiente();
            indice++;
        }

        for (int i = inicio; i < fin; i++) {
            cout << "          [" << i << "]                     ";
        }
        cout << "\n";

        int alturaCarta = cartasVisuales[0].size();

        for (int linea = 0; linea < alturaCarta; linea++) {

            for (size_t c = 0; c < cartasVisuales.size(); c++) {
                cout << cartasVisuales[c][linea] << "   ";
            }

            cout << "\n";
        }

        cout << "\n";


        cout << "Página " << paginaActual + 1 << " de " << totalPaginas << "\n";

        if (totalPaginas == 1) break;

        cout << "s = siguiente | a = anterior | e = elegir\n";
        char op;
        cin >> op;

        if (op == 's' && paginaActual < totalPaginas - 1)
            paginaActual++;
        else if (op == 'a' && paginaActual > 0)
            paginaActual--;
        else
            break;
    }
}



/*
void ListaMazoFlipJugador::mostrarConIndices(bool modoOscuro) const {
    if (cantidad == 0) {
        cout << "   (mano vacía)"<<endl;
        return;
    }

    NodoManoFlip* actual = head;
    int indice = 0;

    while (actual != nullptr) {

        CartaFlip cartaFlip = actual->getCartaFlip();

        cartaFlip.setModoOscuro(modoOscuro);

        cout << "[" << indice << "]\n";

        cartaFlip.mostrarAmbosLados();

        cout << endl;

        actual = actual->getSiguiente();
        indice++;
    }
}
*/