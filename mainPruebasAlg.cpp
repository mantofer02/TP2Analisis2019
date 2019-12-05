#include "grafo_LA.h"
#include "apo.h"
#include "r11.h"
#include "diccionario.h"
#include "cc.h"
#include <queue>
#include <list>



void Dijkstra(Grafo &grafo, vertice ver, int*VP, vertice*VVA) {//grafo, vertice, vector peso, vector vertice anterior. 	
	R11<vertice> r11; 
	Diccionario<vertice> D;
	D.iniciar(); 
	r11.iniciar(); 
	vertice v = grafo.primerVertice();
	int contador_vertice = 0;  
	while (!(grafo.esVerticeNulo(v))) {						//inicializar VP y VVA. 
			// std :: cout << "ENTRE" << std :: endl;
            if (v != ver){
			r11.agregar(v,contador_vertice++);
			if (grafo.existeArista(ver, v)) {
				VP[r11.indice(v)] = grafo.peso(ver, v); 
			}
			else {
				VP[r11.indice(v)] = INFINITY;	//infinito
			}
			VVA[r11.indice(v)] = ver; 
		}	
		v = grafo.siguienteVertice(v);
        // std :: cout << "SALI" << std :: endl; 
	} 
	D.agregar(ver); 
	int menor; int contador; int peso_menor; 
	while (D.numElem() < grafo.numVertices()) {	//hay que recorer todos los vertices, se necesitan n-1 pivotes. 
		// std :: cout << D.numElem() << std :: endl;
        menor = -1; peso_menor = INFINITY; contador = 0; 
		while (contador < grafo.numVertices()-1) {	//la longitud de VP. 
			if (VP[contador] <= peso_menor && !D.pertenece(r11.vertice(contador))) {	//si es el menor pero no es un pivote anterior o el vertice de parametro. 
				menor = contador;
				peso_menor = VP[contador]; 
			}
			contador++; 
		}
		vertice v = r11.vertice(menor);	//pivote. 
		D.agregar(v);
		vertice v_ady = grafo.primerVerticeAdy(v); 
		while (!(grafo.esVerticeNulo(v_ady))) {		//se recorren todos los adyacentes.
			if (v_ady != ver){			//pero no me puedo incluir a mi, porque deporsi no posee un campo en VP. 
				if (VP[r11.indice(v_ady)] > grafo.peso(v,v_ady) + VP[r11.indice(v)]) {
					VP[r11.indice(v_ady)] = grafo.peso(v,v_ady) + VP[r11.indice(v)]; 
					VVA[r11.indice(v_ady)] = v;
				}		
			}
			v_ady = grafo.siguienteVerticeAdy(v,v_ady); 	
		}	
	} 
	D.destruir(); 
	r11.destruir();
}


int main(){
    Grafo grafo; 
    grafo.iniciar(); 	
    
    grafo.agregarVertice(1); //0 
    grafo.agregarVertice(2); //1
    grafo.agregarVertice(3); //2


    grafo.agregarArista(grafo.getVertice(2),grafo.getVertice(3),5);
    grafo.agregarArista(grafo.getVertice(1),grafo.getVertice(3), 20);   

//    std :: cout << grafo.existeArista(grafo.getVertice(2) , grafo.getVertice(3)) << std :: endl;

   
    
    // std :: cout << grafo.esVerticeNulo(grafo.siguienteVerticeAdy(grafo.getVertice(3), grafo.primerVerticeAdy(grafo.getVertice(3))));
    int* VP = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
    vertice* VVA = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 


    Dijkstra(grafo, grafo.primerVertice(), VP, VVA); 


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
        
    return 0;
}