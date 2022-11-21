#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int find(string a, string b){
	int s=a.size();
	int z=b.size();
	for(int i=0; i<s; i++){
		if(a[i]==b[0]){
			int aux=0;
			bool encontrado=true;
			while((encontrado==true) && (aux<z)){
				if(a[i+aux]!=b[aux]){
					encontrado=false;
				}
				aux++;
			}
			if(aux==z){
				return i++;
			}
		}
	}
	return -1;
}
int main(){
	string a;
	string b;
	cout<<"Escribe la cadena:"<<endl;
	getline(cin, a);
	cout<<"Escribe lo que quieres buscar y saber en que posicion aparece:"<<endl;
	getline(cin, b);
	cout<<"Posiciones: "<<endl; //Si es -1 significa que no esta
	cout<<find(a,b)<<endl; 			
	cin.ignore();
	cin.get();
}