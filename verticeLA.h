#include <iostream>

typedef std :: string ETIQUETA;

struct vertice{
    ETIQUETA etiqueta;
    int indice;

    vertice(ETIQUETA etiqueta){
        this->etiqueta = etiqueta;
        indice = -1;
    }
    vertice(ETIQUETA etiqueta, int indice){
        this->etiqueta = etiqueta;
        this->indice = indice;
    }
    vertice(){
        this->etiqueta = " ";
        this->indice = -1;  
    }
    void imprimir(){
        std :: cout << " Etiqueta :  " << this->etiqueta;
    }
};