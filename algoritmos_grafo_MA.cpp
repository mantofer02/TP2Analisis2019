#include "algoritmos_grafo_MA.h"

Algoritmos_grafo_MA::Algoritmos_grafo_MA() {
	
	
}


void Algoritmos_grafo_MA::Dijkstra(Grafo_MA&grafo, vertice ver, int*VP, int*VVA) {//grafo, vertice, vector peso, vector vertice anterior. 	
	R11<vertice> r11; 
	Diccionario D;
	D.iniciar(); 
	r11.iniciar(); 
	vertice v = grafo.primerVertice();
	int contador_vertice = 0;  
	while (v != verticeNulo) {						//inicializar VP y VVA. 
		if (v != ver) {
			r11.agregar(v,contador_vertice++);
			if (grafo.existeArista(ver, v)) {
				VP[r11.indice(v)] = grafo.peso(ver, v); 
			}
			else {
				VP[r11.indice(v)] = INFINITY;	//infinito
			}
			VVA[r11.indice(v)] = ver; 
		}	
		v = grafo.siguienteVertice(v); 
	} 

	D.agregar(ver); 

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
			if (v_ady != ver) {			//pero no me puedo incluir a mi, porque deporsi no posee un campo en VP. 
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
R11<vertice> r11; 
r11.iniciar(); 
vertice v = grafo.primerVertice(); int contador_vertice = 0; 
while (v != verticeNulo) {
	r11.agregar(v, contador_vertice++); 
	v = grafo.siguienteVertice(v); 
}

for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
	vertice v_x = r11.vertice(index_x); 
	for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
		vertice v_y = r11.vertice(index_y); 
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

void Algoritmos_grafo_MA::Prim(Grafo_MA&grafo, vertice ver) {
Diccionario D; 
D.iniciar(); 	
D.agregar(ver); 
vertice v; 
vertice v_ady; 
int peso_minimo; 				//peso de la arista con menor peso.
vertice v_padre;  					//vertice de origen de dicha arista.
vertice v_minimo;  					//vertice de destino de dicha arista. 


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
CC cc; APO<vertice> apo; 
cc.iniciar(grafo.numVertices());
apo.iniciar();  
vertice v = grafo.primerVertice(); 
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
	arista_t<vertice>* arista = apo.sacar(); 
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
		vertice v = grafo.primerVertice(); 
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


void Algoritmos_grafo_MA::profundidadPrimeroR(Grafo_MA&grafo, vertice ver, Diccionario&D) {
	D.agregar(ver); 
	std::cout << grafo.etiqueta(ver) << std::endl; 
	vertice v_ady = grafo.primerVerticeAdy(ver); 
	while (v_ady != verticeNulo) {
		if (!D.pertenece(v_ady)) {
			profundidadPrimeroR(grafo, v_ady, D); 
		}
		v_ady = grafo.siguienteVerticeAdy(ver, v_ady); 		
	}
}


void Algoritmos_grafo_MA::anchoPrimero(Grafo_MA&grafo) {

 vertice ver = grafo.primerVertice();
 Diccionario D; 
 queue<vertice> C; 
 D.iniciar();  
 while (ver != verticeNulo) {
	 if (!D.pertenece(ver)) {
		C.push(ver); 
		D.agregar(ver); 
		while (!C.empty()) {
			vertice v = C.front(); 
			std::cout << grafo.etiqueta(v) << std::endl; 
			C.pop(); 
			vertice v_ady = grafo.primerVerticeAdy(v);
			while (v_ady != verticeNulo) {
				if (!D.pertenece(v_ady)) {
					C.push(v_ady); 
					D.agregar(v_ady); 
				}
				v_ady = grafo.siguienteVerticeAdy(v,v_ady); 	
			}			
		}
	 }
	 ver = grafo.siguienteVertice(ver); 
 }	
} 


void Algoritmos_grafo_MA::aislarVertice(Grafo_MA&grafo, vertice ver) {
	vertice v_ady = grafo.primerVerticeAdy(ver); 
	while (v_ady != verticeNulo) {
		grafo.eliminarArista(ver, v_ady);
		grafo.eliminarArista(v_ady, ver);		//porque es no dirigido. 
		v_ady = grafo.siguienteVerticeAdy(ver, v_ady);   
	} 	
}


bool is_it_already(std::list<vertice>&L, vertice ver) {
	//buscar si ese vertice ya esta en la lista 
	bool is_there = false; 
	list<vertice>::iterator current_element;
	current_element = L.begin();  
	for (int iteration = 0; iteration < L.size(); ++iteration) {
		if (*current_element == ver) {
			is_there = true; 
			iteration = L.size(); 
		}
		++current_element; 
	}
	return is_there; 	
}


bool Algoritmos_grafo_MA::is_there_cycles(Grafo_MA&grafo) {
 bool is_there = false; 
 
 if (!grafo.vacio()) {
	 vertice v = grafo.primerVertice();
	 Diccionario D; 
	 list<vertice> L; 
	 D.iniciar();  
	 while (v != verticeNulo && !is_there) {
		if (!D.pertenece(v)) {
			is_there_cyclesR(grafo, v, -1,  D, L, is_there); 
		} 
		v = grafo.siguienteVertice(v);  
	 } 	
}
return is_there; 	
}


void showlist(list <vertice>&g) 
{ 
    list <vertice> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
  
void Algoritmos_grafo_MA::is_there_cyclesR(Grafo_MA&grafo, vertice ver, vertice vertice_anterior,  Diccionario&D, std::list<vertice>&L, bool&is_there) {
		D.agregar(ver);
		L.push_back(ver); 
		vertice v_ady = grafo.primerVerticeAdy(ver);
		while (v_ady != verticeNulo && !is_there) {
			if (!D.pertenece(v_ady)) {
				is_there_cyclesR(grafo, v_ady, ver, D, L, is_there);
				L.pop_back();  
			}
			else {
				if (v_ady != vertice_anterior) {	//dado que es grafo no dirigido, siempre va a tener de adyacente de donde vengo, eso no cuenta como ciclo. 
					is_there = is_it_already(L, v_ady); 
				}
				if (is_there) {
					std::cout << "el ciclo se genera del vertice : " << ver << " al vertice : " << v_ady << std::endl; 
					std::cout << "el recorrido que llevaba la recursividad corresponde a : " << std::endl; 
					showlist(L);   
				}
			}
			v_ady = grafo.siguienteVerticeAdy(ver, v_ady); 	
		} 	
}

/*
int best_path = 0; 
int amount_solutions = 0; 
int* sol = NULL; 
Diccionario D; 
*/

void Algoritmos_grafo_MA::CH(Grafo_MA&grafo, Diccionario&D, vertice* Sol, vertice* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones, int indice) {

vertice v = Sol[indice-1]; 
D.agregar(v); 


if (indice == grafo.numVertices()) {		//llegue a una posible solucion factible. 
	if (grafo.existeArista(v,Sol[0])) {		//tengo una solucion factible. 
		++contador_soluciones; 
		costo+= grafo.peso(v,Sol[0]); 
		std::cout << "se encontro una solucion factible" << std::endl; 
		if (costo < mejor_costo) {
			mejor_costo = costo; 
			Sol[indice] = Sol[0];
			for (int index = 0; index <= grafo.numVertices(); ++index) {
				mejor_Sol[index] = Sol[index]; 
			}
		}
		//arrepentimiento 
		costo-= grafo.peso(v, Sol[0]);
	}

}	
else {	
	vertice v_ady = grafo.primerVerticeAdy(v); 
	while (v_ady != verticeNulo) {
		if (!D.pertenece(v_ady)) {
			Sol[indice] = v_ady; 
			costo+= grafo.peso(v,v_ady); 
			CH(grafo, D, Sol, mejor_Sol, costo, mejor_costo, contador_soluciones, indice+1);
			D.pop(); 
			costo-= grafo.peso(v,v_ady);  
		}
		v_ady = grafo.siguienteVerticeAdy(v,v_ady); 
	}
}
	
}


void Algoritmos_grafo_MA::encontrarPuntosArticulacion(Grafo_MA&grafo, vertice*puntos) {
	
	if (!grafo.vacio()) {
		int* orden = (int*)calloc(grafo.numVertices(), sizeof(int)); 
		int* mas_bajo = (int*)calloc(grafo.numVertices(), sizeof(int));
		Diccionario D; 	D.iniciar(); 
		R11<vertice> r11; 	r11.iniciar(); 
		vertice v = grafo.primerVertice();
		int contador_vertice = 0;  
		while (v != verticeNulo) {
			r11.agregar(v, contador_vertice);
			++contador_vertice; 
			v = grafo.siguienteVertice(v);  
		}
		v = grafo.primerVertice(); 
		while (v != verticeNulo) {
			if (!D.pertenece(v)) {
				puntosArticulacion(grafo, D, mas_bajo, orden, r11, puntos,v , 0); 	
			}
			v = grafo.siguienteVertice(v); 
		}
		
		free(orden); 
		free(mas_bajo);  
		D.destruir(); 
		r11.destruir(); 
	}
	else {
		//no hay nada que hacer. 
	}
}

int min(int a, int b) {
	if (a < b) {
		return a; 
	}
	else {
		return b; 
	}
}

void Algoritmos_grafo_MA::puntosArticulacion(Grafo_MA&grafo, Diccionario&D, int*mas_bajo, int*orden, R11<vertice>&r11, vertice*puntos, vertice v, int indice) {
	D.agregar(v); 
	mas_bajo[r11.indice(v)] = indice; 
	orden[r11.indice(v)] = indice; 
	int sons = 0; 
	vertice v_ady = grafo.primerVerticeAdy(v); 
	while (v_ady != verticeNulo) {
		if (!D.pertenece(v_ady)) {
			++sons; 
			puntosArticulacion(grafo, D, mas_bajo, orden, r11, puntos, v_ady, indice+1); 
			if (mas_bajo[r11.indice(v_ady)] >= orden[r11.indice(v)]) {		//encontre un punto de articulacion. 
				puntos[puntos[0]+1] = v;					//..
				++puntos[0];
			}
			mas_bajo[r11.indice(v)] = min(mas_bajo[r11.indice(v)], mas_bajo[r11.indice(v_ady)]); 
		}
		else {	//hay un ciclo. 
			mas_bajo[r11.indice(v)] = min(mas_bajo[r11.indice(v_ady)], orden[r11.indice(v_ady)]);  
		}
		v_ady = grafo.siguienteVerticeAdy(v,v_ady); 
	}
	if (indice == 0 && sons >= 2) {
		puntos[puntos[0]+1] = v;
		++puntos[0];
	}
}


void Algoritmos_grafo_MA::colorear_grafo(Grafo_MA&grafo, CC&mejor_sol, int&colores, int&menor_cantidad, int&contador_soluciones) {
if (!grafo.vacio()) {
	CC ccc; 
	ccc.iniciar(grafo.numVertices()); 
	CC cca; 
	cca.iniciar(grafo.numVertices()); 
	int index_conjunto = 0; 
	while (index_conjunto < grafo.numVertices()) {
		ccc.agregarConjunto(index_conjunto);
		cca.agregarConjunto(index_conjunto); 
		++index_conjunto;  
	}
	
	vertice v = grafo.primerVertice(); 
	int index_v = 0; 
	while (v != verticeNulo) {
		vertice v_ady = grafo.primerVerticeAdy(v); 
		while (v_ady != verticeNulo) {
			cca.agregarAConjunto(index_v, v_ady); 
			v_ady = grafo.siguienteVerticeAdy(v,v_ady); 
		}
		v = grafo.siguienteVertice(v); 
		++index_v;  
	}
	
	v = grafo.primerVertice(); 
	colorear(grafo, mejor_sol,  ccc, cca, v, colores, menor_cantidad, contador_soluciones); 
	/*
	std::cout << "ya se inicializo todo : " << std::endl; 
	std::cout << "imprimiendo la picha : " << std::endl; 
	std::cout << ccc.printCC() << std::endl; 
	std::cout << "-------------" << std::endl; 
	std::cout << cca.printCC() << std::endl; 
	*/
}
//else no hay nada que hacer. 
}


void Algoritmos_grafo_MA::colorear(Grafo_MA&grafo, CC&mejor_sol, CC&ccc, CC&cca, vertice v, int&colores, int&menor_cantidad, int&contador_soluciones){

 if (v == verticeNulo) {
	 ++contador_soluciones; 
	 if (colores < menor_cantidad) {
		 menor_cantidad = colores;
		 std::cout << "encontre una solucion factible " << std::endl;  
		 std::cout << ccc.printCC() << std::endl; 
		 //copiar todo lo de ccc a mejor_sol; 
	 }
 }
 
 int index = 0; 
 while (index < grafo.numVertices() && colores < menor_cantidad) {
	 int conjunto_c = ccc.obtConjunto(index); 		//deme el conjunto del color index. 
	 int conjunto_a = cca.obtConjunto(v);			//deme el conjunto que corresponde a ese vertice. 
	 if (!ccc.existeInterseccion(conjunto_c, cca, conjunto_a)) {		//si entre mis adyacentes no hay ninguno con el color index. 
		 ccc.agregarAConjunto(v, index); 
		 bool new_color = false; 
		 if (index <=menor_cantidad) {				//si se esta llegando a un nuevo ciclo del while osea se esta seleccionando un nuevo color. 
			 ++colores; 
			 new_color = true; 
		 }
		 colorear(grafo, mejor_sol, ccc, cca, grafo.siguienteVertice(v), colores, menor_cantidad, contador_soluciones);
		 //arrepentimiento. 
		 ccc.sacarDeConjunto(index, v);
		 if (new_color) {
			 --colores; new_color = false; 
		 }   
	 } 
	++index;  
 }	
 	
	
}

			
CC::CC() {
	
}


bool CC::existeInterseccion(int conjunto, CC&cc_1, int conjunto_cc1) {
	bool exist = false; 
	for (int index = 1; index <= this->cc[conjunto][0]; ++index) {
		for (int index_cc = 1; index_cc <= cc_1.cc[conjunto_cc1][0]; ++index_cc) {
			if (this->cc[conjunto][index] == cc_1.cc[conjunto_cc1][index_cc]) {
				exist = true; index_cc = cc_1.cc[conjunto_cc1][0]+1; 
				index = this->cc[conjunto][0]+1; 
			}
		}
	}
	return exist; 	
}


void CC::sacarDeConjunto(int conjunto, int vertice) {
	--this->cc[conjunto][0]; 
}

int CC::obtConjunto(int index) {
	return index; 
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
	//this->cc[conjunto][this->amount_c-1] = 0; 
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

void Diccionario::pop() {
	--this->ultimoLleno; 
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
	

void iniciarM(int** matrix, int rows, int columns) {
	matrix = (int**)malloc(rows*sizeof(int*));
	for (int row = 0; row < rows; ++row) {
		matrix[row] = (int*)malloc(columns*sizeof(int)); 
	} 	
}

void iniciarV(int* vector, int columns) {
	vector = (int*)calloc(columns, sizeof(int)); 	
} 
