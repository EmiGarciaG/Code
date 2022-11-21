#include <stdio.h>
#include <stdlib.h>
//Escribe una solución recursiva que calcule el algoritmo de Euclides, usado para calcular el máximo común divisor de dos enteros. El algoritmo de Euclides se describe del siguiente modo: mcd(x, y) = x, si y = 0 mcd(x, y) = mcd (y, mod(x,y)) si y > 0 y x >= y
int mcd(int x, int y){
  if(y==0){
     return x;
  }
  else{
     return mcd(y, x%y);
  }
}

int main (int argc, char * argv[]) {
   int x,y;
   int MCD;

   if (argc!=3) {
      printf("Error al ejecutar,escriba: %s <num X> <num Y> \n",argv[0]);
      exit(-1);
   }
   x=atoi(argv[1]);
   y=atoi(argv[2]);
   MCD=mcd(x,y);
   printf("El maximo comun divisor de %d y %d es %d \n", x, y, MCD);
   return 0;
}



