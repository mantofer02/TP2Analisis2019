all : run

run: main.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h relacion.h cc.h 
	g++ main.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h relacion.h cc.h -o start
	./start

