#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  float a=3.4;
  float b=1.2;
  //Operaciones aplicando el orden de las operaciones
  float c=a*b+12.4/7;
  float d=(a*b+12.4)/7;
  float e=((a*b)+12.4)/7;
  cout<<"c="<<c<<endl;
  cout<<"d="<<d<<endl;
  cout<<"e="<<e<<endl;
}

