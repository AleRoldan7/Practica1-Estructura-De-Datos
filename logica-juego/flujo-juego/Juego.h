//
// Created by alejandro on 16/2/26.
//

#ifndef UNO_JUEGO_H
#define UNO_JUEGO_H
#include "GritoUNO.h"
#include "TurnosJuego.h"
#include "../../clases/jugador/Jugador.h"
#include "../../clases/lista/mazo-lista/MazoFlip.h"
#include "../../configuracion-partida/ConfiguracionPartida.h"
#include "../efecto-cartas/EfectoCartas.h"


class Juego {
private:
    ConfiguracionPartida configuracion;

    Jugador* jugadores;
    int cantidadJugadores;

    MazoCartas mazo;
    MazoFlip mazoFlip;

    TurnosJuego turnosJuego;
    EfectoCartas efectoCartas;
    GritoUNO gritoUno;

    Carta cartaMesa;
    CartaFlip cartaMesaFlip;

    bool modoFlip;
    bool ladoOscuro;

    void loopNormal();
    void loopFlip();

    bool cartaValidaFlip(CartaFlip jugada, CartaFlip mesa);

    public:

    Juego();
    ~Juego();

    void iniciarJuego();
    void loopJuego();
};


#endif //UNO_JUEGO_H