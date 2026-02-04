//
// Created by alejandro on 4/2/26.
//

#include "MazoCartas.h"

#include "../../../utils/UtilColorCarta.h"

MazoCartas::MazoCartas() {
    createMazo();
}


void MazoCartas::createMazo() {

    ColorCarta colores[] = {
        ROJO, VERDE, AMARILLO, AZUL
    };

    colorANSI(colores[0]);
    colorANSI(colores[1]);
    colorANSI(colores[2]);
    colorANSI(colores[3]);

    for (int c = 0; c < 4; c++) {
        mazo.push(Carta(colores[c], CARTA_NUMERO, CERO));

        for (int v = UNO; v <= NUEVE; v++) {
            mazo.push(Carta(colores[c], CARTA_NUMERO, (ValorCarta)v));
            mazo.push(Carta(colores[c], CARTA_NUMERO, (ValorCarta)v));
        }
    }

    for (int c = 0; c < 4; c++) {
        mazo.push(Carta(colores[c], CARTA_ACCION, SALTO));
        mazo.push(Carta(colores[c], CARTA_ACCION, SALTO));

        mazo.push(Carta(colores[c], CARTA_ACCION, REVERSE));
        mazo.push(Carta(colores[c], CARTA_ACCION, REVERSE));

        mazo.push(Carta(colores[c], CARTA_ACCION, TOMA_2));
        mazo.push(Carta(colores[c], CARTA_ACCION, TOMA_2));
    }

    for (int i = 0; i < 4; i++) {
        mazo.push(Carta(NEGRA, CARTA_COMODIN, CAMBIA_COLOR));
        mazo.push(Carta(NEGRA, CARTA_COMODIN, TOMA_4));
    }
}

Carta MazoCartas::robarCarta() {
    return mazo.pop();
}

int MazoCartas::cartasRestantes() {
    return mazo.sizeMazo();
}
