#include "algoritmos_grafo_MA.h"

Algoritmos_grafo_MA::Algoritmos_grafo_MA() {
	
	
}


void Algoritmos_grafo_MA::Dijkstra(Grafo_MA&grafo, int vertice, int*VP, int*VVA) {//grafo, vertice, vector peso, vector vertice anterior. 	
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
CC cc; APO<int> apo; 
cc.iniciar(grafo.numVertices());
apo.iniciar();  
int v = grafo.primerVertice(); 
int index_conjunto = 0; 
while (v != verticeNulo) {
	cc.agregarConjunto(index_conjunto);
	cc.agregarAConjunto(v, index_conjunto);
	
	int v_ady = grafo.primerVerticeAdy(v);
	while (v_ady != verticeNulo) {
		apo.insertar(v,v_ady, grafo.peso(v, v_ady));
		v_ady = grafo.siguienteVerticeAdy(v,v_ady);  	
	}
		 
	++index_conjunto; 
	v = grafo.siguienteVertice(v); 
	 	
}

#if 0
std::cout << "imprimiendo CC : " << std::endl; 
std::cout << cc.printCC() << std::endl; 
std::cout << "imprimiendo APO : " << std::endl; 
std::cout << apo.printAPO() << std::endl; 
#endif 


int aristas_escogidas = 0; 
std::cout << "aristas seleccionadas : " << std::endl; 
while (aristas_escogidas < grafo.numVertices()-1) {		//se necesitan seleccionar n-1 aristas / n = cantidad de vertices. 
	arista_t<int>* arista = apo.sacar(); 
		if (arista != NULL) { 
		int conjunto_1 = cc.conjuntoAlQuePertenece(arista->vertice_origen);
		int conjunto_2 = cc.conjuntoAlQuePertenece(arista->vertice_destino); 
		if (conjunto_1 != conjunto_2) {
			++aristas_escogidas; 
			cc.unir(conjunto_1, conjunto_2);
			std::cout << "vertice origen : " << arista->vertice_origen << " vertice destino : " << arista->vertice_destino << " peso : " << arista->peso << std::endl; 
		}
		else {
			//esa arista genera ciclo, por lo tanto no sirve, seguir buscando. 
		} 
	}
	else {
		std::cout << "algo salio mal" << std::endl; 
	}
} 
}



void Algoritmos_grafo_MA::profundidadPrimero(Grafo_MA&grafo) {
	if (!grafo.vacio()) {
		Diccionario D; 
		D.iniciar(); 
		int v = grafo.primerVertice(); 
		while (v != verticeNulo) {
			if (!D.pertenece(v)) {
				profundidadPrimeroR(grafo, v, D); 
			}
			v = grafo.siguienteVertice(v); 
		}
		D.destruir(); 
	}
	else {
		std::cout << "el grafo esta vacio " << std::endl; 
	}
}


void Algoritmos_grafo_MA::profundidadPrimeroR(Grafo_MA&grafo, int vertice, Diccionario&D) {
	D.agregar(vertice); 
	std::cout << grafo.etiqueta(vertice) << std::endl; 
	int v_ady = grafo.primerVerticeAdy(vertice); 
	while (v_ady != verticeNulo) {
		if (!D.pertenece(v_ady)) {
			profundidadPrimeroR(grafo, v_ady, D); 
		}
		v_ady = grafo.siguienteVerticeAdy(vertice, v_ady); 		
	}
}


void Algoritmos_grafo_MA::anchoPrimero(Grafo_MA&grafo) {

 int vertice = grafo.primerVertice();
 Diccionario D; 
 queue<int> C; 
 D.iniciar();  
 while (vertice != verticeNulo) {
	 if (!D.pertenece(vertice)) {
		C.push(vertice); 
		D.agregar(vertice); 
		while (!C.empty()) {
			int v = C.front(); 
			std::cout << grafo.etiqueta(v) << std::endl; 
			C.pop(); 
			int v_ady = grafo.primerVerticeAdy(v);
			while (v_ady != verticeNulo) {
				if (!D.pertenece(v_ady)) {
					C.push(v_ady); 
					D.agregar(v_ady); 
				}
				v_ady = grafo.siguienteVerticeAdy(v,v_ady); 	
			}			
		}
	 }
	 vertice = grafo.siguienteVertice(vertice); 
 }	
} 


