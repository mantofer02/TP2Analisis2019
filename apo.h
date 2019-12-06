#include <iostream>
#include <sstream>
using namespace std; 
#define LONGITUDAPO 100
#define INFINITY 999999999

template <typename T>
struct arista_t{
	T vertice_origen; 
	T vertice_destino; 
	int peso; 	
}; 


template<class T>
class APO {
	private:
	arista_t<T>* heap_vector; 
	int ultimaPosicion;
	int cantidadNodos; 
	
	public:
	APO(); 
	void iniciar(); 
	void insertar(T vertice_origen, T vertice_destino, int peso);  
	arista_t<T>* sacar(); 
	string printAPO(); 
		
}; 



template<class T>
	APO<T>::APO() {	
}

template <class T>
void APO<T>::iniciar() {
	this->heap_vector = (arista_t<T>*)calloc(LONGITUDAPO, sizeof(T)); 	
	this->cantidadNodos = 0; 
	this->ultimaPosicion = 1; 
}

template <class T>
void APO<T>::insertar(T vertice_origen, T vertice_destino, int peso){
	int index = this->ultimaPosicion;  
	bool finished = false;
	int father = 0; 
	if (this->cantidadNodos != 0) {
	
		while (!finished) {		//si aun no se acomoda y no soy la raiz. 	
			if (index %2 == 0) {				//soy el hijo izquierdo de alguien. 
				father = index/2; 
			}
			else {								//soy el hijo derecho de alguien. 
				father = (index-1)/2; 
			}
			if (peso < this->heap_vector[father].peso) {	//si mi peso es menor al de mi padre. 
				this->heap_vector[index].vertice_origen = this->heap_vector[father].vertice_origen; 
				this->heap_vector[index].vertice_destino = this->heap_vector[father].vertice_destino; 
				this->heap_vector[index].peso = this->heap_vector[father].peso; 
				index = father; 
				
				if (index == 1) {					//llegue a la raiz 
					finished = true; 	
				} 
			}
			else {									//ya no puedo seguir subiendo, posicion valida. 
				finished = true; 
			}		
		}	
	}
	this->heap_vector[index].vertice_origen = vertice_origen; 
	this->heap_vector[index].vertice_destino = vertice_destino; 
	this->heap_vector[index].peso = peso; 
	++this->cantidadNodos; 
	++this->ultimaPosicion;  
	
}


template <class T>
arista_t<T>* APO<T>::sacar(){
	arista_t<T>* arista  = NULL; 
	if (this->cantidadNodos != 0){
		arista = new arista_t<T>(); 
		arista->vertice_origen = this->heap_vector[1].vertice_origen; 
		arista->vertice_destino = this->heap_vector[1].vertice_destino; 	
		arista->peso = this->heap_vector[1].peso; 	
		--cantidadNodos; 

		bool finished = false; 
		int last_position = this->ultimaPosicion; 
		if (this->cantidadNodos != 0) {
			int weight = this->heap_vector[ultimaPosicion-1].peso; 
			int index = 1; 
			int son_selected = 0; 
			int weight_s1; 
			int weight_s2; 
			while (!finished){
				int pos_s1 = index*2; 
				int pos_s2 = (index*2)+1; 
				weight_s1 = INFINITY; 
				weight_s2 = INFINITY; 
				if (pos_s1 < last_position-1) {				//si es una posicion valida. 
					weight_s1 = this->heap_vector[pos_s1].peso;  //tome su peso. 
				}
				if (pos_s2 < last_position-1) {				//si es una posicion valida. 
					weight_s2 = this->heap_vector[pos_s2].peso; //tome su peso. 
				} 
				if (weight_s1 != INFINITY || weight_s2 != INFINITY) {	//si alguna posicion es valida. 	
					if (weight > weight_s1 || weight > weight_s2) {		//el padre tiene que ser menor o igual que sus hijos. 
						if (weight_s1 < weight_s2) {				//se intercambia con el hijo menor. 
							son_selected = pos_s1;  
						}
						else{
							son_selected = pos_s2;  
						}
					
					this->heap_vector[index].vertice_origen = this->heap_vector[son_selected].vertice_origen; 
					this->heap_vector[index].vertice_destino = this->heap_vector[son_selected].vertice_destino; 
					this->heap_vector[index].peso = this->heap_vector[son_selected].peso; 
					index = son_selected; 
				}
				else {
					finished = true; 			//el padre es menor que sus hijos(los que tenga, 1 o 2), dejar en esa posicion. 
				}	
			} 
			else {								//el padre no tiene hijos, dejar en esa posicion. 
				finished = true; 
			}
		}
		this->heap_vector[index].vertice_origen = this->heap_vector[this->ultimaPosicion-1].vertice_origen; 
		this->heap_vector[index].vertice_destino = this->heap_vector[this->ultimaPosicion-1].vertice_destino; 
		this->heap_vector[index].peso =  this->heap_vector[this->ultimaPosicion-1].peso; 	
	}
	--this->ultimaPosicion; 
	}
	else {
		std::cout << "ya no hay elementos en el APO" << std::endl;  
	}
	return arista; 
}


template <class T>
string APO<T>::printAPO() {
	stringstream ss; 
	for (int index = 1; index < this->ultimaPosicion; ++index) {
		if (index != this->ultimaPosicion -1) { 
			ss << this->heap_vector[index].peso << ", ";
		}
		else {
			ss << this->heap_vector[index].peso; 
		} 
	}
	ss << "\n";  	
	return ss.str();
}


