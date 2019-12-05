#include "tester.h"

Tester::Tester() {
	
	
}


#define grafo1 MIGRAFO

void Tester::iniciarTest(int test_id) {
	
	Grafo grafo1; 
	grafo1.iniciar(); 
	
	
	grafo1.agregarVertice(2); 
	grafo1.agregarVertice(3); 
	grafo1.agregarVertice(1); 
	grafo1.agregarVertice(4); 	
	grafo1.agregarVertice(6); 
	grafo1.agregarVertice(5); 

	grafo1.agregarArista(grafo.getVertice(2),grafo.getVertice(3),500);	
	grafo1.agregarArista(grafo.getVertice(1),grafo.getVertice(2),8);
	grafo1.agregarArista(grafo.getVertice(1),grafo.getVertice(6),1000);
	grafo1.agregarArista(grafo.getVertice(2),grafo.getVertice(4),7);
	grafo1.agregarArista(grafo.getVertice(6),grafo.getVertice(3),40);
	grafo1.agregarArista(grafo.getVertice(4),grafo.getVertice(6),20);
	grafo1.agregarArista(grafo.getVertice(4),grafo.getVertice(5),35);
	grafo1.agregarArista(grafo.getVertice(5),grafo.getVertice(6),5);        
	grafo1.agregarArista(grafo.getVertice(3),grafo.getVertice(1),90);
	grafo1.agregarArista(grafo.getVertice(3),grafo.getVertice(5),8);  
	
	#if 0 
	Grafo grafo2; 
	grafo2.iniciar(); 
	#endif 

	#if 0 
	Grafo grafo3; 
	grafo3.iniciar(); 
	#endif 
		
	#if 0 
	Grafo grafo4; 
	grafo4.iniciar(); 
	#endif 
	
	#if 0 
	Grafo grafo5; 
	grafo5.iniciar(); 
	#endif 

	
	switch(test_id) {
		case 0:
		
		break; 
		
		
		case 1:
			testDijkstra(MIGRAFO); 
			
		break; 
		
		case 2:
			testFloyd(MIGRAFO); 
		break; 
		
		case 3:
			testPrim(MIGRAFO); 
		break; 
		
		case 4:
			testKruskal(MIGRAFO); 
		break; 
		
		
		case 5:
			testProfundidadPrimero(MIGRAFO); 
		break; 
		
		
		case 6: 
			testAnchoPrimero(MIGRAFO); 
		break; 
		
		
		case 7: 
			testAislarVertice(MIGRAFO); 
		break; 
		
		case 8: 
			testCiclos(MIGRAFO); 
		break; 
		
		case 9: 
			testCircuitoHamilton(MIGRAFO); 
		break; 
		
		case 10:
			testPuntosArticulacion(MIGRAFO); 
		break; 
		
		case 11:
			testColorearGrafo(MIGRAFO); 
		break; 
		
		
		case 12: 
			testExisteCaminoEntreTodoParDeVertices(MIGRAFO); 
		break; 
	}
	
}


void Tester::testDijkstra(Grafo&grafo) {

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 	
    int* VP = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
	vertice* VVA = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 
	//--------------------------------------------------------------------------------------------	
	
	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Dijkstra(grafo, grafo.primerVertice(), VP, VVA); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;
	
	
	#if 0 			//si se desea ver los resultados, como es un test, creo que da igual ver los resultados. 
	
	std::cout << "Vector de Peso despues de ejecutar Dijikstra : " << std::endl; 
	for (int index = 0; index < grafo.numVertices()-1; ++index) {
		std::cout << VP[index] << ", "; 
	}

	std::cout << std::endl; 

	std::cout << "Vector de vertice anterior despues de ejecutar Dijstra:  : " << std::endl; 
	for (int index = 0; index < grafo.numVertices()-1;  ++index) {
		std::cout << VVA[index] << ", "; 
	}

	std::cout << std::endl;
	#endif 
	
	//DESTRUCCIÓN ESTRUCTURA DE DATOS DONDE GUARDA LOS RESULTADOS. 
	free(VP); 
	free(VVA); 
	//--------------------------------------------------------------------------------------------
}

void Tester::testFloyd(Grafo&grafo){
	
	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	int** MP = (int**)malloc(grafo.numVertices()*sizeof(int*)); 	//matriz de peso
	vertice** MVI = (vertice**)malloc(grafo.numVertices()*sizeof(vertice*)); 	//matriz de vertice intermedio. 

	
	for (int row = 0; row < grafo.numVertices(); ++row) {
		MP[row] = (int*)malloc(grafo.numVertices()*sizeof(int)); 
		MVI[row] = (vertice*)malloc(grafo.numVertices()*sizeof(vertice)); 	
	} 
	//--------------------------------------------------------------------------------------------
	

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
	
	
	#if 0 							//PARA IMPRIMIR LOS RESULTADOS. 
	stringstream ss; 
	for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
		for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
			ss << MP[index_x][index_y] << ", "; 
		}
		ss << "\n"; 
	}

	std::cout << "IMPRIMIENDO MP" << std::endl; 
	std::cout << ss.str() << std::endl; 

	ss.str(""); 

	for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
		for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
			ss << MVI[index_x][index_y] << ", "; 
		}
		ss << "\n"; 
	}

	std::cout << "imprimiendo MVI" << std::endl; 
	std::cout << ss.str() << std::endl; 
	#endif 
	
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
	
	
}

void Tester::testPrim(Grafo&grafo) {

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
	
	

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
	


	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
	
}

void Tester::testKruskal(Grafo&grafo){
	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;		
	
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
			
	
} 

void Tester::testProfundidadPrimero(Grafo&grafo) {

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
			
}

void Tester::testAnchoPrimero(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;		

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
}

void Tester::testAislarVertice(Grafo&grafo){
	
	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;		

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
} 

void Tester::testCiclos(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;			

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
}

void Tester::testCircuitoHamilton(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;			

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
	
} 

void Tester::testPuntosArticulacion(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 

	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
	
} 

void Tester::testColorearGrafo(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
 	

	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
	
}

void Tester::testExisteCaminoEntreTodoParDeVertices(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 


	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Floyd(grafo, MP, MPI); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	
	
	//--------------------------------------------------------------------------------------------
		
	
} 
 
