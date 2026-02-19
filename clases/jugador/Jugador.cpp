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

void Jugador::recibirCartaFlip(const CartaFlip& cartaFlip) {
    mazoFlipJugador.insertarOrdenado(cartaFlip);
}

void Jugador::mostrarMano() {
    cout << "Mano de "<<nombreJugador<< ":" << endl;
    manoJugador.mostrarMazoJugador();
}

void Jugador::mostrarManoConIndices() {
    cout << "Mano de " << nombreJugador << ": "<<endl;
    manoJugador.mostrarMazoJugadorConIndices();
}
void Jugador::mostrarManoFlipConIndices(bool modoOscuro) const {

    cout<<"Mano de: "<<nombreJugador<<endl;
    mazoFlipJugador.mostrarConIndices(modoOscuro);
}


int Jugador::cantidadCartas() {
    return manoJugador.sizeMazoJugador();
}

Carta Jugador::jugarCarta(int posicionCarta) {
    Carta carta = manoJugador.obtenerCarta(posicionCarta);
    manoJugador.eliminarCarta(posicionCarta);
    return carta;
}

CartaFlip Jugador::jugarCartaFlip(int posicionCarta) {

    CartaFlip carta = mazoFlipJugador.obtenerCartaFlip(posicionCarta);

    mazoFlipJugador.eliminarCartaFlip(posicionCarta);

    return carta;
}

bool Jugador::ganoJugador() {
    return cantidadCartas() == 0;
}

bool Jugador::tieneUno() {
    return cantidadCartas() == 1;
}

void Jugador::setNombreJugador(string nombreJugador) {
    this->nombreJugador = nombreJugador;
}

string Jugador::getNombreJugador() {
    return nombreJugador;
}