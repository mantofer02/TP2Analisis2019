#include "algoritmos_grafo_MA.h"

Algoritmos_grafo_MA::Algoritmos_grafo_MA() {
	
	
}


void Algoritmos_grafo_MA::Dijkstra(Grafo_MA&grafo, int vertice, int*VP, int*VVA) {//grafo, vertice, vector peso, vector vertice anterior. 	
	#if 1
	R11 r11; 
	Diccionario D;
	D.iniciar(); 
	r11.iniciar(); 
	int v = grafo.primerVertice();
	int contador_vertice = 0;  
	while (v != verticeNulo) {						//inicializar VP y VVA. 
		if (v != vertice) {
			r11.agregar(v,contador_vertice++);
			if (grafo.existeArista(vertice, v)) {
				VP[r11.indice(v)] = grafo.peso(vertice, v); 
			}
			else {
				VP[r11.indice(v)] = INFINITY;	//infinito
			}
			VVA[r11.indice(v)] = vertice; 
		}	
		v = grafo.siguienteVertice(v); 
	} 

	D.agregar(vertice); 

	int menor; int contador; int peso_menor; 
	while (D.numElem() < grafo.numVertices()) {	//hay que recorer todos los vertices, se necesitan n-1 pivotes. 
		menor = -1; peso_menor = INFINITY; contador = 0; 
		while (contador < grafo.numVertices()-1) {	//la longitud de VP. 
			if (VP[contador] <= peso_menor && !D.pertenece(r11.vertice(contador))) {	//si es el menor pero no es un pivote anterior o el vertice de parametro. 
				menor = contador;
				peso_menor = VP[contador]; 
			}
			contador++; 
		}
		int v = r11.vertice(menor);	//pivote. 
		D.agregar(v);
		int v_ady = grafo.primerVerticeAdy(v); 
		while (v_ady != verticeNulo) {		//se recorren todos los adyacentes.
			if (v_ady != vertice) {			//pero no me puedo incluir a mi, porque deporsi no posee un campo en VP. 
				if (VP[r11.indice(v_ady)] > grafo.peso(v,v_ady) + VP[r11.indice(v)]) {
					VP[r11.indice(v_ady)] = grafo.peso(v,v_ady) + VP[r11.indice(v)]; 
					VVA[r11.indice(v_ady)] = v;
				}		
			}
			v_ady = grafo.siguienteVerticeAdy(v,v_ady); 	
		}	
	} 

	D.destruir(); 
	r11.destruir();
	#endif
}




void Algoritmos_grafo_MA::Floyd(Grafo_MA&grafo, int** MP, int** MVI) {
R11 r11; 
r11.iniciar(); 
int v = grafo.primerVertice(); int contador_vertice = 0; 
while (v != verticeNulo) {
	r11.agregar(v, contador_vertice++); 
	v = grafo.siguienteVertice(v); 
}

for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
	int v_x = r11.vertice(index_x); 
	for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
		int v_y = r11.vertice(index_y); 
		if (v_x != v_y) {
			if (grafo.existeArista(v_x, v_y)) {
				MP[index_x][index_y] = grafo.peso(v_x, v_y);
				MVI[index_x][index_y] = verticeNulo;  		
			}
			else {
				MP[index_x][index_y] = INFINITY; 
				MVI[index_x][index_y] = verticeNulo; 
			} 		
			
		}
		else {	//son los mismos.
			MP[index_x][index_y] = 0; 
			MVI[index_x][index_y] = verticeNulo; 
		}		
	}	
} 

for (int pivote = 0; pivote < grafo.numVertices(); ++pivote) { 
	for (int origen = 0; origen < grafo.numVertices(); ++origen) {
		for (int destino = 0; destino < grafo.numVertices(); ++destino) {
			if (MP[origen][destino] > MP[origen][pivote] + MP[pivote][destino]) {
				MP[origen][destino] = MP[origen][pivote] + MP[pivote][destino]; 
				MVI[origen][destino] = pivote; 
			}
		} 	
	} 
}

} 

