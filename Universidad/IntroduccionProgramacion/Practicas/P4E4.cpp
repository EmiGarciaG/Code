#include <iostream>
using namespace std;
void divisores(int v){
int i=1;
while(i<=v) {
			if(v%i==0) {																												//La funci�n se aplicar� a los n�meros positivos
					cout<<i<<endl;
					}
					i++;
		}
}
int main() {
		int n;
		cout<<"Introduce el numero del que quieres saber sus divisores"<<endl;
		cin>>n;
		if(n==0){
		cout<<"Sus divisores son infinitos"<<endl;
		}
		else{
		while(n<0){
		cout<<"Introduce el numero positivo del que quieres saber sus divisores"<<endl;
		cin>>n;
		}
		cout<<"Sus divisores son:  "<<endl;
		divisores(n);
		}
		cin.ignore();
		cin.get();
}
