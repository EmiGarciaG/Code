#include <iostream>
using namespace std;
int factorial(int v) {
		int fac=1;
		if (v<0){
		return 0;																		//Como no existe factorial de un numero negativo devuelve 0
		}																			// El factorial de un número muy grande resultará negativo, otro numero, o 0 ya que se trata de un int y no recoge todos los valores, en combinacion la variable la hago en float para que funcione mejor
		while(v>0) {																//Como factorial de 1 y 0 es 1 el factorial empezara por 1
		fac=fac*v;
		v--;
		}
	return fac;
}
int main() {
	int n;
	cout<<"Introduce el numero de factorial"<<endl;
	cin>>n;
	cout<<"El factorial es: "<<factorial(n)<<endl;
	cin.ignore();
	cin.get();
}
