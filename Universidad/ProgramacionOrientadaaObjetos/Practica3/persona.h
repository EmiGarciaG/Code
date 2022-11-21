//Fichero persona.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef PERSONA_H
#define PERSONA_H
#include <string>

//Declaracion de namespaces
using namespace std;

//Declaracion clase Persona
class Persona{
    private:            //Parte privada de la clase Persona
        string dni, nombre, apellidos, direccion, localidad, provincia, pais;   //Variables tipo string dni, nombre, apellidos, direccion, localidad, provincia, pais
        int edad;       //Variable tipo int edad
    public:             //Parte publica de la clase Persona
        Persona(string DNI, string NOMBRE="", string APELLIDOS="", int EDAD=0, string DIRECCION="", string LOCALIDAD="", string PROVINCIA="", string PAIS=""){
            dni=DNI;
            nombre=NOMBRE;
            apellidos=APELLIDOS;
            edad=EDAD;
            direccion=DIRECCION;
            localidad=LOCALIDAD;
            provincia=PROVINCIA;
            pais=PAIS;
        } //Constructor por defecto
        inline void setDNI(string DNI){dni=DNI;}    //Funcion tipo void para cambiar el valor del dni
        inline string getDNI() const {return dni;}  //Funcion tipo string que devuelve el dni
        inline void setNombre(string NOMBRE){nombre=NOMBRE;}    //Funcion tipo void para cambiar el valor del nombre
        inline string getNombre() const {return nombre;}    //Funcion tipo string que devuelve el nombre   
        inline void setApellidos(string APELLIDOS){apellidos=APELLIDOS;}    //Funcion tipo void para cambiar el valor de los apellidos
        inline string getApellidos() const {return apellidos;}  //Funcion tipo string que devuelve los apellidos
        inline string getApellidosyNombre() const {return apellidos+", "+nombre;}   //Funcion tipo string que devuelve los apellidos,nombre
        inline void setDireccion(string DIRECCION){direccion=DIRECCION;}    //Funcion tipo void para cambiar el valor de la direccion
        inline string getDireccion() const {return direccion;}  //Funcion tipo string que devuelve la direccion
        inline void setLocalidad(string LOCALIDAD){localidad=LOCALIDAD;}    //Funcion tipo void para cambiar el valor de la localidad
        inline string getLocalidad() const {return localidad;}  //Funcion tipo string que devuelve la localidad
        inline void setProvincia(string PROVINCIA){provincia=PROVINCIA;}    //Funcion tipo void para cambiar el valor de la provincia
        inline string getProvincia() const {return provincia;}  //Funcion tipo string que devuelve la provincia
        inline void setPais(string PAIS){pais=PAIS;}    //Funcion tipo void para cambiar el valor del pais
        inline string getPais() const {return pais;}    //Funcion tipo string que devuelve el pais
        bool setEdad(int EDAD); //Funcion tipo bool para cambiar el valor de la edad y comprobar que es valida
        inline int getEdad() const {return edad;}   //Funcion tipo int que devuelve la edad
        bool mayor();   //Funcion tipo bool para comprobar la mayoria de edad
};
//Fin declaracion del fichero persona.h
#endif

