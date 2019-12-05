#include "grafo_LA.h"
#include "apo.h"
#include "r11.h"
#include "diccionario.h"
#include "cc.h"
#include <queue>
#include <list>



void Prim(Grafo&grafo, vertice ver) {			//ESTE ALGORITMO VA IMPRIMIENDO, SE LE PODRIA PONER UN BOOL, PARA QUE IMPRIMA DE FORMAS 
	Diccionario<vertice> D; 												//DIFERENTES. 	
	D.iniciar(); 	
	D.agregar(ver); 
	vertice v; 
	vertice v_ady; 
	int peso_minimo; 				//peso de la arista con menor peso.
	vertice v_padre;  					//vertice de origen de dicha arista.
	vertice v_minimo;  					//vertice de destino de dicha arista. 
	std::cout << "aristas seleccionadas : " << std::endl; 

while (D.numElem() < grafo.numVertices()) {
	v = grafo.primerVertice(); 
	peso_minimo = INFINITY; 
	while (!grafo.esVerticeNulo(v)) {
		if (D.pertenece(v)) {
			v_ady = grafo.primerVerticeAdy(v); 
			while (!grafo.esVerticeNulo(v_ady)) {
				if (!D.pertenece(v_ady)) {
					if (grafo.peso(v, v_ady) < peso_minimo) {
						peso_minimo = grafo.peso(v, v_ady); 
						v_padre = v; 
						v_minimo = v_ady; 
					}
				}
				v_ady = grafo.siguienteVerticeAdy(v, v_ady);  
			}	
		}
		v = grafo.siguienteVertice(v); 
	}
	D.agregar(v_minimo); 													//PORQUE AQUI YO IMPRIMO MI VERTICE COMO SI NADA, PERO PARA LA LISTA NO
	std::cout << "vertice origen : " << v_padre << " vertice destino : " << v_minimo << " peso : " << peso_minimo << std::endl; 	
}																			//AMENOS QUE SE SOBRECARGUE EL OPERADOR PARA QUE SE PUEDA IMPRIMIR EL OBJETO. 			
																			//COMO UN TIPO TOSTRING DE JAVA. 
D.destruir(); 	
}

int main(){
    Grafo grafo; 
    grafo.iniciar(); 	
    
    grafo.agregarVertice(1); //0 
    grafo.agregarVertice(2); //1
    grafo.agregarVertice(3); //2


    grafo.agregarArista(grafo.getVertice(2),grafo.getVertice(3),5);
    grafo.agregarArista(grafo.getVertice(1),grafo.getVertice(3), 20);   

    Prim(grafo, grafo.primerVertice());	
    return 0;
}