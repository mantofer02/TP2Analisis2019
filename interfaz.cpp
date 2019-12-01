#include "interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz(){
    desplegarMenu();
}

Interfaz::~Interfaz(){
    
}

void Interfaz::desplegarMenu(){
    cout << "Bienvenido al programa de grafos. Digite los dígitos correspondientes a los operadores básicos  o algoritmos que desea usar:\n" << endl;
    cout << "------OPERADORES BASICOS--------\n1. Crear.\n2. Destruir.\n3. Vaciar.\n4. AgregarVertice.\n5. EliminarVertice.\n6. ModificarEtiqueta.\n
    7. Etiqueta.\n8. AgregarArista.\n9. EliminarArista.\n10. ModificarPeso.\n11. Peso. \n12. PrimerVertice.\n13. SiguienteVertice. \n 14. PrimerVerticeAdyacente.\n
    15. SiguienteVerticeAdyacente. \n 16. ExisteArista. \n 17. NumAristas. \n 18. NumVertices. \n 19. NumVerticesAdyacentes."; 
    cout << "------ALGORITMOS--------\n20. Recorrido en Ancho Primero. \n 21. Recorrido en Profundidad Primero. \n 22. Averiguar si el grando tiene ciclos. \n
    23.Dijkstra. \n24. Floyd. \n25. Encontrar Circuito de Hamilton de Menor Costo. \n26. Colorear el grafo. \n27. Prim.\n28. Kruskal. \n
    29. Averiguar cuantos componentes conexos tiene el grafo. \n30. Aislar un vértice. \n31. Encontrar los pintos de articulación.\n32. Averiguar si existe camino entre todo par de vertices.\n 
    33. Salir." << endl;
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
                string etiqueta; 
                cout << "Ingrese la etiqueta del nuevo vertice." << endl;
                cin >> etiqueta;
                grafo.agregarVertice(etiqueta);
                cout << "El vertice con etiqueta "<< etiqueta <<" fue agregado exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 5){
                string etiqueta; 
                cout << "Ingrese la etiqueta del vertice a eliminar." << endl;
                cin >> etiqueta;
                grafo.eliminarVertice(etiqueta);
                cout << "El vertice con etiqueta "<< etiqueta <<" fue eliminado exitosamente." << endl;
                desplegarMenu();
            }
            if(decision == 6){
                string etiqueta; 
                string nuevaEtiqueta;
                cout << "Ingrese la etiqueta del vertice a cambiar(debe ser valido en el grafo)." << endl;
                cin >> etiqueta;
                cout << "Ingrese la nueva eiqueta del vertice." << endl;
                cin >> nuevaEtiqueta;
                grafo.modificarEtiqueta(etiqueta, nuevaEtiqueta);
                cout << "La etiqueta fue modificada exitosamente." << endl; 
                desplegarMenu();
            }
            if(decision == 7){
                int vertice = 0;    
                cout << "Ingrese el numero del vertice que desea conocer la etiqueta." << endl;
                if(!(cin >> vertice)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    string etiquetaRetornada = grafo.etiqueta(vertice);
                    if(etiquetaRetornada != NULL){
                        cout << "La etiqueta correspondiente al vértice ingresado es " << etiquetaRetornada <<endl;
                    }
                    else{                      
                        cout << "El vertice ingresado no existe en el grafo." << endl;
                    }
                    
                }
                desplegarMenu();
            }
            if(decision == 8){
                int vertice1 = 0;    
                int vertice2 = 0;
                int peso = 0;                
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> vertice2)){
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
                            grafo.agregarArista(vertice1, vertice2, peso);
                        }
                    }    
                }
                desplegarMenu();
            }
            if(decision == 9){
                int vertice1 = 0;    
                int vertice2 = 0;
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> vertice2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        grafo.eliminarArista(vertice1, vertice2);
                    }
                }    
                desplegarMenu();
            }
            if(decision == 10){
                int vertice1 = 0;    
                int vertice2 = 0;
                int peso = 0;                
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> vertice2)){
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
                            grafo.modificarPeso(vertice1, vertice2, peso);
                        }
                    }    
                }
                desplegarMenu();
            }
            if(decision == 11){
                int vertice1 = 0;    
                int vertice2 = 0;
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> vertice2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        int peso = grafo.peso(vertice1, vertice2);
                        cout << "El peso de la arista entre los vertices solicitados es " << peso << endl;
                    }
                }    
                desplegarMenu();

            }

            if(decision == 12){
                int vertice = grafo.primerVertice();
                if(vertice == -1){
                    cout << "El grafo esta vacio." << endl;   
                }
                else{
                    cout << "El primer vertice tiene de etiqueta " << grafo.etiqueta(vertice) << "." << endl;
                }
                desplegarMenu();
            }
            if(decision == 13){
                int vertice1 = 0;    
                cout << "Ingrese el numero del vertice del que se desea conocer el siguiente vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    int verticeSiguiente = grafo.primerVertice();
                    if(verticeSiguiente == -1){
                        cout << "El vertice que quiere averiguar es el ultimo del grafo." << endl;   
                    }
                    else{
                        cout << "El siguiente vertice tiene de etiqueta " << grafo.etiqueta(verticeSiguiente) << "." << endl;
                    }    
                }
                desplegarMenu();
            }
            if(decision == 14){
                int vertice1 = 0;    
                cout << "Ingrese el numero del vertice del que se desea conocer el primer vertice adyacente." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    int primerVerticeAdyacente = grafo.primerVerticeAdy(vertice1);
                    if(primerVerticeAdyacente == -1){
                        cout << "El vertice no tiene vertices adyacentes." << endl;   
                    }
                    else{
                        cout << "El primer vertice adyacente tiene etiqueta " << grafo.etiqueta(primerVerticeAdyacente) << "." << endl;
                    }    
                }
                desplegarMenu();

            }
            if(decision == 15){
                int vertice1 = 0;    
                int vertice2 = 0;
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del vertice adyacente al primer vertice." << endl;
                    if(!(cin >> vertice2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        int verticeAdyacenteSiguiente = grafo.siguienteVerticeAdy(vertice1, vertice2);
                        if(verticeAdyacenteSiguiente == -1){
                            cout << "El vertice no tiene mas vertices adyacentes." << endl;   
                        }
                        else{
                            cout << "El siguiente vertice adyacente tiene etiqueta " << grafo.etiqueta(verticeAdyacenteSiguiente) << "." << endl;
                        }
                    }    
                }
                desplegarMenu();

            }
            if(decision == 16){
                int vertice1 = 0;    
                int vertice2 = 0;
                cout << "Ingrese el numero del primer vertice." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    cout << "Ingrese el numero del segundo vertice." << endl;
                    if(!(cin >> vertice2)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                    }
                    else{
                        bool existeArista = grafo.existeArista(vertice1, vertice2);
                        if(existeArista){
                            cout << "Existe una arista entre este par de vertices." << endl;   
                        }
                        else{
                            cout << "No existe arista entre este par de vertices." << endl;
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
                int vertice = 0;    
                cout << "Ingrese el numero del vertice que desea conocer el numero de vertices adyacentes." << endl;
                if(!(cin >> vertice)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    int numVerticesAdyacentes = grafo.numVerticesAdy(vertice);
                    cout << "El vertice solicitado tiene "<< numVerticesAdyacentes <<" ." << endl;
                }
                desplegarMenu();

            }
            if(decision == 20){
                cout << "El resultado de recorrer el grafo por ancho primero es:" << endl;
                algoritmos.anchoPrimero(grafo);
                desplegarMenu();
            }
            if(decision == 21){
                cout << "El resultado de recorrer el grafo por profundidad primero es:" << endl;
                algoritmos.profundidadPrimero(grafo);
                desplegarMenu();
            }
            if(decision == 22){
                bool respuesta = algoritmos.is_there_cycles(grafo);    
                if(respuesta){
                    cout << "El grafo tiene ciclos." << endl;
                }
                else{
                    cout << "El grafo no tiene ciclos." << endl;                    
                }
                desplegarMenu();
            }
            if(decision == 23){
                int* vectorDePesos = (int*)calloc((grafo.numVertices()-1), sizeof(int)); //vector peso
                vertice* vectorVerticeAnterior = (vertice*)calloc((grafo.numVertices()-1), sizeof(vertice)); 	//vector vertice anterior 

                algoritmos.Dijkstra(grafo, 1, vectorDePesos, vectorVerticeAnterior); 

                cout << "El resultado del vector de pesos es: " << endl; 
                for (int index = 0; index < grafo.numVertices()-1; ++index) {
                    cout << vectorDePesos[index] << ", "; 
                }
                cout << endl; 
                cout << "El resultado del vector de los vertices anteriores es: " << endl; 
                for (int index = 0; index < grafo.numVertices()-1;  ++index) {
                    cout << vectorVerticeAnterior[index] << ", "; 
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

                std::cout << "El resultado de la matriz de pesos es: " << std::endl; 
                std::cout << ss.str() << std::endl; 

                ss.str(""); 

                for (int index_x = 0; index_x < grafo.numVertices(); ++index_x) {
                    for (int index_y = 0; index_y < grafo.numVertices(); ++index_y) {
                        ss << matrizDeVerticesIntermedios[index_x][index_y] << ", "; 
                    }
                    ss << "\n"; 
                }

                std::cout << "El resultado de la matriz de vertices intermedios es:" << std::endl; 
                std::cout << ss.str() << std::endl; 

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
                free(soluciones);
                free(mejorSolucion);    
                //HAY QUE VER CUANDO NO TIENE SOLUCION
                desplegarMenu();
            }
            if(decision == 26){
                CC<vertice> mejorSolucion; 
                mejorSolucion.iniciar(grafo.numVertices());
                int menor_cantidad = INFINITY; 
                int colores = 0; 
                int contador_soluciones = 0; 
                algoritmos.colorear_grafo(grafo, mejorSolucion, colores, menor_cantidad, contador_soluciones); 
                string resultado = mejorSolucion.printCC();
                cout << "El resultado de la mejor solucion al algoritmo de coloreo es la siguiente:\n"<< resultado << std::endl; 
                //mejorSolucion.destruir();               
                desplegarMenu();

            }
            if(decision == 27){
                algoritmos.Prim(grafo, 0);			
                desplegarMenu();
            }
            if(decision == 28){
                algoritmos.Kruskal(grafo); 			
                desplegarMenu();

            }
            if(decision == 29){
                //FALTA COMPONENTES FUERTEMENTE CONEXOS
                desplegarMenu();

            }
            if(decision == 30){
                vertice vertice1 = 0;
                cout << "Ingrese el numero del vertice a aislar." << endl;
                if(!(cin >> vertice1)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "El valor que introdujo no es valido. Por favor intente de nuevo." << endl;
                }
                else{
                    algoritmos.aislarVertice(grafo, vertice1);
                    cout << "El vertice ingresado fue aislado existosamente." << endl;    
                }
                desplegarMenu();
            }
            if(decision == 31){
                vertice* puntos = (vertice*)calloc(grafo.numVertices(), sizeof(vertice)); 
                algoritmos.encontrarPuntosArticulacion(grafo, puntos); 
                std::cout << "Los puntos de articulacion del grafo son los siguientes: " << std::endl; 
                stringstream ss; 
                for (int index = 1; index <= puntos[0]; ++index) {
                    if (index != puntos[0]) {
                        ss << puntos[index] << ", "; 
                    }
                    else {
                        ss << puntos[index]; 
                    }
                }
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
