#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int digitos(string cad){
	int count=0; 
	int s=cad.size();
	for(int i=0; i<s; i++){
		if(isdigit(cad[i])){
		count++;
		}
	}
	return count;
}
int main(){
	string cad;
	cout<<"Escribe una cadena para saber cuantos numeros tiene:"<<endl;
	getline(cin, cad);
	cout<<digitos(cad)<<endl;
	cin.ignore();
	cin.get();
}