#include <sstream>
#include "grafo_MA.h"


#define INFINITY 999999999
#define TAMANYO 10		//misma cantidad de vertices del grafo. 


class Algoritmos_grafo_MA {
	
	private: 
	
	public: 
	Algoritmos_grafo_MA(); 
	void Dijkstra(Grafo_MA&grafo, int vertice, int*VP, int*VVA); 
	void Floyd(Grafo_MA&grafo, int** MP, int** MVI); 
	void Prim(Grafo_MA&grafo, int vertice);
	void Kruskal(Grafo_MA&grafo);  
	
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
