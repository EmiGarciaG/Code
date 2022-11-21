#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std; 
float trace(float m[4] [4]) {
	float suma=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
				if(i==j){
				suma+=m[i] [j];
				}
		}
	}
	return suma;
}
 
//// 
int test();//indica que la funcion test esta mas abajo
int main(){ 
		test();
		cout<<"Correcto"<<endl;
		cin.ignore();
		cin.get();
}
//funcion de test
int test(){
	
	float m[4][4]={ {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	assert( trace(m)== 10 );
	return 0;
}	


