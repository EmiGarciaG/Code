#include <iostream>
using namespace std;
int main() {
		int n,i=1;
		cout<<"Introduce el numero del que quieres saber sus divisores"<<endl;
		cin>>n;
		cout<<"Sus divisores son: "<<endl;
		while(i<=n) {
			if(n%i==0) {
					cout<<i<<endl;
					}
					i++;
		}
		cin.ignore();
		cin.get();
}
