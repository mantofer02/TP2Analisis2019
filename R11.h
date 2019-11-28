#define INFINITY 999999999
#define TAMANYO 30		//misma cantidad de vertices del grafo. 

template <class T>
class R11 {
	private: 
	T** matrix; 
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
	
	for (int index = 0; index < this->ultimoLleno; ++index) {
		free(this->matrix[index]);
	}
	free(this->matrix);
	
}

template <class T>
void R11<T>::iniciar() {
	this->matrix = (T**)calloc(TAMANYO,sizeof(T*));
	for (int row = 0; row < TAMANYO; ++row) {
		this->matrix[row] = (T*)calloc(2,sizeof(T)); 
	} 
	this->ultimoLleno = 0; 
}


template <class T>
void R11<T>::agregar(T ver, int indice) {
	if (this->ultimoLleno < TAMANYO) {
		matrix[ultimoLleno][0] = ver; 
		matrix[ultimoLleno][1] = indice; 
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
		if (this->matrix[index][0] == ver) {
			found = true;
			image = this->matrix[index][1];  
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
		if (this->matrix[index][1] == indice) {
			found = true; 
			image = this->matrix[index][0]; 
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
	ss << this->matrix[index][0] << " = " << this->matrix[index][1] << "\n"; 
}

return ss.str(); 	
}
