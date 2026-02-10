//
// Created by alejandro on 4/2/26.
//

#include "Carta.h"

#include <iostream>

#include "../../utils/CentrarTexto.h"
#include "../../utils/UtilColorCarta.h"
#include "../../utils/UtilTipoCarta.h"
#include "../../utils/UtilValorCarta.h"

using namespace std;

Carta::Carta() {

}

Carta::Carta(ColorCarta color, TipoCarta tipo, ValorCarta valor) {

    this->color = color;
    this->tipo = tipo;
    this->valor = valor;
}


void Carta::mostrarCarta() {

    cout << colorANSI(color);

    cout << "┌─────────┐\n";
    cout << "│" << centrarTexto(valorCartaString(valor), 9) << "│\n";
    cout << "│" << centrarTexto(tipoCartaString(tipo), 9) << "│\n";
    cout << "│         │\n";
    cout << "│         │\n";
    cout << "└─────────┘\n";

    cout << "\033[0m";
}



ColorCarta Carta::getColor() {
    return color;
}

TipoCarta Carta::getTipo() {
    return tipo;
}

ValorCarta Carta::getValor() {
    return valor;
}