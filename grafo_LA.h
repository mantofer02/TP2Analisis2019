#ifndef GRAFITO
#define GRAFITO

#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include "verticeLA.h"

// using namespace std;

 
/* Implementado Por Lista de Adyacencia */
/* NO PUEDEN HABER 2 VERTICES CON ETIQUETAS IGUALES, SI NO SE CAE TODO*/
// OJO, AGREGAR LOS GRAFOS POR REFERENCIA, PARA QUE SI MODIFICO LA ETIQUETA DE LA PRIMERA LISTA, SE MODIFIQUE EL DE LA SEGUNDA
class Grafo{
    private:
        int cantidadDeVertices;
        int cantidadDeAristas;
  
  
        /*
        ------------PARA EL PAIR-------
        first = indice del vertice en L1
        second = peso de la arista
        -------------------------------x
        */
       
       /*
        El indice es determinado en l     
       */
    
    public:
        std :: vector <vertice> l1;
        std :: vector <std :: vector<std :: pair<int, int>>> l2;
        Grafo();
        void iniciar();
        void destruir();
        void vaciar();
        int vacia();
        int peso(vertice, vertice);
        int existeArista( vertice, vertice);
        void modificarEtiqueta(vertice, ETIQUETA);
        void modificarPeso(vertice, vertice, int);
        void agregarArista(vertice, vertice, int);
        void agregarVertice(ETIQUETA);
        void eliminarArista(vertice, vertice);
        void eliminarVertice(vertice); //Se supone que es aislado
        int numVerticesAdy(vertice);
        int numVertices();
        int numAristas();
        vertice primerVertice();
        vertice siguienteVertice(vertice);
        vertice primerVerticeAdy(vertice);
        void borrarVertice(vertice);
        vertice siguienteVerticeAdy(vertice, vertice);
        void imprimirGrafo();
        vertice getVertice(ETIQUETA);
        int esVerticeNulo(vertice); 
        vertice getVerticeNulo();   
        ETIQUETA etiqueta(vertice); 
        // void aislarVertice(vertice)
};
#endif
