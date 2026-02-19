//
// Created by alejandro on 18/2/26.
//

#ifndef UNO_PILAFLIP_H
#define UNO_PILAFLIP_H
#include "NodoFlip.h"


class PilaFlip {

    private:
    NodoFlip* head;
    int cantidad;

    public:
    PilaFlip();


    void push(CartaFlip cartaFlip);
    CartaFlip pop();
    CartaFlip peek();

    bool isEmpty();
    int sizeMazoFlip();
};


#endif //UNO_PILAFLIP_H