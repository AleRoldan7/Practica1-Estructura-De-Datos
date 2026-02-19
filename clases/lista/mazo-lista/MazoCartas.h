//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_MAZOCARTAS_H
#define UNO_MAZOCARTAS_H
#include "PilaMazo.h"


class MazoCartas {
private:
    PilaMazo mazo;
    void createMazoInicial();

    public:
    MazoCartas();
    MazoCartas(int cantidadJugadores);
    Carta robarCarta();
    int cartasRestantes();
    void revolverCartas();
    void mostrarMazoCompleto();

};


#endif //UNO_MAZOCARTAS_H