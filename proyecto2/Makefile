all: mivector.o generador.cpp red.cpp
	g++ red.cpp mivector.o -lm -o red
	g++ generador.cpp -o generador

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm red
	rm generador
