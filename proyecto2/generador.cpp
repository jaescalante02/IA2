#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxn = 1<<15;
const char *archivo = "out_generador";
int n;

FILE *arch;

void generarOR(){
	for(int i=0;i<maxn && i<(1<<n);i++){
		int res = -1;
		for(int j=0;j<n;j++){
			fprintf(arch,"%d ",(((1<<j) & i)?1:-1));
			if((1<<j)&i) res=1;
		}
		fprintf(arch,"%d\n",res);
	}
}

void generarAND(){
	for(int i=0;i<maxn && i<(1<<n);i++){
		int res = 1;
		for(int j=0;j<n;j++){
			fprintf(arch,"%d ",(((1<<j) & i)?1:-1));
			if(!((1<<j)&i)) res=-1;
		}
		fprintf(arch,"%d\n",res);
	}
}

void generarXOR(){
	for(int i=0;i<maxn && i<(1<<n);i++){
		int res = -1;
		for(int j=0;j<n;j++){
			fprintf(arch,"%d ",(((1<<j) & i)?1:-1));
			int tmp = (((1<<j)&i)?1:-1);
			if(res!=tmp) res=1;
			else res = -1;
		}
		fprintf(arch,"%d\n",res);
	}
}

int main(int argc, char *argv[]){

	if(argc!=3){
		cout<<"Uso: ./generador <tipo_operacion> <tamanio_entrada_neurona>" << endl;
		cout<<"\tLos tipos de operaciones son:\n1 para OR\n2 para AND\n";
		cout<<"\tCualquier otro numero para XOR" << endl;
		return 0;
	}

	//verifica el primer parametro que le dio el usuario
	//1 para OR
	//2 para AND
	//3 para XOR

	//el segundo parametro es el tama#o de la entrada de la neurona
	n = atoi(argv[2]);
	arch = fopen(archivo,"w");
	char c = argv[1][0];
	n = min(n,15);
	if(c=='1')
		generarOR();
	
	else if(c=='2')
		generarAND();
	
	else
		generarXOR();

	fclose(arch);
	


	return 0;
}
