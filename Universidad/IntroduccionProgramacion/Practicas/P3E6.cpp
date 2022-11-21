#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int main() {
	std::srand(time(0));
	int secreto= rand() % 1000;
	cout<<"Intente adivinar el numero secreto"<<endl;
	int x,y;
	cin>>x;
	while(x!=secreto)
	{
		y=x-secreto;
		if(abs(y)<=100)
		{
			cout<<"Estas cerca,"<<endl;
			if(x>secreto)
			{
			cout<<"es mas bajo"<<endl;
			}
			if(x<secreto)																																//Para hacerlo más fácil, la diferencia entre el aleatorio y el escrito en valor absoluto,dependiendo si supera 100 o no, avisa cuanto de cerca o lejos está//
			{																																					//En cambio el ejercicio pedido, seria quitando la parte del valor absoluto y los if del mismo//
			cout<<"es mas grande"<<endl;
			}
		}
		else
		{
				cout<<"Estas lejos,"<<endl;
				if(x>secreto)
				{
				cout<<"es mas bajo"<<endl;
				}
				if(x<secreto)
				{
				cout<<"es mas grande"<<endl;
				}
		}
		cin>>x;
	}
	cout<<"Felicidades acertaste"<<endl;
	cin.ignore();
	cin.get();
}

	