#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int a=3;
  int b=3;
  int c=a*b;
  //Imprimimos el valor de cada variable
  cout<<"El resultado de multiplicar "<<a<<" y "<<b<<" es  "<<c<<endl;
  //Pruebas cambiando su valor
  a=1 ;
  c=a*b;
  cout<<"El resultado de multiplicar "<<a<<" y "<<b<<" es  "<<c<<endl;
  c=c*2;
  cout<<"Ahora c vale "<<c<<endl;
}

