#ifndef GRAFO_MA_H
#define GRAFO_MA_H

#include <sstream>
#include <iostream>

using namespace std; 

#define SIZEGRAFO 30
#define verticeNulo -1

typedef int vertice; 

typedef struct {
	bool conexion; 
	int peso; 
	
} celda_t; 


class Grafo{
	

	private: 	
		int* etiquetas; 
		celda_t** matrix; 
		int ultimoLleno; 

	
	
	public: 	
		/*\
		
		VENDRIA BIEN UN OPERADOR GET VERTICE COMO EN LA LA PARA QUE ASI SE MANEJES LOS LLAMADOS EXTERNOS, Y NO POR TIPO
		
		
		*/
	
	
	
		void iniciar(); 
		void destruir(); 
		void vaciar(); 
		bool vacio(); 
		//Debe ser tipo etiqueta, no entero
		//Peor de los casos, hacemos la etiqueta de LA un entero
		
		int agregarVertice(int etiqueta); 
		
		void agregarArista(vertice vertice_1, vertice vertice_2, int peso);	//ambos vertices deben ser validos.  //MODIFICAR. 
		void eliminarArista(vertice vertice_1, vertice vertice_2); 												//MODIFICAR.
		void eliminarVertice(vertice); 																
		
		bool existeArista(vertice vertice_1, vertice vertice_2); //optional
		
		int peso(vertice vertice_1, vertice vertice_2); 
		void modificarPeso(vertice vertice_1, vertice vertice_2, int peso); 
		void modificarEtiqueta(vertice vertice, int etiqueta); 
		
		
		// Este tambien, hay que ver que hacerle

		int etiqueta(int vertice); 
		
		int numVertices(); 
		
		int numAristas(); 
		
		int numVerticesAdy(vertice); 
		
		vertice primerVerticeAdy(vertice vertice); 
		
		vertice siguienteVerticeAdy(vertice, vertice); 
		vertice primerVertice(); 
		vertice siguienteVertice(vertice vertice1); 
		string printEtiquetas(); 
		string printMatrix(); 
		int esVerticeNulo(vertice);
		vertice getVerticeNulo();
		vertice getVertice(int etiqueta); 
};

#endif
