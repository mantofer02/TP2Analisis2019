#include <iostream>
using namespace std; 
#include <sstream>
template <class T>
class CC {

	private: 
	T** cc; 
	int* counter_ver_c; 
	int amount_c; 
	
	public: 
		CC(); 
		void iniciar(int max_amount_elements); 
		void agregarConjunto(int conjunto);
		void agregarAConjunto(T ver, int conjunto);  
		int conjuntoAlQuePertenece(T ver);//retorna conjunto. . 
		void unir(int conjunto_1, int conjunto_2);
		bool existeInterseccion(int conjunto, CC<T>&cc_1, int conjunto_cc1);   
		void sacarDeConjunto(int conjunto, T ver); 
		int obtConjunto(int index); 
		string printCC(); 
}; 

template <class T>
CC<T>::CC() {
	
}

template <class T>
bool CC<T>::existeInterseccion(int conjunto, CC<T>&cc_1, int conjunto_cc1) {
	bool exist = false; 
	for (int index = 1; index <= this->counter_ver_c[conjunto]/*this->cc[conjunto][0]*/; ++index) {
		for (int index_cc = 1; index_cc <= cc_1.counter_ver_c[conjunto_cc1]/*cc_1.cc[conjunto_cc1][0]*/; ++index_cc) {
			if (this->cc[conjunto][index] == cc_1.cc[conjunto_cc1][index_cc]) {
				exist = true; index_cc = cc_1.counter_ver_c[conjunto_cc1]+1/*cc_1.cc[conjunto_cc1][0]+1*/; 
				index = this->counter_ver_c[conjunto]+1/*this->cc[conjunto][0]+1*/; 
			}
		}
	}
	return exist; 	
}

template <class T>
void CC<T>::sacarDeConjunto(int conjunto, T ver) {
	//--this->cc[conjunto][0];
	--this->counter_ver_c[conjunto];  
}

template <class T>
int CC<T>::obtConjunto(int index) {
	return index; 
} 

template <class T>
void CC<T>::iniciar(int max_amount_elements) {
	this->cc = (T**)calloc(max_amount_elements, sizeof(T*));
	for (int conjunto = 0; conjunto < max_amount_elements; ++conjunto) {
		this->cc[conjunto] = (T*)calloc(max_amount_elements+1, sizeof(T)); 	//la posicion 0 va a decir cuantos elementos posee a partir del 1. 
	}
	
	this->counter_ver_c = (int*)calloc(max_amount_elements, sizeof(int)); 																			//por eso una columna mas que filas. 		
	this->amount_c = 0;   																			
}


template <class T>
void CC<T>::agregarConjunto(int conjunto) {
	++this->amount_c; 	
	//this->cc[conjunto][this->amount_c-1] = 0; 
}

template <class T>
void CC<T>::agregarAConjunto(T ver, int conjunto) {
	if (conjunto < this->amount_c) {
		//++this->cc[conjunto][0];
		++this->counter_ver_c[conjunto];  
		//this->cc[conjunto][this->cc[conjunto][0]] = vertice;
		this->cc[conjunto][this->counter_ver_c[conjunto]] = ver;  
	}
	else {
		std::cout << "se quiere añadir a un conjunto que no existe" << std::endl; 
	}	
}

template <class T>
int CC<T>::conjuntoAlQuePertenece(T ver) {
	int conjunto = -1; 
	bool found = false; 
	for (int c = 0; c < this->amount_c; ++c) {			//conjunto
		for (int v = 1; v <= this->counter_ver_c[c]; ++v) {		//vertice
			if (this->cc[c][v] == ver) {
				conjunto = c; 
				v = this->counter_ver_c[c]+1; //(this->cc[c][0]+1); 
			}
		}
		if (found) {
			c = this->amount_c;	
		}				
	}
	return conjunto; 
}


template <class T>
void CC<T>::unir(int conjunto_1, int conjunto_2) {
	if (conjunto_2 < conjunto_1) {
		int aux = conjunto_1; 
		conjunto_1 = conjunto_2; 
		conjunto_2 = aux; 
	}		//conjunto_1 tiene que ser menor a conjunto_2
	
	for (int ver = 1; ver <= this->counter_ver_c[conjunto_2] /*this->cc[conjunto_2][0]*/; ++ver) {
		agregarAConjunto(this->cc[conjunto_2][ver], conjunto_1); 	
	}
	this->counter_ver_c[conjunto_2] = 0; 
	//this->cc[conjunto_2][0] = 0; 
	
	int last_conjunto = this->amount_c-1; 
	
	for (int ver = 1; ver <= this->counter_ver_c[last_conjunto]/*this->cc[last_conjunto][0]*/; ++ver) {
		agregarAConjunto(this->cc[last_conjunto][ver], conjunto_2); 		
	} 
	--this->amount_c; 			
	this->counter_ver_c[last_conjunto] = 0; 
}


template <class T>
string CC<T>::printCC() {
stringstream ss; 	

for (int conjunto = 0; conjunto < this->amount_c; ++conjunto) {
	for (int ver = 1; ver <= this->counter_ver_c[conjunto]/*this->cc[conjunto][0]*/; ++ver) {
		if (ver != this->counter_ver_c[conjunto] /*this->cc[conjunto][0]*/) {
			ss << this->cc[conjunto][ver] << ", "; 
		}
		else {
			ss << this->cc[conjunto][ver]; 
		}
	}
	ss << "\n"; 
}	
	
return ss.str(); 	
}
