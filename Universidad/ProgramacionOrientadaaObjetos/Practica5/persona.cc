//Fichero persona.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include "persona.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <string>

//Declaracion de namespaces
using namespace std;

//Funcion setEdad(Cambiar la edad y validar su valor)
bool Persona::setEdad(int EDAD){
    if(EDAD<0){
        return false;
    }
    else{
        edad=EDAD;
        return true;
    }
}

//Funcion mayor(Comprobación de la mayoría de edad)
bool Persona::mayor(){
    if(getEdad()>18){
        return true;
    }
    else{
        return false;
    }
}