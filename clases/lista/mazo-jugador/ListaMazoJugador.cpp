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

int ListaMazoJugador::sizeMazoJugador() {
    return cantidadCartas;
}