void Algoritmos_grafo_MA::Prim(Grafo_MA&grafo, int vertice) {
Diccionario D; 
D.iniciar(); 	
D.agregar(vertice); 
int v; 
int v_ady; 
int peso_minimo; 				//peso de la arista con menor peso.
int v_padre;  					//vertice de origen de dicha arista.
int v_minimo;  					//vertice de destino de dicha arista. 


std::cout << "aristas seleccionadas : " << std::endl; 

while (D.numElem() < grafo.numVertices()) {
	v = grafo.primerVertice(); 
	peso_minimo = INFINITY; 
	while (v != verticeNulo) {
		if (D.pertenece(v)) {
			v_ady = grafo.primerVerticeAdy(v); 
			while (v_ady != verticeNulo) {
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
	D.agregar(v_minimo); 
	std::cout << "vertice origen : " << v_padre << " vertice destino : " << v_minimo << " peso : " << peso_minimo << std::endl; 	
}

D.destruir(); 	
}


void Algoritmos_grafo_MA::Kruskal(Grafo_MA&grafo) {
	
	
}





APO::APO() {
	
	
}

void APO::iniciar() {
this->heap_vector = (arista_t*)calloc(LONGITUDAPO, sizeof(int)); 	
this->cantidadNodos = 0; 
this->ultimaPosicion = 1; 
}

void APO::insertar(int vertice_origen, int vertice_destino, int peso) {
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



arista_t* APO::sacar() {
 if (this->cantidadNodos != 0) {
	arista_t* arista = new arista_t(); 
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
		while (!finished) {
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
					else {
						son_selected = pos_s2;  
					}
					
					this->heap_vector[index].vertice_origen = this->heap_vector[son_selected].vertice_origen; 
					this->heap_vector[index].vertice_destino = this->heap_vector[son_selected].vertice_destino; 
					this->heap_vector[index].peso = this->heap_vector[son_selected].peso; 
					index = son_selected; 
				}
				else {
					finished = true; 			//el padre es menor que sus hijos, dejar en esa posicion. 
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
}


string APO::printAPO() {
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

Diccionario::Diccionario() {	
}

void Diccionario::destruir() {
	free(this->vector); 
}


void Diccionario::iniciar() {
	this->vector = (int*)malloc(TAMANYO*sizeof(int)); 
	this->ultimoLleno = 0; 
}

void Diccionario::agregar(int vertice) {
	this->vector[this->ultimoLleno] = vertice; 
	++this->ultimoLleno; 
}

bool Diccionario::pertenece(int vertice) {
	bool found = false; 
	for (int index = 0; index < this->ultimoLleno; ++index) {
		if (this->vector[index] == vertice) {
			found = true; index = this->ultimoLleno; 
		}
	}
	return found; 	
}


int Diccionario::numElem() {
	return this->ultimoLleno; 
}
	
string Diccionario::printD() {
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
	

R11::R11() {
}

void R11::destruir() {
	
	for (int index = 0; index < this->ultimoLleno; ++index) {
		free(this->matrix[index]);
	}
	free(this->matrix);
	
}

void R11::iniciar() {
	this->matrix = (int**)calloc(TAMANYO,sizeof(int*));
	for (int row = 0; row < TAMANYO; ++row) {
		this->matrix[row] = (int*)calloc(2,sizeof(int)); 
	} 
	this->ultimoLleno = 0; 
}


void R11::agregar(int vertice, int indice) {
	if (this->ultimoLleno < TAMANYO) {
		matrix[ultimoLleno][0] = vertice; 
		matrix[ultimoLleno][1] = indice; 
		++this->ultimoLleno; 
	}
	else {
		std::cout << "la R11 ya esta llena, no deberia de meterse mas vectores de los que existen" << std::endl; 
	}
	
}

int R11::indice(int vertice) {
	int index = 0;
	int image = -1; 
	bool found = false;  
	while (index < this->ultimoLleno && !found) {
		if (this->matrix[index][0] == vertice) {
			found = true;
			image = this->matrix[index][1];  
		}
		else {
			index++; 		
		}	
	}
	
	 return image; 
}


int R11::vertice(int indice) {
	int index = 0; 
	bool found = false; 
	int image = -1; 
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

string R11::printR11() {
stringstream ss; 
for (int index = 0; index < this->ultimoLleno; ++index) {
	ss << this->matrix[index][0] << " = " << this->matrix[index][1] << "\n"; 
}

return ss.str(); 	
}


void iniciarM(int** matrix, int rows, int columns) {
	matrix = (int**)malloc(rows*sizeof(int*));
	for (int row = 0; row < rows; ++row) {
		matrix[row] = (int*)malloc(columns*sizeof(int)); 
	} 	
}

void iniciarV(int* vector, int columns) {
	vector = (int*)calloc(columns, sizeof(int)); 	
} 
