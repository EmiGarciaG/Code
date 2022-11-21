//Fichero ruleta.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include "ruleta.h"
#include <iostream>
#include <fstream>

//Declaracion de namespaces
using namespace std; 

//Funcion escribeJugadores(Rellena el fichero con la lista de los jugadores)
void Ruleta::escribeJugadores(){
    string fichero="jugadores.txt";    
    ofstream fs;
    fs.open(fichero);
    fs.clear();
    list <Jugador>::iterator it;
    for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
        fs<<it->getDNI()<<","<<it->getCodigo()<<","<<it->getNombre()<<","<<it->getApellidos()<<","<<it->getDireccion()<<","<<it->getLocalidad()<<","<<it->getProvincia()<<","<<it->getPais()<<","<<it->getDinero()<<endl;
    }
    fs.close();
}
//Funcion addJugador(Añade un jugador a la lista si no existe y cre un fichero con su dni)
bool Ruleta::addJugador(Jugador j){
    list <Jugador>::iterator it;
    for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
        if(j.getDNI()==it->getDNI()){
            return false;
        }
    }
    jugadores_.push_back(j);
    string fichero=j.getDNI()+".txt";
    ofstream fs;
    fs.open(fichero);
    fs.close();
    return true;
}
//Funcion deleteJugador(Elimina un jugador de la lista escribiendo su dni)
int Ruleta::deleteJugador(string DNI){
    if(jugadores_.empty()){
        return -1;
    }
    list <Jugador>::iterator it;
    for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
        if(DNI==it->getDNI()){
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}
//Funcion deleteJugador(Elimina un jugador de la lista)
int Ruleta::deleteJugador(Jugador j){
    if(jugadores_.empty()){
        return -1;
    }
    list <Jugador>::iterator it;
    for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
        if(j.getDNI()==it->getDNI()){
            jugadores_.erase(it);
            return 1;
        }
    }
    return -2;
}
//Funcion leeJugadores(Escribe por pantalla los jugadores escritos en el fichero)
void Ruleta::leeJugadores(){
    jugadores_.clear();
    string fichero="jugadores.txt";   
    ifstream fe;
    fe.open(fichero);
    char edad[100];
    string dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais, dinero;
    while(getline(fe, dni, ',')){
        getline(fe, codigo, ',');
        getline(fe, nombre, ',');
        getline(fe, apellidos, ',');
        getline(fe, direccion, ',');
        getline(fe, localidad, ',');
        getline(fe, provincia, ',');
        getline(fe, pais, ',');
        getline(fe, dinero, '\n');
        Jugador j(dni,codigo, nombre, apellidos, atoi(edad), direccion ,localidad, provincia, pais);
        j.setDinero(stoi(dinero));
        jugadores_.push_back(j);
    }
    fe.close();
}
//Funcion getPremios(Realiza el cálculo de los premios de acuerdo a la puesta y el tipo de apuesta de los jugadores)
void Ruleta::getPremios(){
    list <Jugador>::iterator it;
    list <Apuesta> apuestas;
    list <Apuesta>::iterator ita;
    for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
        it->setApuestas();
        apuestas=it->getApuestas();
        for(ita=apuestas.begin(); ita!=apuestas.end(); ita++){
            switch(ita->tipo){
                case 1:
                    if(getBola()==stoi(ita->valor)){
                        it->setDinero(it->getDinero()+35*ita->cantidad);
                        setBanca(getBanca()-35*ita->cantidad);
                    }
                    else{
                        it->setDinero(it->getDinero()-ita->cantidad);
                        setBanca(getBanca()+ita->cantidad);
                    }
                break;
                case 2:
                    if(ita->valor=="rojo"){
                        if(getBola()==(1|3|5|7|9|12|14|16|18|19|21|23|25|27|30|32|34|36)){
                            it->setDinero(it->getDinero()+ita->cantidad);
                            setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                    else if(ita->valor=="negro"){
                        if(getBola()==(2|4|6|8|10|11|13|15|17|20|22|24|26|28|29|31|33|35)){
                            it->setDinero(it->getDinero()+ita->cantidad);
                            setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                break;
                case 3:
                    if(ita->valor=="par"){
                        if(getBola()%2==0 && getBola()!=0){
                        it->setDinero(it->getDinero()+ita->cantidad);
                        setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                    else if(ita->valor=="impar"){
                        if(getBola()%2!=0){
                        it->setDinero(it->getDinero()+ita->cantidad);
                        setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                break;
                case 4:
                     if(ita->valor=="alto"){
                        if(getBola()>=19 && getBola()<=36){
                            it->setDinero(it->getDinero()+ita->cantidad);
                            setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                    else if(ita->valor=="bajo"){
                        if(getBola()>=1 && getBola()<=18){
                            it->setDinero(it->getDinero()+ita->cantidad);
                            setBanca(getBanca()-ita->cantidad);
                        }
                        else{
                            it->setDinero(it->getDinero()-ita->cantidad);
                            setBanca(getBanca()+ita->cantidad);
                        }
                    }
                break;
                default:
                break;
            }
        }
    }
}
//Funcion setBanca(Cambiar la banca y validar su valor)
bool Ruleta::setBanca(int BANCA){
    if(BANCA<0){
        return false;
    }
    else{
        banca_=BANCA;
        return true;
    }
}
//Funcion setBanca(Cambiar la bola y validar su valor)
bool Ruleta::setBola(int BOLA){
    if(BOLA>=0 && BOLA<=36){
        bola_=BOLA;
        return true;
    }
    else{
        return false;
    }
}

