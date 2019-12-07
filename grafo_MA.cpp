#include "grafo_MA.h"




/*
Requiere : Un grafo no inicializado. 
Efecto : Inicializa el grafo.
Modifica : El grafo, ya que lo inicializa..
*/
void Grafo::iniciar() {
	this->etiquetas = (ETIQUETA*)malloc(SIZEGRAFO*sizeof(ETIQUETA));
	this->matrix = (celda_t**)malloc(SIZEGRAFO*sizeof(celda_t*)); 
	for (int vertice = 0; vertice < SIZEGRAFO; ++vertice) {
		this->matrix[vertice] = (celda_t*)malloc(SIZEGRAFO*sizeof(celda_t)); 
	}
	this->ultimoLleno = 0; 
}



/*
Requiere : Un grafo ya inicializado. 
Efecto : Destruye el grafo fisicamente.
Modifica : El grafo, liberando la memoria.
*/
void Grafo::destruir() {
	//liberar memoria. 
	free(etiquetas); 
	for (int index = 0; index < SIZEGRAFO; ++index) {
		free(matrix[index]);
	}
	free(matrix); 
	vaciar(); 
}




/*
Requiere : Un grafo ya inicializado. 
Efecto : Vacia el grafo.
Modifica : El indicador de ultimo lleno, apuntandolo a nulo.
*/
void Grafo::vaciar() {
	this->ultimoLleno = 0; 
}



/*
Requiere : Un grafo ya inicializado. 
Efecto : Pregunta si el grafo esta vacio o no.
Modifica : El booleano que indica si el grafo esta vacio o no.
*/
bool Grafo::vacia() {
	bool empty = true;
	if (this->ultimoLleno > 0) {
		empty = false; 
	} 	
	return empty; 
}


/*
Requiere : Un grafo ya inicializado ; una etiqueta. 
Efecto : Agrega un vertice al grafo.
Modifica : El grafo, agregando un vertice nuevo.
*/
int Grafo :: agregarVertice(ETIQUETA etiqueta) {
	int vertice = this->ultimoLleno; 
	if (ultimoLleno <SIZEGRAFO) {
		this->etiquetas[this->ultimoLleno] = etiqueta; 
		++this->ultimoLleno; 
		
		for (int column_matrix = 0; column_matrix < this->ultimoLleno; ++column_matrix) {
			this->matrix[vertice][column_matrix].conexion = false; 
			//el peso da igual, queda con basura. 
		}
		
		for (int row_matrix = 0; row_matrix < this->ultimoLleno; ++row_matrix) {
			this->matrix[row_matrix][vertice].conexion = false; 
			//el peso da igual, queda con basura. 
		}
	
	}
	else {
		std::cout << "el grafo esta lleno, no se pueden agregar mas vertices " << std::endl; 
	}
	

	
	return vertice; 			//el vertice es un entero que corresponde al vector de etiquetas. 
}



/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Agraga una arista al grafo.
Modifica : El grafo, agregando una arista.
*/
void Grafo :: agregarArista(int vertice_1, int vertice_2, int peso) {
	//los vertices son validos si son menores al ultimo lleno. 
	if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno && vertice_1 != vertice_2) {
		this->matrix[vertice_1][vertice_2].conexion = true;	//se crea la conexion en la matriz de adyacencia.  
		this->matrix[vertice_1][vertice_2].peso = peso; 
		this->matrix[vertice_2][vertice_1].conexion = true;			//hay desperdicio por simetria, pero es no dirigido.  
		this->matrix[vertice_2][vertice_1].peso = peso; 
	}
	else {
		std::cout << "la arista no se pudo agregar porque uno o ambos vertices ingresados son invalidos" << std::endl; 
	}
}


/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Elimina la arista del grafo.
Modifica : El grafo, eliminando su arista.
*/
void Grafo :: eliminarArista(int vertice_1, int vertice_2) {
	if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno && vertice_1 != vertice_2) {
		this->matrix[vertice_1][vertice_2].conexion = false; 	
		this->matrix[vertice_2][vertice_1].conexion = false; 
	}
	else {
		std::cout << "la arista no se pudo eliminar puesto que no existe" << std::endl; 
	}
}


