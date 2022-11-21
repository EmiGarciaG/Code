#include <stdio.h>
//Codifica una función recursiva que permita sumar los dígitos de un número. Implementa un programa para probarla. Ejemplo: Entrada: 124 Resultado: 7.
int sumadigitos(int n){
  	if(n<10){
  	  	return n;
  	}
  	else{
  		return n%10 + sumadigitos(n/10);
  	}
}
int main(){
  int n;
  printf("Introduzca un numero para realizar la suma de sus digitos \n");
  scanf("%d",&n);
  int suma=sumadigitos(n);
  printf("La suma de los digitos de %d es %d \n", n, suma);
}
