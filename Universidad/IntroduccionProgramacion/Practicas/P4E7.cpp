#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int Ndivisores(int v){
int i=1,contador=0;
while(i<=v) {
			if(v%i==0) {
					contador++;
					}
					i++;
		}
	return contador;
}
int main() {
		int n;
		cout<<"Introduce el numero del que quieres saber el numero de divisores que tiene"<<endl;
		cin>>n;
		cout<<"El numero de divisores que tiene es: "<<Ndivisores(n)<<endl;
		cin.ignore();
		cin.get();
}

