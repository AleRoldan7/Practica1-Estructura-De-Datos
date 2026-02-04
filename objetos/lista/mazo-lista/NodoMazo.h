//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_NODOMAZO_H
#define UNO_NODOMAZO_H
#include "../../carta/Carta.h"


class NodoMazo {
public:
    Carta carta;
    NodoMazo* sigueinte;

    NodoMazo();
    NodoMazo(Carta c): carta(c), sigueinte(nullptr){};
};

#endif //UNO_NODOMAZO_H