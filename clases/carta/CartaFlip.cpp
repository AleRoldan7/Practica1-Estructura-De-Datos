//
// Created by alejandro on 17/2/26.
//

#include "CartaFlip.h"
#include <iostream>
using namespace std;

CartaFlip::CartaFlip() {

}

CartaFlip::CartaFlip(Carta claro, Carta oscuro) {
    this->ladoClaro = claro;
    this->ladoOscuro = oscuro;
}

/*
void CartaFlip::voltearCartaFlip() {
    esOscuro = !esOscuro;
}

void CartaFlip::setModoOscuro(bool modo) {
    esOscuro = modo;
}
*/

Carta CartaFlip::getCartaActual(bool ladoOscuro)  {
    return ladoOscuro ? this->ladoOscuro : this->ladoClaro;
}

void CartaFlip::mostrarCartaActual(bool ladoOscuro)  {
    if (ladoOscuro) {
        this->ladoOscuro.mostrarCarta();
    } else {
        this->ladoClaro.mostrarCarta();
    }
}

vector<string> CartaFlip::lineaHorizontalFlip() {

    vector<string> resultado;

    vector<string> claro = ladoClaro.lineaHorizontal();
    vector<string> oscuro = ladoOscuro.lineaHorizontal();

    resultado.push_back("╔══════════════════════════╗");
    resultado.push_back("║        CARTA FLIP        ║");
    resultado.push_back("╠══════════════════════════╣");
    resultado.push_back("║        LADO CLARO        ║");

    int anchoMarco = 70;
    int anchoCarta = claro[0].length();
    int padding = (anchoMarco - anchoCarta) / 2;
    string espacios(padding, ' ');

    for (auto &linea : claro)
        resultado.push_back(espacios + linea);

    resultado.push_back("╠══════════════════════════╣");
    resultado.push_back("║        LADO OSCURO       ║");

    for (auto &linea : oscuro)
        resultado.push_back(espacios + linea);

    resultado.push_back("╚══════════════════════════╝");

    return resultado;
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


void CartaFlip::setCartaActual(Carta& carta, bool oscuro) {
    if (oscuro) {
        ladoOscuro = carta;
    } else {
        ladoClaro = carta;
    }
}
