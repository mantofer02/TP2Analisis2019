#include "grafo_MA.h"
#include "apo.h"
#include "r11.h"
#include "diccionario.h"
#include "cc.h"
#include <queue>
#include <list>

#define INFINITY 999999999
#define TAMANYO 30		//misma cantidad de vertices del grafo. 

class Algoritmos_grafo{
	private: 
	
	public: 
		Algoritmos_grafo(); 
		void Dijkstra(Grafo &grafo, vertice ver, int*VP, vertice*VVA); 
		void Floyd(Grafo &grafo, int** MP, vertice** MVI); 
		void Prim(Grafo &grafo, vertice ver);
		void Kruskal(Grafo &grafo); 
		void profundidadPrimero(Grafo &grafo); 
		void profundidadPrimeroR(Grafo &grafo, vertice ver, Diccionario<vertice>&D); 
		void anchoPrimero(Grafo &grafo);  
		void aislarVertice(Grafo &grafo, vertice ver); 
		bool is_there_cycles(Grafo &grafo); 
		void is_there_cyclesR(Grafo &grafo, vertice ver, vertice vertice_anterior, Diccionario<vertice>&D, std::list<vertice>&L, bool&is_there); 
		void CH(Grafo &grafo, Diccionario<vertice>&D, vertice* Sol, vertice* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones, int indice); 
		void encontrarPuntosArticulacion(Grafo &grafo, vertice*puntos, int&contador_puntos);
		void puntosArticulacion(Grafo &grafo, Diccionario<vertice>&D, int*mas_bajo, int*orden, R11<vertice>&r11, vertice*puntos, vertice v, int indice, int&contador_puntos); 
		void colorear_grafo(Grafo &grafo, CC<vertice>&mejor_sol, int&colores, int&menor_cantidad, int&contador_soluciones, bool&found);
		void colorear(Grafo &grafo, CC<vertice>&mejor_sol, CC<vertice>&ccc, CC<vertice>&cca, vertice v, int&colores, int&menor_cantidad, int&contador_soluciones, R11<vertice>&r11, bool&found); 
		bool existeCaminoEntreTodoParDeVertices(Grafo &grafo);
		void recorrer(Grafo&grafo, vertice ver, Diccionario<vertice>&D); 
}; 



