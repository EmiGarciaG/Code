#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int a;
	cout<<"Introduzca un numero de la semana"<<endl;
	cin>>a;
	if(a<=7 && a>=1) {
		if(a>=1 && a<=5) {
		cout<<"Dia laborable"<<endl;
		}
		else {
		cout<<"Fin de semana"<<endl;
		}
	}
	else {
	cout<<"ERROR"<<endl;
	}
	cin.ignore();
	cin.get();
    system("pause");
}

