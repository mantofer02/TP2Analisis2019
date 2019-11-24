#include "grafo_LA.h"

int main(){
    Grafo mio;
    mio.agregarVertice("A");
    mio.agregarVertice("B");
    mio.agregarVertice("C");
    mio.agregarVertice("D");
    mio.agregarVertice("E");
    mio.agregarVertice("F");
    mio.agregarVertice("G");

    // mio.l1[2].imprimir();
    
    mio.agregarArista(mio.getVertice("A"),mio.getVertice("B"), 89);
    mio.agregarArista(mio.getVertice("A"),mio.getVertice("F"), 89);
    mio.agregarArista(mio.getVertice("A"),mio.getVertice("E"), 89);
    mio.agregarArista(mio.getVertice("G"),mio.getVertice("F"), 89);
    mio.agregarArista(mio.getVertice("A"),mio.getVertice("B"), 89);
    mio.agregarArista(mio.getVertice("C"),mio.getVertice("E"), 89);
    
    mio.primerVtcAdyacente(mio.getVertice("A"));
    mio.primerVtcAdyacente(mio.getVertice("D"));

    // std :: cout << mio.existeArista(mio.getVertice("C"),mio.getVertice("B"));
    mio.imprimirGrafo();
    return 0;
}