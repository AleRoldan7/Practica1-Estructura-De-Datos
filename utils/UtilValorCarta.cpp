//
// Created by alejandro on 3/2/26.
//

#include "UtilValorCarta.h"

const char* valorCartaString(ValorCarta valorCarta) {
    switch (valorCarta) {

        case CERO: return "0";
        case UNO: return "1";
        case DOS: return "2";
        case TRES: return "3";
        case CUATRO: return "4";
        case CINCO: return "5";
        case SEIS: return "6";
        case SIETE: return "7";
        case OCHO: return "8";
        case NUEVE: return "9";

        case TOMA_1: return "+1";
        case TOMA_2: return "+2";
        case TOMA_3: return "+3";
        case TOMA_4: return "+4";
        case TOMA_6: return "+6";

        case SALTO: return "SALTO";
        case SALTO_TODOS: return "SALTO TODOS";
        case REVERSE: return "REV";
        case CAMBIA_COLOR: return "COLOR";
        case COLOR_ETERNO: return "ETERNO";
        case FLIP: return "FLIP";

        default: return "SIN NADA";
    }
}

const char* simboloCarta(ValorCarta valor) {

    switch (valor) {

        case CERO: return "0";
        case UNO: return "1";
        case DOS: return "2";
        case TRES: return "3";
        case CUATRO: return "4";
        case CINCO: return "5";
        case SEIS: return "6";
        case SIETE: return "7";
        case OCHO: return "8";
        case NUEVE: return "9";

        case TOMA_2: return "+2";
        case TOMA_4: return "+4";
        case TOMA_6: return "+6";
        case TOMA_1: return "+1";
        case TOMA_3: return "+3";

        case REVERSE: return "REV";
        case SALTO: return "X";
        case SALTO_TODOS: return "XX";
        case CAMBIA_COLOR: return "COL";
        case COLOR_ETERNO: return "INF";
        case FLIP: return "<->";


        default: return "?";
    }
}
