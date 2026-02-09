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
    void mostrarMazoJugadorConIndices();
    int sizeMazoJugador();
    Carta jugarCarta(int posicionCarta);
    Carta obtenerCarta(int posicionCarta);
    void eliminarCarta(int posicionCarta);
};


#endif //UNO_LISTAMAZOJUGADOR_H