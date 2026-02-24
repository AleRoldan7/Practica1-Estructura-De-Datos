//
// Created by alejandro on 16/2/26.
//

#include "Juego.h"
#include <iostream>

#include "../creacion-jugador/CrearJugador.h"
using namespace std;

Juego::Juego()
    : jugadores(nullptr),
      cantidadJugadores(0),
      mazo(0),
      turnosJuego(),
      efectoCartas(&configuracion),
      gritoUno(),
      ladoOscuro(false),
      modoFlip(false)
{
}

Juego::~Juego() {
    delete[] jugadores;
}

void Juego::iniciarJuego() {

    int modoJuego;

    cout<<"----------Modos de juego----------"<<endl;
    cout<<"1.Modo Normal"<<endl;
    cout<<"2.Modo Flip"<<endl;
    cout<<"Seleccione modo de juego: ";
    cout<<"----------------------"<<endl;
    cin>>modoJuego;

    modoFlip = (modoJuego == 2);
    ladoOscuro = false;

    configuracion.configurar();

    CrearJugador creador;
    cantidadJugadores = creador.solicitarJugadores();
    jugadores = creador.crearJugadores(cantidadJugadores);

    turnosJuego = TurnosJuego(jugadores, cantidadJugadores);

    if (!modoFlip) {

        mazo = MazoCartas(cantidadJugadores);
        cout<<"Mazo creado con "<<mazo.cartasRestantes()<<" cartas"<<endl;

        for (int i = 0; i < cantidadJugadores; i++) {
            for (int j = 0; j < 7; j++) {
                jugadores[i].recibirCarta(mazo.robarCarta());
            }
        }

        do {
            cartaMesa = mazo.robarCarta();
        } while (cartaMesa.getTipo() != CARTA_NUMERO);

        cartaMesa.mostrarCarta();

    } else {

        mazoFlip = MazoFlip(cantidadJugadores);
        cout<<"Mazo Flip creado con "<<mazoFlip.cantidadRestantes()<<" cartas"<<endl;

        for (int i = 0; i < cantidadJugadores; i++) {
            for (int j = 0; j < 7; j++) {
                jugadores[i].recibirCartaFlip(mazoFlip.robarCartaFlip());
            }
        }

        cartaMesaFlip = mazoFlip.robarCartaFlip();

        cout<<"Carta inicial (LADO CLARO):"<<endl;
        cartaMesaFlip.mostrarAmbosLados();
    }

    loopJuego();
}

void Juego::loopJuego() {

    if (!modoFlip) {
        loopNormal();
    } else {
        loopFlip();
    }
}


