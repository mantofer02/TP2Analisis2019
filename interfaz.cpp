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
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 21){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 22){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 23){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 24){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 25){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 26){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 27){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 28){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 29){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 30){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 31){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 32){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
        }        
    }
    Crear
    Destruir 
    Vaciar 
    AgregarVértice
    EliminarVértice 
    ModificarEtiqueta
    Etiqueta
    AgregarArista
    EliminarArista
    ModificarPeso
    Peso
    PrimerVértice
    SiguienteVértice
    PrimerVérticeAdyacente 
    SiguienteVérticeAdyacente
    ExisteArista
    NumAristas
    NumVértices
    NumVérticesAdyacentes

    
}
