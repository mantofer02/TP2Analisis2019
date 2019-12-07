#include "interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz(){
	std::cout << "Antes de Comenzar debe recordar Iniciar el grafo y saber que las etiquetas y pesos son numeros enteros" << std::endl; 
	//seria bueno poner aquí un timer, para que esto se pueda leer. 
	
    desplegarMenu();
}

Interfaz::~Interfaz(){
    
}

void Interfaz::desplegarMenu(){
    cout << "Bienvenido al programa de grafos. Digite los dígitos correspondientes a los operadores básicos  o algoritmos que desea usar:\n" << endl;

	std::cout << "-------------------------------------" << std::endl; 
	std::cout << "------------OB------------------" << std::endl; 
	std::cout << "-------------------------------------" << std::endl; 
	std::cout << "Digite :" << std::endl;
    std::cout << "1: Iniciar" << std::endl;
    std::cout << "2: Destruir" << std::endl;
    std::cout << "3: Vaciar" << std::endl;
	std::cout << "4: Agregar Vertice" << std::endl;
	std::cout << "5: Eliminar Vertice" << std::endl;
    std::cout << "6: Modificar Etiqueta" << std::endl;
    std::cout << "7: Etiqueta" << std::endl;				//REVISA PARA L.A
    std::cout << "8: AgregarArista" << std::endl;
    std::cout << "9: Eliminar Arista" << std::endl;
	std::cout << "10: Modificar Peso" << std::endl;
	std::cout << "11: Peso" << std::endl;
	std::cout << "12: Primer Vertice" << std::endl;
    std::cout << "13: Siguiente Vertice" << std::endl;
	std::cout << "14: Primer Vertice Ady" << std::endl;
    std::cout << "15: Siguiente Vertice Ady" << std::endl;
    std::cout << "16: Existe Arista" << std::endl;
    std::cout << "17: Numero de Aristas" << std::endl;
    std::cout << "18: Numero de Vertices" << std::endl;
	std::cout << "19: Numero de Vertices Ady" << std::endl;
	
	std::cout << "------------------------------------------------" << std::endl; 
	std::cout << "------------------Algoritmos------------------" << std::endl;  
	std::cout << "------------------------------------------------" << std::endl; 
	
    std::cout << "20: Recorrido Ancho Primero" << std::endl;
    std::cout << "21: Recorrido Profundodad Primero" << std::endl;
    std::cout << "22: Averiguar si el grafo posee ciclos" << std::endl;
    std::cout << "23: Dijkstra" << std::endl;
	std::cout << "24: Floyd" << std::endl;
	std::cout << "25: Encontrar Circuito Hamilton de menor costo" << std::endl;
	std::cout << "26: Colorear el grafo" << std::endl;
    std::cout << "27: Prim" << std::endl;
	std::cout << "28: Kruskal" << std::endl;    
    std::cout << "29: Componentes Conexos(NA)" << std::endl;
    std::cout << "30: Aislar un vertice" << std::endl;
    std::cout << "31: Encontrar Puntos de Articulacion" << std::endl;
    std::cout << "32: Averiguar si existe camino entre todo par de vertices" << std::endl;
    std::cout << "-----------------------------------" << std::endl; 
    std::cout << "33: Salir" << std::endl; 
    std::cout << "-----------------------------------" << std::endl; 
    
    int decision = 0;
    if(!(cin >> decision)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
        desplegarMenu();
    }
    else{
        if(0 < decision || decision < 33){
            if(decision == 1){
                grafo.iniciar();
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 2){
                grafo.destruir();
                cout << "El grafo fue destruido exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 3){
                grafo.vaciar();
                cout << "El grafo fue vaciado exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 4){
                ETIQUETA etiqueta; 
                cout << "Ingrese la etiqueta del nuevo vertice." << endl;
                cin >> etiqueta;
                grafo.agregarVertice(etiqueta);
                cout << "El vertice con etiqueta "<< etiqueta <<" fue agregado exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 5){
                ETIQUETA etiqueta; 
                cout << "Ingrese la etiqueta del vertice a eliminar." << endl;
                cin >> etiqueta;
                vertice ver = grafo.getVertice(etiqueta); 
                if (!grafo.esVerticeNulo(ver)) {
					grafo.eliminarVertice(ver);
					cout << "El vertice con etiqueta "<< etiqueta <<" fue eliminado exitosamente." << endl;
				}
				else {
					std::cout << "el vertice que desea eliminar del grafo no existe" << std::endl; 
				}
                desplegarMenu();
            }
            if(decision == 6){
                ETIQUETA etiqueta; 
                ETIQUETA nuevaEtiqueta;
                cout << "Ingrese la etiqueta del vertice a cambiar(debe ser valido en el grafo)." << endl;
                cin >> etiqueta;
                vertice ver = grafo.getVertice(etiqueta); 
                if (!grafo.esVerticeNulo(ver)) {
					cout << "Ingrese la nueva eiqueta del vertice." << endl;
					cin >> nuevaEtiqueta;
					grafo.modificarEtiqueta(ver, nuevaEtiqueta);
					cout << "La etiqueta fue modificada exitosamente." << endl;
				}
				else {
					std::cout << "la etiqueta ingresada no corresponde a ningun vertice" << std::endl; 
				} 
                desplegarMenu();
            }
            if(decision == 7){
                vertice ver;
                int number = 0;     
                cout << "Ingrese el numero del vertice que desea conocer la etiqueta." << endl;
                if(!(cin >> number)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    ETIQUETA etiquetaRetornada = grafo.etiqueta(ver);
                    if(etiquetaRetornada != ""){
                        cout << "La etiqueta correspondiente al vértice ingresado es " << etiquetaRetornada <<endl;
                    }
                    else{                      
                        cout << "El vertice ingresado no existe en el grafo." << endl;
                    }
                    
                }
                desplegarMenu();
            }
            if(decision == 8){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = ""; 
                ETIQUETA etiqueta2 = ""; 
                int peso = 0;                
                cout << "Ingrese la etiqueta del primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese la etiqueta del segundo vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        cout << "Ingrese el peso de la arista." << endl;
                        if(!(cin >> peso)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                        }
                        else{
							
							vertice1 = grafo.getVertice(etiqueta1); 
							vertice2 = grafo.getVertice(etiqueta2); 
							if (!grafo.esVerticeNulo(vertice1) && !grafo.esVerticeNulo(vertice2)) {								
								grafo.agregarArista(vertice1, vertice2, peso);
							}     
                        }
                    }    
                }
                desplegarMenu();
            }
            if(decision == 9){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = ""; 
                ETIQUETA etiqueta2 = ""; 
                
                cout << "Ingrese la etiqueta primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese la etiqueta del segundo vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
						
						vertice1 = grafo.getVertice(etiqueta1); 
						vertice2 = grafo.getVertice(etiqueta2); 
						
						if (!grafo.esVerticeNulo(vertice1) && !grafo.esVerticeNulo(vertice2)) {
							grafo.eliminarArista(vertice1, vertice2);
						}
						else {
							std::cout << "los datos ingresados son invalidos, por favor intente de nuevo" << std::endl; 
						}
                    }
                }    
                desplegarMenu();
            }
            if(decision == 10){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = "";
                ETIQUETA etiqueta2 = ""; 
                int peso = 0;                
                cout << "Ingrese la etiqueta del primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese la etiqueta del segundo vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        cout << "Ingrese el nuevo peso de la arista." << endl;
                        if(!(cin >> peso)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                        }
                        else{
							
							vertice1 = grafo.getVertice(etiqueta1); 
							vertice2 = grafo.getVertice(etiqueta2); 
							
							if (!grafo.esVerticeNulo(vertice1) && !grafo.esVerticeNulo(vertice2)) {
								grafo.modificarPeso(vertice1, vertice2, peso);
							}
							else {
								std::cout << "los datos ingresados son invalidos, por favor intente de nuevo" << std::endl; 
							}
                        }
                    }    
                }
                desplegarMenu();
            }
            if(decision == 11){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = "";
                ETIQUETA etiqueta2 = "";  
                cout << "Ingrese la etiqueta del primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese la etiqueta del segundo vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
						
						vertice1 = grafo.getVertice(etiqueta1); 
						vertice2 = grafo.getVertice(etiqueta2); 
						if (!grafo.esVerticeNulo(vertice1) && !grafo.esVerticeNulo(vertice2)) {						
							int peso = grafo.peso(vertice1, vertice2);
							cout << "El peso de la arista entre los vertices solicitados es " << peso << endl;
						}
						else {
							std::cout << "los datos ingresados son invalidos, por favor intente de nuevo" << std::endl; 
						}
                    }
                }    
                desplegarMenu();

            }

            if(decision == 12){
                vertice ver = grafo.primerVertice();
                if(!grafo.esVerticeNulo(ver)){
                    cout << "El grafo esta vacio." << endl;   
                }
                else{
                    cout << "El primer vertice tiene de etiqueta " << grafo.etiqueta(ver) << "." << endl;
                }
                desplegarMenu();
            }
            if(decision == 13){
                vertice vertice1;    
                ETIQUETA etiqueta1 = ""; 
                cout << "Ingrese la etiqueta del vertice al que desea conocer la etiqueta de su siguiente vertice" << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
					
					vertice1 = grafo.getVertice(etiqueta1); 
					if (!grafo.esVerticeNulo(vertice1)) {
						vertice verticeSiguiente = grafo.siguienteVertice(vertice1);
						if(grafo.esVerticeNulo(verticeSiguiente)){
							cout << "El vertice que quiere averiguar es el ultimo del grafo." << endl;   
						}
						else{
							cout << "El siguiente vertice tiene de etiqueta " << grafo.etiqueta(verticeSiguiente) << "." << endl;
						}    
					}
					else {
						std::cout << "la etiqueta ingresada no corresponde a ningun vertice, por favor intente de nuevo" << std::endl; 	
					}
                }
                desplegarMenu();
            }
            if(decision == 14){
                vertice vertice1;
                ETIQUETA etiqueta1 = "";     
                cout << "Ingrese la etiqueta del vertice del que se desea conocer el primer vertice adyacente." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
					
					vertice1 = grafo.getVertice(etiqueta1); 
					
                    vertice primerVerticeAdyacente = grafo.primerVerticeAdy(vertice1);
                    if(grafo.esVerticeNulo(primerVerticeAdyacente)){
                        cout << "El vertice no tiene vertices adyacentes." << endl;   
                    }
                    else{
                        cout << "El primer vertice adyacente tiene etiqueta " << grafo.etiqueta(primerVerticeAdyacente) << "." << endl;
                    }    
                }
                desplegarMenu();

            }
            if(decision == 15){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = ""; 
                ETIQUETA etiqueta2 = ""; 
                cout << "Ingrese la etiqueta del numero del primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese la etiqueta del vertice adyacente al primer vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
						
						vertice1 = grafo.getVertice(etiqueta1); 
						vertice2 = grafo.getVertice(etiqueta2); 
						
						if (grafo.existeArista(vertice1, vertice2)) {
							
							vertice verticeAdyacenteSiguiente = grafo.siguienteVerticeAdy(vertice1, vertice2);
							if(grafo.esVerticeNulo(verticeAdyacenteSiguiente)){
								cout << "El vertice no tiene mas vertices adyacentes." << endl;   
							}
							else{
								cout << "El siguiente vertice adyacente tiene etiqueta " << grafo.etiqueta(verticeAdyacenteSiguiente) << "." << endl;
							}									
							
						}
						else {
							std::cout << "las etiquetas ingresadas no poseen ningun tipo de relacion de adyacencia" << std::endl; 	
						}	
                    }    
                }
                desplegarMenu();

            }
            if(decision == 16){
                vertice vertice1;    
                vertice vertice2;
                ETIQUETA etiqueta1 = ""; 
                ETIQUETA etiqueta2 = ""; 
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> etiqueta1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> etiqueta2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
						
						vertice1 = grafo.getVertice(etiqueta1); 
						vertice2 = grafo.getVertice(etiqueta2); 
						
						if (!grafo.esVerticeNulo(vertice1) && !grafo.esVerticeNulo(vertice2)) {
							
							bool existeArista = grafo.existeArista(vertice1, vertice2);
							if(existeArista){
								cout << "Existe una arista entre este par de vertices." << endl;   
							}
							else{
								cout << "No existe arista entre este par de vertices." << endl;
							}
							
						}
						else {
							std::cout << "los datos ingresados son invalidos, por favor intente de nuevo" << std::endl; 	
						}
				
                    }    
                }
                desplegarMenu();

            }
            if(decision == 17){
                int numAristas = grafo.numAristas();
                cout << "El grafo tiene " << numAristas << " aristas." << endl;
                desplegarMenu();
            }
            if(decision == 18){
                int numVertices = grafo.numVertices();
                cout << "El grafo tiene " << numVertices << " vertices." << endl;
                desplegarMenu();
            }
            if(decision == 19){
                vertice ver; 
                ETIQUETA etiqueta = "";    
                cout << "Ingrese la etiqueta del vertice que desea conocer el numero de vertices adyacentes." << endl;
                if(!(cin >> etiqueta)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
					
					ver = grafo.getVertice(etiqueta); 
					
					if (!grafo.esVerticeNulo(ver)) {
						int numVerticesAdyacentes = grafo.numVerticesAdy(ver);
						cout << "El vertice solicitado tiene "<< numVerticesAdyacentes <<" ." << endl;						
					}
					else {
						std::cout << "la etiqueta ingresada no corresponde a ningun vertice, por favor intentelo de nuevo" << std::endl; 
					} 
					
                }
                desplegarMenu();

            }
            if(decision == 20){
                cout << "La impresion de los vertices en ancho primero corresponde a :" << endl;
                algoritmos.anchoPrimero(grafo);
                desplegarMenu();
            }
            if(decision == 21){
                cout << "La imprsion de los vertices en profundidad primero corresponde a :" << endl;
                algoritmos.profundidadPrimero(grafo);
                desplegarMenu();
            }
            if(decision == 22){
                bool respuesta = algoritmos.is_there_cycles(grafo);    
                if(respuesta){
                    cout << "El grafo ingresado si posee ciclos" << endl;
                }
                else{
                    cout << "El grafo ingresado no posee ningun ciclo." << endl;                    
                }
                desplegarMenu();
            }
            if(decision == 23){
                int* vectorDePesos = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
                vertice* vectorVerticeAnterior = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 
				
				ETIQUETA etiqueta = ""; 
				vertice ver; 
				std::cout << "ingrese la etiqueta del vertice desde el cual desea ejecutar el algoritmo de Dijkstra" << std::endl; 
				cin >> etiqueta; 
				
				ver = grafo.getVertice(etiqueta); 
				
				if (!grafo.esVerticeNulo(ver)) {

                algoritmos.Dijkstra(grafo, grafo.primerVertice(), vectorDePesos, vectorVerticeAnterior); 

					cout << "El resultado del vector de pesos despues de ejecutar el algoritmo de Dijkstra corresponde a : " << endl; 
					for (int index = 0; index < grafo.numVertices()-1; ++index) {
						cout << vectorDePesos[index] << ", "; 
					}
					cout << endl; 
					cout << "El resultado del vector de los vertices anteriores despues de ejecutar el algoritmo de Dijkstra corresponde a : " << endl; 
					for (int index = 0; index < grafo.numVertices()-1;  ++index) {
						vertice current_vertex = vectorVerticeAnterior[index]; 
						ETIQUETA current_etiqueta = grafo.etiqueta(current_vertex); 
						cout << current_etiqueta << ", "; 
					}
					std::cout << std::endl; 
					std::cout << "para el caso de grafo por matriz de adyacencia los vertices anteriores no se encuentran en terminos de etiquetas, si desea conocer la etiqueta, ejecutar el O.B correspondiente" << std::endl; 								
				}
				else {
					std::cout << "la etiqueta ingresada no es valida, por favor intente de nuevo" << std::endl; 
				}
				
                cout << std::endl;
                free(vectorDePesos);
                free(vectorVerticeAnterior); 
                desplegarMenu();

            }
            if(decision == 24){
                int** matrizDePesos = (int**)malloc(grafo.numVertices()*sizeof(int*)); 	//matriz de peso
                vertice** matrizDeVerticesIntermedios = (vertice**)malloc(grafo.numVertices()*sizeof(vertice*)); 	//matriz de vertice intermedio. 

                for (int row = 0; row < grafo.numVertices(); ++row) {
                    matrizDePesos[row] = (int*)malloc(grafo.numVertices()*sizeof(int)); 
                    matrizDeVerticesIntermedios[row] = (vertice*)malloc(grafo.numVertices()*sizeof(vertice)); 	
                } 

                algoritmos.Floyd(grafo, matrizDePesos, matrizDeVerticesIntermedios); 

                stringstream ss; 
                for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
                    for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
                        ss << matrizDePesos[index_x][index_y] << ", "; 
                    }
                    ss << "\n"; 
                }

                std::cout << "El resultado de la matriz de pesos despues de ejecutar el algoritmo de Floyd corresponde a : " << std::endl; 
                std::cout << ss.str() << std::endl; 

                ss.str(""); 

                for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
                    for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
                        ss << matrizDeVerticesIntermedios[index_x][index_y] << ", "; 
                    }
                    ss << "\n"; 
                }

                std::cout << "El resultado de la matriz de vertices intermedios despues de ejecutar el algoritmo de FLoyd corresponde a :" << std::endl; 
                std::cout << ss.str() << std::endl; 
				
				std::cout << std::endl; 
				std::cout << "en el caso del grafo por matriz de adyacencia la matriz de vertice intermedio no se encuentra en terminos de etiquetas, si desea conocer las etiquetas ejecutar el O.B correspondiente " << std::endl; 
				
				
                for (int row = 0; row < grafo.numVertices(); ++row) {
                    free(matrizDePesos[row]); 
                    free(matrizDeVerticesIntermedios[row]); 	
                } 

                free(matrizDePesos);
                free(matrizDeVerticesIntermedios);
                desplegarMenu();
            }
            if(decision == 25){
                Diccionario<vertice> diccionario; 
                diccionario.iniciar(); 
                vertice* soluciones = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));
                vertice* mejorSolucion = (vertice*)calloc(grafo.numVertices()+1, sizeof(vertice));
                int costo = 0; 
                int mejor_costo = INFINITY; 
                int contador_soluciones = 0; 
                soluciones[0] = grafo.primerVertice(); 
                algoritmos.CH(grafo, diccionario, soluciones, mejorSolucion, costo, mejor_costo, contador_soluciones, 1);   
                //std::cout << "se finalizo con exito" << std::endl; 
                std::cout << "La cantidad de soluciones factibles para el circuito hamilton es: " << contador_soluciones << std::endl; 
                
                if (contador_soluciones > 0) {
					stringstream ss; 
					for (int index_sol = 0; index_sol <= grafo.numVertices(); ++index_sol) {
						if (index_sol != grafo.numVertices()) {
							ss << mejorSolucion[index_sol] << ", "; 
						}
						else {
							ss << mejorSolucion[index_sol]; 
						}	
					}
					ss << "\n"; 
					std::cout << "El resultado de la mejor solucion al circuito hamilton es la siguiente: " << std::endl; 
					std::cout << ss.str() << std::endl;
					std::cout << std::endl; 
					std::cout << "para el caso del grafo por matriz de adyacencia los vertices de la mejor solucion no se encuentran en terminos de etiquetas, para conocer esta informacion, ejecutar los O.B correspondientes" << std::endl;    												
				}
				else {
					std::cout << "el grafo ingresado no posee ningn circuito de hamilton" << std::endl; 
				}
                free(soluciones);
                free(mejorSolucion);    
                desplegarMenu();
            }
            if(decision == 26){
                CC<vertice> mejorSolucion; 
                mejorSolucion.iniciar(grafo.numVertices());
                int menor_cantidad = INFINITY; 
                int colores = 0; 
                int contador_soluciones = 0; 
                bool found = false; 
                algoritmos.colorear_grafo(grafo, mejorSolucion, colores, menor_cantidad, contador_soluciones, found); 
                if (found) {
					string resultado = mejorSolucion.printCC();
					std::cout << "A continuacion se mostraran varias lineas con diferentes vertices asociados a cada linea, dicha linea corresponde a un color y los vertices que se agruparon a dicho color" << std::endl; 
					std::cout << "El resultado de la mejor solucion al algoritmo de coloreo es la siguiente:\n"<< resultado << std::endl; 
					//mejorSolucion.destruir();
				}
				else {
					std::cout << "el grafo no pude ser coloreado exitosamente" << std::endl; 
				}               
                desplegarMenu();

            }
            if(decision == 27){
                vertice vertice = grafo.primerVertice(); 
                algoritmos.Prim(grafo, vertice);			
                desplegarMenu();
            }
            if(decision == 28){
                algoritmos.Kruskal(grafo); 			
                desplegarMenu();
            }
            if(decision == 29){
                std::cout << "este algoritmo solo corresponde a los grafos dirigidos, por lo tanto no aplica y fue sacado de la tarea programada" << std::endl; 
                desplegarMenu();

            }
            if(decision == 30){
                vertice vertice1;
                ETIQUETA etiqueta = ""; 
                cout << "Ingrese la etiqueta del vertice a aislar." << endl;
                if(!(cin >> etiqueta)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{	
					vertice1 = grafo.getVertice(etiqueta);
					if (!grafo.esVerticeNulo(vertice1)) {
						algoritmos.aislarVertice(grafo, vertice1);
						cout << "El vertice ingresado fue aislado existosamente." << endl;   							
					} 
					else {
						std::cout << "la etiqueta ingresada no corresponde a ningun vertice, por favor intentelo de nuevo" << std::endl; 
					}
                }
                desplegarMenu();
            }
            if(decision == 31){
                vertice* puntos = (vertice*)calloc(grafo.numVertices(), sizeof(vertice)); 
                int contador_puntos = 0; 
                algoritmos.encontrarPuntosArticulacion(grafo, puntos, contador_puntos); 
                stringstream ss; 
				#if 1				
				std::cout << "se encontraron un total de : " << contador_puntos << " puntos de articulacion en el grafo" << std::endl; 
				std::cout << "Los vertices puntos de articulacion del grafo corresponden a : " << std::endl; 
				for (int index = 0; index < contador_puntos; ++index) {
					if (index != contador_puntos-1) {
						ss << puntos[index] << ", "; 
					}
					else {
						ss << puntos[index]; 
					}
				}
				#endif 	
                ss << "\n"; 
                std::cout << ss.str() << std::endl; 
                free(puntos);
                desplegarMenu();
            }
            if(decision == 32){
                bool resultado = algoritmos.existeCaminoEntreTodoParDeVertices(grafo);
                if(resultado){
                    cout << "En el grafo existe un camino entre todo par de vertices." << endl;
                }
                else{
                    cout << "En el grafo no existe un camino entre todo par de vertices." << endl;
                }
                desplegarMenu();

            }
        }        
    }    
}
