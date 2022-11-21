#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
float factorial(int v) {
		float fac=1;
		if (v<0){
		return 0;																		//Como no existe factorial de un numero negativo devuelve 0
		}																			// El factorial de un número muy grande resultará negativo, otro numero, o 0 ya que se trata de un int y no recoge todos los valores, en combinacion la variable la hago en float para que funcione mejor
		while(v>0) {																//Como factorial de 1 y 0 es 1 el factorial empezara por 1
		fac=fac*v;
		v--;
		}
	return fac;
}

int combinaciones(int n, int k){
int combinacion, diferencia;
diferencia=n-k;
combinacion=factorial(n)/(factorial(k)*factorial(diferencia));
return combinacion;
}

int main(){
int x,y;
cout<<"Escribe la combinacion que quieras calcular"<<endl;
cin>>x;
cin>>y;
	while(y>x || x<0 || y<0){																			//La combinación solo es posible si el primer valor es mayor que el segundo y ambos son positivos
	cout<<"El primer valor tiene que ser mayor que el segundo y ambos positivos, escribelos de nuevo: "<<endl;		
	cin>>x;
	cin>>y;
	}
cout<<"Resultado: "<<combinaciones(x, y)<<endl;
combinaciones(x, y);
cin.ignore();
cin.get();
}

