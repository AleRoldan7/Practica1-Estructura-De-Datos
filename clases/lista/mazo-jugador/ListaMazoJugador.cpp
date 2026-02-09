//
// Created by alejandro on 5/2/26.
//

#include "ListaMazoJugador.h"
#include <iostream>
using namespace std;

ListaMazoJugador::ListaMazoJugador() {
    nodo = nullptr;
    cantidadCartas = 0;
}

ListaMazoJugador::~ListaMazoJugador() {

    while (nodo != nullptr) {
        NodoMazo* aux = nodo;
        nodo = nodo->sigueinte;
        delete aux;
    }
}

bool ordenarMazoJugador(Carta cartaA, Carta cartaB) {

    if (cartaA.getColor() != cartaB.getColor()) {
        return cartaA.getColor() < cartaB.getColor();
    }

    if (cartaA.getTipo() != cartaB.getTipo()) {
        return  cartaA.getTipo() < cartaB.getTipo();
    }

    return cartaA.getValor() < cartaB.getValor();
}

void ListaMazoJugador::insertarCartasOrdenada(Carta carta) {
    NodoMazo* nuevo = new NodoMazo(carta);

    if (nodo == nullptr || ordenarMazoJugador(carta, nodo->carta)) {
        nuevo->sigueinte = nodo;
        nodo = nuevo;
    } else {
        NodoMazo* actual = nodo;

        while (actual->sigueinte != nullptr && !ordenarMazoJugador(carta, actual->sigueinte->carta)) {
            actual = actual->sigueinte;
        }

        nuevo->sigueinte = actual->sigueinte;
        actual->sigueinte = nuevo;
    }

    cantidadCartas++;
}

void ListaMazoJugador::mostrarMazoJugador() {

    NodoMazo* actual = nodo;

    cout<<"Cartas jugador ( "<<cantidadCartas<<" ):"<<endl;

    while (actual != nullptr) {
        actual->carta.mostrarCarta();
        actual = actual->sigueinte;
    }
}

Carta ListaMazoJugador::jugarCarta(int posicionCarta) {

    if (posicionCarta < 0 || posicionCarta >= cantidadCartas) {
        cout<<"Carta en posicion invalida"<<endl;
    }

    NodoMazo* actual = nodo;
    NodoMazo* anterior = nullptr;

    for (int i = 0; i < posicionCarta; i++) {
        anterior = actual;
        actual = actual->sigueinte;
    }

    Carta carta = actual->carta;

    if (anterior == nullptr) {

        nodo = actual->sigueinte;

    } else {

        anterior->sigueinte = actual->sigueinte;
    }

    delete actual;
    cantidadCartas--;

    return carta;
}

int ListaMazoJugador::sizeMazoJugador() {
    return cantidadCartas;
}

Carta ListaMazoJugador::obtenerCarta(int posicionCarta) {

    NodoMazo* actual = nodo;
    int posicion = 0;

    while (actual != nullptr && posicion < posicionCarta) {
        actual = actual->sigueinte;
        posicion++;
    }

    return actual->carta;
}

void ListaMazoJugador::eliminarCarta(int posicionCarta) {

    if (!nodo) return;

    if (posicionCarta == 0) {
        NodoMazo* aux = nodo;
        nodo = nodo->sigueinte;
        delete aux;
    } else {
        NodoMazo* actual = nodo;

        for (int i = 0; i < posicionCarta - 1; i++) {
            actual = actual->sigueinte;
        }

        NodoMazo* aux = actual->sigueinte;
        actual->sigueinte = aux->sigueinte;
        delete aux;
    }

    cantidadCartas--;
}

void ListaMazoJugador::mostrarMazoJugadorConIndices() {

    NodoMazo* actual = nodo;
    int indice = 0;

    cout << "\nCartas del jugador (" << cantidadCartas << "):\n";

    while (actual != nullptr) {
        cout << "[" << indice << "]\n";
        actual->carta.mostrarCarta();
        cout << endl;
        actual = actual->sigueinte;
        indice++;
    }
}
