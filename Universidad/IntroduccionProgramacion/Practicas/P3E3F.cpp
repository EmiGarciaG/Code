#include <iostream>
using namespace std;
int main() {
		int n,div=0;
		cout<<"Introduce el numero para saber si es o no primo"<<endl;
		cin>>n;
		if(n>=0){
		cout<<"Sus divisores son: "<<endl;
			for(int i=1; i<=n;i++) {
				if(n%i==0) {
						cout<<i<<endl;															//El numero dos es considerado primo, mientras que 1 no//
						div++;
						}
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
