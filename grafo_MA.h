#ifndef GRAFO_MA_H
#define GRAFO_MA_H

#include <sstream>
#include <iostream>

using namespace std; 

#define SIZEGRAFO 100
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
		/*
		 * Efecto : Inicializa un grafo con Matriz de Adyacencia, como hay que conocer M el tamaño se encuentra especificado en el .h
		 * Requiere : Que el grafo exista
		 * Modifica : Reserva Memoria para poder ser utilizada por el grafo crea tanto el vector de etiquetas como la matriz ambos de dimensiones M y MxM
		 *
		 * */
		void iniciar(); 
		/*
		 * Efecto : Detruye el grafo
		 * Requiere : Que el grafo exista
		 * Modifica : No modifica nada, solo destruye todo el grafo y queda inutilizable, a menos que se vuelva a inicializar. 
		 *
		 * */		
		void destruir(); 
		/*
		 * Efecto : Vacia el grafo
		 * Requiere : Que el grafo exista y se encuentre inicializado
		 * Modifica : El contador de vertices, solo es un vaciado lógico, más no fisico, tarda O(1)
		 *
		 * */
		void vaciar(); 
		/*
		 * Efecto : Retorna un booleano si el grafo esta vacio o no
		 * Requiere : Que el grafo exista y se encuentre inicializado. 
		 * Modifica : No Modifica nada solo retorna informacion existente. 
		 *
		 * */
		bool vacia(); 

		/*
		 * Efecto : Agregar un Vertice en el grafo
		 * Requiere : Que el grafo exista, se encuentre inicializado y que el grafo no se encuentre lleno, por eso hay que conocer M. 
		 * Modifica : El vector de etiquetas y la matriz de adyacencia, al igual que los contadores correspondientes. 
		 *
		 * */		
		int agregarVertice(int etiqueta); 

		/*
		 * Efecto : Agrega una arista entre 2 vertices existentes. 
		 * Requiere : Que el grafo exista, se encuentre inicializado y los vertices ingresados sean vertices validos en el grafo. 
		 * Modifica : La matriz de adyacencia agrendo una arista entre 2 vertices. 
		 *
		 * */		
		void agregarArista(vertice vertice_1, vertice vertice_2, int peso);	
		/*
		 * Efecto : Elimina una arista del grafo. 
		 * Requiere : Que el grafo exista, se encuentre inicializado y que los 2 vertices sean validos. 
		 * Modifica : la matriz de adyacencia. 
		 *
		 * */
		void eliminarArista(vertice vertice_1, vertice vertice_2); 
		/*
		 * Efecto : Elimina un vertice del grafo. 
		 * Requiere : Que el grafo se encuentre inicializado, exista y que el vertice ingresado sea valido. 
		 * Modifica : El vector de etiquetas para cada vertice, y la matriz de adyacencia. 
		 *
		 * */							
		void eliminarVertice(vertice ver); 																
		
		/*
		 * Efecto : retorna un booleano de si existe arista entre 2 vertices. 
		 * Requiere : Que el grafo exista, se encuentre inicializado y que ambos vertices ingresados sean validos. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		bool existeArista(vertice vertice_1, vertice vertice_2); //optional
		
		/*
		 * Efecto : retorna el peso existente entre 2 vertices. 
		 * Requiere : Que el grafo exista, se encuentre inicializado y que ambos vertices sean validos. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		int peso(vertice vertice_1, vertice vertice_2); 
		
		/*
		 * Efecto : Modifica el peso entre 2 vertices. 
		 * Requiere : Que el grafo exista, se encuentre inicializado, que ambos vertices sean validos y posean una arista entre ellos. 
		 * Modifica : Modifica el peso existente entre 2 vertices. 
		 *
		 * */
		void modificarPeso(vertice vertice_1, vertice vertice_2, int peso); 
		
		/*
		 * Efecto : Modifica la etiqueta correspondiente a un vertice. 
		 * Requiere : Que el vertice exista. 
		 * Modifica : La etiqueta de un vertice. 
		 *
		 * */
		void modificarEtiqueta(vertice ver, int etiqueta); 
		
		
		/*
		 * Efecto : retorna la etiqueta correspondiente a un vertice
		 * Requiere : que el vertice exista
		 * Modifica : no modifica nada, solo retorna informacion. 
		 *
		 * */

		int etiqueta(vertice ver); 
		
		/*
		 * Efecto : Retorna la cantidad de vertices que posee el grafo. 
		 * Requiere : Que el grafo exista y se encuentre inicializado. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		int numVertices(); 
		
		/*
		 * Efecto : retorna la cantidad de aristas correspondientes al grafo. 
		 * Requiere : Que el grafo exista y se encuentre inicializado. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		int numAristas(); 
		
		/*
		 * Efecto : retorna la cantidad de vertices adyacentes del vertice ingresado. 
		 * Requiere : que el vertice ingresado exista.
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		int numVerticesAdy(vertice ver); 
		
		
		/*
		 * Efecto : retorna el primer Vertice adyacente de un vertice. 
		 * Requiere : Que el vertice ingresado sea valido. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		vertice primerVerticeAdy(vertice ver); 
		
		/*
		 * Efecto : retorna el siguiente vertice adyacente de un vertice despues del que se desea saber. 
		 * Requiere : que tanto el vertice, como el vertice adyacente sean vertices validos, y que realmente exista una arista entre ambos. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		vertice siguienteVerticeAdy(vertice ver, vertice ver_ady); 
		
		/*
		 * Efecto : retorna el primer vertice del grafo. 
		 * Requiere : que el grafo exista, y se encuentre inicializado. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		vertice primerVertice(); 

		/*
		 * Efecto : retorna el siguiente vertice del grafo, despues del ingresado.  
		 * Requiere : que el grafo exista, se encuentre inicializado y que el vertice ingresado sea valido. 
		 * Modifica : No modifica nada, solo retorna informacion existente. 
		 *
		 * */
		vertice siguienteVertice(vertice ver); 
		
		/*
		 * NO APLICA, SOLO ES CON FINES DE TESTING. 
		 * Efecto : 
		 * Requiere : 
		 * Modifica : 
		 *
		 * */
		string printEtiquetas(); 
		
		/* NO APLICA, SOLO ES CON FINES DE TESTING. 
		 * Efecto : 
		 * Requiere : 
		 * Modifica : 
		 *
		 * */
		string printMatrix(); 
		
		/* NO APLICA, SOLO ES CON FINES DE TESTING. 
		 * Efecto : 
		 * Requiere : 
		 * Modifica : 
		 *
		 * */
		bool esVerticeNulo(vertice ver);
		
		/* NO APLICA, SOLO ES CON FINES DE TESNTING. 
		 * Efecto : 
		 * Requiere : 
		 * Modifica : 
		 *
		 * */
		vertice getVerticeNulo();
		
		/* NO APLICA SOLO ES CON FINES DE TESTING. 
		 * Efecto : 
		 * Requiere : 
		 * Modifica : 
		 *
		 * */
		vertice getVertice(int etiqueta); 
};

/*
public: 	
	void iniciar(); 
	void destruir(); 
	void vaciar(); 
	bool vacio(); 
	int agregarVertice(int etiqueta); 
	void agregarArista(int vertice_1, int vertice_2, int peso);	//ambos vertices deben ser validos.  //MODIFICAR. 
	void eliminarArista(int vertice_1, int vertice_2); 												//MODIFICAR.
	void eliminarVertice(int vertice); 																
	bool existeArista(int vertice_1, int vertice_2); //optional
	int peso(int vertice_1, int vertice_2); 
	void modificarPeso(int vertice_1, int vertice_2, int peso); 
	void modificarEtiqueta(int vertice, int etiqueta); 
	int etiqueta(int vertice); 
	int numVertices(); 
	int numAristas(); 
	int numVerticesAdy(int vertice); 
	int primerVerticeAdy(int vertice); 
	int siguienteVerticeAdy(int vertice, int actual_vertice_ady); 
	int primerVertice(); 
	int siguienteVertice(int vertice); 
	string printEtiquetas(); 
	string printMatrix(); 

*/

#endif
