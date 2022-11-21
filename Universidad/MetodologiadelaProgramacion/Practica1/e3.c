#include <stdio.h>
//Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza en FE9 entonces, después de ejecutar todas las sentencias:
int main(){

	int i, j=25;
	int *pi, *pj;
	pj=&i;
	*pj=j+5;
	i=*pj+5;
	pi=pj;
	*pi=i+j;
//a) ¿Qué valor es representado por &i?
	printf("\nValor de &i: \n %p", &i);
//b) ¿Qué valor es representado por &j?
	printf("\nValor de &j: \n %p", &j);
//c) ¿Qué valor es asignado a pj?
	printf("\nValor de pj: \n %p", pj);
//d) ¿Qué valor es asignado a *pj?
	printf("\nValor de *pj: \n %i", *pj);
//e) ¿Qué valor es asignado a i?
	printf("\nValor de i: \n %i", i);
//f) ¿Qué valor es representado por pi?
	printf("\nValor de pi: \n %p", pj);
//g) ¿Qué valor es asignado a *pi?
	printf("\nValor de *pi: \n %i", *pi);
//h) ¿Qué valor es representado por la expresión (*pi + 2)?
	printf("\nValor de (*pi+2): \n %i \n", (*pi+2));
	return 0;
}
