#ifndef INTERFAZ
#define INTERFAZ
#include "algoritmos_grafo.h"


class Interfaz{
    private:
        
        Grafo_MA grafo;
        Algoritmos_grafo_MA algoritmos;

    public:

        Interfaz();
        ~Interfaz();
        void desplegarMenu();
};

#endif
