#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool esperfecto(int v) {
		int i=1,perfecto=0;
		while(i<=v/2) {
			if(v%i==0) {
					perfecto=perfecto+i;						//Para saber si es perfecto, la suma de sus divisores hasta n/2(la mitad del numero) debe ser igual al numero
					}
					i++;
		}
		if(perfecto==v){
		return true;
		}
		return false;
}

int main(){
	int n;
	cout<<"Escriba un numero para saber si es o no perfecto"<<endl;
	cin>>n;
	if(esperfecto(n)==true){
	cout<<"Es perfecto"<<endl;
	}
	else{
	cout<<"No es perfecto"<<endl;
    }
	cin.ignore();
	cin.get();
}

