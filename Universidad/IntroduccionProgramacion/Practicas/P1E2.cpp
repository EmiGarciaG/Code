#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	float angulo,radianes;
	cout<<"Introduzca el valor del angulo"<<endl;
	cin>>angulo;
	radianes=angulo*(3.1415/180);
	cout<<"El angulo convertido en radianes es: "<<radianes<<endl;
    cin.ignore();
	cin.get();
	system("pause");
}

