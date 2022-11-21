#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std; 
void stats(float m[4] [4], float res[2]){
	float s=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			s=s+m[i] [j];
		}
	}
	res[0]=s/16;
	float z=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			z=z+(m[i] [j]-res[0])*(m[i] [j]-res[0]);
		}
	}
	res[1]=sqrt(z/16);
}
//// 
int test();//indica que la funcion test esta mas abajo
int main(){ 
		test();
		cout<<"Correcto"<<endl;
		system("pause");
		return 0;
}
//funcion de test
 
int test(){
	
	float m[4][4]={ {1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
	float st[2];
	stats(m,st);
	assert( fabs( st[0]-2.5)<1e-3  && fabs(st[1]-1.11803)<1e-3);
	return 0;
}	


