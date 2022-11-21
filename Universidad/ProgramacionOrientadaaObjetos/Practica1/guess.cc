//Fichero guess.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>
#include <ctime>
#include <cstdlib>

//Declaracion de namespaces
using namespace std;

//Declaracion main
int main(){
    srand(time(NULL));                      //Semilla del rand time(NULL) returns “UNIX Epoch”, this is seconds since 00:00:00 1 January 1970
    int x;                                  //Declaracion variable tipo int x 
    int numero=(rand()%10);                 //Declaracion variable tipo int numero con valor entre 0 y 10
    bool encontrado=false;                  //Declaracion variable tipo bool encontrado con valor false
    cout<<"Adivine el numero:"<<endl;           //Salida por pantalla pidiendo la adivinacion del numero aleatorio
    cin>>x;                                 //Entrada por teclado del valor introducido por el usuario
    while(!encontrado){                     //Bucle hasta la adivinacion del numero
        if(numero==x){                      //Acierto 
            cout<<"Felicidades"<<endl;
            encontrado=true;
        }
        else{                               //Fallo
            cout<<"Pruebe de nuevo:"<<endl;
            cin>>x;
        }
    }
}
//Fin del programa
