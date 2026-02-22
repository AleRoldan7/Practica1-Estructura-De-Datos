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