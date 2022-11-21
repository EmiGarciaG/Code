#include <iostream>
using namespace std;
void lee(float v[], int n){
	for(int i=0; i<n;i++){
		cin>>v[i];
	}
}
	void imprime(float v[], int n){
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
}
int main() {
	int n;
	cout<<"Escribe la cantidad de numeros que quieras meter en el vector"<<endl;
	cin>>n;
	cout<<"Escribe los componentes del vector"<<endl;
	float v[n];
	lee(v, n);
	imprime(v, n);
	cin.ignore();
	cin.get();
}