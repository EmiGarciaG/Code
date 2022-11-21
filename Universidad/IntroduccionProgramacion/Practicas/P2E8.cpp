#include <iostream>
using namespace std;
int main() {
	int x=0,y=1,n;
	cout<<"Indique el numero de la sucesion"<<endl;
	cin>>n;
	cout<<"Sucesion"<<endl;
	cout<<x<<endl;
	cout<<y<<endl;
	while(n>2) {
	int sucesion;
	sucesion=x+y;
	x=y;
	y=sucesion;
	cout<<sucesion<<endl;
	n--;
	}
	cin.ignore();
	cin.get();
}
	
	
	