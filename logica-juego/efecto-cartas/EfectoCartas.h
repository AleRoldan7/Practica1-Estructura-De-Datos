//
// Created by alejandro on 5/2/26.
//

#ifndef UNO_REGLASJUEGO_H
#define UNO_REGLASJUEGO_H
#include <string>

#include "../../clases/carta/Carta.h"
#include "../../clases/lista/mazo-lista/MazoFlip.h"
#include "../../configuracion-partida/ConfiguracionPartida.h"
#include "../flujo-juego/TurnosJuego.h"


class EfectoCartas {

private:
    ConfiguracionPartida* configuracion;

    public:
    EfectoCartas();
    EfectoCartas(ConfiguracionPartida* config);
    bool cartaValida(Carta& cartaJugada, Carta& cartaMesa);
    bool efectoCarta(Carta& carta, TurnosJuego& turnos, MazoCartas& mazo, Jugador* jugadores, int cantidadJugadores);
    bool victoriaJugador(Jugador& jugador);

    bool cartaValidaFlip(CartaFlip& cartaJugadaFlip, CartaFlip& cartaMesaFlip);
    bool efectoCartaFlip(
        CartaFlip& carta,
        TurnosJuego& turnos,
        MazoFlip& mazoFlip,
        Jugador* jugadores,
        int cantidadJugadores,
        bool& ladoOscuro
    );

    ColorCarta pedirColor();
    void robarHastaColor(Jugador& jugador, MazoFlip& mazo, ColorCarta colorBuscado);
};


#endif //UNO_REGLASJUEGO_H