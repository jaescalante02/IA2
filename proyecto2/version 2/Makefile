all: mivector.o red.cpp red_iris.cpp red_iris_n_clases.cpp
	g++ red.cpp mivector.o -lm -o red
	g++ red_iris.cpp mivector.o -lm -o red_iris
	g++ red_iris_3_clases.cpp mivector.o -lm -o red_iris_3_clases
	g++ red_iris_n_clases.cpp mivector.o -lm -o red_iris_n_clases

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm red
	rm red_iris
	rm red_iris_n_clases
	rm red_iris_3_clases
