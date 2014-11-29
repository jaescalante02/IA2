all: mivector.o red_iris.cpp
	g++ red_iris.cpp mivector.o -lm -o red_iris

mivector.o: mivector.h mivector.cpp
	g++ -c mivector.cpp

clean:
	rm -rf *.o *.out
	rm -rf *~
	rm -rf red_iris

