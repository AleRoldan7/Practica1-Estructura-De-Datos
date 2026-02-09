//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_REGLASJUEGO_H
#define UNO_REGLASJUEGO_H
#include <string>

#include "../../clases/carta/Carta.h"
#include "../flujo-juego/TurnosJuego.h"


class ReglasJuego {

    public:
    ReglasJuego();
    bool cartaValida(Carta& cartaJugada, Carta& cartaMesa);
    bool efectoCarta(Carta& carta, TurnosJuego& turnos, MazoCartas& mazo, Jugador* jugadores, int cantidadJugadores);
    bool victoriaJugador(Jugador& jugador);
};


#endif //UNO_REGLASJUEGO_H