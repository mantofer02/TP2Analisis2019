#ifndef GRAFO_MA_H
#define GRAFO_MA_H

#include <sstream>
#include <iostream>
using namespace std; 

#define SIZEGRAFO 30
#define verticeNulo -1

typedef struct {
	bool conexion; 
	int peso; 
	
} celda_t; 


class Grafo_MA {
	

private: 	
int* etiquetas; 
celda_t** matrix; 
int ultimoLleno; 

	
	
public: 	
void iniciar(); 
void destruir(); 
void vaciar(); 
bool vacio(); 
int agregarVertice(int etiqueta); 
void agregarArista(int vertice_1, int vertice_2, int peso);	//ambos vertices deben ser validos.  
void eliminarArista(int vertice_1, int vertice_2); 
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

};

#endif
