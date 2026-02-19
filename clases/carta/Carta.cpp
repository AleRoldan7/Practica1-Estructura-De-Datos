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

/*
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
*/

/*
void Carta::mostrarCarta() {

    cout << colorANSI(color);

    cout << "┌─────────┐\n";

    cout << "│" << centrarTexto(valorCartaString(valor), 9) << "│\n";

    if (tipo == CARTA_NUMERO) {
        cout << "│ NUMERO  │\n";
    } else {
        cout << "│" << centrarTexto(colorCartaString(color), 9) << "│\n";
    }

    cout << "│         │\n";
    cout << "│         │\n";
    cout << "└─────────┘\n";

    cout << "\033[0m";
}
*/

/*
void Carta::mostrarCarta() {

    cout << colorANSI(color);

    string texto = valorCartaString(valor);
    string simbolo = simboloCarta(valor);

    cout << "┌─────────┐\n";

    cout << "│" << texto;
    cout << string(9 - texto.length(), ' ') << "│\n";

    cout << "│         │\n";

    cout << "│" << centrarTexto(simbolo, 9) << "│\n";

    cout << "│         │\n";

    cout << "│";
    cout << string(9 - texto.length(), ' ') << texto << "│\n";

    cout << "└─────────┘\n";

    cout << "\033[0m";
}
*/

void Carta::mostrarCarta() {

    cout << colorANSI(color);

    string texto = valorCartaString(valor);
    string simbolo = simboloCarta(valor);

    cout << "┌─────────┐\n";

    cout << "│" << texto;

    if (texto.length() < 9)
        cout << string(9 - texto.length(), ' ');
    else
        cout << texto.substr(0,9);

    cout << "│\n";

    cout << "│         │\n";

    cout << "│" << centrarTexto(simbolo, 9) << "│\n";

    cout << "│         │\n";

    cout << "│";

    if (texto.length() < 9)
        cout << string(9 - texto.length(), ' ') << texto;
    else
        cout << texto.substr(0,9);

    cout << "│\n";

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

void Carta::setColor(ColorCarta color) {
    this->color = color;
}

void Carta::setTipo(TipoCarta tipo) {
    this->tipo = tipo;
}

void Carta::setValor(ValorCarta valor) {
    this->valor = valor;
}
