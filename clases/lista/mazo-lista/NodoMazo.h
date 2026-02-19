//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_NODOMAZO_H
#define UNO_NODOMAZO_H
#include "../../carta/Carta.h"
#include "../../carta/CartaFlip.h"


class NodoMazo {
public:
    Carta carta;
    NodoMazo* sigueinte;
    CartaFlip cartaFlip;

    NodoMazo();
    NodoMazo(Carta c): carta(c), sigueinte(nullptr){};
    NodoMazo(CartaFlip cartaFlip): cartaFlip(cartaFlip), sigueinte(nullptr){};
};

#endif //UNO_NODOMAZO_H