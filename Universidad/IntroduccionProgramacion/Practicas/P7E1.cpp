#include <iostream>
#include <string>
using namespace std;
int espacios(string cad){
	int count=0; 
	int s=cad.size();
	for(int i=0; i<s; i++){
		if(cad[i]==' '){
		count++;
		}
	}
	return count;
}
int main(){
	string cad;
	cout<<"Escribe una cadena para saber cuantos espacios tiene:"<<endl;
	getline(cin, cad);
	cout<<espacios(cad)<<endl;
	cin.ignore();
	cin.get();
}