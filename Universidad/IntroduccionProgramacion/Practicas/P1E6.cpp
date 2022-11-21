#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	float a,b,c,d,media;
	cout<<"Introduzca cuatro numeros"<<endl;
	cin>>a>>b>>c>>d;
	media=(a+b+c+d)/4;
	cout<<"La media de los cuatro numeros es: "<<media<<endl;
	cin.ignore();
	cin.get();
    system("pause");
}

