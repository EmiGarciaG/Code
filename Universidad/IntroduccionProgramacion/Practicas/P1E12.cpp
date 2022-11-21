#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int a;
	cout<<"Introduzca el dia de la semana"<<endl;
	cin>>a;
	switch (a) {
	case 1: {
		cout<<"Lunes"<<endl;
	} break;
	case 2: {
		cout<<"Martes"<<endl;
	} break;
	case 3: {
		cout<<"Miercoles"<<endl;
	} break;
	case 4: {
		cout<<"Jueves"<<endl;
	} break;
	case 5: {
		cout<<"Viernes"<<endl;
	} break;
	case 6: {
		cout<<"Sabado"<<endl;
	} break;
	case 7: {
		cout<<"Domingo"<<endl;
	} break;
	default: {
		cout<<"ERROR"<<endl;
	}
}
	cin.ignore();
	cin.get();
    system("pause");
}

