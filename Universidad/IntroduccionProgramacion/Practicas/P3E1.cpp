#include <iostream>
using namespace std;
int main() {
int x,menor,i=5;
while(i>0){
	cout<<"Escriba un numero"<<endl;
	cin>>x;
	if(x<=menor) {
		menor=x;
	}
	i--;
}
cout<<"El menor es: "<<menor<<endl;
cin.ignore();
cin.get();
}