#if 0 
void shift_vertex_info(int current_vertex, int** matrix) {
	
	
	//desplazar un 5 significa mover todo a la posicion del 4.
	for (int row = 0; row < current_vertex-1; ++row) {
		matrix[row][current_vertex-1].conexion = matrix[row][current_vertex].conexion; 
		matrix[row][current_vertex-1].peso = matrix[row][current_vertex].peso; 
	}
	
	for (int column = 0; column < current_vertex-1; ++column) {
		matrix[current_vertex-1][column].conexion = matrix[current_vertex][column].conexion; 
	}
	
	matrix[current_vertex-1][current_vertex-1].conexion = matrix[current_vertex][current_vertex].conexion; 
	matrix[current_vertex-1][current_vertex-1].peso = matrix[current_vertex][current_vertex].peso; 
	
	
}

#endif 


/*
Requiere : Un grafo ya inicializado ; un vertice de parametro y que este aislado. 
Efecto : Elimina el vertice del grafo.
Modifica : El grafo, eliminadno el vertice.
*/
void Grafo::eliminarVertice(int vertice) { //requiere que el vertice este aislado. 
	
	for (int row = 0; row < vertice; ++row) {
		for (int column = vertice+1; column < this->ultimoLleno; ++column) {
			
			this->matrix[row][column-1].conexion = this->matrix[row][column].conexion; 
			this->matrix[row][column-1].peso = this->matrix[row][column].peso; 
				 
		} 			
	}
	
	for (int row = vertice+1; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < vertice; ++column) {	
			
			this->matrix[row-1][column].conexion = this->matrix[row][column].conexion; 
			this->matrix[row-1][column].peso = this->matrix[row][column].peso; 	
			
		} 		
	}
	
	for (int row = vertice+1; row < this->ultimoLleno; ++row) {
		for (int column = vertice+1; column < this->ultimoLleno; ++column) {
			
			this->matrix[row-1][column-1].conexion = this->matrix[row][column].conexion; 
			this->matrix[row-1][column-1].peso = this->matrix[row][column].peso; 	
				
		}
	}  
			
	/*
	for (int current_vertex = vertice+1; current_vertex < this->ultimoLleno; ++current_vertex) {		
		shift_vertex_info(current_vertex, this->matrix); 
	}
	*/
	

	for (int label = vertice+1; label < this->ultimoLleno; ++label) {
		this->etiquetas[label-1] = this->etiquetas[label]; 
	}
	
	--this->ultimoLleno; 
}

/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Retorna si existe una arista entre los 2 vertices de parametro.
Modifica : N/A.
*/
bool Grafo::existeArista(int vertice_1, int vertice_2) {
	if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno) {
		return this->matrix[vertice_1][vertice_2].conexion; 
	}
	else {
		std::cout << "se retorna falso porque los vertices ingresados no son validos" << std::endl; 
		return false; 
	}
 }


/*
Requiere : Un grafo ya inicializado ; un vertice de salida ; un vertice de llegada. 
Efecto : Retorna el peso de una arista.
Modifica : N/A.
*/
int Grafo::peso(int vertice_1, int vertice_2) {
	return this->matrix[vertice_1][vertice_2].peso; 
} 


/*
Requiere : Un grafo ya inicializado ; un vertice de parametro de punto de salida; un vertice de parametro de punto de llegada. 
Efecto : Cambia el peso de una arista.
Modifica : Modifica el peso de la arista presente, si existe.
*/
void Grafo::modificarPeso(int vertice_1, int vertice_2, int peso) {
	this->matrix[vertice_1][vertice_2].peso = peso; 
}



/*
Requiere : Un grafo ya inicializado ; un vertice de parametro ; una nueva etiqueta. 
Efecto : Cambia la etiqueta de un vertice.
Modifica : La etiqueta del vertice enviado por parametro.
*/
void Grafo::modificarEtiqueta(int vertice, ETIQUETA etiqueta) {
	this->etiquetas[vertice] = etiqueta; 
}



/*
Requiere : Un grafo ya inicializado ; un vertice de parametro. 
Efecto : Retorna la etiqueta de un grafo.
Modifica : N/A
*/
ETIQUETA Grafo::etiqueta(int ver) {
	if (ver < this->ultimoLleno) {
		return this->etiquetas[ver];
	}
	else {
		return " "; 
	}
}




/*
Requiere : Un vertice ya inicializado.
Efecto : Devuelve la cantidad de vertices presentes en el grafo.
Modifica : N/A
*/
int Grafo::numVertices() {
	return this->ultimoLleno; 
}


