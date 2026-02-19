//
// Created by alejandro on 17/2/26.
//

#include "NodoFlip.h"

NodoFlip::NodoFlip(CartaFlip cartaFlip) {
    this->cartaFlip = cartaFlip;
    this->siguiente = nullptr;
}

CartaFlip NodoFlip::getCartaFlip() {
    return cartaFlip;
}

NodoFlip* NodoFlip::getSiguiente() {
    return siguiente;
}

void NodoFlip::setSiguiente(NodoFlip* siguiente) {
    this->siguiente = siguiente;
}
