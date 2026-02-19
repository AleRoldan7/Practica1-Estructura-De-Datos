//
// Created by alejandro on 3/2/26.
//

#ifndef UNO_JUGADOR_H
#define UNO_JUGADOR_H

#include <iostream>

#include "../carta/CartaFlip.h"
#include "../lista/mazo-jugador/ListaMazoFlipJugador.h"
#include "../lista/mazo-jugador/ListaMazoJugador.h"

using namespace std;

class Jugador {
    private:
    ListaMazoJugador manoJugador;
    ListaMazoFlipJugador mazoFlipJugador;
    string nombreJugador;
    bool gane = false;

    public:
    Jugador();
    Jugador(string nombre);

    void recibirCarta(Carta carta);
    void recibirCartaFlip(const CartaFlip& cartaFlip);
    void mostrarMano();
    void mostrarManoConIndices();
    int cantidadCartas();
    Carta jugarCarta(int posicionCarta);
    bool tieneUno();
    bool ganoJugador();
    string getNombreJugador();
    void setNombreJugador(string nombreJugador);
    CartaFlip jugarCartaFlip(int posicionCarta);

    void mostrarManoFlipConIndices(bool modoOscuro) const;
};


#endif //UNO_JUGADOR_H