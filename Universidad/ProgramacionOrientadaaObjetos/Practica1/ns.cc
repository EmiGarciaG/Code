//Fichero ns.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include <iostream>

//Declaracion de namespaces
namespace n1{
    int a;
    int b;
}

namespace n2{
    int a;
    int c;
}

using namespace std;

//Declaracion main
int main(void){
    int a=55; //Variable a con valor 55 
    n1::a=0;  //Variable a con valor 0 en namespace n1
    n2::a=2;  //Variable a con valor 2 en namespace n2
    cout<<"n1::a="<<n1::a<<endl;    //Salida por pantalla del valor a del namespace n1
    cout<<"n2::a="<<n2::a<<endl;    //Salida por pantalla del valor a del namespace n2
    cout<<"a="<<a<<endl;            //Salida por pantalla del valor a
}
//Fin del programa