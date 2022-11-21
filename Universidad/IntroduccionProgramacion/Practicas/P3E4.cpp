#include <iostream>
using namespace std;
int main() {
		int n,i;
		cout<<"Introduce el numero del que quieres saber sus divisores"<<endl;
		cin>>n;
		i=n;
		cout<<"Sus divisores son: "<<endl;
		while(i>=1) {
			if(n%i==0) {
					cout<<i<<endl;
					}
					i--;
		}
		cin.ignore();
		cin.get();
}
