#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include <math.h>

using namespace std;

ofstream *output;

void create_point( float begin, float end){

  (*output)<<begin<< " "<<end<< endl;

    //dd skip=3715 count=4852 if=juan.warc of=t1.txt bs=1
}


int main(int argc, char *argv[]){

	if(argc!=3){
		cout<<"Uso: ./generador-puntos <semilla> <nombre_archivo generado>" << endl;
		return 0;
	}

  output = new ofstream(argv[2]);  
	
	srand(atoi(argv[1]));
	for(int i=0;i<5000;){
	
	  float r = 3 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(17-3)));
	  
	  float aux = sqrt(49.0 - (r-10.0)*(r-10.0)) + 10.0;
	  
	  float r1 = 3 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(aux-3)));
	  
	  if((r-10)*(r-10)+(r1-10)*(r1-10)<49){
	    create_point(r,r1);
	    ++i;
	  }  
	}
		
	for(int i=0;i<5000;){
	
	  float r =  static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0));	  
	  float r1 = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0));
	  
	  if((r-10)*(r-10)+(r1-10)*(r1-10)>49){
	    create_point(r,r1);
	    ++i;
	  }  
	}		
				
  output->close();

	return 0;
}
