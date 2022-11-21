#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void fijaValorAleatorio( int v[], int n, int max){
	int secs=time(0);
	srand(secs);
	for(int i=0; i<n; i++){
		v[i]=rand()%max;
	cout<<v[i]<<" ";
	}
}
int main(){
	int n,max;
	cout<<"Escribe la cantidad de elementos que quieres que genere"<<endl;
	cin>>n;
	cout<<"Escribe el rango de los numeros aleatorios"<<endl;
	cin>>max;
	int v[n];
	fijaValorAleatorio(v, n, max);
	cin.ignore();
	cin.get();
}