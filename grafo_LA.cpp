#include "grafo_LA.h"



Grafo :: Grafo(){
    cantidadDeVertices = 0;
    cantidadDeAristas = 0;
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

vertice Grafo :: getVertice(ETIQUETA laEtiqueta){
    vertice verticeNulo;
    verticeNulo.indice = -1;



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

int Grafo :: numVerticesAdy(vertice v1){
    return l2[v1.indice].size();
}

int Grafo :: numVertices(){
    return cantidadDeVertices;
}

int Grafo :: numAristas(){
    return cantidadDeAristas;
}


//Hay que ver como se le hace con el vertice nulo, osea cuando la lista esta vacia
vertice Grafo :: primerVertice(){
    vertice verticeNulo;
    verticeNulo.indice = -1;

    if(cantidadDeVertices == 0){
        return verticeNulo;
    }else{
        return l1[0];
    }
}

vertice Grafo :: siguienteVertice(vertice v1){
    vertice verticeNulo;
    verticeNulo.indice = -1;
    
    
    if(v1.indice + 1 < cantidadDeVertices){
        // l1[v1.indice + 1].imprimir();
        return l1[v1.indice + 1];
    }else{
        return verticeNulo;
    }
} 

vertice Grafo :: primerVerticeAdy(vertice v1){       
    vertice verticeNulo;
    verticeNulo.indice = -1;
    
    if(l2[v1.indice].size()){
        return l1[l2[v1.indice][0].first];
        l1[l2[v1.indice][0].first].imprimir();
    }else{
        return verticeNulo;
        verticeNulo.imprimir();
    }
}

vertice Grafo :: siguienteVerticeAdy(vertice v1, vertice adyacente){
     vertice verticeNulo;
    verticeNulo.indice = -1;
    
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

void Grafo :: borrarVertice(vertice v1){
    int indiceDelBorrado = v1.indice;
    for(int i = indiceDelBorrado; i < l1.size() - 1; i++){
        l1[i].etiqueta = l1[i + 1].etiqueta;
    }
    l1.pop_back();
    l2.erase(l2.begin() + indiceDelBorrado);
    cantidadDeVertices--;
}

void Grafo :: imprimirGrafo(){
    if(!vacia()){    
        for(int i = 0; i < cantidadDeVertices; i++){
            std :: cout << " Etiqueta :  " << l1[i].etiqueta << " ||  ";
                    for(int j = 0; j < l2[i].size(); j++){
                        std :: cout << " < Etiqueta :  " << l1[l2[i][j].first].etiqueta << " | Peso : " << l2[i][j].second << " > ---> ";
                    }
            std :: cout << std :: endl;
        }
    }
}

int Grafo :: esVerticeNulo(vertice v1){
    return v1.indice == -1;
}

vertice Grafo :: getVerticeNulo(){       
    vertice verticeNulo;
    verticeNulo.indice = -1;
    return verticeNulo;
}

ETIQUETA Grafo :: etiqueta(vertice v1){
    return v1.etiqueta;
}