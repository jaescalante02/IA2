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

const int max_iter = 50000;

vector<int> respuestas,respuestas2,respuestas3;
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
    char tipo[40];
    while(fscanf(arch,"%lf,%lf,%lf,%lf,%s",&caso[1],&caso[2],&caso[3],&caso[4],tipo)!=EOF){
//      fscanf("%lf,%lf,%lf,%s"",&caso[1],&caso[2],&caso[3],&caso[4],tipo);
      caso[0]=1.0;
      //printf("%lf %lf %lf %lf %s\n",caso[1],caso[2],caso[3],caso[4],tipo);
      if(tipo[5]=='s')
  	    respuestas.push_back(1),respuestas2.push_back(-1),respuestas3.push_back(-1);
  	  else if(tipo[6]=='e'){
  	    respuestas.push_back(-1),respuestas2.push_back(1),respuestas3.push_back(-1);
  	    }
  	  else{
  	    respuestas.push_back(-1),respuestas2.push_back(-1),respuestas3.push_back(1);
  	    }
    	  
      casos.push_back(caso);
    }
}

void leer2(){

    caso_prueba.resize(n+1);
    while(fscanf(pruebas,"%lf,%lf,%lf,%lf",&caso_prueba[1],&caso_prueba[2],&caso_prueba[3],&caso_prueba[4])!=EOF){
      caso_prueba[0]=1.0;
//      for(int i=1;i<=4;i++) cout << caso_prueba[i] << " ";
 //     cout << endl;
      // de leer los numeros i de este caso
     // for(int i =0;i<n-1;i++) fscanf(pruebas,"%lf",&caso_prueba[i+2]);
	    //for(int i=0;i<3;i++) cout << caso_prueba[i]<< " ";
	    //cout << endl;
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
  
  //vectores de pesos de las neurona de la capa de output
  mi_vector vec,vec2,vec3;
  
  srand(time(NULL));
  
  //vectores de pesos de las neuronas de la capa intermedia
  vector<mi_vector> intermedias;
  for(int i=0;i<neuronas;i++){
    vec.ws.push_back((rand()%100)/100000.0);
    vec2.ws.push_back((rand()%100)/100000.0);
    vec3.ws.push_back((rand()%100)/100000.0);        
    
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
          //basandome en las neuronas de las capas del output
          double o = sigmoidal(vec.mult(outs));
          double o2 = sigmoidal(vec2.mult(outs));
          double o3 = sigmoidal(vec3.mult(outs));
          int resp = (o>0.5)?1:-1;
          //calculo el diferencial del vector de pesos de la unica neurona de la
          //capa del output
          
          double tmp = (resp==1?1.0:0.0);
          //valor objetivo
          double t = (double)respuestas[j];
          double t2 = (double) respuestas2[j];
          double t3 = (double)respuestas3[j];
          
          //Delta de la primera neurona de la capa del output
          double delta_output = o*(1.-o)*(t-o);
          
          //Delta de la segunda neurona de la capa del output
          double delta_output2 = o2*(1.-o2)*(t2-o2);

          //Delta de la segunda neurona de la capa del output
          double delta_output3 = o3*(1.-o3)*(t3-o3);
//          cout << delta_output << " " << delta_output2 << " " << delta_output3 << endl;
          //calculo el vector de los deltas para las neuronas del medio
          vector<double> deltas;
          
          for(int k=0;k<neuronas;k++){
              double tmp2 = outs[k];
  
              deltas.push_back(tmp2*(1.-tmp2)*\
                        ((vec.ws[k])*delta_output+(vec2.ws[k])*delta_output2+\
                          (vec3.ws[k])*delta_output3));

          }

          
          //actualizo el vector de pesos de la unica neurona que hay en la capa
          //de output hacia la intermedia
          for(int k=0;k<neuronas;k++){
            vec.ws[k]+=tasa*delta_output*outs[k];
            vec2.ws[k]+=tasa*delta_output2*outs[k];
            vec3.ws[k]+=tasa*delta_output3*outs[k];
          }
            
          //actualizo los vectores de pesos de cada una de las neuronas de la 
          //capa intermedia hacia la de entrada
          for(int k=0;k<neuronas;k++){
            for(int l=0;l<n+1;l++){
              intermedias[k].ws[l]+=tasa*deltas[k]*casos[j][l];
            }
          }
          
  
          error_total+=(t-o)*(t-o)+(t2-o2)*(t2-o2)+(t3-o3)*(t3-o3);
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
          double o2= sigmoidal(vec2.mult(outs));
          double o3= sigmoidal(vec3.mult(outs));
          //cout << o << " " << o2 << " " << o3 <<endl;
          int resp = (fabs(o-0.5)<0.0001 || o>0.5)?1:0;
          int resp2 = (fabs(o2-0.5)<0.0001 || o2>0.5)?1:0;
          int resp3 = (fabs(o3-0.5)<0.0001 || o3>0.5)?1:0; 
          
          if(resp2) resp =2;
          else if(resp3) resp=3;
          else resp=1;
          fprintf(salida_pruebas,"%d\n",resp);
    }

    fclose(pruebas);

    fclose(salida_pruebas);

  }
	return 0;
}