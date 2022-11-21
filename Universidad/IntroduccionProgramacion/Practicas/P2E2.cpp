#include <iostream>
using namespace std;
int main() {
		int n,suma=0;
		cout<<"Introduce el numero de factorial"<<endl;
		cin>>n;
		while(n>0) {
		suma=suma+n;
		n--;
		}
		cout<<"El sumatorio es: "<<suma<<endl;
		cin.ignore();
		cin.get();
}
