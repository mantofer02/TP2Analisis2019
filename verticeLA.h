#include <iostream>

typedef std :: string ETIQUETA;
// typedef std :: string ETIQUETA;


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
        this->etiqueta = " " ;
        this->indice = -1;  
    }

    void imprimir(){
        std :: cout << " Etiqueta :  " << this->etiqueta << std :: endl;
        std :: cout << " Indice :  " << this->indice << std :: endl;
    }

    int operator==(vertice v1){
        return this->etiqueta==v1.etiqueta;
    }

    void operator=(vertice v1){
        this->etiqueta = v1.etiqueta;
        this->indice = v1.indice;
    }

    friend std :: ostream& operator<<( std :: ostream &output, const vertice &v1) { 
         output << " Etiqueta :  " << v1.etiqueta;
         return output;            
    }

    int operator!=(vertice v1){
        int sonDiferentes = 0;
        if(this->etiqueta != v1.etiqueta){
            sonDiferentes = 1;
        }
        return sonDiferentes;
    }
    
};