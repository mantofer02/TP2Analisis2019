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
    cout << "------OPERADORES BASICOS--------\n1. Crear.\n2. Destruir.\n3. Vaciar.\n4. AgregarVertice.\n5. EliminarVertice.\n6. ModificarEtiqueta.\n7. Etiqueta.\n8. AgregarArista.\n9. EliminarArista.\n10. ModificarPeso.\n11. Peso. \n12. PrimerVertice.\n13. SiguienteVertice. \n 14. PrimerVerticeAdyacente.\n15. SiguienteVerticeAdyacente. \n 16. ExisteArista. \n 17. NumAristas. \n 18. NumVertices. \n 19. NumVerticesAdyacentes."; 
    cout << "------ALGORITMOS--------\n20. Recorrido en Ancho Primero. \n 21. Recorrido en Profundidad Primero. \n 22. Averiguar si el grando tiene ciclos. \n23.Dijkstra. \n24. Floyd. \n25. Encontrar Circuito de Hamilton de Menor Costo. \n26. Colorear el grafo. \n27. Prim.\n28. Kruskal. \n29. Averiguar cuantos componentes conexos tiene el grafo. \n30. Aislar un vértice. \n31. Encontrar los pintos de articulación.\n32. Averiguar si existe camino entre todo par de vertices.\n 33. Salir." << endl;
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
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 5){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 6){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 7){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 8){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 9){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 10){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 11){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();
            }

            if(decision == 12){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 13){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 14){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 15){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 16){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 17){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 18){
                cout << "El grafo fue inicializado exitosamente." << endl;
                desplegarMenu();

            }
            if(decision == 19){
                cout << "El grafo fue inicializado exitosamente." << endl;
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
