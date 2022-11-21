#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool palindromo(string& cad){
	int s=cad.size();
	for(int j=0; j<s; j++){
		cad[j]=toupper(cad[j]);
	}
	for(int i=0; i<s; i++){
		if(cad[i]!=cad[s-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	string cad;
	cout<<"Escribe una cadena para saber si es un palindromo:"<<endl;
	getline(cin, cad);
	if(palindromo(cad)==true){
		cout<<"Es un palindromo"<<endl;
	}
	else{
		cout<<"No es un palindromo"<<endl;
	}
	cin.ignore();
	cin.get();
}