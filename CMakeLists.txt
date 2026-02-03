cmake_minimum_required(VERSION 3.10)
project(Uno)

set(CMAKE_CXX_STANDARD 20)

add_executable(Uno main.cpp
        enums/CartaColor.h
        enums/TipoCarta.h
        enums/ValorCarta.h
        objetos/carta/Carta.cpp
        objetos/carta/Carta.h
        objetos/jugador/jugador.cpp
        objetos/jugador/jugador.h
        objetos/lista/mazo-lista/MazoLista.cpp
        objetos/lista/mazo-lista/MazoLista.h
)
