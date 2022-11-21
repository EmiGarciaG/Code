//Fichero Ejercicio5.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "jugador.h"

//Declaracion de los namespaces
using namespace std;

//Funcion de tipo bool para ordenar de forma ascendente los dnis de los jugadores
bool ordenarDNIAsc(Jugador i,Jugador j){
	return i.getDNI()<j.getDNI();
} 

//Funcion de tipo bool para ordenar de forma descendente los dnis de los jugadores
bool ordenarDNIDesc(Jugador i,Jugador j){
	return i.getDNI()>j.getDNI();
} 

//Declaracion main
int main(){
	vector <Jugador> v;	//Vector de jugadores
	int opc=0, dni=0, codigo=0;	//Variables de tipo int opc(para elegir), dni y codigo
	srand(time(NULL));	//Inicio aleatorios
	cout<<"Elige si quieres introducir los DNIs(1) o que se generen de forma aleatoria(2):";
	cin>>opc;
	if(opc==1){
		int n;
		cout<<"Cantidad de Jugadores:";
		cin>>n;
		for(int i=0; i<n; i++){
			cout<<"Escribe el DNI:";
			cin>>dni;
			while(dni<10000000){
				cout<<"Escribe un DNI valido(8 digitos):";	//Control de que todos los dni tengan la misma cantidad de digitos
				cin>>dni;
			}
			cout<<"Escribe el codigo:";
			cin>>codigo;
			string DNI=to_string(dni);
			string CODIGO=to_string(codigo);
			Jugador aux(DNI, CODIGO);	//Creacion del jugador
			v.push_back(aux);	//Adicion del jugador al vector
		}
	}
	else if(opc==2){
		for(int i=0; i<5; i++){
			dni=(rand()%99999999);
			while(dni<10000000){	//Control de que todos los dni tengan la misma cantidad de digitos
				dni=(rand()%99999999);
			}
			codigo=(i+1);
			string DNI=to_string(dni);
			string CODIGO=to_string(codigo);
			Jugador aux(DNI, CODIGO);
			v.push_back(aux);
		}
	}
	else{
		cout<<"Error al escribir el modo de introducción"<<endl;
		return 0;
	}
	cout<<"Vector Jugador sin ordenar DNIs:"<<endl;
	for(vector <Jugador>::iterator it=v.begin(); it!=v.end(); ++it){
		cout<<"DNI:"<<it->getDNI()<<"\t"<<"CODIGO:"<<it->getCodigo()<<endl;
	}
	cout<<"Elige el ordenamiento, ascendente(1) o descendente(2):";
	cin>>opc;
	if(opc==1){
		sort(v.begin(), v.end(), ordenarDNIAsc);	//Funcion sort con la funcion ordenarDNIAsc para ordenar de forma ascendente los dnis
	}
	else if(opc==2){
		sort(v.begin(), v.end(), ordenarDNIDesc);	//Funcion sort con la funcion ordenarDNIDesc para ordenar de forma descendente los dnis
	}
	else{
		cout<<"Error al escribir el modo de ordenamiento"<<endl;
		return 0;
	}
	cout<<"Vector Jugador ordenado:"<<endl;
	for(vector <Jugador>::iterator it=v.begin(); it!=v.end(); ++it){
		cout<<"DNI:"<<it->getDNI()<<"\t"<<"CODIGO:"<<it->getCodigo()<<endl;
	}
}
//Fin del programa
