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
    std::cout << "El tiempo de duración de Floyd corresponde a : " << elapsed_seconds << " s." <<endl;	
	
	
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
    
	misAlgoritmos.Prim(grafo, grafo.primerVertice()); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Prim corresponde a : " << elapsed_seconds << " s." <<endl;	
	


	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
		
	
}

void Tester::testKruskal(Grafo&grafo){
	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.Kruskal(grafo); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Kruskal corresponde a : " << elapsed_seconds << " s." <<endl;		
	
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
			
	
} 

void Tester::testProfundidadPrimero(Grafo&grafo) {

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.profundidadPrimero(grafo); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de profundidadPrimero corresponde a : " << elapsed_seconds << " s." <<endl;	

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
			
}

void Tester::testAnchoPrimero(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.anchoPrimero(grafo); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de AnchoPrimero corresponde a : " << elapsed_seconds << " s." <<endl;		

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
		
}

void Tester::testAislarVertice(Grafo&grafo){
	
	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.aislarVertice(grafo, grafo.primerVertice()); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración para aislar el vertice ingresado corresponde a : " << elapsed_seconds << " s." <<endl;		

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
		
} 

void Tester::testCiclos(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	if (misAlgoritmos.is_there_cycles(grafo)) {
		std::cout << "El grafo ingresado si posee ciclos" << std::endl; 
	}
	else {
		std::cout << "El grafo ingresado no posee ciclos" << std::endl; 
	}
	
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración para determinar la existencia de ciclos corresponde a : " << elapsed_seconds << " s." <<endl;			

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
		
}

void Tester::testCircuitoHamilton(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	Diccionario<vertice> D; 
	D.iniciar(); 
	vertice* Sol = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));				//solución temporal
	vertice* mejor_Sol = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));			//la mejor solución encontrada. 
	int costo = 0; 																			//costo temporal. 
	int mejor_costo = INFINITY; 															//el mejor costo encontrado, comienza en inf para la primera iteracion. 
	int contador_soluciones = 0; 															//cuantas soluciones factibles presenta el grafo. 
	Sol[0] = grafo.primerVertice(); 														//se comienza ingresando en Sol[0] el vertice de partida. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.CH(grafo, D, Sol, mejor_Sol, costo, mejor_costo, contador_soluciones, 1);	//el 1 es un indice, dejarlo asi.    
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Circuito de Hamilton con menor costo corresponde a : " << elapsed_seconds << " s." <<endl;			


	#if 0 				//si se desea ver el resultado del algoritmo. 
		
	std::cout << "se finalizo con exito" << std::endl; 
	std::cout << "soluciones factibles : " << contador_soluciones << std::endl; 
	stringstream ss; 
	for (int index_sol = 0; index_sol <= grafo.numVertices(); ++index_sol) {
		if (index_sol != grafo.numVertices()) {
			ss << mejor_Sol[index_sol] << ", "; 
		}
		else {
			ss << mejor_Sol[index_sol]; 
		}	
	}
	ss << "\n"; 
	std::cout << "la mejor solucion corresponde a : " << std::endl; 
	std::cout << ss.str() << std::endl;   	
	#endif 
	

	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	free(Sol);
	free(mejor_Sol);
	D.destruir(); 
	//--------------------------------------------------------------------------------------------
		
	
} 

void Tester::testPuntosArticulacion(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	vertice* puntos = (vertice*)calloc(grafo.numVertices(), sizeof(vertice)); 
	int contador_puntos = 0; 
	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);

	misAlgoritmos.encontrarPuntosArticulacion(grafo, puntos, contador_puntos); 

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración para encontrar Puntos de Articulacion en el grafo ingresado corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
    
    #if 0 				//si se desean ver los resultados. 
	std::cout << "imprimiendo los puntos de articulacion : " << std::endl; 
	stringstream ss; 
	for (int index = 0; index < contador_puntos; ++index) {
		if (index != contador_puntos-1) {
			ss << puntos[index] << ", "; 
		}
		else {
			ss << puntos[index]; 
		}
	}
	ss << "\n"; 
	std::cout << ss.str() << std::endl;
    #endif 		
    				
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	free(puntos)
	//--------------------------------------------------------------------------------------------
		
	
} 

void Tester::testColorearGrafo(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 		
	CC<vertice> mejor_sol; 
	mejor_sol.iniciar(grafo.numVertices());
	int menor_cantidad = INFINITY; 
	int colores = 0; 
	int contador_soluciones = 0; 
	//--------------------------------------------------------------------------------------------


	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.colorear_grafo(grafo, mejor_sol, colores, menor_cantidad, contador_soluciones); 	
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	mejor_sol.destruir(); 
	//--------------------------------------------------------------------------------------------
		
	
}

void Tester::testExisteCaminoEntreTodoParDeVertices(Grafo&grafo){

	//INICIALIZACION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------

	struct timespec start_time;
    struct timespec finish_time;
    double elapsed_seconds = 0.0; 
        
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
	misAlgoritmos.existeCaminoEntreTodoParDeVertices(grafo); 
    
    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    elapsed_seconds = finish_time.tv_sec - start_time.tv_sec	+ 1e-9 * (finish_time.tv_nsec - start_time.tv_nsec);
    std::cout << "El tiempo de duración de Dijstra corresponde a : " << elapsed_seconds << " s." <<endl;	
    		
	//DESTRUCCION ESTRUCTURAS DE DATOS DONDE GUARDA LOS RESULTADOS. 
	//NO APLICA. 
	//--------------------------------------------------------------------------------------------
		
	
} 
 
