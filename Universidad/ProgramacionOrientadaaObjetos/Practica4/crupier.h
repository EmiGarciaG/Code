//Fichero crupier.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef CRUPIER_H
#define CRUPIER_H
#include "persona.h"
#include <string>

//Declaracion de namespaces
using namespace std;

//Declaracion de la clase Crupier
class Crupier : public Persona{  						//Crupier "hereda" de persona por lo que declaramos su parte publica
    private:                                            //Parte privada de la clase Crupier
        string codigo;                                  //Variable tipo string codigo
    public:
        Crupier(string DNI, string CODIGO, string NOMBRE="", string APELLIDOS="", int EDAD=0, string DIRECCION="", string LOCALIDAD="", string PROVINCIA="", string PAIS=""):Persona(DNI, NOMBRE, APELLIDOS, EDAD, DIRECCION, LOCALIDAD, PROVINCIA, PAIS){
        	codigo=CODIGO;
		} //Constructor por defecto
        inline void setCodigo(string CODIGO){codigo=CODIGO;}   //Funcion tipo void para cambiar el valor del codigo
        inline string getCodigo() const {return codigo;}       //Funcion tipo string que devuelve el codigo
};
//Fin declaracion del fichero crupier.h
#endif