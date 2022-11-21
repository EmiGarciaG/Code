#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string concatena(string a, string b){
	string cad=a+b;
	return cad;
}
int main(){
	string a;
	string b;
	cout<<"Escribe una cadena:"<<endl;
	getline(cin, a);
	cout<<"Escribe la cadena que quieres sumar:"<<endl;
	getline(cin, b);
	cout<<concatena(a, b)<<endl;
	cin.ignore();
	cin.get();
}