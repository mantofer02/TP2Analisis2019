#include "grafo_LA.h"

Grafo :: Grafo(){
    cantidadDeVertices = 0;
    cantidadDeAristas = 0;
}

Grafo :: vertice :: vertice(ETIQUETA etiqueta){
    this->etiqueta = etiqueta;
    this->indice = 0;
}

Grafo :: vertice :: vertice(ETIQUETA etiqueta, int indice){
    this->etiqueta = etiqueta;
    this->indice = indice;
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
    cantidadDeAristas = 0;

}

int Grafo :: peso(vertice v1, vertice v2){
    int peso = -1;
    int indice1 = v1.indice;
    int indice2 = v2.indice;
    if(indice1 < cantidadDeVertices && indice2 < cantidadDeVertices){
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
    if(indice1 < cantidadDeVertices){
        int fila1 = indice1;
        int columna1 = 0;
        while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
            columna1++;
        }
        if(l2[fila1][columna1].first == v2.indice){
            existe = 1;
        }
    }
    return existe;
}

void Grafo :: modificarEtiqueta(vertice v1, ETIQUETA laEtiqueta){
    if(v1.indice < cantidadDeVertices){
        l1[v1.indice].etiqueta = laEtiqueta;
    }
}

void Grafo :: modificarPeso(vertice v1, vertice v2, int pesoAAgregar){
    int indice1 = v1.indice;
    int indice2 = v2.indice;
    if(indice1 < cantidadDeVertices && indice2 < cantidadDeVertices){
        int fila1 = indice1;
        int fila2 = indice2;
        int columna1, columna2 = 0;
        while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
            columna1++;
        }
        while(columna2 < l2[fila2].size() && l2[fila2][columna2].first != v1.indice){
            columna1++;
        }

        if(columna1 < l2[fila1].size() && columna2 < l2[fila2].size()){
            l2[fila1][columna1].second = pesoAAgregar;
            l2[fila2][columna2].second = pesoAAgregar;
            // Revisar ese menor, podria ser menor o igual
        }
    }
}

void Grafo :: agregarArista(vertice v1, vertice v2, int pesoAAgregar){
    if(!existeArista(v1,v2)){
        int fila1 = v1.indice;
        int fila2 = v2.indice;
        std :: pair <int, int> par1, par2;
        par1 = std :: make_pair(v2.indice, pesoAAgregar);
        par2 = std :: make_pair(v1.indice, pesoAAgregar);
        l2[fila1].push_back(par1);
        l2[fila2].push_back(par2);
        cantidadDeAristas++;
    }
}

void Grafo :: agregarVertice(ETIQUETA laEtiqueta){
    vertice nuevo(laEtiqueta, cantidadDeVertices);
    l1.push_back(nuevo);
    cantidadDeVertices++;
}

void Grafo :: eliminarArista(vertice v1, vertice v2){
    if(existeArista(v1,v2)){
        int fila1 = v1.indice;
        int fila2 = v2.indice;
        int columna1, columna2 = 0;
        while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
            columna1++;
        }
        while(columna2 < l2[fila2].size() && l2[fila2][columna2].first != v1.indice){
            columna2++;
        }
        if(columna1 < l2[fila1].size() && columna2 < l2[fila2].size()){
            l2[fila1].erase(l2[fila1].begin() + columna1);
            l2[fila2].erase(l2[fila2].begin() + columna2);
            // Revisar ese menor, podria ser menor o igual
        }
    }
}