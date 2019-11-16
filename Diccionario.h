#ifndef miDicc
#define miDicc

#define VERTICE int

#include <iostream>
#include <vector>

using namespace std; 


class Diccionario{
    private:
      // vector<Vertices> dic;
        vector<VERTICE> dic;
    public:
        Diccionario();
        void iniciar();
        int pertenece(VERTICE);
        void agregar(VERTICE);
        void borrar(VERTICE);
        /* void borrar(vertice); */

};

#endif