//
// Created by alejandro on 17/2/26.
//

#ifndef UNO_CARTAFLIP_H
#define UNO_CARTAFLIP_H
#include "Carta.h"
using std::vector;


class CartaFlip {
private:

    Carta ladoClaro;
    Carta ladoOscuro;
    //bool esOscuro;

    public:
    CartaFlip();
    CartaFlip(Carta claro, Carta oscuro);

    //void voltearCartaFlip();
    //void setModoOscuro(bool modo);

    Carta getCartaActual(bool ladoOscuro);
    void mostrarCartaActual(bool ladoOscuro);
    void mostrarAmbosLados();
    void setCartaActual(Carta& carta, bool ladoOscuro);
    vector<std::string> lineaHorizontalFlip();
};


#endif //UNO_CARTAFLIP_H