//Fichero Ejercicio4.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <algorithm>
#include <vector>

//Declaracion de los namespaces
using namespace std; 

//Funcion de tipo bool para ordenar de forma descendente 
bool Desc(int i, int j){
	return i>j;
}

//Funcion de tipo bool para ordenar de forma ascendente
bool Asc(int i, int j){
	return i<j;
}

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
	cout<<"Vector sin ordenar: "<<endl;
	for(int i=0; i<n; i++){
		cout<<"v["<<i<<"]=";
		cout<<v[i]<<endl;		
	}
	cout<<endl;
	string opc;	//Variable tipo string para el tipo de ordenamiento
	cout<<"Escriba el tipo de ordenamiento, Asc(Ascendente) o Desc(Descendente):"<<endl;
	cin>>opc;
	if(opc.compare("Asc")==0){
		sort(v.begin(), v.end(), Asc);	//Funcion sort con la funcion Asc para ordenar de forma ascendente
		cout<<"Vector orden ascendente "<<endl;
		for(int i=0; i<n; i++){
			cout<<"v["<<i<<"]=";
			cout<<v[i]<<endl;		
		}
	}
	else if(opc.compare("Desc")==0){
		sort(v.begin(), v.end(), Desc);	//Funcion sort con la funcion Desc para ordenar de forma descendente
		cout<<"Vector orden descendente "<<endl;
		for(int i=0; i<n; i++){
			cout<<"v["<<i<<"]=";
			cout<<v[i]<<endl;		
		}
	}
	else{
		cout<<"Error al insertar el orden"<<endl;
	}
}
//Fin del programa