//Fichero jugador.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"
#include <string>
#include <list>

//Declaracion de namespaces
using namespace std;

//Declaracion struct Apuesta
struct Apuesta{
    int tipo, cantidad;         //Variable tipo int tipo y cantidad
    string valor;               //Variable tipo string valor
};

//Declaracion de la clase Jugador
class Jugador : public Persona{                         //Jugador "hereda" de persona por lo que declaramos su parte publica
    private:                                            //Parte privada de la clase Jugador
        int dinero;                                     //Variable tipo int dinero
        string codigo;                                  //Variable tipo string codigo
        list <Apuesta> apuestas;                        //Declaracion lista de apuestas
    public:                                             //Parte publica de la clase Jugador
        Jugador(string DNI, string CODIGO, string NOMBRE="", string APELLIDOS="", int EDAD=0, string DIRECCION="", string LOCALIDAD="", string PROVINCIA="", string PAIS=""):Persona(DNI, NOMBRE, APELLIDOS, EDAD, DIRECCION, LOCALIDAD, PROVINCIA, PAIS){
            codigo=CODIGO; 
            dinero=1000;
        } //Constructor por defecto
        inline void setCodigo(string CODIGO){codigo=CODIGO;} //Funcion tipo void para cambiar el valor del codigo
        inline string getCodigo() const {return codigo;}     //Funcion tipo string que devuelve el codigo
        inline void setDinero(int DINERO){dinero=DINERO;}    //Funcion tipo void para cambiar el valor del dinero
        inline int getDinero() const {return dinero;}        //Funcion tipo int que devuelve el dinero
        inline list <Apuesta> getApuestas() const {return apuestas;} //Funcion tipo list que devuelve las apuestas
        void setApuestas(); //Funcion tipo void para cambiar las apuestas
};
//Fin declaracion del fichero jugador.h
#endif