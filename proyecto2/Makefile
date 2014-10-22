all: mivector.o generador.cpp red.cpp
	g++ red.cpp mivector.o -lm -o red
	g++ generador.cpp -o generador
	g++ generador_puntos.cpp -o generador-puntos

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm red
	rm generador generador-puntos
