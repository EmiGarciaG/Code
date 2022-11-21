#include <stdio.h>
#include <ctype.h>
//10. Codifica un programa que usando funciones y aritmética de punteros:•Lea un vector de elementos tipo double (leeVector).•Imprima los datos del vector por pantalla (escribeVector).•Sume los elementos mayores que cero del vector (sumaPositivos).
void leevector(double vector[], int n){
	for(int i=0; i<n; i++){
		printf("Introduzca el elemento del vector en la posicion %i: \n", i);
		scanf("%lf", &vector[i]);
	}
}
void imprimevector(double vector[], int n){
	for(int i=0; i<n; i++){
		printf("Posicion[%i]=%lf\n", i, vector[i]);
	}
}
void sumavector(double vector[], int n, double *suma){
	for(int i=0; i<n; i++){
		if(vector[i]>0){
			*suma=*suma+vector[i];
		}
	}
}
int main(){
	int n=0;
	printf("Introduzca el numero de elementos del vector: \n");
	scanf("%i", &n);
	double vector[n];
	leevector(vector, n);
	imprimevector(vector, n);
	double suma=0;
	sumavector(vector, n, &suma);
	printf("La suma de los elementos mayores que 0 son: %lf\n", suma);
	return 0;
}
