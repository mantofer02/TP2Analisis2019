#include "grafo_LA.h"

Grafo :: Grafo(){

}

Grafo :: vertice :: vertice(ETIQUETA etiqueta){
    this->etiqueta = etiqueta;
}

Grafo :: vertice :: vertice(){

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
}

int Grafo :: peso(vertice v1, vertice v2){
    int indiceV1 = 0;
    int indiceV2 = 0;
    int peso = -1;
    while(l1[indiceV1].etiqueta != v1.etiqueta && indiceV1 < l1.size()){
        indiceV1++;
    }
    
    while(l1[indiceV2].etiqueta != v2.etiqueta && indiceV2 < l1.size()){
        indiceV2++;
    }

    if(indiceV1 < l1.size && indiceV2 < l1.size){
        int fila = indiceV1;
        int columna = 0;
        while(l2[fila][columna].first != indiceV2 && columna < l1.size){
            columna++;
        }
        if(columna < l1.size)
            peso = l2[fila][columna].second;
    }
    return peso;
    // devuelve -1 si no existe la arista
}

int Grafo :: existeArista(vertice v1, vertice v2){
    int existe = 0;
    int indiceV1 = 0;
    int indiceV2 = 0;
    while(l1[indiceV1].etiqueta != v1.etiqueta && indiceV1 < l1.size()){
        indiceV1++;
    }
    
    while(l1[indiceV2].etiqueta != v2.etiqueta && indiceV2 < l1.size()){
        indiceV2++;
    }

    if(indiceV1 < l1.size && indiceV2 < l1.size){
        int fila = indiceV1;
        int columna = 0;
        while(l2[fila][columna].first != indiceV2 && columna < l1.size){
            columna++;
        }
        if(l2[fila][columna].first == indiceV2 && columna < l1.size)
            existe = 1;
    }
    return existe;
}


//Hacerlo por referencia
void Grafo :: modificarEtiqueta(vertice v1, ETIQUETA laEtiqueta){
    int indiceV1 = 0;
    while(l1[indiceV1].etiqueta != v1.etiqueta && indiceV1 < l1.size()){
        indiceV1++;
    }
    if(contador < l1.size){
        l1[contador].etiqueta = laEtiqueta;
    }
    // devuelve -1 si no existe la arista
}

void Grafo :: modificarPeso(vertice v1, vertice v2, int peso){
    int contador1 = 0;
    int contador2 = 0;
    while(l1[contador1].etiqueta != v1.etiqueta && contador1 < l1.size()){
        contador1++;
    }
    while(l1[contador2].etiqueta != v1.etiqueta && contador2 < l1.size()){
        contador2++;
    }
    if(contador1 < l1.size && contador2 < l1.size){
        int fila1 = contador1;
        int fila2 = contador2;
        int columna1 = 0;
        int columna2 = 0;
        while(l2[fila1][columna1].first->etiqueta != v1.etiqueta){
            columna1++;
        }
        while(l2[fila2][columna2].first->etiqueta != v2.etiqueta){
            columna2++;
        }
        l2[fila1][columna1].second = peso;
        l2[fila2][columna2].second = peso; 
    } 
}

void Grafo :: agregarArista(vertice v1, vertice v2, int peso){
    int contador1 = 0;
    int contador2 = 0;
    while(l1[contador1].etiqueta != v1.etiqueta && contador1 < l1.size()){
        contador1++;
    }
    while(l1[contador2].etiqueta != v1.etiqueta && contador2 < l1.size()){
        contador2++;
    }       
}