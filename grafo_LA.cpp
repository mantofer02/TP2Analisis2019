#include "grafo_LA.h"

Grafo :: Grafo(){
    cantidadDeVertices = 0;
}

Grafo :: vertice :: vertice(ETIQUETA etiqueta){
    this->etiqueta = etiqueta;
    this->indice = 0;
}

Grafo :: vertice :: vertice(){
    this->etiqueta = "/0";
    this->indice = 0;
}

void Grafo :: iniciar(){

}

int Grafo :: vacia(){
    return l1.empty();
}

void Grafo :: destruir(){
    // ver como hacerle
}

void Grafo :: vaciar(){
    l1.empty();
    l2.empty();
    cantidadDeVertices = 0;

}

int Grafo :: peso(vertice v1, vertice v2){
    int peso = -1;
    int indice1 = v1.indice;
    int indice2 = v2.indice;
    if(indice1 && indice2){
        int fila1 = indice1;
        int columna1 = 0;
        while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
            columna1++;
        }
        if(l2[fila1][columna1].first == v2.indice){
            peso = l2[fila1][columna1].second;
        }
    }
    return peso;
}

int Grafo :: existeArista( vertice v1, vertice v2){
    int existe = 0;
    int indice1 = v1.indice;
    if(indice1){
        int fila1 = indice1;
        int columna1;
        while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
            columna1++;
        }
        if(l2[fila1][columna1].first == v2.indice){
            existe = 1;
        }
    }
    return existe;
}