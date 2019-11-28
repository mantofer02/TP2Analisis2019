all : run

run: main.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h r11.h cc.h 
	g++ main.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h r11.h cc.h -o start
	./start

