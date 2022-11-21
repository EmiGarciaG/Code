//Fichero dados.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <string>
#include "ruleta.h"
//Declaracion namespace
using namespace std;

//Declaracion main
int main(){
	Crupier c("33XX","codigo1");
  	Ruleta r(c);
	int opcion=0, valor=0;
	string DNI, CODIGO;	
	while(opcion!=7){
		switch(opcion){
			case 1:
				r.leeJugadores(); 
			break;

			case 2:
				r.escribeJugadores();
			break;
			
			case 3:
				//cout<<r.getEstadoRuleta()<<endl;
			break;

			case 4:
				r.giraRuleta();
				cout<<"El numero que ha salido es: "<<r.getBola()<<endl;
				r.getPremios();
			break;
				
			case 5:
				cout<<"Escribe el dni del jugador que quieres borrar: "<<endl;
				cin>>DNI;
				r.deleteJugador(DNI);
			break;

			case 6:
				cout<<"Escribe el dni del jugador que quieres añadir: "<<endl;
				cin>>DNI;
				cout<<"Escribe el codigo del jugador que quieres añadir: "<<endl;
				cin>>CODIGO;
				Jugador jadd(DNI, CODIGO);
				r.addJugador(jadd);
			break;

			default:
			break;

		}
		cout<<"Elija una opción:"<<endl;
		cout<<"	1.Cargar los jugadores del fichero jugadores.txt"<<endl;
		cout<<"	2.Guardar los jugadores en jugadores.txt"<<endl;
		cout<<"	3.Ver el estado de la ruleta, el dinero de la banca y el de los jugadores"<<endl;
		cout<<"	4.Hacer girar la ruleta mostrando el número que ha salido, los premios de cada jugador y lo que gana/pierde la banca"<<endl;
		cout<<"	5.Eliminar un jugador de la mesa"<<endl;	
		cout<<"	6.Añadir un jugador a la mesa"<<endl;
		cout<<"	7.Salir del programa"<<endl;
		cin>>opcion;
	}
	return 0;
}