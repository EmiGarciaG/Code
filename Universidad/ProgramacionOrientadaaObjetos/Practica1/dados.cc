//Fichero dados.cc
//Declaracion includes para bibliotecas y ficheros.h 
#include "dados.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std; 

//Declaracion constructor por defecto
Dados::Dados(){
    d1=d2=1;
    srand(time(NULL));
    count1=count2=0;
    media1=media2=0;
    v1.resize(5,0);
    v2.resize(5,0);
}
//Declaracion constructor con los dos dados introducidos
Dados::Dados(int &dado1, int &dado2){
    d1=dado1;
    d2=dado2;
    srand(time(NULL));
    count1=count2=0;
    media1=media2=0;
    v1.resize(5,0);
    v2.resize(5,0);
}
//Funcion lanzamiento(Cambia aleatoriamente el valor de los dados, agregando su valor para la media y contando el lanzamiento)
void Dados::lanzamiento(){
    d1=((rand()%6)+1);
    pushDado1(d1);
    media1=media1+d1;
    d2=((rand()%6)+1);
    pushDado2(d2);
    media2=media2+d2;
    count1++;
    count2++;
}
//Funcion setDado1(Cambia el valor del dado 1 por el introducido por el usuario, validando su valor)
bool Dados::setDado1(int dado1){
    if(dado1>=1 && dado1<=6){
        d1=dado1;
        media1=media1+d1;
        count1++;
        pushDado1(d1);
        return true;
    }
    return false;
}
//Funcion setDado2(Cambia el valor del dado 2 por el introducido por el usuario, validando su valor)
bool Dados::setDado2(int dado2){
    if(dado2>=1 && dado2<=6){
        d2=dado2;
        media2=media2+d2;
        count2++;
        pushDado2(d2);
        return true;
    }
    return false;
}
//Funcion pushDado1(En el vector de los últimos 5 valores cambia la posición 0 por el último valor al primer dado)
void Dados::pushDado1(int &valor){
    for(int i=4; i>0; i--){
        v1[i]=v1[i-1];
    }
    v1[0]=valor;
}
//Funcion pushDado2(En el vector de los últimos 5 valores cambia la posición 0 por el último valor al segundo dado)
void Dados::pushDado2(int &valor){
    for(int i=4; i>0; i--){
        v2[i]=v2[i-1];
    }
    v2[0]=valor;
}
//Funcion getMedia1(Devuelve la media de los últimos valores que ha obtenido el dado 1)
float Dados::getMedia1() const{
    if(count1==0){
        return 0;
    }
    float media=(float) media1 / (float) count1;
    return media;
}
//Funcion getMedia2(Devuelve la media de los últimos valores que ha obtenido el dado 2)
float Dados::getMedia2() const{
    if(count2==0){
        return 0;
    }
    float media= (float) media2/ (float) count2;
    return media;
}
//Funcion getUltimos1(Devuelve los últimos 5 valores del dado 1)
void Dados::getUltimos1(int v[]) const{
    for(int i=0; i<5; i++){
        v[i]=v1[i];  
    }
}
//Funcion getUltimos2(Devuelve los últimos 5 valores del dado 2)
void Dados::getUltimos2(int v[]) const{
    for(int i=0; i<5; i++){
        v[i]=v2[i];    
    }
}
//Insertador propio
ostream &operator<<(ostream &out, const Dados &d){
    out<<"Valor Dado1="<<d.getDado1()<<endl;
    out<<"Valor Dado2="<<d.getDado2()<<endl;
    return out;
};
//Extractor propio
istream &operator>>(istream &in, Dados &d){
    int valor=0;
    while(!d.setDado1(valor)){
        cout<<"Dado1:";
        in>>valor;
        if(!d.setDado1(valor)){
            cout<<"Valor Incorrecto"<<endl;
        }
    }
    valor=0;
    while(!d.setDado2(valor)){
        cout<<"Dado2:";
        in>>valor;
        if(!d.setDado2(valor)){
            cout<<"Valor Incorrecto"<<endl;
        }
    }
    return in;
};
