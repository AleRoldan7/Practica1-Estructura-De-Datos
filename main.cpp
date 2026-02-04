#include <iostream>

#include "objetos/carta/Carta.h"
#include "objetos/lista/mazo-lista/MazoCartas.h"
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


    return 0;

}