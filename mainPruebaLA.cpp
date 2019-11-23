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
    mio.agregarArista(mio.getVertice("A"),mio.getVertice("B"), 89);
    mio.imprimirGrafo();
    return 0;
}