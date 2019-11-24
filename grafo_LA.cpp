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
    this->etiqueta = " ";
    this->indice = -1;
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

Grafo :: vertice Grafo :: getVertice(ETIQUETA laEtiqueta){
    int counter = 0;
    while(counter < l1.size() && l1[counter].etiqueta != laEtiqueta){
        counter++;
    }
    if(counter < l1.size()){
        return l1[counter];
    }else{
        return verticeNulo;
    }
}

int Grafo :: existeArista( vertice v1, vertice v2){
    int existe = 0;
    int columna1 = 0;
    int fila1 = v1.indice;
    while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != v2.indice){
        columna1++;
    }
    if(columna1 < l2[fila1].size()){
        existe = 1;
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
    std :: vector <std :: pair<int, int>> listaNueva;
    l2.push_back(listaNueva);
    // std :: cout << "Se agrego" << std :: endl;
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

int Grafo :: numVerticesAdyacentes(vertice v1){
    return l2[v1.indice].size();
}

int Grafo :: numVertices(){
    return cantidadDeVertices;
}

int Grafo :: numAristas(){
    return cantidadDeAristas;
}


//Hay que ver como se le hace con el vertice nulo, osea cuando la lista esta vacia
Grafo :: vertice Grafo :: primerVertice(){
    if(cantidadDeVertices == 0){
        return verticeNulo;
    }else{
        return l1[0];
    }
}

Grafo :: vertice Grafo :: steVertice(vertice v1){
    if(v1.indice + 1 < cantidadDeVertices){
        return l1[v1.indice + 1];
    }else{
        return verticeNulo;
    }
} 

Grafo :: vertice Grafo :: primerVtcAdyacente(vertice v1){       
    if(l2[v1.indice].size()){
        return l1[l2[v1.indice][0].first];
        l1[l2[v1.indice][0].first].imprimir();
    }else{
        return verticeNulo;
        verticeNulo.imprimir();
    }
}

Grafo :: vertice Grafo :: steVtcAdyacente(vertice v1, vertice adyacente){
    int indice1 = v1.indice;
    int fila1 = indice1;
    int columna1= 0;
    while(columna1 < l2[fila1].size() && l2[fila1][columna1].first != adyacente.indice){
        columna1++;
    }
    if(columna1 + 1 < l2[fila1].size()){
        return l1[l2[fila1][columna1 + 1].first];        
    }else{
        return verticeNulo;
    }
}

void Grafo :: vertice :: imprimir(){
    std :: cout << " Etiqueta :  " << this->etiqueta;
}

void Grafo :: imprimirGrafo(){
    // std :: cout << "aqui" << std :: endl;
    if(!vacia()){
        // std :: cout << "TAMA;O" << l1.size();    
        for(int i = 0; i < cantidadDeVertices; i++){
            std :: cout << " Etiqueta :  " << l1[i].etiqueta << " ||  ";
            // if(!l2.empty()){
                // if(l2[i].empty()){
                    for(int j = 0; j < l2[i].size(); j++){
                        std :: cout << " < Etiqueta :  " << l1[l2[i][j].first].etiqueta << " | Peso : " << l2[i][j].second << " > ---> ";
                    }
                // }
            // }
            std :: cout << std :: endl;
        }
    }
}