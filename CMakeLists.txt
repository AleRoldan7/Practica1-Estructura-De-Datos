cmake_minimum_required(VERSION 3.10)
project(Uno)

set(CMAKE_CXX_STANDARD 20)

add_executable(Uno main.cpp
        enums/CartaColor.h
        enums/TipoCarta.h
        enums/ValorCarta.h
        clases/jugador/Jugador.cpp
        clases/jugador/Jugador.h
        clases/lista/lista-circular/ListaCircular.cpp
        clases/lista/lista-circular/ListaCircular.h
        utils/UtilColorCarta.cpp
        utils/UtilColorCarta.h
        utils/UtilValorCarta.cpp
        utils/UtilValorCarta.h
        clases/carta/Carta.cpp
        clases/carta/Carta.h
        utils/UtilTipoCarta.cpp
        utils/UtilTipoCarta.h
        utils/CentrarTexto.cpp
        utils/CentrarTexto.h
        clases/lista/mazo-lista/NodoMazo.cpp
        clases/lista/mazo-lista/NodoMazo.h
        clases/lista/mazo-lista/PilaMazo.cpp
        clases/lista/mazo-lista/PilaMazo.h
        clases/lista/mazo-lista/MazoCartas.cpp
        clases/lista/mazo-lista/MazoCartas.h
        clases/lista/mazo-jugador/ListaMazoJugador.cpp
        clases/lista/mazo-jugador/ListaMazoJugador.h
        clases/lista/mazo-jugador/NodoMano.h
        logica-juego/creacion-jugador/CrearJugador.cpp
        logica-juego/creacion-jugador/CrearJugador.h
        logica-juego/reparticion-cartas/ReparteCartasJugador.cpp
        logica-juego/reparticion-cartas/ReparteCartasJugador.h
        logica-juego/reglas/ReglasJuego.cpp
        logica-juego/reglas/ReglasJuego.h
        logica-juego/flujo-juego/TurnosJuego.cpp
        logica-juego/flujo-juego/TurnosJuego.h
        utils/LimpiarPantalla.cpp
        utils/LimpiarPantalla.h
        logica-juego/flujo-juego/GritoUNO.cpp
        logica-juego/flujo-juego/GritoUNO.h
)
