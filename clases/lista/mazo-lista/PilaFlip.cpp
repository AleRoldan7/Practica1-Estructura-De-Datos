//
// Created by alejandro on 18/2/26.
//

#include "PilaFlip.h"
#include <iostream>
using namespace std;

PilaFlip::PilaFlip() {
    head = nullptr;
    cantidad = 0;
}



void PilaFlip::push(CartaFlip cartaFlip) {

    NodoFlip* nuevo = new NodoFlip(cartaFlip);

    nuevo->setSiguiente(head);
    head = nuevo;

    cantidad++;
}

CartaFlip PilaFlip::pop() {

    if (isEmpty()) {
        cout<<"La pila esta vacia"<<endl;
        exit(1);
    }

    NodoFlip* aux = head;
    CartaFlip cartaFlip = aux->getCartaFlip();
    head = aux->getSiguiente();

    delete aux;
    cantidad--;

    return cartaFlip;
}

CartaFlip PilaFlip::peek() {

    if (isEmpty()) {
        cout<<"La pila esta vacia"<<endl;
        exit(1);
    }

    return head->getCartaFlip();
}

bool PilaFlip::isEmpty() {
    return head == nullptr;
}

int PilaFlip::sizeMazoFlip() {
    return cantidad;
}


