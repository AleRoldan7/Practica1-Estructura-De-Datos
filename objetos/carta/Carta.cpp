//
// Created by alejandro on 3/2/26.
//

#include "../carta/Carta.h"

Carta::Carta(ColorCarta colorCarta, TipoCarta tipoCarta, ValorCarta valorCarta) {

    color = colorCarta;
    tipo = tipoCarta;
    valor = valorCarta;
}

ColorCarta Carta::getColor() const {
    return color;
}

TipoCarta Carta::getTipo() const {
    return tipo;
}

ValorCarta Carta::getValor() const {
    return valor;
}

