//
// Created by alejandro on 10/2/26.
//

#ifndef UNO_GRITOUNO_H
#define UNO_GRITOUNO_H
#include "TurnosJuego.h"
#include "../../configuracion-partida/ConfiguracionPartida.h"


class GritoUNO {
private:
    bool unoPendiente;
    int indiceJugadorPendiente;

public:
    GritoUNO();

    void verificarSiDebeGritar(TurnosJuego& turnos);
    void intentarReporte(TurnosJuego& turnos, MazoCartas& mazo);

    void limpiarEstado();
};

#endif //UNO_GRITOUNO_H