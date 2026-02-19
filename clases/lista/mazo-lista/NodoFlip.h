//
// Created by alejandro on 17/2/26.
//

#ifndef UNO_NODOFLIP_H
#define UNO_NODOFLIP_H
#include "../../carta/CartaFlip.h"


class NodoFlip {
private:
    CartaFlip cartaFlip;
    NodoFlip* siguiente;

    public:
    NodoFlip();
    NodoFlip(CartaFlip cartaFlip);

    CartaFlip getCartaFlip();
    NodoFlip* getSiguiente();

    void setSiguiente(NodoFlip* siguiente);
};


#endif //UNO_NODOFLIP_H