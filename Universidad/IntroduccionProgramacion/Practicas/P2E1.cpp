#include <iostream>
using namespace std;
int main() {
		float media;
		int a,b=0,n=0;
		cout<<"Introduzca el valor"<<endl;
		cin>>a;
		b=a;
		while(a>0) {
		b=b+a;
		cout<<"Introduzca el siguiente valor"<<endl;
		cin>>a;
		n++;
		}
		media=b/n;
		cout<<"La media es: "<<media<<endl;
		cin.ignore();
		cin.get();
	}
	