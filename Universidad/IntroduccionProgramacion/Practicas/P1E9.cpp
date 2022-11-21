#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int x;
	cout<<"Introduzca el numero del mes"<<endl;
	cin>>x;
	if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12) {
	cout<<"El mes tiene 31 dias"<<endl;
	}
	if (x==4 || x==6 || x==9 || x==11) {
	cout<<"El mes tiene 30 dias"<<endl;
	}
	if(x==2) {
	cout<<"El mes tiene 28 dias"<<endl;
	}
	cin.ignore();
	cin.get();
    system("pause");
}

