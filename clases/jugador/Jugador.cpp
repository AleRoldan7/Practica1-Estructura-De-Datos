//
// Created by alejandro on 3/2/26.
//

#include "Jugador.h"

Jugador::Jugador() {

    nombreJugador = "";
    gane = false;
}

Jugador::Jugador(string nombre) {
    nombreJugador = nombre;
    gane = false;
}

void Jugador::recibirCarta(Carta carta) {
    manoJugador.insertarCartasOrdenada(carta);
}

void Jugador::mostrarMano() {
    cout << "Mano de "<<nombreJugador<< ":" << endl;
    manoJugador.mostrarMazoJugador();
}

int Jugador::cantidadCartas() {
    return manoJugador.sizeMazoJugador();
}

string Jugador::getNombreJugador() {
    return nombreJugador;
}