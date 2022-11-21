#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	float a,b,c;
	cout<<"Introduzca tres numeros"<<endl;
	cin>>a>>b>>c;
	if(a>b && a>c) {
	cout<<"El mayor es: "<<a<<endl;
	}
	else {
		if(b>a && b>c) {
		cout<<"El mayor es: "<<b<<endl;
		}
		else {
		cout<<"El mayor es: "<<c<<endl;
		}
	}
	cin.ignore();
	cin.get();
    system("pause");
}

