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

void GritoUNO::reportarJugador(Jugador *jugador, int cantidad, MazoCartas &mazo) {

    char opcion;

    if (!gritoPendiente) return;
    cout<<"¿Reportar al jugador que no grito 'UNO' "<<jugador[indiceJugador].getNombreJugador()<< "? (Si/No)";
    cin>>opcion;

    if (opcion == 'S' || opcion == 's') {
        cout << "Ingrese índice del jugador que reporta: ";
        int reportador;
        cin >> reportador;

        if (reportador >= 0 && reportador < cantidad &&
            reportador != indiceJugador) {

            cout << "Reporte válido. El jugador roba 2 cartas.\n";
            jugador[indiceJugador].recibirCarta(mazo.robarCarta());
            jugador[indiceJugador].recibirCarta(mazo.robarCarta());

            } else {
                cout << "Reporte inválido. El reportador roba 2 cartas.\n";
                jugador[reportador].recibirCarta(mazo.robarCarta());
                jugador[reportador].recibirCarta(mazo.robarCarta());
            }
    }

    gritoPendiente = false;
    indiceJugador = -1;
}

bool GritoUNO::unoPendiente() const {
    return gritoPendiente;
}
