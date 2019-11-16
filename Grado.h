#ifndef GRAFITO
#define GRAFITO

#include <utility>
#include <string>
#include <vector>

using namespace std;

#define ETIQUETA string
#define VALOR int

/* Implementado Por Lista de Adyacencia */
/* NO PUEDEN HABER 2 VERTICES CON ETIQUETAS IGUALES, SI NO SE CAE TODO*/

class Grafo{

    private:
        struct Vertice{
            Vertice(ETIQUETA);
            ETIQUETA etiqueta;
        };
        pair <Vertice*, int> celdaL2;
    public:
        Grafo();
        void iniciar();
        void destruir();
        void vaciar();
        int vacia();
        int peso(Vertice &V1, Vertice &V2); 
        int existeArista(Vertice &V1, Vertice &V2);
        void modificarEtiqueta(Vertice &V1, ETIQUETA);
        void modificarPeso(Vertice &V1, Vertice &V2, int);
        void agregarArista(Vertice &V1, Vertice &V2, int);
        void agregarVertice(ETIQUETA);
        void eliminarArista(Vertice &V1, Vertice &V2);
        void eliminarVertice(Vertice &V1); //Se supone que es aislado
        void numVerticesAdyacentes(Vertice &V1);
        int numVertices();
        int numAristas();
        Vertice primerVertice();
        Vertice steVertice(Vertice &V);
        Vertice primerVtcAdyacente(Vertice &V1);
        Vertice steVtcAdyacente(Vertice &V1);
};
#endif
