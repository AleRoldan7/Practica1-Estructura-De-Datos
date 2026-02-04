//
// Created by alejandro on 4/2/26.
//

#include "PilaMazo.h"
#include "../../carta/Carta.h"

#include <iostream>
using namespace std;

PilaMazo::PilaMazo() {
    cabeza = nullptr;
    cantidad = 0;
}

void PilaMazo::push(Carta carta) {
    NodoMazo* nuevo = new NodoMazo(carta);
    nuevo->sigueinte = cabeza;
    cabeza = nuevo;
    cantidad++;
}

Carta PilaMazo::pop() {
    if (esVacia()) {
        cout<<"Pila vacia"<<endl;
        exit(1);
    }

    NodoMazo* tmp = cabeza;
    Carta carta = tmp->carta;
    cabeza = tmp->sigueinte;
    delete tmp;
    cantidad--;

    return carta;

}

bool PilaMazo::esVacia() {
    return cabeza == nullptr;
}

int PilaMazo::sizeMazo() {
    return cantidad;
}


