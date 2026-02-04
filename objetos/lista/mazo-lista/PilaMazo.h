//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_PILAMAZO_H
#define UNO_PILAMAZO_H
#include "NodoMazo.h"


class PilaMazo {
    private:
    NodoMazo* cabeza;
    int cantidad;

    public:
    PilaMazo();

    void push(Carta carta);
    Carta pop();
    Carta peek();
    bool esVacia();
    int sizeMazo();
};


#endif //UNO_PILAMAZO_H