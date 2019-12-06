#include "algoritmos_grafo.h"

Algoritmos_grafo::Algoritmos_grafo() {	
}

/*
Requiere :  Un grafo inicializado; Un vertice de salida del grafo; un vector de vertice adyacente que venga inicializado desde afuera
Efecto : Calcula el recorrido minimo de un vertice inicial al resto de los vertices del grafo
Modifica : Modifica el valor de los pesos dentro del vector de vertice
*/
void Algoritmos_grafo::Dijkstra(Grafo &grafo, vertice ver, int*VP, vertice*VVA){//grafo, vertice, vector peso, vector vertice anterior. 	
	R11<vertice> r11; 
	Diccionario<vertice> D;
	D.iniciar(); 
	r11.iniciar(); 
	vertice v = grafo.primerVertice();
	int contador_vertice = 0;  
	while (!(grafo.esVerticeNulo(v))) {						//inicializar VP y VVA. 
            if (v != ver){
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
		// std :: cout << D.numElem() << std :: endl;
        menor = -1; peso_menor = INFINITY; contador = 0; 
		while (contador < grafo.numVertices()-1) {	//la longitud de VP. 
			if (VP[contador] <= peso_menor && !D.pertenece(r11.vertice(contador))) {	//si es el menor pero no es un pivote anterior o el vertice de parametro. 
				menor = contador;
				peso_menor = VP[contador]; 
			}
			contador++; 
		}
		vertice v = r11.vertice(menor);	//pivote. 
		D.agregar(v);
		vertice v_ady = grafo.primerVerticeAdy(v); 
		while (!(grafo.esVerticeNulo(v_ady))) {		//se recorren todos los adyacentes.
			if (v_ady != ver){			//pero no me puedo incluir a mi, porque deporsi no posee un campo en VP. 
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



/*
Requiere : Un algoritmo inicializado; una matriz de recorridos; una matriz de pesos de vectores
Efecto : Asigna valores a las matrices de recorridos y de costos
Modifica : Las matrices de pesos y recorridos mediante la informacion del grafo 
*/
void Algoritmos_grafo :: Floyd(Grafo &grafo, int** MP, vertice** MVI) {
	R11<vertice> r11; 
	r11.iniciar(); 
	vertice v = grafo.primerVertice(); int contador_vertice = 0; 
	while (!grafo.esVerticeNulo(v)) {
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
					MVI[index_x][index_y] = grafo.getVerticeNulo();  		
				}
				else {
					MP[index_x][index_y] = INFINITY; 
					MVI[index_x][index_y] = grafo.getVerticeNulo(); 
				} 		
				
			}
			else {	//son los mismos.
				MP[index_x][index_y] = 0; 
				MVI[index_x][index_y] = grafo.getVerticeNulo(); 
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


/*
Requiere : Un grafo inicializado; un vertice de salida
Efecto : Calcula el arbol de minimo costo de un grafo
Modifica : Los valores de las estructuras auxiliares para calcular el arbol de minimo costo
*/
void Algoritmos_grafo::Prim(Grafo&grafo, vertice ver) {			//ESTE ALGORITMO VA IMPRIMIENDO, SE LE PODRIA PONER UN BOOL, PARA QUE IMPRIMA DE FORMAS 
	Diccionario<vertice> D; 												//DIFERENTES. 	
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
		while (!grafo.esVerticeNulo(v)) {
			if (D.pertenece(v)) {
				v_ady = grafo.primerVerticeAdy(v); 
				while (!grafo.esVerticeNulo(v_ady)) {
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
		D.agregar(v_minimo); 													//PORQUE AQUI YO IMPRIMO MI VERTICE COMO SI NADA, PERO PARA LA LISTA NO
		std::cout << "vertice origen : " << v_padre << " vertice destino : " << v_minimo << " peso : " << peso_minimo << std::endl; 	
	}																			//AMENOS QUE SE SOBRECARGUE EL OPERADOR PARA QUE SE PUEDA IMPRIMIR EL OBJETO. 			
																				//COMO UN TIPO TOSTRING DE JAVA. 
	D.destruir(); 	
}

/*
Requiere : Un grafo ya inicializado
Efecto : Calcula el arbol de minimo costo
Modifica : EL valor de las estructuras auxiliares para calcular el arbol de minimo costo
*/
void Algoritmos_grafo::Kruskal(Grafo&grafo) {								//LA MISMA COSA DE PRIM, AQUI SE VA IMPRIMIENDO. 
	CC<vertice> cc; APO<vertice> apo; 												//O SE PODRIA METER LOS RESUTLADOS EN ALGUN LADO Y QUE LOS RETORNE. 
	cc.iniciar(grafo.numVertices());												//YA AHI CADA QUIEN QUE IMPRIMA COMO QUIERA. 
	apo.iniciar();  
	vertice v = grafo.primerVertice(); 
	int index_conjunto = 0; 
	while (!grafo.esVerticeNulo(v)) {
		cc.agregarConjunto(index_conjunto);
		cc.agregarAConjunto(v, index_conjunto);
		
		vertice v_ady = grafo.primerVerticeAdy(v);
		while (!grafo.esVerticeNulo(v_ady)) {
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


/*
Requiere : Um grafo ya inicializado con vertices
Efecto : Genera un etiquetado y recorrido mediante adyacencia del grafo
Modifica : Las estructura auxiliares para mostrar el recorrido de adyacencia
*/
void Algoritmos_grafo::profundidadPrimero(Grafo&grafo) {
	if (!grafo.vacia()){
		Diccionario<vertice> D; 
		D.iniciar(); 
		vertice v = grafo.primerVertice(); 
		while (!grafo.esVerticeNulo(v)) {
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


void Algoritmos_grafo::profundidadPrimeroR(Grafo&grafo, vertice ver, Diccionario<vertice>&D) {
	D.agregar(ver); 
	// std::cout << grafo.etiqueta(ver) << std::endl; 
	vertice v_ady = grafo.primerVerticeAdy(ver); 
	while (!grafo.esVerticeNulo(v_ady)) {
		if (!D.pertenece(v_ady)) {
			profundidadPrimeroR(grafo, v_ady, D); 
		}
		v_ady = grafo.siguienteVerticeAdy(ver, v_ady); 		
	}
}

/*
Requiere : Un grafo ya inicializado con vertices
Efecto : Recorre el grafo recursivamente mediante los vecinos del vertice actual
Modifica : Las estructuras auxiliares para mostrar el recorrido del grafo
*/
void Algoritmos_grafo::anchoPrimero(Grafo&grafo) {
	vertice ver = grafo.primerVertice();
	Diccionario<vertice> D; 
	queue<vertice> C; 
	D.iniciar();  
	while (!grafo.esVerticeNulo(ver)) {
		if(!D.pertenece(ver)) {
			C.push(ver); 
			D.agregar(ver); 
			while (!C.empty()) {
				vertice v = C.front(); 
				// std::cout << grafo.etiqueta(v) << std::endl; 
				C.pop(); 
				vertice v_ady = grafo.primerVerticeAdy(v);
				while (!grafo.esVerticeNulo(v_ady)) {
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

/*
Requiere : Un grafo ya inicializado; un vertice especifico no nulo que se desea aislar.
Efecto : Elimina las arista de salida y llegada del vertice seleccionado.
Modifica : Las aristas de llegada y salida del vertice.
*/
void Algoritmos_grafo::aislarVertice(Grafo&grafo, vertice ver) {
	vertice v_ady = grafo.primerVerticeAdy(ver); 
	while (!grafo.esVerticeNulo(v_ady)) {
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

/*
Requiere : Un grafo inicializado
Efecto : Calcula si el grafo enviado por parametro posee lazos 
Modifica : Las variables locales para identificar si hay lazos dentro del arbol
*/
bool Algoritmos_grafo::is_there_cycles(Grafo&grafo) {
	bool is_there = false; 
 
	 if (!grafo.vacia()) {
		 vertice v = grafo.primerVertice();
		 Diccionario<vertice> D; 
	 	list<vertice> L; 
	 	D.iniciar();  
	 	while (!grafo.esVerticeNulo(v) && !is_there) {
			if (!D.pertenece(v)) {
				is_there_cyclesR(grafo, v, -1,  D, L, is_there); 
			} 
			v = grafo.siguienteVertice(v);  
	 	} 	
	}
	return is_there; 	
}


void showlist(list <vertice>&g){ 
    list <vertice> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

			//AQUI ES EL MISMO PROBLEMA DE PRIM Y KRUSKAL, SE VA IMPRIMIENDO. LO MISMO QUE DIJE ARRIBA. 
void Algoritmos_grafo::is_there_cyclesR(Grafo&grafo, vertice ver, vertice vertice_anterior,  Diccionario<vertice>&D, std::list<vertice>&L, bool&is_there) {
	D.agregar(ver);
	L.push_back(ver); 
	vertice v_ady = grafo.primerVerticeAdy(ver);
	while (!grafo.esVerticeNulo(v_ady) && !is_there) {
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
Requiere : Un grafo ya inicializado; Un diccionario de vertices inicializado; Variables externas que permitan identificar las mejores soluciones posibles
Efecto : Calcula si el grafo posee un Circuito de hamilton; y de ser asi, calcula el circuito el circuito de menot costo que forme el grafo. 
Modifica : Modifica las estructuras auxliares y mediante la aplicacion de exhaustiva pura se busca el CH de menor costo.
*/
void Algoritmos_grafo::CH(Grafo&grafo, Diccionario<vertice>&D, vertice* Sol, vertice* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones,  int indice) {
	D.agregar(Sol[indice-1]); 
	vertice v_ady = grafo.primerVerticeAdy(Sol[indice-1]); 
	while (!grafo.esVerticeNulo(v_ady)) {
		if (!D.pertenece(v_ady)) {
			costo+= grafo.peso(Sol[indice-1], v_ady); 
			Sol[indice] = v_ady; 
			if (indice == grafo.numVertices()-1) {
				if (grafo.existeArista(v_ady, Sol[0])) {
					++contador_soluciones; 
					costo+=  grafo.peso(v_ady, Sol[0]); 
					if (costo < mejor_costo) {
						mejor_costo = costo; 
						std::cout << "se encontro una solucion factible" << std::endl; 
						for (int index = 0; index < grafo.numVertices(); ++index) {
							mejor_Sol[index] = Sol[index]; 
						}
						costo-= grafo.peso(v_ady, Sol[0]); 
					}
				}
				else {
					CH(grafo, D, Sol, mejor_Sol, costo, mejor_costo, contador_soluciones, indice); 
					D.pop(); 
				}
				//arrepentimiento. 
				costo-= grafo.peso(Sol[indice-1], v_ady); 
			} 
		} 
		v_ady = grafo.siguienteVerticeAdy(Sol[indice-1], v_ady); 
	}
}



#if 0 
void Algoritmos_grafo::CH(Grafo&grafo, Diccionario<vertice>&D, vertice* Sol, vertice* mejor_Sol, int&costo, int&mejor_costo, int&contador_soluciones, int indice) {

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
	while (!grafo.esVerticeNulo(v_ady)) {
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

#endif 


/*
Requiere : Un grafo ya inicializado; Un puntero de vertices que permita determinar los puntos de articulacion
Efecto : Calcula los puntos de articulacion de un grafo, los cuales son los vertices que si no existerian el grafo no estaria conectado 
Modifica : Modifica las estructuras aledañas para generar un bosque abarcador y encontrar los vertices que forman puntos de articulacion
*/
void Algoritmos_grafo::encontrarPuntosArticulacion(Grafo&grafo, vertice*puntos, int&contador_puntos) {
	
	if (!grafo.vacia()) {
		int* orden = (int*)calloc(grafo.numVertices(), sizeof(int)); 
		int* mas_bajo = (int*)calloc(grafo.numVertices(), sizeof(int));
		Diccionario<vertice> D; 	D.iniciar(); 
		R11<vertice> r11; 	r11.iniciar(); 
		vertice v = grafo.primerVertice();
		int contador_vertice = 0;  
		while (!grafo.esVerticeNulo(v)) {
			r11.agregar(v, contador_vertice);
			++contador_vertice; 
			v = grafo.siguienteVertice(v);  
		}
		v = grafo.primerVertice(); 
		while (!grafo.esVerticeNulo(v)) {
			if (!D.pertenece(v)) {
				puntosArticulacion(grafo, D, mas_bajo, orden, r11, puntos,v , 0, contador_puntos); 	
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



void Algoritmos_grafo::puntosArticulacion(Grafo&grafo, Diccionario<vertice>&D, int*mas_bajo, int*orden, R11<vertice>&r11, vertice*puntos, vertice v, int indice, int&contador_puntos) {
	D.agregar(v); 
	mas_bajo[r11.indice(v)] = indice; 
	orden[r11.indice(v)] = indice; 
	int sons = 0; 
	vertice v_ady = grafo.primerVerticeAdy(v); 
	while (!grafo.esVerticeNulo(v_ady)) {
		if (!D.pertenece(v_ady)) {
			++sons; 
			puntosArticulacion(grafo, D, mas_bajo, orden, r11, puntos, v_ady, indice+1, contador_puntos); 
			if (mas_bajo[r11.indice(v_ady)] >= orden[r11.indice(v)]) {		//encontre un punto de articulacion. 
				puntos[contador_puntos] = v;								
				++contador_puntos; 
			}
			mas_bajo[r11.indice(v)] = min(mas_bajo[r11.indice(v)], mas_bajo[r11.indice(v_ady)]); 
		}
		else {	//hay un ciclo. 
			mas_bajo[r11.indice(v)] = min(mas_bajo[r11.indice(v_ady)], orden[r11.indice(v_ady)]);  
		}
		v_ady = grafo.siguienteVerticeAdy(v,v_ady); 
	}
	if (indice == 0 && sons >= 2) {
		//ESTO
		puntos[contador_puntos + 1] = v;
		++contador_puntos; 
	}
}

/*
Requiere : Un grafo ya inicializado; un conjunto de conjuntos ya inicializado; un set de colores. 
Efecto : Colorea el grafo de tal manera que 2 vertices adyacentes no tengan el mismo color.
Modifica : Las estructuras aledañas para colorear el grafo.
*/
void Algoritmos_grafo::colorear_grafo(Grafo&grafo, CC<vertice>&mejor_sol, int&colores, int&menor_cantidad, int&contador_soluciones, bool&found) {
	if (!grafo.vacia()){
		CC<vertice> ccc; 
		ccc.iniciar(grafo.numVertices()); 
		CC<vertice> cca; 
		cca.iniciar(grafo.numVertices());
		R11<vertice> r11;
		r11.iniciar(); 
		
		int index_conjunto = 0; 
		
		while (index_conjunto < grafo.numVertices()) {
			ccc.agregarConjunto(index_conjunto);
			cca.agregarConjunto(index_conjunto); 
			++index_conjunto;  
		}
		
		vertice v = grafo.primerVertice(); 
		
		int index_v = 0; 
		
		while (!grafo.esVerticeNulo(v)) {
			r11.agregar(v, index_v);
			vertice v_ady = grafo.primerVerticeAdy(v); 
			while (!grafo.esVerticeNulo(v_ady)) {
				cca.agregarAConjunto(v_ady, index_v); 
				v_ady = grafo.siguienteVerticeAdy(v,v_ady); 
			}
			v = grafo.siguienteVertice(v); 
			++index_v; 
			
		}
		
		v = grafo.primerVertice(); 
		colorear(grafo, mejor_sol,  ccc, cca, v, colores, menor_cantidad, contador_soluciones, r11, found); 
		
	}
//else no hay nada que hacer. 
}

void Algoritmos_grafo::colorear(Grafo&grafo, CC<vertice>&mejor_sol, CC<vertice>&ccc, CC<vertice>&cca, vertice v, int&colores, int&menor_cantidad, int&contador_soluciones, R11<vertice>&r11, bool&found){

	if (grafo.esVerticeNulo(v)) {
		++contador_soluciones; 
		if (colores < menor_cantidad) {
			menor_cantidad = colores;
			found = true; 
			ccc.moveData(mejor_sol); 	//mueve la solucion actual a la mejor solucion. 
		}
	}
	
	int index = 0; 
	while (index < grafo.numVertices() && colores < menor_cantidad) {
		int conjunto_c = ccc.obtConjunto(index); 		//deme el conjunto del color index. 
		int conjunto_a = cca.obtConjunto(r11.indice(v));			//deme el conjunto que corresponde a ese vertice. 
		if (!ccc.existeInterseccion(conjunto_c, cca, conjunto_a)) {		//si entre mis adyacentes no hay ninguno con el color index. 
			ccc.agregarAConjunto(v, index); 
			bool new_color = false; 
			if (index >=menor_cantidad) {				//si se esta llegando a un nuevo ciclo del while osea se esta seleccionando un nuevo color. 
				++colores; 
				new_color = true; 
			}
			colorear(grafo, mejor_sol, ccc, cca, grafo.siguienteVertice(v), colores, menor_cantidad, contador_soluciones, r11, found);
			ccc.sacarDeConjunto(index, v);
			if (new_color) {
				--colores; new_color = false; 
			}   
		} 
		++index;  
	}		
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

/*
Requiere : Un grafo inicializado. 
Efecto : Calcula si en el grafo es posible llegar a cualquier vertice desde el mismo de salida.
Modifica : El valor booleano identificando si es cierto o no.
*/
bool Algoritmos_grafo::existeCaminoEntreTodoParDeVertices(Grafo&grafo) {

	bool existe = false; 
	Diccionario<vertice> D;
	D.iniciar(); 
	vertice v = grafo.primerVertice(); 
	recorrer(grafo, v, D);  

	if (D.numElem() == grafo.numVertices()) {
		existe = true; 
	}
	return existe; 
}

/*
Requiere : Un grafo ya inicializado; un vertice de salida.
Efecto : Recorre el grafo de forma arbitraria
Modifica : N/A
*/
void Algoritmos_grafo::recorrer(Grafo&grafo, vertice ver, Diccionario<vertice>&D) {
	D.agregar(ver); 
	vertice v_ady = grafo.primerVerticeAdy(ver); 
	while (!grafo.esVerticeNulo(v_ady)) {
		if (!D.pertenece(v_ady)) {
			recorrer(grafo, v_ady, D);	
		} 
		v_ady = grafo.siguienteVerticeAdy(ver, v_ady);
	} 
}
