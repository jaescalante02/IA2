#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *bla;
	FILE *bla2;
	bla = fopen("conjunto_a_clasificar","w");
	bla2 = fopen("input_100_pociento","r");
	double t1,t2,t3,t4;
	char t[100];
	while(fscanf(bla2,"%lf,%lf,%lf,%lf,%s",&t1,&t2,&t3,&t4,t)!=EOF){
		fprintf(bla,"%.1lf,%.1lf,%.1lf,%.1lf\n",t1,t2,t3,t4);
		}
	fclose(bla2);
	fclose(bla);
}
