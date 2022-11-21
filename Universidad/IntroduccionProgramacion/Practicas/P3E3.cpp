#include <iostream>
using namespace std;
int main() {
		int n,i=1,div=0;
		cout<<"Introduce el numero para saber si es o no primo"<<endl;
		cin>>n;
		if(n>=0){
		cout<<"Sus divisores son: "<<endl;
			while(i<=n) {
				if(n%i==0) {
						cout<<i<<endl;
						div++;
						}
						i++;
			}
			if(div==2) {
			cout<<"El numero es primo"<<endl;
			}
			else {
			cout<<"El numero no es primo"<<endl;
			}
		}
		cin.ignore();
		cin.get();
}
