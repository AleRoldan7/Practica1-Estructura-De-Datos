//
// Created by alejandro on 9/2/26.
//

#include "LimpiarPantalla.h"
#include <iostream>
#include <cstdlib>

void limpiarPantalla() {
    std::cout << "\033[2J\033[H" << std::flush;
}