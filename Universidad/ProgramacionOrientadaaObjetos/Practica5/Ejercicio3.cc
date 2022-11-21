//Fichero Ejercicio3.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <algorithm>
#include <vector>

//Declaracion de los namespaces
using namespace std; 

//Declaracion main
int main(){
	int n=0;	//Variable tipo int para el numero de elementos
	cout<<"Escriba cuantos elementos quieres que tenga el vector: "<<endl;
	cin>>n;
	vector <int> v(n);	//Vector de tipo int 
	cout<<"Escriba los elementos del vector(solo se aceptan enteros): "<<endl;
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"]=";
		cin>>v[i];
	}
	cout<<endl;
	cout<<"Vector sin ordenar:"<<endl;
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"]=";
		cout<<v[i]<<endl;		
	}
	cout<<endl;
	sort(v.begin(), v.end()); //Funcion sort para ordenar de forma ascendente (por defecto) el vector
	cout<<"Vector ordenado:"<<endl;
	for(int i=0; i<n; i++){
			cout<<"v["<<i<<"]=";
			cout<<v[i]<<endl;		
	}
}
//Fin del programa
	