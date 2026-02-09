//
// Created by alejandro on 5/2/26.
//

#include "TurnosJuego.h"

TurnosJuego::TurnosJuego() {
    indiceActual = 0;
    direccion = 1;
    cantidadJugadores = 0;
    jugador = nullptr;
}

TurnosJuego::TurnosJuego(Jugador *jugador, int cantidadJugadores) {
    this->jugador = jugador;
    this->cantidadJugadores = cantidadJugadores;
    this->indiceActual = 0;
    this->direccion = 1;
}

Jugador& TurnosJuego::jugadorActual() {
    return jugador[indiceActual];
}

void TurnosJuego::siguienteTurno() {
    indiceActual = direccion + indiceActual;

    if (indiceActual >= cantidadJugadores) {
        indiceActual = 0;
    }

    if (indiceActual < 0) {
        indiceActual = cantidadJugadores - 1;
    }
}

void TurnosJuego::saltarTurno() {
    siguienteTurno();
    siguienteTurno();
}

void TurnosJuego::invertirDireccion() {
    direccion = -direccion;
}

int TurnosJuego::getIndiceActual() {
    return indiceActual;
}
