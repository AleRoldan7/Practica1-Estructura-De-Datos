//
// Created by alejandro on 3/2/26.
//

#ifndef UNO_JUGADOR_H
#define UNO_JUGADOR_H

#include <iostream>

#include "../lista/mazo-lista/MazoCartas.h"
using namespace std;

class jugador {
    private:
    MazoCartas mazoLista;
    string nombreJugador;
    bool gane = false;

    public:
    jugador();
    ~jugador();
    jugador(string nombre);

    MazoCartas getMazoLista();
    void setMazoLista(MazoCartas mazoLista);
    string getNombreJugador();
    void setNombreJugador(string nombreJugador);
};


#endif //UNO_JUGADOR_H