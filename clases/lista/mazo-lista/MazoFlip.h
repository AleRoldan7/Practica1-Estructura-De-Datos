//
// Created by alejandro on 17/2/26.
//

#ifndef UNO_MAZOFLIP_H
#define UNO_MAZOFLIP_H
#include "PilaFlip.h"


class MazoFlip {

private:
    PilaFlip mazoFlip;
    void createMazoFlip();

    public:
    MazoFlip();
    MazoFlip(int cantidadJugadores);
    CartaFlip robarCartaFlip();
    int cantidadRestantes();
    bool isEmpty();
    void mostrarMazoFlip();
    void revolverCartaMazoFlip();
};


#endif //UNO_MAZOFLIP_H