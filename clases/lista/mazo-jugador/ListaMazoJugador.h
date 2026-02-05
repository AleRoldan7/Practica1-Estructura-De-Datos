//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_LISTAMAZOJUGADOR_H
#define UNO_LISTAMAZOJUGADOR_H
#include "../mazo-lista/MazoCartas.h"


class ListaMazoJugador {
private:
    NodoMazo* nodo;
    int cantidadCartas;

public:
    ListaMazoJugador();
    ~ListaMazoJugador();

    void insertarCartasOrdenada(Carta carta);
    void mostrarMazoJugador();
    int sizeMazoJugador();
};


#endif //UNO_LISTAMAZOJUGADOR_H