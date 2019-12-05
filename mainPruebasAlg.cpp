#include "grafo_MA.h"
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
			if (!(v == ver)) {
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
	} 
	D.agregar(ver); 
	int menor; int contador; int peso_menor; 
	while (D.numElem() < grafo.numVertices()) {	//hay que recorer todos los vertices, se necesitan n-1 pivotes. 
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
			if (!(v_ady == ver)){			//pero no me puedo incluir a mi, porque deporsi no posee un campo en VP. 
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

    int* VP = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
    vertice* VVA = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 


    Dijkstra(grafo, 1, VP, VVA); 


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