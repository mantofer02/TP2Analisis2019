all : run

run: main_prueba.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h r11.h cc.h 
	g++ main_prueba.cpp grafo_MA.cpp algoritmos_grafo.cpp apo.h diccionario.h r11.h cc.h -o start
	./start
	
test: mainTest.cpp tester.cpp algoritmos_grafo.cpp grafo_MA.cpp apo.h r11.h diccionario.h cc.h 
	g++ mainTest.cpp tester.cpp algoritmos_grafo.cpp grafo_MA.cpp apo.h r11.h diccionario.h cc.h -o start
	./start

test1: mainTest.cpp tester.cpp algoritmos_grafo.cpp grafo_LA.cpp apo.h r11.h diccionario.h cc.h 
	g++ mainTest.cpp tester.cpp algoritmos_grafo.cpp grafo_LA.cpp apo.h r11.h diccionario.h cc.h -o start
	./start

program:  main.cpp grafo_MA.cpp algoritmos_grafo.cpp interfaz.cpp apo.h diccionario.h r11.h cc.h 
	g++ main.cpp grafo_MA.cpp algoritmos_grafo.cpp interfaz.cpp apo.h diccionario.h r11.h cc.h -o start
	./start
	
program1: main.cpp grafo_LA.cpp algoritmos_grafo.cpp interfaz.cpp apo.h diccionario.h r11.h cc.h 
	g++ main.cpp grafo_LA.cpp algoritmos_grafo.cpp interfaz.cpp apo.h diccionario.h r11.h cc.h -o start
	./start	
