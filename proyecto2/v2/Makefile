all: mivector.o red.cpp red_iris.cpp red_iris_n_clases.cpp
	g++ red.cpp mivector.o -lm -o red
	g++ red_iris.cpp mivector.o -lm -o red_iris
	g++ red_iris_n_clases.cpp mivector.o -lm -o red_iris_n_clases

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm -rf red
	rm -rf red_iris
	rm -rf red_iris_n_clases

