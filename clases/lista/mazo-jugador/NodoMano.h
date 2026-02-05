//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_NODOMANO_H
#define UNO_NODOMANO_H
#include "../../carta/Carta.h"


class NodoMano {
    public:
    Carta carta;
    NodoMano* siguiente;

    NodoMano();
    NodoMano(Carta c) {
        carta = c;
        siguiente = nullptr;
    }
};


#endif //UNO_NODOMANO_H