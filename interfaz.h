#ifndef INTERFAZ
#define INTERFAZ
#include "algoritmos_grafo.h"


class Interfaz{
    private:
        
        Grafo_MA grafo;
        int* vectorDePesos;
        vertice* vectorDeVerticesAdyacentes;
        int** matrizDePesos;
        vertice** matrizDeVerticesIntermedios;

    public:

        Interfaz();
        ~Interfaz();
        void desplegarMenu();
};

#endif
