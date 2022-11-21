#include <iostream>
using namespace std;
bool espar(int v){
	if (v%2==0) {
		return true;
	}
	else {
	return false;
	}
}
int main(){
	int n;
	cout<<"Escribe un numero para saber si es par"<<endl;
	cin>>n;
	if (espar(n)==true){
	cout<<"Es par"<<endl;
	}
	if (espar(n)==false){
	cout<<"No es par"<<endl;
	}
	cin.ignore();
	cin.get();
}