#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float x,raiz;
	cout<<"Introduzca un valor para x"<<endl;
	cin>>x;
	if(x>0) {
		raiz=sqrt(x);
		cout<<"La raiz de x es: "<<raiz<<endl;
	}
   else {
	cout<<"ERROR"<<endl;
	}
	cin.ignore();
	cin.get();
    system("pause");
}

