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

void Jugador::mostrarManoConIndices() {
    cout << "Mano de " << nombreJugador << ": "<<endl;
    manoJugador.mostrarMazoJugadorConIndices();
}

int Jugador::cantidadCartas() {
    return manoJugador.sizeMazoJugador();
}

Carta Jugador::jugarCarta(int posicionCarta) {
    Carta carta = manoJugador.obtenerCarta(posicionCarta);
    manoJugador.eliminarCarta(posicionCarta);
    return carta;
}

bool Jugador::ganoJugador() {
    return cantidadCartas() == 0;
}

bool Jugador::tieneUno() {
    return cantidadCartas() == 1;
}

string Jugador::getNombreJugador() {
    return nombreJugador;
}