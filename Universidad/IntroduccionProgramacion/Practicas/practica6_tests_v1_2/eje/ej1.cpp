#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std; 

int find(float m[4] [4], float val){
	int count=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
				if(m[i] [j]==val){
					count++;
				}
		}
	}
	return count;
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
	assert(  find(m,1 )==4);
	assert(  find(m,2 )==4);
	assert(  find(m,-1 )==0);
	return 0;
}	


