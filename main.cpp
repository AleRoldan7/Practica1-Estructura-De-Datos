#include <iostream>
using namespace std;

int main() {

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

    return 0;

}