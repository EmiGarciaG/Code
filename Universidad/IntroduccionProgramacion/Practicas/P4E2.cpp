#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool esprimo(int v) {
int i=2;
	while(i<=v/2){
		if(v%i==0){
		return false;
		}																																//0,1 y 2 serán declarados como primos y solo se aplicara la función a los números positivos 
		i++;
	} 
	return true;
}

int main(){
int n;
cout<<"Escribe un numero para saber si es primo o no"<<endl;
cin>>n;
if( esprimo(n)==true){
cout<<"Es primo"<<endl;
}
else{
cout<<"No es primo"<<endl;
}
cin.ignore();
cin.get();
}