//
// Created by alejandro on 3/2/26.
//

#include "ListaCircular.h"



ListaCircular::ListaCircular() {
    raiz = NULL;
}

ListaCircular::~ListaCircular() {

    if (raiz != NULL) {
        NodoCircular *aux = raiz->siguiente;
        NodoCircular *aux2;
        while (aux != raiz) {

            aux2 = aux;
            aux = aux->siguiente;
            delete aux2;
        }
        delete raiz;
    }
}

void ListaCircular::agregarPrimero(jugador j) {

    NodoCircular *nodo = new NodoCircular();
    nodo->player = j;

    if (raiz == NULL) {
        nodo->siguiente = nodo;
        nodo->anterior = nodo;
        raiz = nodo;
    } else {
        NodoCircular* ultimo = raiz->anterior;

        nodo->siguiente = raiz;
        nodo->anterior = ultimo;

        ultimo->siguiente = nodo;
        raiz->anterior = nodo;

        raiz = nodo;
    }
}

void ListaCircular::agregarUltimo(jugador j) {

    NodoCircular *nodo = new NodoCircular();
    nodo->player = j;

    if (raiz == NULL) {
        nodo->siguiente = nodo;
        nodo->anterior = nodo;
        raiz = nodo;
    } else {
        NodoCircular* ultimo = raiz->anterior;
        nodo->siguiente = raiz;
        nodo->anterior = ultimo;
        ultimo->siguiente = nodo;
        raiz->anterior = nodo;
    }
}

int ListaCircular::cantidad() {

    if (raiz == NULL) return 0;

    int contador = 1;
    NodoCircular *aux = raiz->siguiente;

    while (aux != raiz) {
        contador++;
        aux = aux->siguiente;
    }

    return contador;
}

bool ListaCircular::estaVacia() {
    if (raiz == NULL) {
        return true;
    } else {
        return false;
    }
}
