#include <iostream>
using namespace std;
int main() {
		int n,suma=0;
		cout<<"Introduce el numero"<<endl;
		cin>>n;
		while(n>0) {
			if(n%2!=0) {
		suma=suma+n;
		}
		n--;
		}
		cout<<"La suma de los numeros impares es: "<<suma<<endl;
		cin.ignore();
		cin.get();
}
