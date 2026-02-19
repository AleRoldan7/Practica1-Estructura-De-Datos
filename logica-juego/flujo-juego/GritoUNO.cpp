//
// Created by alejandro on 10/2/26.
//

#include "GritoUNO.h"
#include <iostream>
using namespace std;

GritoUNO::GritoUNO() {
    unoPendiente = false;
    indiceJugadorPendiente = -1;
}

void GritoUNO::verificarSiDebeGritar(TurnosJuego& turnos) {

    Jugador& jugador = turnos.jugadorActual();

    if (jugador.cantidadCartas() == 1) {

        string entrada;
        cout << "Te queda 1 carta. Escribe 'UNO' para evitar penalizacion: ";
        cin >> entrada;

        if (entrada == "UNO" || entrada == "uno") {
            cout << "Gritaste UNO correctamente.\n";
            limpiarEstado();
        } else {
            cout << "No gritaste UNO. Quedas expuesto a reporte.\n";
            unoPendiente = true;
            indiceJugadorPendiente = turnos.getIndiceActual();
        }
    }
}

void GritoUNO::intentarReporte(TurnosJuego& turnos, MazoCartas& mazo) {

    if (!unoPendiente) return;

    cout << "¿Alguien quiere reportar que no grito UNO? (reportar / no): ";

    string opcion;
    cin >> opcion;

    if (opcion == "reportar") {

        int reportador = turnos.getIndiceActual();

        if (indiceJugadorPendiente != -1) {

            cout << "Reporte valido. El jugador roba 2 cartas.\n";

            turnos.getJugador(indiceJugadorPendiente)
                .recibirCarta(mazo.robarCarta());
            turnos.getJugador(indiceJugadorPendiente)
                .recibirCarta(mazo.robarCarta());

        } else {

            cout << "Reporte incorrecto. El reportador roba 2 cartas.\n";

            turnos.getJugador(reportador)
                .recibirCarta(mazo.robarCarta());
            turnos.getJugador(reportador)
                .recibirCarta(mazo.robarCarta());
        }
    }

    limpiarEstado();
}

void GritoUNO::limpiarEstado() {
    unoPendiente = false;
    indiceJugadorPendiente = -1;
}