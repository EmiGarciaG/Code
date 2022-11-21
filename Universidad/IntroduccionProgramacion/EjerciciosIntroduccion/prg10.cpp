#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int a;
  //Petición de datos por pantalla
  cout<<"Introduzca un valor para a y pulse Intro"<<endl;
  //Introducción de datos
  cin>> a;
  cout<<"a="<<a<<endl;
  float f=2;
  cout<<"f="<<f<<endl;
  cout<<"Introduzca un valor para f y pulse Intro"<<endl;
  //Cambio de valor por parte del usuario
  cin>>f;
  cout<<"f="<<f<<endl;
  double d;
  cout<<"Introduzca un valor para d y pulse Intro"<<endl;
  cin>>d;
  d=d*f; //Conversion de tipos implícita
  cout<<"d="<<d<<endl;
}
