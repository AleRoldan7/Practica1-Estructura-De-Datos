//
// Created by alejandro on 5/2/26.
//

#include "../../logica-juego/creacion-jugador/CrearJugador.h"

#include <iostream>
using namespace std;

CrearJugador::CrearJugador() {
    cantidadJugadores = 0;
}

int CrearJugador::solicitarJugadores() {

    int catidad;

    do {
        cout<<"Ingrese la cantidad de jugadores: "<<endl;
        cin>>catidad;
    }while (catidad < 2 );

    return catidad;
}

/*
Jugador *CrearJugador::crearJugadores(int &cantidad) {

    Jugador* jugadores = new Jugador[cantidad];

    for (int i = 0; i < cantidad; i++) {
        string nombre;
        cout<<"Ingrese nombre: "<<endl;
        cin>>nombre;

        jugadores[i] = Jugador(nombre);
    }

    return jugadores;
}
*/

Jugador *CrearJugador::crearJugadores(int &cantidad) {
    Jugador* jugadores = new Jugador[cantidad];

    for (int i = 0; i < cantidad; i++) {
        string nombre;
        cout << "Ingrese nombre: ";
        cin >> nombre;

        jugadores[i].setNombreJugador(nombre);
    }

    return jugadores;
}
