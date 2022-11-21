#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char  **argv){
	int a,b,c;
	cout<<"Introduzca dos numeros"<<endl;
	cin>>a>>b;
	cout<<"a="<<
	 a<<" b="<<b<<endl;
	if (a>b) {
	cout<<"Como a es mayor que b intercambiamos su valor"<<endl;
	c=a;
	a=b;
	b=c;
	cout<<"a="<<
	 a<<" b="<<b<<endl;
	}
	cin.ignore();
	cin.get();
    system("pause");
}

