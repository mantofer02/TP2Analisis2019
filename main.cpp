#include "algoritmos_grafo_MA.h"

#if 1						

int main (int argc, char* argv[]) {

Grafo_MA grafo; 
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


#if 0
int* VP = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
int* VVA = (int*)calloc((grafo.numVertices()-1), sizeof(int)); 	//vector vertice anterior 


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


#if 0 
int** MP = (int**)malloc(grafo.numVertices()*sizeof(int*)); 	//matriz de peso
int** MVI = (int**)malloc(grafo.numVertices()*sizeof(int*)); 	//matriz de vertice intermedio. 

for (int row = 0; row < grafo.numVertices(); ++row) {
	MP[row] = (int*)malloc(grafo.numVertices()*sizeof(int)); 
	MVI[row] = (int*)malloc(grafo.numVertices()*sizeof(int)); 	
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

//algoritmos.Prim(grafo, 0);

APO apo; 
apo.iniciar(); 
apo.insertar(0,0,10); 
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,7); 
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,1); 
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,5); 
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,4);
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,1);
std::cout << apo.printAPO() << std::endl; 
apo.insertar(0,0,3);
std::cout << apo.printAPO() << std::endl; 


apo.sacar(); 
std::cout << apo.printAPO() << std::endl; 
apo.sacar(); 
std::cout << apo.printAPO() << std::endl; 
apo.sacar(); 
std::cout << apo.printAPO() << std::endl; 
//apo.insertar(0,0,7); 
//apo.insertar(0,0,8);    
 

std::cout << apo.printAPO() << std::endl; 
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
 

//grafo.eliminarVertice(); 


}

#endif 




/*
std::cout << "imprimiendo R11 : " << std::endl; 
std::cout << r11.printR11() << std::endl; 

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
*/
