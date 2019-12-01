#ifndef GRAFITO
#define GRAFITO

#include <utility>
#include <string>
#include <vector>
#include <iostream>


// using namespace std;

typedef std :: string ETIQUETA;
 
/* Implementado Por Lista de Adyacencia */
/* NO PUEDEN HABER 2 VERTICES CON ETIQUETAS IGUALES, SI NO SE CAE TODO*/
// OJO, AGREGAR LOS GRAFOS POR REFERENCIA, PARA QUE SI MODIFICO LA ETIQUETA DE LA PRIMERA LISTA, SE MODIFIQUE EL DE LA SEGUNDA
class Grafo{
    private:
        struct vertice{
            vertice(ETIQUETA);
            vertice(ETIQUETA, int);
            vertice();
            void imprimirVertice();
            ETIQUETA etiqueta;
            int indice;
        };
        int cantidadDeVertices;
        int cantidadDeAristas;
        // std :: vector <vertice> l1;
        // std :: vector <std :: vector<std :: pair<int, int>>> l2;
        vertice verticeNulo;
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
        int peso( vertice, vertice);
        int existeArista( vertice, vertice);
        void modificarEtiqueta(vertice, ETIQUETA);
        void modificarPeso(vertice, vertice, int);
        void agregarArista(vertice, vertice, int);
        void agregarVertice(ETIQUETA);
        void eliminarArista(vertice, vertice);
        void eliminarVertice(vertice); //Se supone que es aislado
        int numVerticesAdyacentes(vertice);
        int numVertices();
        int numAristas();
        vertice primerVertice();
        vertice steVertice(vertice);
        vertice primerVtcAdyacente(vertice);
        vertice steVtcAdyacente(vertice, vertice);
        void imprimirGrafo();
        vertice getVertice(ETIQUETA);
        // void aislarVertice(vertice)
};
#endif
