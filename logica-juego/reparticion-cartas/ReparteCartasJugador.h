//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_REPARTECARTASJUGADOR_H
#define UNO_REPARTECARTASJUGADOR_H
#include "../../clases/jugador/Jugador.h"
#include "../../clases/lista/mazo-lista/MazoCartas.h"
#include "../../clases/lista/mazo-lista/MazoFlip.h"


class ReparteCartasJugador {

public:

    ReparteCartasJugador();

    void repartirCartasJugador(MazoCartas& mazo, Jugador* jugador, int cantidadJugadores);
    void repartirCartasFlip(MazoFlip& mazoFlip, Jugador* jugador, int cantidadJugadres);

};


#endif //UNO_REPARTECARTASJUGADOR_H