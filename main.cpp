#include "algoritmos_grafo.h"

#if 1					

int main (int argc, char* argv[]) {

Grafo grafo; 
grafo.iniciar(); 	
grafo.agregarVertice(2); //0	el parametro solo es la etiqueta, lo que importa es el numero comentado. 
grafo.agregarVertice(3); //1
grafo.agregarVertice(1); //2
grafo.agregarVertice(4); //3	
grafo.agregarVertice(6); //4
grafo.agregarVertice(5); //5

grafo.agregarArista(0,1,500);	//agrega arista del vertice 0 al 1, si se traduce a las etiquetas sería del 2 al 3
grafo.agregarArista(2,0,8);
grafo.agregarArista(2,4,1000);
grafo.agregarArista(0,3,7);
grafo.agregarArista(4,1,40);
grafo.agregarArista(3,4,20);
grafo.agregarArista(3,5,35);
grafo.agregarArista(5,4,5);        
grafo.agregarArista(1,2,90);
grafo.agregarArista(1,5,8);  

Algoritmos_grafo_MA algoritmos; 


#if 0			//PRUEBA DE DIJKSTRA 
int* VP = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
vertice* VVA = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 


algoritmos.Dijkstra(grafo, 1, VP, VVA); 


std::cout << "imprimiendo VP : " << std::endl; 
for (int index = 0; index < grafo.numVertices()-1; ++index) {
	std::cout << VP[index] << ", "; 
}

std::cout << std::endl; 

std::cout << "imprimiendo VVA : " << std::endl; 
for (int index = 0; index < grafo.numVertices()-1;  ++index) {
	std::cout << VVA[index] << ", "; 
}

std::cout << std::endl; 
#endif 


#if 0			//PRUEBA DE FLOYD 
int** MP = (int**)malloc(grafo.numVertices()*sizeof(int*)); 	//matriz de peso
vertice** MVI = (vertice**)malloc(grafo.numVertices()*sizeof(vertice*)); 	//matriz de vertice intermedio. 

for (int row = 0; row < grafo.numVertices(); ++row) {
	MP[row] = (int*)malloc(grafo.numVertices()*sizeof(int)); 
	MVI[row] = (vertice*)malloc(grafo.numVertices()*sizeof(vertice)); 	
} 

algoritmos.Floyd(grafo, MP, MVI); 

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

#if 0	//PRUEBA DE PRIM
algoritmos.Prim(grafo, 0);			
#endif 


#if 0	//PRUEBA DE KRUSKAL
algoritmos.Kruskal(grafo); 			
#endif 


#if 0	//PRUEBA IMPRIMIR ETIQUETAS USANDO PROFUNDIDAD PRIMERO
algoritmos.profundidadPrimero(grafo); 
#endif 


#if 0	//PRUEBA IMPRIMIR ETIQUETAS USANDO ANCHO PRIMERO. 
algoritmos.anchoPrimero(grafo); 
#endif 

#if 0	//PRUEBA AISLAR VERTICE. 
algoritmos.aislarVertice(grafo, 1); 
#endif 

#if 0	//PRUEBA DE SI HAY CICLOS EN UN GRAFO 
if (algoritmos.is_there_cycles(grafo)) {
	std::cout << "si hay ciclo" << std::endl; 
}
else {
	std::cout << "no hay ciclo" << std::endl; 
}
#endif
 

#if 0 //PRUEBA CIRCUITO HAMILTON DE MENOR COSTO. 
Diccionario<vertice> D; 
D.iniciar(); 
vertice* Sol = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));
vertice* mejor_Sol = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));
int costo = 0; 
int mejor_costo = INFINITY; 
int contador_soluciones = 0; 
Sol[0] = grafo.primerVertice(); 
algoritmos.CH(grafo, D, Sol, mejor_Sol, costo, mejor_costo, contador_soluciones, 1);   

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


#if 0	//PRUEBA PUNTOS DE ARTICULACION.
//hay que inicializar el mas bajo del primer vector y el orden de el tmbn 
vertice* puntos = (vertice*)calloc(grafo.numVertices(), sizeof(vertice)); 
algoritmos.encontrarPuntosArticulacion(grafo, puntos); 
std::cout << "imprimiendo los puntos de articulacion : " << std::endl; 
stringstream ss; 
for (int index = 1; index <= puntos[0]; ++index) {
	if (index != puntos[0]) {
		ss << puntos[index] << ", "; 
	}
	else {
		ss << puntos[index]; 
	}
}
ss << "\n"; 
std::cout << ss.str() << std::endl; 

#endif


#if 1
CC<vertice> mejor_sol; 
mejor_sol.iniciar(grafo.numVertices());
int menor_cantidad = INFINITY; 
int colores = 0; 
int contador_soluciones = 0; 
algoritmos.colorear_grafo(grafo, mejor_sol, colores, menor_cantidad, contador_soluciones); 

#endif    
} 

#endif 




#if 0
int main (int argc, char* argv[]) {

Grafo_MA grafo; 
grafo.iniciar(); 

grafo.agregarVertice(5); 
grafo.agregarVertice(2); 
grafo.agregarVertice(3); 
grafo.agregarVertice(9); 
grafo.agregarVertice(1); 
grafo.agregarVertice(4); 

grafo.agregarArista(0, 1, 50); 
grafo.agregarArista(3, 2, 20); 
grafo.agregarArista(1,4,15); 
grafo.agregarArista(3,1, 60);
grafo.agregarArista(2,0, 40); 

std::cout << "ETIQUETAS" << std::endl; 
std::cout << grafo.printEtiquetas() << std::endl; 
std::cout << "MATRIZ ADYACENCIA" << std::endl; 
std::cout << grafo.printMatrix() << std::endl; 


int vertex = grafo.primerVertice(); 
vertex = grafo.siguienteVertice(vertex);  


//para eliminar un vertice primero se tienen que eliminar todas sus aristas de salida y llegada. 

std::cout << "se va a proceder a eliminar un vertice, primero se eliminan las aristas y luego el vertice " << std::endl << std::endl; 


int vertex_ady = grafo.primerVerticeAdy(vertex); 
while (vertex_ady != verticeNulo) {
 grafo.eliminarArista(vertex, vertex_ady); 						//eliminando todas las aristas de salida. 
 vertex_ady = grafo.siguienteVerticeAdy(vertex, vertex_ady); 	
}


int temp_vertex = grafo.primerVertice(); 
while (temp_vertex != verticeNulo) {
	if (grafo.existeArista(temp_vertex, vertex)) {
		grafo.eliminarArista(temp_vertex, vertex); 
	}
	temp_vertex = grafo.siguienteVertice(temp_vertex); 
}

std::cout << "MATRIZ DESPUES DE ELIMINAR ARISTAS DE SALIDA Y ENTRADA" << std::endl; 
std::cout << grafo.printMatrix() << std::endl; 

grafo.eliminarVertice(vertex);

std::cout << "ETIQUETAS DEPUES DE ELIMINAR VERTICE" << std::endl;
std::cout << grafo.printEtiquetas() << std::endl; 

std::cout << "MATRIZ DESPUES DE ELIMINAR EL VERTICE" << std::endl; 
std::cout << grafo.printMatrix() << std::endl; 

}

#endif 

