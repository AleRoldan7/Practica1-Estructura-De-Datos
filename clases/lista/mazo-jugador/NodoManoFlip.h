//
// Created by alejandro on 18/2/26.
//

#ifndef UNO_NODOMANOFLIP_H
#define UNO_NODOMANOFLIP_H
#include "../../carta/CartaFlip.h"


class NodoManoFlip {

private:
    CartaFlip cartaFlip;
    NodoManoFlip* siguiente;

    public:
    NodoManoFlip();
    NodoManoFlip(const CartaFlip& carta);
    CartaFlip getCartaFlip();
    NodoManoFlip* getSiguiente();
    void setSiguiente(NodoManoFlip* sig);
};


#endif //UNO_NODOMANOFLIP_H