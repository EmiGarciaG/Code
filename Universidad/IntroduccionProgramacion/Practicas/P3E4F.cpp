#include <iostream>
using namespace std;
int main() {
		int n;
		cout<<"Introduce el numero del que quieres saber sus divisores"<<endl;
		cin>>n;
		cout<<"Sus divisores son: "<<endl;
		for(int i=n; i>=0; i--) {
			if(n%i==0) {
					cout<<i<<endl;
					}
		}
		cin.ignore();
		cin.get();
}
