//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_TURNOSJUEGO_H
#define UNO_TURNOSJUEGO_H
#include "../../clases/jugador/Jugador.h"


class TurnosJuego {
private:
    Jugador* jugador;
    int cantidadJugadores;
    int indiceActual;
    int direccion;

public:

    TurnosJuego();
    TurnosJuego(Jugador* jugador, int cantidadJugadores);

    Jugador& jugadorActual();
    void saltarTurno();
    void siguienteTurno();
    void invertirDireccion();

    int getIndiceActual();
};


#endif //UNO_TURNOSJUEGO_H