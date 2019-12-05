#include "algoritmos_grafo.h"
#include <array>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

class Tester {
	private: 
	Algoritmos_grafo misAlgoritmos; 
	
	public:
	Tester(); 
	void iniciarTest(int test_id);
	
		
	void testDijkstra(Grafo&grafo); 
	void testFloyd(Grafo&grafo);
	void testPrim(Grafo&grafo); 
	void testKruskal(Grafo&grafo); 
	void testProfundidadPrimero(Grafo&grafo); 
	void testAnchoPrimero(Grafo&grafo); 
	void testAislarVertice(Grafo&grafo); 
	void testCiclos(Grafo&grafo); 
	void testCircuitoHamilton(Grafo&grafo); 
	void testPuntosArticulacion(Grafo&grafo); 
	void testColorearGrafo(Grafo&grafo); 
	void testExisteCaminoEntreTodoParDeVertices(Grafo&grafo);  	
}; 

