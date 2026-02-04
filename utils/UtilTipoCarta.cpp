//
// Created by alejandro on 4/2/26.
//

#include "UtilTipoCarta.h"

const char* tipoCartaString(TipoCarta tipo) {
    switch (tipo) {
        case CARTA_NUMERO:  return "NUMERO";
        case CARTA_COMODIN: return "COMODIN";
        case CARTA_FLIP:    return "FLIP";
        case CARTA_ACCION:  return "ACCION";
        default:            return "???";
    }
}