#include <stdio.h>
//Se desea mostrar la equivalencia entre funciones que devuelven un resultado y funciones que utilizan parámetros por referencia.
//a) Primera versión: función denominada minimo. Recibe dos números num1 y num2 de tipo int pasados por valor. Devuelve como resultado el mínimo de los números num1 y num2 pasados como parámetros.
int minimo(int num1, int num2);
//Segunda versión: función denominada minimo_referencia. Recibe dos números num1 y num2 de tipo int pasados por valor. Recibe otro parámetro denominado resultado de tipo int pero pasado por referencia. La función debe asignar a resultado el valor del mínimo de num1 y num2.
void minimo_referencia(int num1, int num2, int *num3);
int main(){
	int a, b, c;
	printf("\nEscribe valor para a: ");
	scanf("%i", &a);
	printf("\nEscribe valor para b: ");
	scanf("%i", &b);
	printf("\nEl minimo de los dos es: %i \n ", minimo(a, b));
	printf("\nEscribe valor para a: ");
	scanf("%i", &a);
	printf("\nEscribe valor para b: ");
	scanf("%i", &b);
	minimo_referencia(a, b, &c);
	printf("\nEl minimo referencia de los dos es: %i \n", c);
	return 0;
}

int minimo(int num1, int num2){
	int m=num1;
	if(num1>num2){
		m=num2;
	}
	if(num1==num2){
		printf("\nLos numeros son iguales");
	}
	return m;
}
void minimo_referencia(int num1, int num2, int *num3){
	if(num1>num2){
		*num3=num2;
	}
	else{
		*num3=num1;
	}
	if(num1==num2){
		printf("\nLos numeros son iguales");
	}
}
