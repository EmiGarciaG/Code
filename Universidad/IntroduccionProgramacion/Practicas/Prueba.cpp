#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int y=0,x=3000;
	int contador=50;
	int cuenta=0;
	cout<<"Introduzca el valor del inicial"<<endl;
	cin>>x;
	while(contador!=0){
		cuenta=((-y/4)+(x/3));
		y=y+cuenta;
		cuenta=((y/4)-(x/3));
		x=x+cuenta;
		cout<<x<<endl;
		cout<<y<<endl;
		contador--;
	}
	cin.ignore();
	cin.get();
    system("pause");
}

