#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int x;
	cout<<"Introduzca un numero"<<endl;
	cin>>x;
	if(x<0) {
	cout<<"El numero es menor que cero"<<endl;	
	}
	else { 
		if(x==0) {
		cout<<"El numero es igual a cero"<<endl;
		}
		else {
		cout<<"El numero es mayor que cero"<<endl;
		}	
	}
	cin.ignore();
	cin.get();
    system("pause");
}

