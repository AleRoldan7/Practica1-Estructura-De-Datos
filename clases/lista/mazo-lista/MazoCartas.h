//
// Created by alejandro on 4/2/26.
//

#ifndef UNO_MAZOCARTAS_H
#define UNO_MAZOCARTAS_H
#include "PilaMazo.h"


class MazoCartas {
private:
    PilaMazo mazo;
    void createMazo();

    public:
    MazoCartas();

    Carta robarCarta();
    int cartasRestantes();
    void revolverCartas();
};


#endif //UNO_MAZOCARTAS_H