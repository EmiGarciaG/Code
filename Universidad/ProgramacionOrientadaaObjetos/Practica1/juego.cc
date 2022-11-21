//Fichero dados.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <vector>
#include "dados.h"
//Declaracion namespace
using namespace std;

//Declaracion main
int main(){
	//Inicio de los dados d
	Dados d;
	int opcion=0, dado=0;		//Variables tipo int opcion y dado
	int v[5];					//Vector int de los ultimos valores
	while(opcion!=14){			
		switch(opcion){			//Se elige una opcion
			case 1:	//Lanzamiento de los dados
				d.lanzamiento();
				cout<<"Se han lanzado los dados"<<endl;
			break;

			case 2:	//Devolver el valor del dado 1
				cout<<"Dado 1: "<<d.getDado1()<<endl;
			break;
			
			case 3:	//Devolver el valor del dado 2
				cout<<"Dado 2: "<<d.getDado2()<<endl;
			break;

			case 4:	//Devolver la suma de los dos dados
				cout<<"Suma: "<<d.getSuma()<<endl;
			break;
				
			case 5: //Devolver la diferencia entre los dos dados
				cout<<"Diferencia: "<<d.getDiferencia()<<endl;
			break;

			case 6:	//Cambiar valor dado 1
				cout<<"Escriba el valor del dado 1"<<endl;
				cin>>dado;
				if(d.setDado1(dado)==false){
					cout<<"Valor denegado"<<endl; //Se evitan valores erroneos
				}
			break;

			case 7: //Cambiar valor dado 2
				cout<<"Escriba el valor del dado 2"<<endl;
				cin>>dado;
				if(d.setDado2(dado)==false){
					cout<<"Valor denegado"<<endl; //Se evitan valores erroneos
				}
			break;

			case 8: //Devolver la media de los valores del dado 1
				cout<<"Media dado 1: "<<d.getMedia1()<<endl;			
			break;

			case 9: //Devolver la media de los valores del dado 2
				cout<<"Media dado 2: "<<d.getMedia2()<<endl;
			break;	

			case 10: //Devolver las veces que ha cambiado el valor del dado 1
				cout<<"Lanzamientos y cambios dado 1: "<<d.getLanzamientos1()<<endl;
			break;

			case 11: //Devolver las veces que ha cambiado el valor del dado 2
				cout<<"Lanzamientos y cambios dado 2: "<<d.getLanzamientos2()<<endl;
			break;

			case 12:
				d.getUltimos1(v);
				cout<<"Ultimos valores dado 1: "<<endl;
				for(int i=0; i<5; i++){
        			cout<<"["<<i<<"]: "<<v[i]<<endl;  
    			}
			break;

			case 13:
				d.getUltimos2(v);
				cout<<"Ultimos valores dado 2: "<<endl;
				for(int i=0; i<5; i++){
        			cout<<"["<<i<<"]: "<<v[i]<<endl;  
    			}
			break;

			default:
			break;

		}
		//Menu para elegir la opcion que queremos
		cout<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"Elija una opción:"<<endl;
		cout<<"	1.Lanzar dados"<<endl;
		cout<<"	2.Obtener Dado1"<<endl;
		cout<<"	3.Obtener Dado2"<<endl;
		cout<<"	4.Obtener Suma Dados"<<endl;
		cout<<"	5.Diferencia Dados"<<endl;	
		cout<<"	6.Cambiar Dado1"<<endl;
		cout<<"	7.Cambiar Dado2"<<endl;
		cout<<"	8.Obtener Media Dado1"<<endl;
		cout<<"	9.Obtener Media Dado2"<<endl;
		cout<<"	10.Obtener Lanzamientos Dado1"<<endl;
		cout<<"	11.Obtener Lanzamientos Dado2"<<endl;
		cout<<"	12.Obtener Ultimos Valores Dado1"<<endl;
		cout<<"	13.Obtener Ultimos Valores Dado2"<<endl;
		cout<<"	14.Salir"<<endl;
		cout<<"Opcion:";
		cin>>opcion;
	}
	return 0;
}
//Fin del programa