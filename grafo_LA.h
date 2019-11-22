#ifndef GRAFITO
#define GRAFITO

#include <utility>
#include <string>
#include <vector>

using namespace std;

typedef string ETIQUETA;
typedef int valor;

/* Implementado Por Lista de Adyacencia */
/* NO PUEDEN HABER 2 VERTICES CON ETIQUETAS IGUALES, SI NO SE CAE TODO*/
// OJO, AGREGAR LOS GRAFOS POR REFERENCIA, PARA QUE SI MODIFICO LA ETIQUETA DE LA PRIMERA LISTA, SE MODIFIQUE EL DE LA SEGUNDA
class Grafo{
    private:
        struct vertice{
            vertice(ETIQUETA);
            vertice()=default;
            ETIQUETA etiqueta;
        };
                
        vector <vertice> l1;
        vector <vector<pair<int, int>>> l2;
        /*
        ------------PARA EL PAIR-------
        first = indice del vertice en L1
        second = peso de la arista
        -------------------------------x
        */
       

       /*
       
       A  | <1 , PESO> <2, PESO>

       B  | C

       C  | A
       
       
       
       */

       /*
        El indice es determinado en l
       
       */
    
    public:
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
        void numVerticesAdyacentes(vertice);
        int numVertices();
        int numAristas();
        vertice primerVertice();
        vertice steVertice(vertice);
        vertice primerVtcAdyacente(vertice);
        vertice steVtcAdyacente(vertice);
};
#endif
