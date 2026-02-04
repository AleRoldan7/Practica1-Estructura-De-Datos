//
// Created by alejandro on 4/2/26.
//

#include "CentrarTexto.h"

std::string centrarTexto(const std::string& texto, int ancho) {
    int espacios = ancho - texto.length();
    if (espacios <= 0) return texto.substr(0, ancho);

    int izq = espacios / 2;
    int der = espacios - izq;

    return std::string(izq, ' ') + texto + std::string(der, ' ');
}