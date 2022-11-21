//Fichero dados.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef DADOS_H
#define DADOS_H
#include <cmath>
#include <vector>
#include <iostream>
//Declaracion de los namespaces
using namespace std;

//Declaracion de la clase Dados
class Dados{
    private:                                            //Parte privada de la clase Dados
        int d1, media1, count1;                         //Declaracion variables tipo int d1, media1, count1
        int d2, media2, count2;                         //Declaracion variables tipo int d2, media2, count
        vector <int> v1, v2;                            //Declaracion vectores tipo int v1, v2
        void pushDado1(int &valor);                     //Funcion tipo void para guardar el ultimo valor del dado1
        void pushDado2(int &valor);                     //Funcion tipo void para guardar el ultimo valor del dado2
    public:                                             //Parte publica de la clase Dados
        Dados();                                        //Constructor por defecto
        Dados(int &dado1, int &dado2);                  //Constructor con los dos dados escritos por el usuario
        void lanzamiento();                             //Funcion tipo void lanzamiento de dados
        inline int getLanzamientos1() const {return count1;}   //Funcion tipo int que devuelve las veces que se ha lanzado el dado1 o se ha cambiado su valor
        inline int getLanzamientos2() const {return count2;}   //Funcion tipo int que devuelve las veces que se ha lanzado el dado2 o se ha cambiado su valor
        inline int getDado1() const {return d1;}        //Funcion tipo int que devuelve el valor del dado1
        inline int getDado2() const {return d2;}        //Funcion tipo int que devuelve el valor del dado1
        bool setDado1(int dado1);                       //Funcion tipo bool para cambiar el valor del dado1 si su valor esta entre el 1-6
        bool setDado2(int dado2);                       //Funcion tipo bool para cambiar el valor del dado2 si su valor esta entre el 1-6
        inline int getSuma() const {return d1+d2;}      //Funcion tipo int que devuelve la suma de los valores de ambos dados    
        float getMedia1() const;                        //Funcion tipo float que devuelve la media de todos los valores del dado1
        float getMedia2() const;                        //Funcion tipo float que devuelve la media de todos los valores del dado2
        inline int getDiferencia() const {return abs(d1-d2);}  //Funcion tipo int que devuelve la diferencia entre los dados
        void getUltimos1(int v[]) const;                //Funcion tipo void que devuelve un vector con los ultimos valores del dado1                  
        void getUltimos2(int v[]) const;                //Funcion tipo void que devuelve un vector con los ultimos valores del dado2
        friend ostream &operator<<(ostream &out, const Dados &d);   //Insertador <<
        friend istream &operator>>(istream &in, Dados &d);  //Extractor >>
};
//Fin declaracion del fichero dados.h
#endif



