#include "grafo_MA.h"
#include "apo.h"
#include "r11.h"
#include "diccionario.h"
#include "cc.h"
#include <queue>
#include <list>

#define INFINITY 999999999
#define TAMANYO 30		//misma cantidad de vertices del grafo. 

class Algoritmos_grafo_MA {
	
	private: 
	
	public: 
	Algoritmos_grafo_MA(); 
	void Dijkstra(Grafo_MA&grafo, vertice ver, int*VP, vertice*VVA); 
	void Floyd(Grafo_MA&grafo, int** MP, vertice** MVI); 
	void Prim(Grafo_MA&grafo, vertice ver);
	void Kruskal(Grafo_MA&grafo); 
	void profundidadPrimero(Grafo_MA&grafo); 
	void profundidadPrimeroR(Grafo_MA&grafo, vertice ver, Diccionario<vertice>&D); 
	void anchoPrimero(Grafo_MA&grafo);  
	void aislarVertice(Grafo_MA&grafo, vertice ver); 
	bool is_there_cycles(Grafo_MA&grafo); 
	void is_there_cyclesR(Grafo_MA&grafo, vertice ver, vertice vertice_anterior, Diccionario<vertice>&D, std::list<vertice>&L, bool&is_there); 
	void CH(Grafo_MA&grafo, Diccionario<vertice>&D, vertice* Sol, vertice* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones, int indice); 
	void encontrarPuntosArticulacion(Grafo_MA&grafo, vertice*puntos);
	void puntosArticulacion(Grafo_MA&grafo, Diccionario<vertice>&D, int*mas_bajo, int*orden, R11<vertice>&r11, vertice*puntos, vertice v, int indice); 
	void colorear_grafo(Grafo_MA&grafo, CC<vertice>&mejor_sol, int&colores, int&menor_cantidad, int&contador_soluciones);
	void colorear(Grafo_MA&grafo, CC<vertice>&mejor_sol, CC<vertice>&ccc, CC<vertice>&cca, vertice v, int&colores, int&menor_cantidad, int&contador_soluciones); 
	bool existeCaminoEntreTodoParDeVertices(Grafo_MA&grafo);
}; 


