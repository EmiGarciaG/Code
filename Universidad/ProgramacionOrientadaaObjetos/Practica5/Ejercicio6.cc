//Fichero Ejercicio6.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <vector>
#include <string>

//Declaracion de los namespaces
using namespace std;

//Declaracion de la plantilla(template)
template <class T>

//Funcion de tipo void para imprimir el vector ya sea int, float o char
void imprimevector(T v, const int n){
	for(int i=0; i<n; i++){
			cout<<v[i]<<" ";
	}
}
//Declaracion main
int main(){
	vector <int> a={1,3,5,7,9};	//Vector tipo int
	vector <float> b={5.6, 7.8, 3.9, 1.2};	//Vector tipo float
	char c[5]="hola";	//Vector tipo char de caracteres 
	vector <string> d={"hola", "que", "tal"};	//Vector tipo string
	cout<<"Vector de enteros:"<<endl;
	imprimevector(a,5);
	cout<<endl;
	cout<<"Vector de floats:"<<endl;
	imprimevector(b,4);
	cout<<endl;
	cout<<"Vector de char:"<<endl;
	imprimevector(c,4);
	cout<<endl;
	cout<<"Ademas he incluido un vector de strings:"<<endl;
	imprimevector(d,3);
	cout<<endl;
}
//Fin del programa