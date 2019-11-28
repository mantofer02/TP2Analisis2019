#include "grafo_LA.h"

int main(){
    Grafo mio;
    mio.agregarVertice("1");
    mio.agregarVertice("2");
    mio.agregarVertice("3");
    mio.agregarVertice("4");
    mio.agregarVertice("5");
    mio.agregarVertice("6");
    mio.agregarVertice("7");
    mio.agregarVertice("8");

    // mio.l1[2].imprimir();
    
    mio.agregarArista(mio.getVertice("1"),mio.getVertice("2"), 1);
    mio.agregarArista(mio.getVertice("2"),mio.getVertice("6"), 3);
    mio.agregarArista(mio.getVertice("6"),mio.getVertice("7"), 2);
    mio.agregarArista(mio.getVertice("7"),mio.getVertice("8"), 2);
    mio.agregarArista(mio.getVertice("2"),mio.getVertice("3"), 2);
    mio.agregarArista(mio.getVertice("3"),mio.getVertice("4"), 1);
    mio.agregarArista(mio.getVertice("5"),mio.getVertice("3"), 1);

    // mio.primerVtcAdyacente(mio.getVertice("A"));
    // mio.primerVtcAdyacente(mio.getVertice("D"));

    // std :: cout << mio.existeArista(mio.getVertice("C"),mio.getVertice("B"));
    mio.imprimirGrafo();
    return 0;
}