void Algoritmos_grafo_MA::aislarVertice(Grafo_MA&grafo, int vertice) {
	int v_ady = grafo.primerVerticeAdy(vertice); 
	while (v_ady != verticeNulo) {
		grafo.eliminarArista(vertice, v_ady);
		grafo.eliminarArista(v_ady, vertice);		//porque es no dirigido. 
		v_ady = grafo.siguienteVerticeAdy(vertice, v_ady);   
	} 	
}


bool is_it_already(std::list<int>&L, int vertice) {
	//buscar si ese vertice ya esta en la lista 
	bool is_there = false; 
	
	return is_there; 	
}


bool Algoritmos_grafo_MA::is_there_cycles(Grafo_MA&grafo) {
 bool is_there = false; 
 
 if (!grafo.vacio()) {
	 int v = grafo.primerVertice();
	 Diccionario D; 
	 list<int> L; 
	 D.iniciar();  
	 while (v != verticeNulo && !is_there) {
		if (!D.pertenece(v)) {
			is_there_cyclesR(grafo, v, D, L, is_there); 
		} 
		v = grafo.siguienteVertice(v);  
	 } 	
}
return is_there; 	
}


void Algoritmos_grafo_MA::is_there_cyclesR(Grafo_MA&grafo, int vertice, Diccionario&D, std::list<int>&L, bool&is_there) {
		D.agregar(vertice);
		L.push_back(vertice); 
		int v_ady = grafo.primerVerticeAdy(vertice);
		while (v_ady != verticeNulo && !is_there) {
			if (!D.pertenece(v_ady)) {
				is_there_cyclesR(grafo, v_ady, D, L, is_there);
				L.pop_back();  
			}
			else {		//tengo que revisar si se genera ciclo. 
				is_there = is_it_already(L, v_ady); 
			}
			v_ady = grafo.siguienteVerticeAdy(vertice, v_ady); 	
		} 
	
	

	
}




CC::CC() {
	
}


void CC::iniciar(int max_amount_elements) {
	this->cc = (int**)calloc(max_amount_elements, sizeof(int*));
	for (int conjunto = 0; conjunto < max_amount_elements; ++conjunto) {
		this->cc[conjunto] = (int*)calloc(max_amount_elements+1, sizeof(int)); 	//la posicion 0 va a decir cuantos elementos posee a partir del 1. 
	}																			//por eso una columna mas que filas. 		
	this->amount_c = 0;   																			
}


void CC::agregarConjunto(int conjunto) {
	++this->amount_c; 	
	this->cc[conjunto][this->amount_c-1] = 0; 
}

void CC::agregarAConjunto(int vertice, int conjunto) {
	if (conjunto < this->amount_c) {
		++this->cc[conjunto][0]; 
		this->cc[conjunto][this->cc[conjunto][0]] = vertice; 
	}
	else {
		std::cout << "se quiere añadir a un conjunto que no existe" << std::endl; 
	}	
}

int CC::conjuntoAlQuePertenece(int vertice) {
	int conjunto = -1; 
	bool found = false; 
	for (int c = 0; c < this->amount_c; ++c) {			//conjunto
		for (int v = 1; v <= this->cc[c][0]; ++v) {		//vertice
			if (this->cc[c][v] == vertice) {
				conjunto = c; 
				v = (this->cc[c][0]+1); 
			}
		}
		if (found) {
			c = this->amount_c;	
		}				
	}
	return conjunto; 
}


void CC::unir(int conjunto_1, int conjunto_2) {
	if (conjunto_2 < conjunto_1) {
		int aux = conjunto_1; 
		conjunto_1 = conjunto_2; 
		conjunto_2 = aux; 
	}		//conjunto_1 tiene que ser menor a conjunto_2
	
	for (int vertice = 1; vertice <= this->cc[conjunto_2][0]; ++vertice) {
		agregarAConjunto(this->cc[conjunto_2][vertice], conjunto_1); 	
	}
	this->cc[conjunto_2][0] = 0; 
	
	int last_conjunto = this->amount_c-1; 
	
	for (int vertice = 1; vertice <= this->cc[last_conjunto][0]; ++vertice) {
		agregarAConjunto(this->cc[last_conjunto][vertice], conjunto_2); 		
	} 
--this->amount_c; 			
}


string CC::printCC() {
stringstream ss; 	

for (int conjunto = 0; conjunto < this->amount_c; ++conjunto) {
	for (int vertice = 1; vertice <= this->cc[conjunto][0]; ++vertice) {
		if (vertice != this->cc[conjunto][0]) {
			ss << this->cc[conjunto][vertice] << ", "; 
		}
		else {
			ss << this->cc[conjunto][vertice]; 
		}
	}
	ss << "\n"; 
}	
	
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
