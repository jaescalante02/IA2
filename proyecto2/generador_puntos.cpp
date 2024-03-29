#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include <math.h>

using namespace std;

ofstream *output;

void create_point( float begin, float end, int n){

  (*output)<<begin<< " "<<end<<" "<<n<< endl;

    //dd skip=3715 count=4852 if=juan.warc of=t1.txt bs=1
}


int main(int argc, char *argv[]){

	if(argc!=4){
		cout<<"Uso: ./generador-puntos <semilla> <numero de casos> <nombre_archivo generado>" << endl;
		return 0;
	}

  int casos = atoi(argv[2]);

  output = new ofstream(argv[3]);  
	
	
	
	srand(atoi(argv[1]));
	for(int i=0;i<casos/2;){
	
	  float r = 3 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(17-3)));
	  
	  float aux = sqrt(49.0 - (r-10.0)*(r-10.0)) + 10.0;
	  
	  float r1 = 3 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(aux-3)));
	  
	  if((r-10)*(r-10)+(r1-10)*(r1-10)<=49){
	    create_point(r,r1, -1);
	    ++i;
	  }  
	}
		
	for(int i=0;i<casos/2;){
	
	  float r =  static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0));	  
	  float r1 = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0));
	  
	  if((r-10)*(r-10)+(r1-10)*(r1-10)>49){
	    create_point(r,r1, 1);
	    ++i;
	  }  
	}		
				
  output->close();

  output = new ofstream("inputs/rejilla.txt");  
  float x =0.1;
  for(int i =0;i<100;++i){
  
    float y = 0.1;
    for(int j=0;j<100;++j){
    
      if((x-10)*(x-10)+(y-10)*(y-10)<=49) create_point(x,y,-1);
      y=y+0.2;
    
    }   
    x=x+0.2; 
  }

  x =0.1;
  for(int i =0;i<100;++i){
  
    float y = 0.1;
    for(int j=0;j<100;++j){
    
      if((x-10)*(x-10)+(y-10)*(y-10)>49) create_point(x,y, 1);
      y=y+0.2;
    
    }   
    x=x+0.2; 
  }


  output->close();

	return 0;
}