/*
Requiere : Un vertice ya inicializado. 
Efecto : Devuelve la cantidad de aristas que estan presentes en el grafo.
Modifica : N/A
*/
int Grafo::numAristas() {
	int counter = 0; 
	for (int row = 0; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < this->ultimoLleno; ++column) {
			if (this->matrix[row][column].conexion == true) {
				++counter; 
			}
		}	
	}
	return counter/2; 
}


/*
Requiere : Un grafo ya inicializado ; Un vertice especifico.	
Efecto : Devuelve un numero equivalente al numero de vertices adyacentes del vertice enviado por parametro.
Modifica : N/A
*/
int Grafo::numVerticesAdy(int vertice) {
	int counter = 0; 
	for (int column = 0; column < this->ultimoLleno; ++column) {
		if (column != vertice) {
			if (this->matrix[vertice][column].conexion == true) {
				++counter; 
			}
		}
	}
	return counter; 
}


/*
Requiere : Un grafo inicializado ; Un vertice de parametro. 
Efecto : Devuelve el primer vertice adyacente del vertice enviado por parametro.
Modifica : N/A
*/
int Grafo::primerVerticeAdy(int vertice) {
	int vertex = -1; 
	for (int column = 0; column < this->ultimoLleno; ++column) {
		if (vertice != column && this->matrix[vertice][column].conexion == true) {
			vertex = column; column = this->ultimoLleno;  
		} 
	}
	return vertex; 
}


/*
Requiere : Una etiqueta. 
Efecto : Devuelve el vertice que tiene la etiqueta en el parametro.
Modifica : N/A
*/
int Grafo::getVertice(ETIQUETA etiqueta) {
	int ver = -1;
	for (int index = 0; index < this->ultimoLleno; ++index) {
		if (this->etiquetas[index] == etiqueta) {
			ver = index; 
		}
	}
	return ver; 
}


/*
Requiere : Un grafo inicializado ; Vertice Actual ; Vertice Adyacente Actual 
Efecto : Devuelve el siguiente vertice adyacente.
Modifica : N/A
*/
int Grafo::siguienteVerticeAdy(int vertice, int actual_vertice_ady) {
  int vertex = -1; 
  for (int column = actual_vertice_ady+1; column < this->ultimoLleno; ++column) {
		if (column != vertice && this->matrix[vertice][column].conexion == true) {
			vertex = column; 
			column = this->ultimoLleno; 
		} 
  }
	return vertex; 
}



/*
Requiere : Un grafo inicializado.
Efecto : Devuelve el primer vertice del grafo (Valor Arbitrario)
Modifica : N/A
*/
int Grafo::primerVertice() {
	vertice vertex = 0;
	
	if (this->ultimoLleno != 0) {	
		return vertex; 
	}
	else {
		return -1; 
	}

} 

/*
Requiere : Un grafo inicializado ; Un vertice de parametro
Efecto : Devuelve el siguiente vertice del grafo. (Relacion Arbitraria) 
Modifica : N/A
*/
int Grafo::siguienteVertice(vertice ver) {
	int vertex = -1; 
	if (ver+1 < this->ultimoLleno) {
		vertex = ver+1; 
	}
	return vertex; 
}



string Grafo::printEtiquetas() {

	stringstream ss; 
	for (int vertex = 0; vertex < this->ultimoLleno; ++vertex) {
		ss << vertex << " ) " << this->etiquetas[vertex] << "\n"; 
	}
		
	return ss.str(); 
	
}


string Grafo::printMatrix() {
	
	stringstream ss; 
	for (int row = 0; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < this->ultimoLleno; ++column) {
			string current_conexion = ""; 
			
			if (this->matrix[row][column].conexion == true) {
				current_conexion = "TRUE"; 
			}
			else {
				current_conexion = "FALSE";
			}
			
			ss << "( " << current_conexion << ", " << this->matrix[row][column].peso << " )" << "  "; 	
		}
		ss << "\n"; 	
	}

	return ss.str(); 	
}

bool Grafo :: esVerticeNulo(vertice v1){
	int total_vertexes = this->ultimoLleno;
	bool is_it = false;  
	if (v1  >= total_vertexes || v1 == -1) {
		is_it = true; 
	}
return is_it; 	
} 


vertice Grafo :: getVerticeNulo(){
	return -1;
}