void Juego::loopNormal() {

    while (true) {

        gritoUno.intentarReporte(turnosJuego, mazo);

        Jugador& actual = turnosJuego.jugadorActual();

        cout<<"================================"<<endl;
        cout<<"Mazo de cartas: "<<mazo.cartasRestantes()<<endl;
        cout<<"================================"<<endl;

        cout<<"Turno de: "<<actual.getNombreJugador()<<endl;

        cout<<"Carta en mesa: "<<endl;
        cartaMesa.mostrarCarta();

        actual.mostrarManoConIndices();

        cout<<"-1: Robar carta"<<endl;
        cout<<"Ingrese el indice de la carta"<<endl;

        int opcion;
        cout<<"Elige opcion: ";
        cin>>opcion;

        if (opcion == -1) {

            if (configuracion.isRobarHastaEncontrar()) {

                Carta robada;
                do {
                    robada = mazo.robarCarta();
                    actual.recibirCarta(robada);
                } while (!efectoCartas.cartaValida(robada, cartaMesa));

            } else {
                actual.recibirCarta(mazo.robarCarta());
            }

            turnosJuego.siguienteTurno();
            continue;
        }

        try {

            Carta jugada = actual.jugarCarta(opcion);

            if (!efectoCartas.cartaValida(jugada, cartaMesa)) {

                cout << "Carta invalida. Robas una carta." << endl;

                actual.recibirCarta(jugada);
                actual.recibirCarta(mazo.robarCarta());

                turnosJuego.siguienteTurno();
                continue;
            }

            cartaMesa = jugada;
            pilaDescarte.push_back(cartaMesa);

            bool efecto =
                efectoCartas.efectoCarta(
                    cartaMesa,
                    turnosJuego,
                    mazo,
                    jugadores,
                    cantidadJugadores
                );

            gritoUno.verificarSiDebeGritar(turnosJuego);

            if (cartaMesa.getTipo() == JOKER) {
                cout << " GANO CON JOKER ";
                cout << actual.getNombreJugador() << " GANADOR INSTANTANEO " << endl;
                break;
            }

            cout << endl;

            if (efectoCartas.victoriaJugador(actual)) {
                cout << "GANADOR: " << actual.getNombreJugador() << endl;
                break;
            }

            cout << "Presiona ENTER para terminar turno...";
            cin.ignore();
            cin.get();

            if (!efecto) {
                turnosJuego.siguienteTurno();
            }

        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void Juego::loopFlip() {
    while (true) {
        limpiarPantalla();
        Jugador& actual = turnosJuego.jugadorActual();

        cout << "================================\n";
        cout << "Mazo Flip: " << mazoFlip.cantidadRestantes() << endl;
        cout << "Modo actual: " << (ladoOscuro ? "OSCURO" : "CLARO") << endl;
        cout << "================================\n";

        cout << "Turno de: " << actual.getNombreJugador() << endl;

        cout << "Carta en mesa (lado actual):\n";
        cartaMesaFlip.mostrarCartaActual(ladoOscuro);

        cout << " Tu mano: " << endl;
        actual.mostrarManoFlipConIndices(ladoOscuro);

        cout<<"-1: Robar carta"<<endl;
        cout<<"Ingrese el indice de la carta: ";

        int opcion;
        cin >> opcion;

        if (opcion == -1) {
            actual.recibirCartaFlip(mazoFlip.robarCartaFlip());
            turnosJuego.siguienteTurno();
            continue;
        }

        try {
            CartaFlip jugada = actual.jugarCartaFlip(opcion);

            if (!efectoCartas.cartaValidaFlip(jugada, cartaMesaFlip, ladoOscuro)) {
                cout << "Carta inválida. Robas una carta " << endl;
                actual.recibirCartaFlip(jugada);
                actual.recibirCartaFlip(mazoFlip.robarCartaFlip());
                turnosJuego.siguienteTurno();
                continue;
            }

            cartaMesaFlip = jugada;
            pilaDescarteFlip.push_back(cartaMesaFlip);

            bool noAvanzarTurno = efectoCartas.efectoCartaFlip(cartaMesaFlip, turnosJuego, mazoFlip,
                jugadores,
                cantidadJugadores,
                ladoOscuro
            );

            Carta actualCarta = cartaMesaFlip.getCartaActual(ladoOscuro);

            if (actualCarta.getTipo() == JOKER) {
                cout << "GANO CON JOKER ";
                cout << actual.getNombreJugador() << "GANADOR INSTANTANEO " << endl;
                break;
            }

            if (actual.cantidadaCartaFlip() == 0) {
                cout << "GANADOR: " << actual.getNombreJugador() << endl;
                break;
            }

            if (mazoFlip.cantidadRestantes() == 0) {

            }

            if (!noAvanzarTurno) {
                turnosJuego.siguienteTurno();
            }

            cout << "\nPresiona ENTER para continuar...\n";
            cin.ignore();
            cin.get();
            limpiarPantalla();
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

bool Juego::cartaValidaFlip(CartaFlip jugada, CartaFlip mesa) {
    Carta a = jugada.getCartaActual(ladoOscuro);
    Carta b = mesa.getCartaActual(ladoOscuro);

    return (
        a.getColor() == b.getColor() ||
        a.getValor() == b.getValor() ||
        a.getTipo() == CARTA_COMODIN
    );
}

void Juego::victoriaPorJoker(int indiceJugador) {
    ganarJoker = true;
    indiceGanadorJoker = indiceJugador;
}

void Juego::reutilizarPilaDescarte() {

    if (pilaDescarte.size() <= 1) return;

    cout << "Rearmando el mazo para seguir jugando " << endl;

    Carta cartaActual = pilaDescarte.back();
    pilaDescarte.pop_back();


}


void Juego::limpiarPantalla() {
    cout << "\033[2J\033[1;1H";
}
