//
// Created by alejandro on 5/2/26.
//

#include "EfectoCartas.h"

#include "../../utils/UtilColorCarta.h"


EfectoCartas::EfectoCartas() {
}

EfectoCartas::EfectoCartas(ConfiguracionPartida *config) {
    this->configuracion = config;
}

bool EfectoCartas::cartaValida(Carta &cartaJugada, Carta &cartaMesa) {

    if (cartaJugada.getTipo() == CARTA_COMODIN || cartaJugada.getTipo() == JOKER || cartaJugada.getTipo() == GLOTON) {
        return true;
    }

    if (cartaJugada.getColor() == cartaMesa.getColor()) {
        return true;
    }

    if (cartaJugada.getValor() == cartaMesa.getValor()) {
        return true;
    }

    return false;

}

bool EfectoCartas::efectoCarta(Carta &carta, TurnosJuego &turnos, MazoCartas &mazo, Jugador *jugadores, int cantidadJugadores) {

    if (carta.getTipo() == JOKER) {
        cout << "JOKER ACTIVADO" << endl;
        cout << turnos.jugadorActual().getNombreJugador() << " Gano instantaneamente " << endl;
        return true;
    }

    if (carta.getTipo() == GLOTON) {

        cout << "GLOTÓN ACTIVADO" << endl;

        int jugadorActualIndex = turnos.getIndiceActual();

        cout << "Jugadores disponibles:\n";
        for (int i = 0; i < cantidadJugadores; i++) {
            if (i == jugadorActualIndex) continue;
            cout << i << ". " << jugadores[i].getNombreJugador() << " (" << jugadores[i].cantidadCartas() << " cartas) " << endl;
        }

        int objetivoIndex;
        cout << "Elige jugador objetivo: ";
        cin >> objetivoIndex;

        if (objetivoIndex < 0 || objetivoIndex >= cantidadJugadores ||
            objetivoIndex == jugadorActualIndex) {

            cout << "Jugador inválido " << endl;
            return false;
            }

        Jugador& objetivo = jugadores[objetivoIndex];

        for (int i = 0; i < cantidadJugadores; i++) {

            if (i == objetivoIndex) continue;

            Jugador& actual = jugadores[i];

            if (actual.cantidadCartas() <= 1) continue;

            cout << actual.getNombreJugador() << " entrega sus cartas a " << objetivo.getNombreJugador() << endl;

            while (actual.cantidadCartas() > 1) {
                objetivo.recibirCarta(
                    actual.jugarCarta(actual.cantidadCartas() - 1)
                );
            }
        }

        cout << endl << objetivo.getNombreJugador() << " ahora tiene " << objetivo.cantidadCartas() << " cartas " << endl;

        cout << "---------------------------------------------- " << endl;

        return false;
    }


    switch (carta.getValor()) {

        case SALTO:
            turnos.saltarTurno();
            return true;

        case REVERSE:
            if (cantidadJugadores == 2) {
                turnos.saltarTurno();
            } else {
                turnos.invertirDireccion();
            }
            return true;

        case TOMA_1: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            jugadorAfectado.recibirCarta(mazo.robarCarta());
            return true;
        }

        case TOMA_2: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 2; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_3: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 3; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_4: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 4; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case TOMA_6: {
            turnos.siguienteTurno();
            Jugador& jugadorAfectado = turnos.jugadorActual();
            for (int i = 0; i < 6; i++) {
                jugadorAfectado.recibirCarta(mazo.robarCarta());
            }
            turnos.siguienteTurno();
            return true;
        }

        case CAMBIA_COLOR: {

            int opcionColor;

            cout<<"Elige nuevo color: "<<endl;
            cout<<"1. Rojo"<<endl;
            cout<<"2. Azul"<<endl;
            cout<<"3. Verde"<<endl;
            cout<<"4. Amarillo"<<endl;
            cout<<"Opcion: ";
            cin>>opcionColor;

            ColorCarta nuevoColor;

            switch (opcionColor) {
                case 1: nuevoColor = ROJO; break;
                case 2: nuevoColor = AZUL; break;
                case 3: nuevoColor = VERDE; break;
                case 4: nuevoColor = AMARILLO; break;
                default:
                    cout<<"Color invalido. Por defecto lo dejaremos en Rojo"<<endl;
                    nuevoColor = ROJO;
            }

            carta.setColor(nuevoColor);

            return false;
        }
        default:
            return false;
    }
}

