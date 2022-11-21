#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int i=12;
  float f=i;//Conversion implícita. No se pierde precisión
  f=1.2;
  i=f;//Conversion implícita
  i=int(f);//Conversion explícita  
  cout<<i<<endl;
  f=91.1;
  cout<<f<<endl;
  double dd=f;
  dd=9991.1123123159980;
  f=dd;//Pérdida de precision 
  cout<<f<<endl;
}

