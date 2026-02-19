//
// Created by alejandro on 17/2/26.
//

#include "MazoFlip.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

MazoFlip::MazoFlip() {
    createMazoFlip();
    revolverCartaMazoFlip();
    cout << "Cartas creadas: " << mazoFlip.sizeMazoFlip() << endl;
}

MazoFlip::MazoFlip(int cantidadJugadores) {
    int cantidadMazos = ((cantidadJugadores -1) / 6) +1;

    for (int i = 0; i < cantidadMazos; i++) {
        createMazoFlip();
    }

    revolverCartaMazoFlip();
}

void MazoFlip::createMazoFlip() {

    vector<Carta> ladoClaro;
    vector<Carta> ladoOscuro;

    ColorCarta colorClaro[] = {ROJO, VERDE, AMARILLO, AZUL};
    ColorCarta colorOscuro[] = {ROSA, TURQUESA, NARANJA, VIOLETA};


    for (int c = 0; c < 4; c++) {

        ladoClaro.push_back(Carta(colorClaro[c], CARTA_NUMERO, CERO));
        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_NUMERO, CERO));

        for (int v = UNO; v <= NUEVE; v++) {

            ladoClaro.push_back(Carta(colorClaro[c], CARTA_NUMERO, (ValorCarta)v));
            ladoClaro.push_back(Carta(colorClaro[c], CARTA_NUMERO, (ValorCarta)v));

            ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_NUMERO, (ValorCarta)v));
            ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_NUMERO, (ValorCarta)v));
        }
    }


    for (int c = 0; c < 4; c++) {

        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, TOMA_1));
        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, TOMA_1));

        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, REVERSE));
        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, REVERSE));

        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, SALTO));
        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, SALTO));

        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, FLIP));
        ladoClaro.push_back(Carta(colorClaro[c], CARTA_ACCION, FLIP));

        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, TOMA_3));
        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, TOMA_3));

        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, REVERSE));
        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, REVERSE));

        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, SALTO_TODOS));
        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, SALTO_TODOS));

        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, FLIP));
        ladoOscuro.push_back(Carta(colorOscuro[c], CARTA_ACCION, FLIP));
    }


    for (int i = 0; i < 4; i++) {

        ladoClaro.push_back(Carta(NEGRA, CARTA_COMODIN, CAMBIA_COLOR));
        ladoClaro.push_back(Carta(NEGRA, CARTA_COMODIN, TOMA_2));

        ladoOscuro.push_back(Carta(NEGRA, CARTA_COMODIN, COLOR_ETERNO));
        ladoOscuro.push_back(Carta(NEGRA, CARTA_COMODIN, TOMA_6));
    }


    random_device rd;
    mt19937 g(rd());

    shuffle(ladoClaro.begin(), ladoClaro.end(), g);
    shuffle(ladoOscuro.begin(), ladoOscuro.end(), g);


    int cantidad = ladoClaro.size();

    for (int i = 0; i < cantidad; i++) {
        mazoFlip.push(CartaFlip(ladoClaro[i], ladoOscuro[i]));
    }

}

void MazoFlip::revolverCartaMazoFlip() {

    if (mazoFlip.sizeMazoFlip() <= 1) return;

    PilaFlip aux;
    PilaFlip temp;

    srand(time(nullptr));

    while (!mazoFlip.isEmpty()) {
        aux.push(mazoFlip.pop());
    }

    while (!aux.isEmpty()) {

        int saltos = rand() % aux.sizeMazoFlip();

        for (int i = 0; i < saltos; i++) {
            temp.push(aux.pop());
        }

        mazoFlip.push(aux.pop());

        while (!temp.isEmpty()) {
            aux.push(temp.pop());
        }
    }
}

void MazoFlip::mostrarMazoFlip() {

    PilaFlip auxiliar;

    cout << "\n===== MAZO FLIP COMPLETO =====\n\n";

    while (!mazoFlip.isEmpty()) {

        CartaFlip carta = mazoFlip.pop();
        carta.mostrarAmbosLados();
        auxiliar.push(carta);
    }

    while (!auxiliar.isEmpty()) {
        mazoFlip.push(auxiliar.pop());
    }
}

int MazoFlip::cantidadRestantes() {
    return mazoFlip.sizeMazoFlip();
}

CartaFlip MazoFlip::robarCartaFlip() {
    return mazoFlip.pop();
}

bool MazoFlip::isEmpty() {
    return mazoFlip.isEmpty();
}