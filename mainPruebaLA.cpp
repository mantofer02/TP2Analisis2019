#include "grafo_LA.h"
#include "diccionario.h"

int main(){
    Grafo mio;
    mio.agregarVertice("A");
    mio.agregarVertice("B");
    mio.agregarVertice("C");
    mio.agregarVertice("D");
    mio.agregarVertice("E");
    mio.agregarVertice("F");
    mio.agregarVertice("G");
    // mio.agregarVertice("8");

    // mio.l1[2].imprimir();

    Diccionario<vertice> miDic;
    // miDic.agregar(mio.getVertice("4"));

    // Diccionario miDic;
    // miDic.agregar(mio.getVertice("4"));    

    // miDic.agregar(34);

    // std :: cout << miDic.pertenece(mio.getVertice("4"));



    mio.agregarArista(mio.getVertice("A"),mio.getVertice("B"), 1);
    mio.agregarArista(mio.getVertice("B"),mio.getVertice("F"), 3);
    // mio.agregarArista(mio.getVertice("F"),mio.getVertice(""), 2);
    // mio.agregarArista(mio.getVertice("G"),mio.getVertice("8"), 2);
    mio.agregarArista(mio.getVertice("B"),mio.getVertice("C"), 2);
    // mio.agregarArista(mio.getVertice("3"),mio.getVertice("4"), 1);
    mio.agregarArista(mio.getVertice("E"),mio.getVertice("C"), 1);

    // mio.primerVtcAdyacente(mio.getVertice("A"));
    // mio.primerVtcAdyacente(mio.getVertice("D"));

    // std :: cout << mio.existeArista(mio.getVertice("C"),mio.getVertice("B"));
    mio.imprimirGrafo();

    mio.borrarVertice(mio.getVertice("D"));


    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;
    std :: cout << std :: endl;

    mio.imprimirGrafo();

    return 0;
}