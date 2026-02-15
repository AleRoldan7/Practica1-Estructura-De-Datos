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

Jugador& TurnosJuego::getJugador(int indice) {
    return jugador[indice];
}

void TurnosJuego::siguienteTurno() {
    indiceActual = (indiceActual + direccion + cantidadJugadores) % cantidadJugadores;
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
