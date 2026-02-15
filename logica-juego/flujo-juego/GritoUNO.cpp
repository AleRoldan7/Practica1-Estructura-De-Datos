//
// Created by alejandro on 10/2/26.
//

#include "GritoUNO.h"
#include <iostream>
using namespace std;

GritoUNO::GritoUNO() {
    gritoPendiente = false;
    indiceJugador = -1;
}

void GritoUNO::comprobarUno(TurnosJuego &turnos) {

    Jugador& jugador = turnos.jugadorActual();

    if (jugador.cantidadCartas() == 1) {
        string grito;
        cout<<"Te queda una carta, escribe 'UNO': "<<endl;
        cin>>grito;

        if (grito == "UNO") {
            cout<<"Grito 'UNO'"<<endl;
            gritoPendiente = false;
            indiceJugador = -1;
        } else {
            cout<<"No gritaste UNO te reportaran"<<endl;
            gritoPendiente = true;
            indiceJugador = turnos.getIndiceActual();
        }
    }
}

void GritoUNO::reportarJugador(TurnosJuego& turnos, MazoCartas &mazo) {

    if (!gritoPendiente) return;

    int indiceJugadorReportado = turnos.getIndiceActual();

    if (indiceJugadorReportado == indiceJugador) {
        gritoPendiente = false;
        return;
    }

    Jugador& jugador = turnos.jugadorActual();

    char opcion;

    cout << "¿Reportar al jugador que no gritó UNO? (s/n): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        cout << "Reporte válido. El jugador roba 2 cartas.\n";

        turnos.getJugador(indiceJugador).recibirCarta(mazo.robarCarta());
        turnos.getJugador(indiceJugador).recibirCarta(mazo.robarCarta());
    }

    gritoPendiente = false;
    indiceJugador = -1;
}

bool GritoUNO::unoPendiente() const {
    return gritoPendiente;
}
