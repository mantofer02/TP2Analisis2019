#ifndef INTERFAZ
#define INTERFAZ
#include "algoritmos_grafo.h"


class Interfaz{
    private:
        
        Grafo grafo; 
        Algoritmos_grafo algoritmos;

    public:

        Interfaz();
        ~Interfaz();
        void desplegarMenu();
};

#endif
