#include <iostream>
using namespace std;
int main() {
	int x,suma=0,media=0;
	cout<<"Escriba un numero"<<endl;
	cin>>x;
	suma=suma+x;
	while(media<30)
	{
		int n=1;
		cout<<"Escriba un numero"<<endl;
		cin>>x;
		suma+=x;
		n++;
		media=suma/n;
	}
	cout<<"La media es: "<<media<<endl;
	cin.ignore();
	cin.get();
}
