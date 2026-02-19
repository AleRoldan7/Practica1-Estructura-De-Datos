//
// Created by alejandro on 18/2/26.
//

#include "NodoManoFlip.h"

NodoManoFlip::NodoManoFlip() {
    this->siguiente = nullptr;
}

NodoManoFlip::NodoManoFlip(const CartaFlip& carta) {
    this->cartaFlip = carta;
    this->siguiente = nullptr;
}


CartaFlip NodoManoFlip::getCartaFlip() {
    return cartaFlip;
}

NodoManoFlip* NodoManoFlip::getSiguiente() {
    return siguiente;
}


void NodoManoFlip::setSiguiente(NodoManoFlip* sig) {
    siguiente = sig;
}