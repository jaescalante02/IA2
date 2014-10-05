#include<iostream>
#include<cstdio>
#include"mivector.h"
#include<vector>
#include<cstdlib>
#include<cmath>
#include"mivector.h"
using namespace std;

//Descriptor del archivo de casos
FILE *arch;

//Descriptor del archivo de salida
FILE *out;

//taza deaprendizaje dada por el usuario 
double taza;

//Representa el numero de entradas de la neurona, dada por el usuario
int n;


const int max_iter = 20;

vector<int> respuestas;
//vector que representa un caso dado por el archivo de casos
//el ultimo elemento sera el resultado de la operacion, que en este caso
//puede ser un and un or o un xor
vector<vector<int> > casos;

//vector que representa un caso de entrada
vector<int> caso;
//funcion encargada de leer el archivo de casos de un entrenamiento
void leer(){

    caso.resize(n+1);
    while(fscanf(arch,"%d",&caso[1])!=EOF){
      caso[0]=1;
      // termino de leer los numeros de este caso
      for(int i =0;i<n-1;i++) fscanf(arch,"%d",&caso[i+2]);
	  respuestas.push_back(0);
      fscanf(arch,"%d",&respuestas[respuestas.size()-1]);
      casos.push_back(caso);
    }
}

//contador del numero de iteraciones
int cnt;
int n_casos;

int main(int argc, char *args[]){
  //Los parametros pasados como argumento deben ser
  if(argc!=5){
    cout<<"Uso:\n./adaline <tasa_de_aprendizaje> <archivo_de_casos> " \
        <<"<numero_de_entradas_del_adaline> <valor_inicial_vector_de_pesos>"<<endl;
    return 0;
  }
  taza = strtod(args[1],NULL);
  arch = fopen(args[2],"r");
  out = fopen("adaline.out","w"); 
  n = atoi(args[3]);
  double inic = strtod(args[4],NULL);

  //vector de pesos
  mi_vector vec(vector<double> (n+1,inic));
  
  //vector de diferencial
  n_casos++;
  
  cnt = 0;
  leer();

  
  for(int i=0;i<max_iter;i++){
      double error_total = 0.0;
      mi_vector diff(vector<double> (n+1,0.0));
      for(int j=0;j<casos.size();j++){
        //calculo como evalua la neurona esta iteracion en este caso
        double o = vec.mult(casos[j]);
        
        //valor objetivo
        double t = (double)respuestas[j];
     //  	cout << t << " " << o << endl; 
        error_total+=(t-o)*(t-o);
        
        //calculo el diferencial que hay que sumarle al vector de pesos actual
        for(int k=0;k<n+1;k++) 
          diff.ws[k]+=(taza)*(t-o)*casos[j][k];
      }
/*	  cout << "\nvec = (";
	  for(int k=0;k<vec.ws.size();k++){
		  cout << vec.ws[k] << ", ";
	  }
	  cout <<")"<< endl;

	  cout << "\ndiff = (";
	  for(int k=0;k<diff.ws.size();k++){
		  cout << diff.ws[k] << ", ";
	  }
	  cout <<")"<< endl;
*/
      vec = vec + diff;
//	  imprimo el numero de iteracion y el error en el archivo
      fprintf(out,"%d %lf\n",i,error_total*1./2/casos.size());
//      for(int k=0;k<n+1;k++) cout << diff.ws[k] << " ";
 //     cout << endl;
      //si ya no hay error para ningun caso, quiere decir que ya la neurona 
      //esta entrenada
//	  cout << "error =" << (error_total/2)/casos.size() << endl;
//      if(error_total/casos.size()<1.01)
  //      break;
  }
    
  
  fclose(arch);
  fclose(out);
	return 0;
}
