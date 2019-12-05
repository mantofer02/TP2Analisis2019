#include <iostream>
#include <sstream>
using namespace std;
#define INFINITY 999999999
#define TAMANYO 30		//misma cantidad de vertices del grafo. 
#define verticeNulo -1

template <class T>
class R11 {
	private: 
	T* vertices;
	int* indices; 
	int ultimoLleno; 
	
	public:
	R11();
	void agregar(T ver, int indice); 
	void iniciar();
	int indice(T ver); 
	T vertice(int indice);  
	void destruir(); 
	string printR11(); 	
}; 


template <class T>
R11<T>::R11() {
}

template <class T>
void R11<T>::destruir() {
	
	/*
	for (int index = 0; index < this->ultimoLleno; ++index) {
		free(this->matrix[index]);
	}
	free(this->matrix);
	*/
	
	free(this->vertices); 
	free(this->indices); 
}

template <class T>
void R11<T>::iniciar() {
	this->vertices = (T*)calloc(TAMANYO, sizeof(T));
	this->indices = (int*)calloc(TAMANYO, sizeof(int)); 
	this->ultimoLleno = 0; 
	
	/*
	this->matrix = (T**)calloc(TAMANYO,sizeof(T*));
	for (int row = 0; row < TAMANYO; ++row) {
		this->matrix[row] = (T*)calloc(2,sizeof(T)); 
	} 
	this->ultimoLleno = 0; 
	*/
}


template <class T>
void R11<T>::agregar(T ver, int indice) {
	if (this->ultimoLleno < TAMANYO) {
		//matrix[ultimoLleno][0] = ver; 
		//matrix[ultimoLleno][1] = indice; 
		this->vertices[ultimoLleno] = ver; 
		this->indices[ultimoLleno] = indice; 
		++this->ultimoLleno; 
	}
	else {
		std::cout << "la R11 ya esta llena, no deberia de meterse mas vectores de los que existen" << std::endl; 
	}
	
}

template <class T>
int R11<T>::indice(T ver) {
	int index = 0;
	int image = -1; 
	bool found = false;  
	while (index < this->ultimoLleno && !found) {
		if (this->vertices[index] == ver) {
			found = true;
			//image = this->matrix[index][1]; 
			image = this->indices[index]; 
		}
		else {
			index++; 		
		}	
	}
	
	 return image; 
}


template <class T>
T R11<T>::vertice(int indice) {
	int index = 0; 
	bool found = false; 
	T image = verticeNulo; 
	while (index < this->ultimoLleno && !found) {
		if (this->indices[index] == indice) {
			found = true; 
			//image = this->matrix[index][0];
			image = this->vertices[index];  
		}
		else {
			index++; 
		} 	
	}
	 return image; 	
}

template <class T>
string R11<T>::printR11() {
stringstream ss; 
for (int index = 0; index < this->ultimoLleno; ++index) {
	ss << this->vertices[index] << " = " << this->indices[index] << "\n"; 
}

return ss.str(); 	
}
