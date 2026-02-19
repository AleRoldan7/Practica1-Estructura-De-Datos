#include <iostream>

#include "clases/carta/Carta.h"
#include "clases/lista/mazo-lista/MazoCartas.h"
#include "clases/lista/mazo-lista/MazoFlip.h"
#include "configuracion-partida/ConfiguracionPartida.h"
#include "logica-juego/creacion-jugador/CrearJugador.h"
#include "logica-juego/flujo-juego/GritoUNO.h"
#include "logica-juego/flujo-juego/TurnosJuego.h"
#include "logica-juego/efecto-cartas/EfectoCartas.h"
#include "logica-juego/flujo-juego/Juego.h"
#include "logica-juego/reparticion-cartas/ReparteCartasJugador.h"
#include "utils/LimpiarPantalla.h"
using namespace std;

int main() {


     /*
    cout << "Prueba de colores en consola (UNO)\n\n";

    cout << "\033[31m"  // Rojo
         << "┌─────────┐\n"
         << "│  ROJO   │\n"
         << "│    5    │\n"
         << "└─────────┘\n"
         << "\033[0m\n";

    cout << "\033[32m"  // Verde
         << "┌─────────┐\n"
         << "│ VERDE   │\n"
         << "│   +2    │\n"
         << "└─────────┘\n"
         << "\033[0m\n";

    cout << "\033[34m"  // Azul
         << "┌─────────┐\n"
         << "│  AZUL   │\n"
         << "│   SALTO │\n"
         << "└─────────┘\n"
         << "\033[0m\n";

    cout << "\033[33m"  // Amarillo
         << "┌─────────┐\n"
         << "│AMARILLO │\n"
         << "│   REV   │\n"
         << "└─────────┘\n"
         << "\033[0m\n";

    cout << "Fin de la prueba\n";
     */


     /*
     Carta manual(ROJO, CARTA_NUMERO, SIETE);
     std::cout << "Manual (debería ser roja):\n";
     manual.mostrarCarta();

     std::cout << "Desde el mazo (debería pintar también): "<<endl;
     MazoCartas mazo;

     std::cout << "Total inicial: " << mazo.cartasRestantes() << endl;

     while (mazo.cartasRestantes() > 8) {
          Carta c = mazo.robarCarta();
          c.mostrarCarta();
     }
     */


     /*
     MazoCartas mazoCartas;
     mazoCartas.revolverCartas();

     CrearJugador crearJugador;
     int cantidad = crearJugador.solicitarJugadores();
     Jugador* jugador = crearJugador.crearJugadores(cantidad);

     ReparteCartasJugador reparteCartasJugador;
     reparteCartasJugador.repartirCartasJugador(mazoCartas, jugador, cantidad );

     for (int i = 0; i < cantidad; i++) {
          jugador[i].mostrarMano();
     }


     TurnosJuego turno(jugador, cantidad);

     cout << "Jugador actual: "
          << turno.jugadorActual().getNombreJugador() << endl;

     turno.siguienteTurno();

     cout << "Siguiente jugador: "
          << turno.jugadorActual().getNombreJugador() << endl;

     turno.siguienteTurno();
     cout <<"Siguiente jugador: " << turno.jugadorActual().getNombreJugador() << endl;
     */



     /*

     for (int ronda = 0; ronda < 10; ronda++) {

          cout << "\n====================\n";
          Jugador& actual = turnos.jugadorActual();

          cout << "Turno de: " << actual.getNombreJugador() << endl;
          cout << "Carta en mesa:\n";3
          cartaMesa.mostrarCarta();

          // SIMULACIÓN: jugador roba y juega esa carta
          Carta jugada = mazo.robarCarta();
          cout << "Carta jugada:\n";
          jugada.mostrarCarta();

          // Aplicar efecto
          reglas.efectoCarta(jugada, turnos, mazo, jugadores, cantidad);

          // La carta pasa a ser la nueva carta en mesa
          cartaMesa = jugada;

          // Avanzar turno
          turnos.siguienteTurno();
     }


     */

    /*
    ConfiguracionPartida confi;
    confi.configurar();


    CrearJugador creador;
    int cantidad = creador.solicitarJugadores();
    Jugador* jugadores = creador.crearJugadores(cantidad);

    MazoCartas mazo(cantidad);
    cout<<"Mazo creado con "<<mazo.cartasRestantes()<<" cartas"<<endl;

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < 2; j++) {
            jugadores[i].recibirCarta(mazo.robarCarta());
        }
    }

    Carta cartaMesa;
    do {
        cartaMesa = mazo.robarCarta();
    } while (cartaMesa.getTipo() == CARTA_COMODIN);

    cout<<"Carta inicial en mesa: "<<endl;
    cartaMesa.mostrarCarta();

    TurnosJuego turnos(jugadores, cantidad);
    EfectoCartas reglas;
    GritoUNO gritoUNo;

    while (true) {

        gritoUNo.reportarJugador(turnos, mazo);
        Jugador& actual = turnos.jugadorActual();

        cout<<"================================"<<endl;
        cout<<"Mazo de cartas: "<<mazo.cartasRestantes()<<endl;
        cout<<"================================"<<endl;

        cout<<"===================================="<<endl;
        cout<<"Turno de: "<<actual.getNombreJugador()<<endl;
        cout<<"===================================="<<endl;

        cout<<"Carta en mesa: "<<endl;
        cartaMesa.mostrarCarta();

        actual.mostrarManoConIndices();

        cout<<"Opciones: "<<endl;
        cout<<"-1 → Robar carta"<<endl;
        cout<<"0..N → Jugar carta por indice "<<endl;

        int opcion;
        cout<<"Elige opcion: ";
        cin>>opcion;

        if (opcion == -1) {
            cout<<"Robando carta "<<endl;
            actual.recibirCarta(mazo.robarCarta());
            turnos.siguienteTurno();
            continue;
        }

        try {
            Carta jugada = actual.jugarCarta(opcion);

            if (!reglas.cartaValida(jugada, cartaMesa)) {
                cout<<"Carta invalida. Robas una carta."<<endl;
                actual.recibirCarta(jugada);
                actual.recibirCarta(mazo.robarCarta());
                turnos.siguienteTurno();
                continue;
            }

            cartaMesa = jugada;
            bool efecto = reglas.efectoCarta(jugada, turnos, mazo, jugadores, cantidad);

            gritoUNo.comprobarUno(turnos);


            if (actual.cantidadCartas() == 0) {
                cout<<"GANADOR: "<<actual.getNombreJugador()<<endl;
                break;
            }

            cout<<"Presiona ENTER para terminar tu turno..."<<endl;
            cin.ignore();
            cin.get();

            if (!efecto) {
                turnos.siguienteTurno();
            }

        } catch (exception& e) {
            cout<<"Error: "<< e.what()<<endl;
        }
    }

     delete[] jugadores;
    */


    Juego juego;
    juego.iniciarJuego();


    /*
    MazoCartas mazoCartas;
    mazoCartas.mostrarMazoCompleto();
    */

    /*
    MazoFlip mazoFlip;
    mazoFlip.mostrarMazoFlip();
    */
    return 0;

}