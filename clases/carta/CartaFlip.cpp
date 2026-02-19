//
// Created by alejandro on 17/2/26.
//

#include "CartaFlip.h"
#include <iostream>
using namespace std;



CartaFlip::CartaFlip() {
    this->esOscuro = false;
}

CartaFlip::CartaFlip(Carta claro, Carta oscuro) {
    this->ladoClaro = claro;
    this->ladoOscuro = oscuro;
    this->esOscuro = false;
}

void CartaFlip::voltearCartaFlip() {
    esOscuro = !esOscuro;
}

void CartaFlip::setModoOscuro(bool modo) {
    esOscuro = modo;
}

Carta CartaFlip::getCartaActual() {
    return esOscuro ? ladoOscuro : ladoClaro;
}

void CartaFlip::mostrarCartaActual() {

    if (esOscuro) {
        ladoOscuro.mostrarCarta();
    } else {
        ladoClaro.mostrarCarta();
    }
}

void CartaFlip::mostrarAmbosLados() {

    cout << "\n╔══════════════════════════╗\n";
    cout << "║        CARTA FLIP        ║\n";
    cout << "╠══════════════════════════╣\n";

    cout << "║        LADO CLARO        ║\n";
    ladoClaro.mostrarCarta();

    cout << "╠══════════════════════════╣\n";

    cout << "║        LADO OSCURO       ║\n";
    ladoOscuro.mostrarCarta();

    cout << "╚══════════════════════════╝\n";
}