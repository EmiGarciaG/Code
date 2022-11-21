//Fichero ruleta.h
//Declaracion includes para bibliotecas y ficheros.h 
#ifndef RULETA_H
#define RULETA_H
#include "crupier.h"
#include "jugador.h"
#include "persona.h"
#include <list>
#include <ctime>
#include <string>

//Declaracion de namespaces
using namespace std;

//Declaracion clase Ruleta
class Ruleta{  
    private:        //Parte privada de la clase Ruleta
        int banca_, bola_;      //Variables tipo int banca y bola
        list <Jugador> jugadores_;      //Lista jugadores
        Crupier crup_;                  //Se inicia un crupier para la ruleta
    public:          //Parte publica de la clase Ruleta
        Ruleta(Crupier crupier):crup_(crupier){
            bola_=-1; 
            banca_=1000000; 
            srand(time(NULL));
        }//Constructor por defecto
        inline int getBanca() const {return banca_;}    //Funcion tipo int que devuelve la banca
        inline int getBola() const {return bola_;}      //Funcion tipo int que devuelve la bola
        bool setBanca(int BANCA);    //Funcion tipo bool para cambiar el valor de la banca y validar su valor
        bool setBola(int BOLA);      //Funcion tipo bool para cambiar el valor de la bola y validar su valor
        inline Crupier getCrupier() const {return crup_;}       //Funcion tipo crupier que devuelve el crupier
        inline void setCrupier(Crupier &CRUPIER){crup_=CRUPIER;} //Funcion tipo void para cambiar el crupier
        inline list <Jugador> getJugadores() const {return jugadores_;} //Funcion tipo list que devuelve los jugadores de la lista
        bool addJugador(Jugador j); //Funcion tipo void que agrega un jugador
        int deleteJugador(string DNI);  //Funcion tipo void que elimina un jugador 
        int deleteJugador(Jugador j);   //Funcion tipo void que elimina un jugador 
        void escribeJugadores();    //Funcion tipo void que escribe los jugadores de la lista en un fichero
        void leeJugadores();    //Funcion tipo void que lee los jugadores de un fichero
        inline void giraRuleta(){bola_=(rand()%37);}    //Funcion tipo void para cambiar el valor de la bola de forma aleatoria
        void getPremios();      //Funcion tipo void que devuelve los premios en el fichero
};
//Fin declaracion del fichero ruleta.h
#endif

