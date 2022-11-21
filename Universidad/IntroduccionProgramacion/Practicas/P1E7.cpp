#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	float practicas,parcial,examen,nota;
	cout<<"Nota de las practicas: "<<endl;
	cin>>practicas;
	cout<<"Nota del parcial: "<<endl;
	cin>>parcial;
	cout<<"Nota del examen: "<<endl;
	cin>>examen;
	nota=(practicas*0.25)+(parcial*0.25)+(examen*0.5);
	cout<<"La nota final es: "<<nota<<endl;
	cin.ignore();
	cin.get();
    system("pause");
}

