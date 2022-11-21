#include <iostream>
using namespace std;
int main() {
	float x,mayor;
	for(int i=0; i>=0; i++) {
		cout<<"Escriba un numero"<<endl;
		cin>>x;
			if(x>=mayor){
			mayor=x;
			}
			if (x<0){
			i=-i;
			}
	}
	cout<<"El mayor es: "<<mayor<<endl;
	cin.ignore();
	cin.get();
}
	