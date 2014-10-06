all: mivector.o perceptron.cpp adaline.cpp generador.cpp
	g++ perceptron.cpp mivector.o -lm -o perceptron
	g++ generador.cpp -o generador
	g++ adaline.cpp mivector.o -lm -o adaline

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm -rf perceptron
	rm -rf generador
	rm -rf adaline
