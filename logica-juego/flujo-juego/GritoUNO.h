//
// Created by alejandro on 10/2/26.
//

#ifndef UNO_GRITOUNO_H
#define UNO_GRITOUNO_H
#include "TurnosJuego.h"


class GritoUNO {
private:
    bool gritoPendiente;
    int indiceJugador;

    public:
    GritoUNO();

    void comprobarUno(TurnosJuego& turnos);
    void reportarJugador(Jugador* jugador, int cantidad, MazoCartas& mazo);
    bool unoPendiente()const;
};


#endif //UNO_GRITOUNO_H