#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string DNI(string& cad){
	int s=cad.size();
	string res;
	if(s!=9){
		res="El dni debe tener 9 caracteres";
		return res;
	}
	for(int i=0; i<s-1; i++){
		if (!isdigit(cad[i])){
			res="Los primeros 8 caracteres deben ser numeros";
			return res;
		}
	}
	string letras="TRWAGMYFPDXBNJZSQVHLCKE";
	int num= stoi(cad);
	if(cad[8]!=letras[(num%23)]){
		res="La letra no corresponde con los datos numericos o es minuscula";
		return res;
	}
	res="Verdadero";
	return res;
}
int main(){
	string cad;
	cout<<"Escribe el DNI para comprobarlo: "<<endl;
	getline(cin, cad);
	cout<<DNI(cad)<<endl;
	while(DNI(cad)!="Verdadero"){
		cout<<"Escribe de nuevo el DNI: "<<endl;
		getline(cin, cad);
		cout<<DNI(cad)<<endl;
	}
	cin.ignore();
	cin.get();
}