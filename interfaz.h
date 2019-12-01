#ifndef INTERFAZ
#define INTERFAZ
#include "algoritmos_grafo.h"


class Interfaz{
    private:
        
        Grafo_MA grafo;
        int* vectorDePesos;
        vertice* vectorVerticeAnterior;
        int** matrizDePesos;
        vertice** matrizDeVerticesIntermedios;
        Algoritmos_grafo_MA algoritmos;

    public:

        Interfaz();
        ~Interfaz();
        void desplegarMenu();
};

#endif
