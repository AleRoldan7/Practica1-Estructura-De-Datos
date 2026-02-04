cmake_minimum_required(VERSION 3.10)
project(Uno)

set(CMAKE_CXX_STANDARD 20)

add_executable(Uno main.cpp
        enums/CartaColor.h
        enums/TipoCarta.h
        enums/ValorCarta.h
        objetos/jugador/jugador.cpp
        objetos/jugador/jugador.h
        objetos/lista/lista-circular/ListaCircular.cpp
        objetos/lista/lista-circular/ListaCircular.h
        utils/UtilColorCarta.cpp
        utils/UtilColorCarta.h
        utils/UtilValorCarta.cpp
        utils/UtilValorCarta.h
        objetos/carta/Carta.cpp
        objetos/carta/Carta.h
        utils/UtilTipoCarta.cpp
        utils/UtilTipoCarta.h
        utils/CentrarTexto.cpp
        utils/CentrarTexto.h
        objetos/lista/mazo-lista/NodoMazo.cpp
        objetos/lista/mazo-lista/NodoMazo.h
        objetos/lista/mazo-lista/PilaMazo.cpp
        objetos/lista/mazo-lista/PilaMazo.h
        objetos/lista/mazo-lista/MazoCartas.cpp
        objetos/lista/mazo-lista/MazoCartas.h
)
