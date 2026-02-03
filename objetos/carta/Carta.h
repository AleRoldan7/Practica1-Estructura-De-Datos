//
// Created by alejandro on 3/2/26.
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

    ColorCarta getColor() const;
    TipoCarta getTipo() const;
    ValorCarta getValor() const;
};


#endif //UNO_CARTA_H