#include <iostream>
using namespace std;
int main() {
		int n,fac=1;
		cout<<"Introduce el numero de factorial"<<endl;
		cin>>n;
		while(n>0) {
		fac=fac*n;
		n--;
		}
		cout<<"El factorial es: "<<fac<<endl;
		cin.ignore();
		cin.get();
}
