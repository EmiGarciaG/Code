#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int vocales(string cad){
	int count=0;
	int s=cad.size();
	for(int i=0; i<s; i++){
		 cad[i]=toupper(cad[i]);
		if(cad[i]=='A' || cad[i]=='E' || cad[i]=='I' || cad[i]=='O' || cad[i]=='U'){
		count++;
		}
	}
	return count;
}
int main(){
	string cad;
	cout<<"Escribe una cadena para saber cuantas vocales hay:"<<endl;
	getline(cin, cad);
	cout<<vocales(cad)<<endl;
	cin.ignore();
	cin.get();
}