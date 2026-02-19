//
// Created by alejandro on 16/2/26.
//

#ifndef UNO_CONFIGURACIONPARTIDA_H
#define UNO_CONFIGURACIONPARTIDA_H


class ConfiguracionPartida {

private:
    bool acumulacionCartas;
    bool retoMas4Activo;
    bool robarHastaEncontrar;
    bool gritoUnoActivo;
    bool ganarConNegra;

    public:

    ConfiguracionPartida();
    void mostrarMenu();
    void configurar();

    bool isAcumulacionActiva();
    bool isRetoMas4Activo();
    bool isRobarHastaEncontrar();
    bool isGritoUnoActivo();
    bool isGanarConNegra();

};


#endif //UNO_CONFIGURACIONPARTIDA_H