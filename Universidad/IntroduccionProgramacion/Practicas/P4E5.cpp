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

void primos(int n){
int cantidad=0;
int i=0;
	while(cantidad<n){
		if( esprimo(i)==true){
		cout<<i<<endl;
		cantidad++;
		}
		i++;
	}
}

int main(){
int x;
cout<<"Escribe la cantidad de n primeros numeros primos que quieres ver en pantalla"<<endl;
cin>>x;
primos(x);
cin.ignore();
cin.get();
}