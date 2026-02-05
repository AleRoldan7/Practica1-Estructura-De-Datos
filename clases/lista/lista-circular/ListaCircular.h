//
// Created by alejandro on 3/2/26.
//

#ifndef UNO_LISTACIRCULAR_H
#define UNO_LISTACIRCULAR_H

#include "../../jugador/Jugador.h"

/*Creacion de una lista circular que contendra a los jugadores*/

class ListaCircular {
private:
    class NodoCircular {
        public:
        Jugador player;
        NodoCircular* siguiente;
        NodoCircular* anterior;
    };

    NodoCircular *raiz;

    public:
    ListaCircular();
    ~ListaCircular();
    void agregarPrimero(Jugador j);
    void agregarUltimo(Jugador j);
    bool estaVacia();
    int cantidad();
};



#endif //UNO_LISTACIRCULAR_H