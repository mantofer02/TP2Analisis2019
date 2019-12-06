#include "grafo_LA.h"



Grafo :: Grafo(){
    cantidadDeVertices = 0;
    cantidadDeAristas = 0;
}



/*
Requiere : Un grafo no inicializado. 
Efecto : Inicializa el grafo.
Modifica : El grafo, ya que lo inicializa..
*/
void Grafo :: iniciar(){
    cantidadDeVertices = 0;
    cantidadDeAristas = 0;
}

/*
Requiere : Un grafo ya inicializado ; un vertice de parametro y que este aislado. 
Efecto : Elimina el vertice del grafo.
Modifica : El grafo, eliminadno el vertice.
*/
void Grafo::eliminarVertice(vertice v) {
	int indiceABorrar = v.indice;
    for(int i = indiceABorrar; i < l1.size() - 1; i++){
        l1[i].etiqueta = l1[i+1].etiqueta;
    }
    l1.erase(l1.end());
    l2.erase(l2.begin() + indiceABorrar);
}


/*
Requiere : Un grafo ya inicializado. 
Efecto : Pregunta si el grafo esta vacio o no.
Modifica : El booleano que indica si el grafo esta vacio o no.
*/
int Grafo :: vacia(){
    return l1.empty();
}



/*
Requiere : Un grafo ya inicializado. 
Efecto : Destruye el grafo fisicamente.
Modifica : El grafo, liberando la memoria.
*/
void Grafo :: destruir(){
    cantidadDeVertices = 0;
}



/*
Requiere : Un grafo ya inicializado. 
Efecto : Vacia el grafo.
Modifica : El indicador de ultimo lleno, apuntandolo a nulo.
*/
void Grafo :: vaciar(){
    l1.empty();
    l2.empty();
    cantidadDeVertices = 0;
    cantidadDeAristas = 0;

}



/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Retorna el peso de una arista.
Modifica : N/A.
*/
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



/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Retorna si existe una arista entre los 2 vertices de parametro.
Modifica : N/A.
*/
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

/*
Requiere : Un grafo ya inicializado ; un vertice de parametro ; una nueva etiqueta. 
Efecto : Cambia la etiqueta de un vertice.
Modifica : La etiqueta del vertice enviado por parametro.
*/
void Grafo :: modificarEtiqueta(vertice v1, ETIQUETA laEtiqueta){
    if(v1.indice < cantidadDeVertices){
        l1[v1.indice].etiqueta = laEtiqueta;
    }
}



/*
Requiere : Un grafo ya inicializado ; un vertice de parametro de punto de salida; un vertice de parametro de punto de llegada. 
Efecto : Cambia el peso de una arista.
Modifica : Modifica el peso de la arista presente, si existe.
*/
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


/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Agraga una arista al grafo.
Modifica : El grafo, agregando una arista.
*/
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


/*
Requiere : Un grafo ya inicializado ; una etiqueta. 
Efecto : Agrega un vertice al grafo.
Modifica : El grafo, agregando un vertice nuevo.
*/
void Grafo :: agregarVertice(ETIQUETA laEtiqueta){
    vertice nuevo(laEtiqueta, cantidadDeVertices);
    l1.push_back(nuevo);
    cantidadDeVertices++;
    std :: vector <std :: pair<int, int>> listaNueva;
    l2.push_back(listaNueva);
    // std :: cout << "Se agrego" << std :: endl;
}


/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Elimina la arista del grafo.
Modifica : El grafo, eliminando su arista.
*/
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



/*
Requiere : Un grafo ya inicializado ; Un vertice especifico.	
Efecto : Devuelve un numero equivalente al numero de vertices adyacentes del vertice enviado por parametro.
Modifica : N/A
*/
int Grafo :: numVerticesAdy(vertice v1){
    return l2[v1.indice].size();
}


/*
Requiere : Un vertice ya inicializado.
Efecto : Devuelve la cantidad de vertices presentes en el grafo.
Modifica : N/A
*/
int Grafo :: numVertices(){
    return cantidadDeVertices;
}


/*
Requiere : Un vertice ya inicializado. 
Efecto : Devuelve la cantidad de aristas que estan presentes en el grafo.
Modifica : N/A
*/
int Grafo :: numAristas(){
    return cantidadDeAristas;
}

/*
Requiere : Un grafo inicializado.
Efecto : Devuelve el primer vertice del grafo (Valor Arbitrario)
Modifica : N/A
*/
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


/*
Requiere : Un grafo inicializado ; Un vertice de parametro
Efecto : Devuelve el siguiente vertice del grafo. (Relacion Arbitraria) 
Modifica : N/A
*/
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



/*
Requiere : Un grafo inicializado ; Un vertice de parametro. 
Efecto : Devuelve el primer vertice adyacente del vertice enviado por parametro.
Modifica : N/A
*/
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


/*
Requiere : Un grafo inicializado ; Vertice Actual ; Vertice Adyacente Actual 
Efecto : Devuelve el siguiente vertice adyacente.
Modifica : N/A
*/
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
