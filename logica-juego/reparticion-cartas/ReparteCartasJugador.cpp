//
// Created by alejandro on 5/2/26.
//

#include "ReparteCartasJugador.h"

ReparteCartasJugador::ReparteCartasJugador() {

}

void ReparteCartasJugador::repartirCartasJugador(MazoCartas &mazo, Jugador* jugador, int cantidadJugadores) {

     const int CANTIDAD_CARTAS = 7;

     for (int i = 0; i < CANTIDAD_CARTAS; i++) {
          for (int j = 0; j < cantidadJugadores; j++) {
               Carta carta = mazo.robarCarta();
               jugador[j].recibirCarta(carta);
          }
     }
}
