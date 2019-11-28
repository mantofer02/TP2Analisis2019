#include "grafo_MA.h"
#include "apo.h"
#include <queue>
#include <list>

#define INFINITY 999999999
#define TAMANYO 30		//misma cantidad de vertices del grafo. 

class Diccionario {
	private: 
	int* vector; 
	int ultimoLleno; 
	
	public: 
	Diccionario(); 
	void iniciar(); 
	void agregar(int vertice);
	bool pertenece(int vertice); 
	void pop(); 
	int numElem();  
	void destruir(); 
	string printD(); 
	
}; 


class R11 {
	private: 
	int** matrix; 
	int ultimoLleno; 
	
	public:
	R11();
	void agregar(int vertice, int indice); 
	void iniciar();
	int indice(int vertice); 
	int vertice(int indice);  
	void destruir(); 
	string printR11(); 	
}; 

class CC {

	private: 
	int** cc; 
	int amount_c; 
	
	public: 
	CC(); 
	void iniciar(int max_amount_elements); 
	void agregarConjunto(int conjunto);
	void agregarAConjunto(int vertice, int conjunto);  
	int conjuntoAlQuePertenece(int vertice);//retorna conjunto. . 
	void unir(int conjunto_1, int conjunto_2);
	bool existeInterseccion(int conjunto, CC&cc_1, int conjunto_cc1);   
	void sacarDeConjunto(int conjunto, int vertice); 
	int obtConjunto(int index); 
	string printCC(); 
}; 

class Algoritmos_grafo_MA {
	
	private: 
	
	public: 
	Algoritmos_grafo_MA(); 
	void Dijkstra(Grafo_MA&grafo, int vertice, int*VP, int*VVA); 
	void Floyd(Grafo_MA&grafo, int** MP, int** MVI); 
	void Prim(Grafo_MA&grafo, int vertice);
	void Kruskal(Grafo_MA&grafo); 
	void profundidadPrimero(Grafo_MA&grafo); 
	void profundidadPrimeroR(Grafo_MA&grafo, int vertice, Diccionario&D); 
	void anchoPrimero(Grafo_MA&grafo);  
	void aislarVertice(Grafo_MA&grafo, int vertice); 
	bool is_there_cycles(Grafo_MA&grafo); 
	void is_there_cyclesR(Grafo_MA&grafo, int vertice, int vertice_anterior, Diccionario&D, std::list<int>&L, bool&is_there); 
	void CH(Grafo_MA&grafo, Diccionario&D, int* Sol, int* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones, int indice); 
	void encontrarPuntosArticulacion(Grafo_MA&grafo, int*puntos);
	void puntosArticulacion(Grafo_MA&grafo, Diccionario&D, int*mas_bajo, int*orden, R11&r11, int*puntos, int v, int indice); 
	void colorear_grafo(Grafo_MA&grafo, CC&mejor_sol, int&colores, int&menor_cantidad, int&contador_soluciones);	//usando la menor cantidad de colores posibles.  //PENDIENTE
	void colorear(Grafo_MA&grafo, CC&mejor_sol, CC&ccc, CC&cca, int v, int&colores, int&menor_cantidad, int&contador_soluciones); 
	bool existeCaminoEntreTodoParDeVertices(Grafo_MA&grafo);	// 	PENDIENTE
}; 



