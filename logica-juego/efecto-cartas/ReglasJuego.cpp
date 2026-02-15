//
// Created by alejandro on 5/2/26.
//

#include "ReglasJuego.h"


ReglasJuego::ReglasJuego() {
}

bool ReglasJuego::cartaValida(Carta &cartaJugada, Carta &cartaMesa) {

    if (cartaJugada.getTipo() == CARTA_COMODIN) {
        return true;
    }

    if (cartaJugada.getColor() == cartaMesa.getColor()) {
        return true;
    }

    if (cartaJugada.getValor() == cartaMesa.getValor()) {
        return true;
    }

    return false;

}

bool ReglasJuego::efectoCarta(Carta &carta, TurnosJuego &turnos, MazoCartas &mazo, Jugador *jugadores, int cantidadJugadores) {

    switch (carta.getValor()) {

        case SALTO:
            turnos.saltarTurno();
            return true;

        case REVERSE:
            if (cantidadJugadores == 2) {
                turnos.saltarTurno();
            } else {
                turnos.invertirDireccion();
            }
            return true;

        case TOMA_1: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            jugadorAfectado.recibirCarta(mazo.robarCarta());
            return true;
        }

        case TOMA_2: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 2; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_3: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 3; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_4: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 4; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_6: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 6; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case CAMBIA_COLOR:
            return false;

        default:
            return false;
    }
}

bool ReglasJuego::victoriaJugador(Jugador &jugador) {
    return jugador.cantidadCartas() == 0;
}
