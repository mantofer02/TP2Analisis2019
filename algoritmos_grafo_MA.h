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
	int numElem();  
	void destruir(); 
	string printD(); 
	
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
	bool is_there_cycles(Grafo_MA&grafo); 	//se implementa haciendo profundidad primero. //PENDIENTE
	void is_there_cyclesR(Grafo_MA&grafo, int vertice, Diccionario&D, std::list<int>&L, bool&is_there); 
	void CH(Grafo_MA&grafo); 				//circuito hamilton de menor costo. //PENDIENTE
	void colorear_grafo(Grafo_MA&grafo);	//usando la menor cantidad de colores posibles.  //PENDIENTE
	void componentesConexos(Grafo_MA&grafo); 				//averiguar cuantos componentes conexos tiene un grafo. //PENDIENTE 
	void encontrarPuntosArticulacion(Grafo_MA&grafo);		//PENDIENTE
	bool existeCaminoEntreTodoParDeVertices(Grafo_MA&grafo);	// 	PENDIENTE
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
	string printCC(); 
}; 
