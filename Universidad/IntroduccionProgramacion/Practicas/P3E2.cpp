#include <iostream>
using namespace std;
int main() {
	float x=0,mayor;
	while(x>=0) {
		cout<<"Escriba un numero"<<endl;
		cin>>x;
			if(x>=mayor){
			mayor=x;
			}
	}
	cout<<"El mayor es: "<<mayor<<endl;
	cin.ignore();
	cin.get();
}
	