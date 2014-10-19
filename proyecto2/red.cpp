#include<iostream>
#include<cstdio>
#include"mivector.h"
#include<vector>
#include<cstdlib>
#include<cmath>
#include"mivector.h"
#include<ctime>
using namespace std;

//Descriptor del archivo de casos de entrenamiento
FILE *arch;

//Descriptor del archivo de salida d eerror
FILE *out;

FILE *pruebas;
FILE *salida_pruebas;

//tasa deaprendizaje dada por el usuario 
double tasa;

//Representa el numero de entradas por neurona de capa intermedia, dada por el usuario
int n;

//Representa el numero de neuronas en la capa intermedia
int neuronas;

const int max_iter = 1000;

vector<int> respuestas;
//vector que representa un caso dado por el archivo de casos
//el ultimo elemento sera el resultado de la operacion, que en este caso
//puede ser un and un or o un xor
vector<vector<double> > casos,casos_prueba;

//vector que representa un caso de entrada
vector<double> caso,caso_prueba;
//funcion encargada de leer el archivo de casos de un entrenamiento

double sigmoidal(double valor){
  return 1./(1.+exp(-valor));
}

void leer(){

    caso.resize(n+1);
    while(fscanf(arch,"%lf",&caso[1])!=EOF){
      caso[0]=1.0;
      // termino de leer los numeros de este caso
      for(int i =0;i<n-1;i++) fscanf(arch,"%lf",&caso[i+2]);
	    respuestas.push_back(0);
      fscanf(arch,"%d",&respuestas[respuestas.size()-1]);
      casos.push_back(caso);
    }
}

void leer2(){

    caso_prueba.resize(n+1);
    while(fscanf(pruebas,"%lf",&caso_prueba[1])!=EOF){
      caso_prueba[0]=1.0;
      // termino de leer los numeros de este caso
      for(int i =0;i<n-1;i++) fscanf(pruebas,"%lf",&caso_prueba[i+2]);
	    
      casos_prueba.push_back(caso_prueba);
    }
}

//contador del numero de iteraciones
int cnt;


int main(int argc, char *args[]){
  //Los parametros pasados como argumento deben ser
  if(argc!=8){
    cout<<"Uso:\n./red <tasa_de_aprendizaje> <archivo_de_casos> " \
        <<"<numero_de_neuronas_de_capa_intermedia> "\
        <<"<numero_de_entradas_por_neurona_de_capa_intermedia> " \
        <<"<archivo_de_salida_errores> <archivo_de_pruebas_a_clasificar> " \
        <<"<archivo_de_salida_clasificado> "<< endl;
    return 0;
  }
  tasa = strtod(args[1],NULL);
  arch = fopen(args[2],"r");
  out = fopen(args[5],"w"); 
  n = atoi(args[4]);
  neuronas = atoi(args[3]); 
  if(args[6][0]!='0'){
    pruebas=fopen(args[6],"r");
    salida_pruebas=fopen(args[7],"w");
  }
  
  double tasa_inicial = tasa;
  
  //vector de pesos de la neurona de salida
  mi_vector vec;
  
  srand(time(NULL));
  
  //vectores de pesos de las neuronas de la capa intermedia
  vector<mi_vector> intermedias;
  for(int i=0;i<neuronas;i++){
    vec.ws.push_back((rand()%100)/100000.0);
    intermedias.push_back(mi_vector());
    for(int j=0;j<n+1;j++)
      intermedias[i].ws.push_back((rand()%100)/100000.0);
  }
  
  cnt = 0;
  leer();
  
  
  
  for(int i=0;i<max_iter;i++){
      double error_total = 0.0;
      
      for(int j=0;j<casos.size();j++){
         vector<double> outs;
      
         for(int k=0;k<neuronas;k++){
            outs.push_back(sigmoidal(intermedias[k].mult(casos[j])));
         }          
        
          //calculo como evalua la red esta iteracion en este caso
          //basandome en la neurona de la capa del output
          double o = sigmoidal(vec.mult(outs));
//          /cout <<o <<endl;
          int resp = (o>0.5)?1:-1;
          
          //calculo el diferencial del vector de pesos de la unica neurona de la
          //capa del output
          
          double tmp = (resp==1?1.0:0.0);
          //valor objetivo
          double t = (double)respuestas[j];
          double delta_output = o*(1.-o)*(t-o);

  
          //calculo el vector de los deltas para las neuronas del medio
          vector<double> deltas;
          
          for(int k=0;k<neuronas;k++){
              double tmp2 = outs[k];
  
              deltas.push_back(tmp2*(1.-tmp2)*(vec.ws[k])*delta_output);

          }

          
          //actualizo el vector de pesos de la unica neurona que hay en la capa
          //de output hacia la intermedia
          for(int k=0;k<neuronas;k++)
            vec.ws[k]+=tasa*delta_output*outs[k];
            
          //actualizo los vectores de pesos de cada una de las neuronas de la 
          //capa intermedia hacia la de entrada
          for(int k=0;k<neuronas;k++){
            for(int l=0;l<n+1;l++){
              intermedias[k].ws[l]+=tasa*deltas[k]*casos[j][l];
            }
          }
          
  
          error_total+=(t-o)*(t-o);
      }
    //imprimo el numero de iteracion y el error en el archivo
      fprintf(out,"%d %lf\n",i,error_total/2.0/casos.size());
  }
    
  
  fclose(arch);
  fclose(out);
  if(args[6][0]!='0'){
    leer2();
    for(int j=0;j<casos_prueba.size();j++){
         vector<double> outs;
      
         for(int k=0;k<neuronas;k++)
            outs.push_back(sigmoidal(intermedias[k].mult(casos_prueba[j])));
                   
          //calculo como evalua la red este caso
          double o = sigmoidal(vec.mult(outs));
//          /cout <<o <<endl;
          int resp = (o>0.5)?1:-1;
          fprintf(salida_pruebas,"%d\n",resp);
    }
  
    fclose(pruebas);
    fclose(salida_pruebas);
  }
	return 0;
}
