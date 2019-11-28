#include <iostream>
#include <sstream>
#define TAMANYO 30		//misma cantidad de vertices del grafo. 
using namespace std; 
template <class T>
class Diccionario {
	private: 
	T* vector; 
	int ultimoLleno; 
	
	public: 
	Diccionario(); 
	void iniciar(); 
	void agregar(T ver);
	bool pertenece(T ver); 
	void pop(); 
	int numElem();  
	void destruir(); 
	string printD(); 
	
}; 



template <class T>
Diccionario<T>::Diccionario() {	
}

template <class T>
void Diccionario<T>::destruir() {
	free(this->vector); 
}

template <class T>
void Diccionario<T>::pop() {
	--this->ultimoLleno; 
}

template <class T>
void Diccionario<T>::iniciar() {
	this->vector = (T*)malloc(TAMANYO*sizeof(T)); 
	this->ultimoLleno = 0; 
}

template <class T>
void Diccionario<T>::agregar(T ver) {
	this->vector[this->ultimoLleno] = ver; 
	++this->ultimoLleno; 
}

template <class T>
bool Diccionario<T>::pertenece(T ver) {
	bool found = false; 
	for (int index = 0; index < this->ultimoLleno; ++index) {
		if (this->vector[index] == ver) {
			found = true; index = this->ultimoLleno; 
		}
	}
	return found; 	
}


template <class T>
int Diccionario<T>::numElem() {
	return this->ultimoLleno; 
}

template <class T>	
string Diccionario<T>::printD() {
	stringstream ss; 
	for (int index = 0; index < this->ultimoLleno; ++index) {
		if (index != this->ultimoLleno-1) {
			ss << this->vector[index] << ", "; 
		}
		else {
			ss << this->vector[index]; 
		}
	}
	return ss.str(); 
}