bool EfectoCartas::cartaValidaFlip(CartaFlip& jugada, CartaFlip& mesa, bool ladoOscuro) {
    Carta actualJugada = jugada.getCartaActual(ladoOscuro);
    Carta actualMesa   = mesa.getCartaActual(ladoOscuro);

    if (actualJugada.getTipo() == CARTA_COMODIN) {
        return true;
    }
    if (actualJugada.getColor() == actualMesa.getColor()) {
        return true;
    }
    if (actualJugada.getValor() == actualMesa.getValor()) {
        return true;
    }
    return false;
}

bool EfectoCartas::efectoCartaFlip(
    CartaFlip& cartaFlip,
    TurnosJuego& turnos,
    MazoFlip& mazoFlip,
    Jugador* jugadores,
    int cantidadJugadores,
    bool& ladoOscuro
) {
    ValorCarta valor = cartaFlip.getCartaActual(ladoOscuro).getValor();
    bool noAvanzarTurnoNormal = false;

    switch (valor) {
        case TOMA_1:
            turnos.siguienteTurno();
            turnos.jugadorActual().recibirCartaFlip(mazoFlip.robarCartaFlip());
            noAvanzarTurnoNormal = true;
            cout << "¡Toma 1!\n";
            break;

        case SALTO:
            turnos.saltarTurno();
            noAvanzarTurnoNormal = true;
            break;

        case REVERSE:
            if (cantidadJugadores == 2) {
                turnos.saltarTurno();
            } else {
                turnos.invertirDireccion();
            }
            break;

        case TOMA_6:
            turnos.siguienteTurno();
            {
                Jugador& victima = turnos.jugadorActual();
                for (int i = 0; i < 5; i++) {
                    victima.recibirCartaFlip(mazoFlip.robarCartaFlip());
                }
                noAvanzarTurnoNormal = true;
                cout << "¡Toma 5! " << victima.getNombreJugador() << " roba 5 cartas.\n";
            }
            break;

        case SALTO_TODOS:
            cout << "¡SALTA A TODOS! " << turnos.jugadorActual().getNombreJugador()
                 << " vuelve a jugar.\n";
            noAvanzarTurnoNormal = true;
            break;

        case COLOR_ETERNO:
        {
            ColorCarta elegido = pedirColor();
            cout << "Color eterno elegido: " << colorCartaString(elegido) << endl;
            turnos.siguienteTurno();
            robarHastaColor(turnos.jugadorActual(), mazoFlip, elegido, ladoOscuro);
            noAvanzarTurnoNormal = true;
            break;
        }

        case CAMBIA_COLOR:
        {
            ColorCarta elegido = pedirColor();
            Carta cartaActual = cartaFlip.getCartaActual(ladoOscuro);
            cartaActual.setColor(elegido);
            cartaFlip.setCartaActual(cartaActual, ladoOscuro);
            cout << "Color cambiado a: " << colorCartaString(elegido) << endl;
            break;
        }

        case FLIP:
            ladoOscuro = !ladoOscuro;
            cout << "***** ¡FLIP! Cambio a "<< (ladoOscuro ? "OSCURO" : "CLARO")<< " ***** "<<endl;
            break;

        default:
            break;
    }

    return noAvanzarTurnoNormal;
}


ColorCarta EfectoCartas::pedirColor() {
    int opcion;
    cout << "Elige nuevo color: "<<endl;
    cout << "1. Rojo    2. Azul "<<endl;
    cout << "3. Verde   4. Amarillo "<<endl;
    cout << "5. Rosa    6. Turquesa "<<endl;
    cout << "7. Naranja 8. Violeta "<<endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: return ROJO;
        case 2: return AZUL;
        case 3: return VERDE;
        case 4: return AMARILLO;
        case 5: return ROSA;
        case 6: return TURQUESA;
        case 7: return NARANJA;
        case 8: return VIOLETA;
        default:
            cout << "Opción inválida : Rojo por defecto "<<endl;
            return ROJO;
    }
}

void EfectoCartas::robarHastaColor(Jugador& jugador, MazoFlip& mazo, ColorCarta colorBuscado, bool ladoOscuro) {
    int cont = 0;
    CartaFlip robada;

    do {
        robada = mazo.robarCartaFlip();
        jugador.recibirCartaFlip(robada);
        cont++;

        cout << jugador.getNombreJugador() << " roba una carta (" << cont << ") " << endl;

    } while (!mazo.isEmpty() && robada.getCartaActual(ladoOscuro).getColor() != colorBuscado);

    cout << "Salió " << colorCartaString(colorBuscado) << "! Para de robar " << endl;
}


bool EfectoCartas::victoriaJugador(Jugador &jugador) {
    return jugador.cantidadCartas() == 0;
}
