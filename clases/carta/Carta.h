//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_CARTA_H
#define UNO_CARTA_H
#include "../../enums/CartaColor.h"
#include "../../enums/TipoCarta.h"
#include "../../enums/ValorCarta.h"


class Carta {
private:
    ColorCarta color;
    TipoCarta tipo;
    ValorCarta valor;

    public:
    Carta();
    Carta(ColorCarta color, TipoCarta tipo, ValorCarta valor);
    Carta(const Carta& otra) : color(otra.color), tipo(otra.tipo), valor(otra.valor) {}

    ColorCarta getColor();
    void setColor(ColorCarta color);
    TipoCarta getTipo();
    void setTipo(TipoCarta tipo);
    ValorCarta getValor();
    void setValor(ValorCarta valor);

    void mostrarCarta();
};


#endif //UNO_CARTA_H