#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void replace(string& cad, char a, char b){
	int s=cad.size();
	for(int i=0; i<s; i++){
		if(cad[i]==a){
			cad[i]=b;
		}
	}
}
int main(){
	string cad;
	char a;
	char b;
	cout<<"Escribe una cadena:"<<endl;
	getline(cin, cad);
	cout<<"Escribe la letra que quieres cambiar:"<<endl;
	cin>>a;
	cout<<"Escribe la letra por la cual quieres cambiar:"<<endl;
	cin>>b;
	replace(cad, a, b);
	cout<<cad<<endl;
	cin.ignore();
	cin.get();
}