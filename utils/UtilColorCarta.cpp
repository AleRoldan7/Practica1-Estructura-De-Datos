//
// Created by alejandro on 3/2/26.
//

#include "UtilColorCarta.h"

const char* colorANSI(ColorCarta color) {
    switch (color) {
        case ROJO:
            return "\033[31m";
        case VERDE:
            return "\033[32m";
        case AMARILLO:
            return "\033[33m";
        case AZUL:
            return "\033[34m";
        case ROSA:
            return "\033[35m";
        case TURQUESA:
            return "\033[36m";
        case NARANJA:
            return "\033[91m";
        case VIOLETA:
            return "\033[95m";
        case MULTICOLOR:
            return "\033[97m";
        case NEGRA:
            return "\033[30m";
        default:
            return "\033[0m";
    }
}