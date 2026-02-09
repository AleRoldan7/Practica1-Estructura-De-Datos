//
// Created by alejandro on 3/2/26.
//

#ifndef UNO_JUGADOR_H
#define UNO_JUGADOR_H

#include <iostream>

#include "../lista/mazo-jugador/ListaMazoJugador.h"

using namespace std;

class Jugador {
    private:
    ListaMazoJugador manoJugador;
    string nombreJugador;
    bool gane = false;

    public:
    Jugador();
    Jugador(string nombre);

    void recibirCarta(Carta carta);
    void mostrarMano();
    void mostrarManoConIndices();
    int cantidadCartas();
    Carta jugarCarta(int posicionCarta);
    bool tieneUno();
    bool ganoJugador();
    string getNombreJugador();
};


#endif //UNO_JUGADOR_H