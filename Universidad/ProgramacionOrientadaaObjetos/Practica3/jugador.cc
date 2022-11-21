//Fichero jugador.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include "jugador.h"
#include <fstream>
#include <string>

//Funcion setApuestas(Limpia la lista de apuestaspara introducir las nuevas apuestas en el fichero del jugador específico)
void Jugador::setApuestas(){
    apuestas.clear();
    string fichero=getDNI()+".txt";                        //Lectura del fichero
    ifstream fe;
    fe.open(fichero);                         //Abrir el fichero
    string CODIGO, VALOR, CANTIDAD;
    while(getline(fe, CODIGO, ',')){
        getline(fe, VALOR, ',');
        getline(fe, CANTIDAD, '\n');
        Apuesta a={stoi(CODIGO), stoi(CANTIDAD), VALOR};    //Convertir a valor numerico
        apuestas.push_back(a);                              //Añadimos las apuestas
    }
    fe.close();                                            //Cierre del fichero
}
