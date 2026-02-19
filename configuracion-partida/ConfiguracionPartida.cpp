//
// Created by alejandro on 16/2/26.
//

#include "ConfiguracionPartida.h"

#include <iostream>
using namespace std;

ConfiguracionPartida::ConfiguracionPartida() {

    acumulacionCartas = false;
    retoMas4Activo = false;
    robarHastaEncontrar = false;
    gritoUnoActivo = false;
    ganarConNegra = true;

}

void ConfiguracionPartida::mostrarMenu() {

    cout << "\033[32m---------------------------------\033[0m" << endl;
    cout << "\033[33m     Configurar Partida          \033[0m" << endl;
    cout << "\033[31m---------------------------------\033[0m" << endl;

    cout << "\033[34m";
    cout << "1. Acumular (+2 o +4)             : "
    << (acumulacionCartas ? "\033[32mACTIVADO\033[0m" : "\033[31mDESACTIVADO\033[0m") << endl;

    cout << "2. Reto del +4                    : "
         << (retoMas4Activo ? "\033[32mACTIVADO\033[0m" : "\033[31mDESACTIVADO\033[0m") << endl;

    cout << "3. Robar hasta encontrar          : "
         << (robarHastaEncontrar ? "\033[32mACTIVADO\033[0m" : "\033[31mDESACTIVADO\033[0m") << endl;

    cout << "4. Permitir ganar con carta negra : "
         << (ganarConNegra ? "\033[32mACTIVADO\033[0m" : "\033[31mDESACTIVADO\033[0m") << endl;

    cout << "\n0. Confirmar y comenzar partida\n";
    cout << "\033[32m---------------------------------\033[0m" << endl;

}

void ConfiguracionPartida::configurar() {

    int opcion;

    do {
        mostrarMenu();
        cout << "\033[33mSeleccione opcion para cambiar estado: \033[0m";
        cin >> opcion;

        switch (opcion) {

            case 1:
                acumulacionCartas = !acumulacionCartas;
                break;

            case 2:
                retoMas4Activo = !retoMas4Activo;
                break;

            case 3:
                robarHastaEncontrar = !robarHastaEncontrar;
                break;

            case 4:
                gritoUnoActivo = !gritoUnoActivo;
                break;

            case 5:
                ganarConNegra = !ganarConNegra;
                break;

            case 0:
                cout << "\033[32m\nConfiguracion confirmada.\033[0m\n" << endl;
                break;

            default:
                cout << "\033[31mOpcion invalida.\033[0m\n";
        }

    } while (opcion != 0);

}

bool ConfiguracionPartida::isAcumulacionActiva() {
    return acumulacionCartas;
}

bool ConfiguracionPartida::isRetoMas4Activo() {
    return retoMas4Activo;
}

bool ConfiguracionPartida::isRobarHastaEncontrar() {
    return robarHastaEncontrar;
}

bool ConfiguracionPartida::isGritoUnoActivo() {
    return gritoUnoActivo;
}

bool ConfiguracionPartida::isGanarConNegra() {
    return ganarConNegra;
}
