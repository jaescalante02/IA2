#include<iostream>
#include"mivector.h"
using namespace std;

mi_vector mi_vector::operator+(const mi_vector &op){
	vector<double> res;

	for(int i=0;i<ws.size();i++) res.push_back(ws[i]+op.ws[i]);

	return mi_vector(res);
}

double mi_vector::mult(const mi_vector &op){
	double res = 0.0;

	for(int i=0;i<ws.size();i++) res+=op.ws[i]*ws[i];

	return res;

}

double mi_vector::mult(vector<int> &op){
	double res = 0.0;

	for(int i=0;i<ws.size();i++) res+=op[i]*ws[i];

	return res;

}

double mi_vector::mult(vector<double> &op){
	double res = 0.0;

	for(int i=0;i<ws.size();i++) res+=op[i]*ws[i];

	return res;

}
