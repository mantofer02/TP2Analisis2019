#include "algoritmos_grafo.h"
#include <array>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

#define MUESTRA 1
#define MAX_VER 1000
#define MAX_ARISTAS 500


class Tester {
	private: 
	Algoritmos_grafo misAlgoritmos; 
	
	public:
	Tester(); 
	void iniciarTest(int test_id);
	
		
	double testDijkstra(Grafo&grafo); 
	double testFloyd(Grafo&grafo);
	double testPrim(Grafo&grafo); 
	double testKruskal(Grafo&grafo); 
	double testProfundidadPrimero(Grafo&grafo); 
	double testAnchoPrimero(Grafo&grafo); 
	double testAislarVertice(Grafo&grafo); 
	double testCiclos(Grafo&grafo); 
	double testCircuitoHamilton(Grafo&grafo); 
	double testPuntosArticulacion(Grafo&grafo); 
	double testColorearGrafo(Grafo&grafo); 
	double testExisteCaminoEntreTodoParDeVertices(Grafo&grafo);  	
}; 

