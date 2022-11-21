/**
@file main.c
@brief cuerpo del programa donde pedimos datos al usuario y devuelve el resultado devuelto por las funciones
*/
//Crea una biblioteca (libMatrices.a) a partir de las cuatro funciones del ejercicio 4 (reservarMemoria, liberarMemoria, rellenaMatriz e imprimeMatriz) y su correspondientefichero de cabecera. Reproduce los resultados del ejercicio 4, pero esta vez haciendo uso de la biblioteca creada (por tanto sólo necesitarás un main(), la inclusión del .h de la biblioteca y enlazar con ella). Utiliza Doxygen para documentar todas las funciones de la biblioteca.(Micro 1)
#include "funciones.h"
int main(){
	int **matriz;
	int fils=0;
	int cols=0;
	int div;
	int suma;
	printf("\nEscriba numero de filas de la matriz: ");
	scanf("%i", &fils);
	printf("\nEscriba numero de columnas de la matriz: ");
	scanf("%i", &cols);
	matriz=reservaMatriz(fils, cols);
	printf("\nEscriba su matriz: ");
	rellenaMatriz(matriz, fils, cols);
	leeMatriz(matriz, fils, cols);
	divisibles(matriz, fils, cols, &div, &suma);
	printf("\nEl numero de elementos divisibles por 3 es: %i", div);  
	printf("\nLa suma de los elementos divisibles por 3 es: %i\n", suma);  
	liberaMatriz(&matriz, fils);
	return 0;
}
