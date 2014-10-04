#include<iostream>
#include<vector>
using namespace std;
#ifndef mivector
#define mivector
	struct mi_vector{
		//vector que contiene los ws actuales de una neurona
		vector<double> ws;
		mi_vector(){}
		mi_vector(vector<double> pesos) : ws(pesos){}
		mi_vector operator+(const mi_vector &);
		double mult(const mi_vector &);
    double mult(vector<int> &);
	};

#endif
