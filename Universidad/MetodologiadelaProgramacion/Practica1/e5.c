#include <stdio.h>	
	
int main(){
	int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};
//a) ¿Cuál es el significado de x?
	printf("\nValor de x: \n %p", x);
//b) ¿Cuál es el significado de (x + 2) ?
	printf("\nValor de (x+2): \n %p", (x+2));
//c) ¿Cuál es el valor de *x?
	printf("\nValor de *x: \n %i", *x);
//d) ¿Cuál es el valor de (*x+2) ?
	printf("\nValor de (*x+2): \n %i", (*x+2));
//e) ¿Cuál es el valor de *(x+2)?
	printf("\nValor de *(x+2): \n %i \n", *(x+2));
	return 0;
}
