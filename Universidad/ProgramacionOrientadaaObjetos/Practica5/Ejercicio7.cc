//Fichero Ejercicio7.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <ctime>
#include <string>

//Declaracion de los namespaces
using namespace std;

//Declaracion de la plantilla(template) y la clase MiClase
template <class T> class MiClase{
	private:	//Parte privada de la clase MiClase
		T x, y;	//Variables tipo T x e y
	public:		//Parte publica de la clase MiClase
		MiClase(T a, T b){	//Constructor por defecto
			x=a; 
			y=b;
		}
		T div(){	//Funcion tipo T que devuelve la division de las variables x e y
			return x/y;
		}
};

//Declaracion main
int main(){
	int opc=0;	//Variable tipo int opc(para elegir)
	float dividendo=0, divisor=0;	//Variables tipo float dividendo y divisor
	cout<<"Elige si quieres introducir los numeros(1) o que se generen de forma aleatoria(2):";
	cin>>opc;
	cout<<endl;
	srand48(time(NULL));
	if(opc==1){
		cout<<"Escribe el dividendo:";
		cin>>dividendo;
		cout<<"Escribe el divisor:";
		cin>>divisor;
	}
	else if(opc==2){
		cout<<"Se van a generar dos numeros aleatorios del 1 al 100:"<<endl;
		dividendo=(drand48()*100);
		cout<<"Dividendo-->"<<dividendo<<endl;
		divisor=(drand48()*100);
		while(divisor==0){	//Evitamos la division por cero
			divisor=(drand48()*100);
		}
		cout<<"Divisor-->"<<divisor<<endl;
	}
	else{
		cout<<"Error al escribir el modo de introducción"<<endl;
		return 0;
	}
	cout<<endl;
	cout<<"La division es: "<<dividendo<<"/"<<divisor<<endl;
	MiClase <int> entera(dividendo, divisor);	//Objeto "entera" de MiClase
	MiClase <float> real(dividendo, divisor);	//Objeto "real" de MiClase
	cout<<"División entera="<<entera.div()<<endl;
	cout<<"División real="<<real.div()<<endl;
}
//Fin del programa