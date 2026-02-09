//
// Created by alejandro on 4/2/26.
//

#include "MazoCartas.h"

#include <cstdlib>
#include <ctime>

#include "../../../utils/UtilColorCarta.h"

MazoCartas::MazoCartas() {
    createMazo();
    revolverCartas();
}


void MazoCartas::createMazo() {

    ColorCarta colores[] = {
        ROJO, VERDE, AMARILLO, AZUL
    };

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

        mazo.push(Carta(colores[c], CARTA_ACCION, BLOQUEO));
        mazo.push(Carta(colores[c], CARTA_ACCION, BLOQUEO));
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

void MazoCartas::revolverCartas() {

    if (mazo.sizeMazo() <= 1) return;

    PilaMazo aux;
    PilaMazo temp;

    srand(time(nullptr));

    while (!mazo.esVacia()) {
        aux.push(mazo.pop());
    }

    while (!aux.esVacia()) {

        int saltos = rand() % aux.sizeMazo();

        for (int i = 0; i < saltos; i++) {
            temp.push(aux.pop());
        }

        mazo.push(aux.pop());

        while (!temp.esVacia()) {
            aux.push(temp.pop());
        }
    }
}

