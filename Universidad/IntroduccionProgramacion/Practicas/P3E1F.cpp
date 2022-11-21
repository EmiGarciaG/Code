#include <iostream>
using namespace std;
int main() {
int x,menor;
for(int i=5; i>0; i--){
	cout<<"Escriba un numero"<<endl;
	cin>>x;
	if(x<=menor) {
		menor=x;
	}
}
cout<<"El menor es: "<<menor<<endl;
cin.ignore();
cin.get();
}