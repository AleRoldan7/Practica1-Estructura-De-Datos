//
// Created by alejandro on 18/2/26.
//

#ifndef UNO_LISTAMANOFLIPJUGADOR_H
#define UNO_LISTAMANOFLIPJUGADOR_H
#include "NodoManoFlip.h"


class ListaMazoFlipJugador {

private:
    NodoManoFlip* head;
    int cantidad;

    bool ordenar(CartaFlip a, CartaFlip b);

    public:

    ListaMazoFlipJugador();
    ~ListaMazoFlipJugador();

    void insertarOrdenado(const CartaFlip& cartaFlip);
    CartaFlip obtenerCartaFlip(int posicion);
    int sizeMazoFlipJugador();
    void eliminarCartaFlip(int posicion);
    void mostrarConIndices(bool modoOscuro = false) const;
};


#endif //UNO_LISTAMANOFLIPJUGADOR_H