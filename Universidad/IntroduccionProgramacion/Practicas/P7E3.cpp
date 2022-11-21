#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void convierte_a_mayusculas(string& cad){
	int s=cad.size();
	for(int i=0; i<s; i++){
		 cad[i]=toupper(cad[i]);
	}
	cout<<cad<<endl;
}
int main(){
	string cad;
	cout<<"Escribe una cadena para poner las letras en mayusculas:"<<endl;
	getline(cin, cad);
	convierte_a_mayusculas(cad);
	cin.ignore();
	cin.get();
}