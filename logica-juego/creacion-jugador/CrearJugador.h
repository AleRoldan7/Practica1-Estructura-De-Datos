//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_CREARJUGADOR_H
#define UNO_CREARJUGADOR_H
#include "../../clases/jugador/Jugador.h"


class CrearJugador {
private:
    int cantidadJugadores;

    public:
    CrearJugador();

    int solicitarJugadores();
    Jugador* crearJugadores(int& cantidad);
};


#endif //UNO_CREARJUGADOR_H