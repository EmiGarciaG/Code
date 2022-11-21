#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Una cadena de caracteres en C es un vector de caracteres terminado en un carácter especial ('\0').Este carácter marca la terminación de la cadena y es utilizado por las funciones de cadenas. Teniendo esto en cuenta, codifica una función denominada estadisticasCadena que reciba una cadena de caracteres y calcule, devolviendo mediante paso de parámetros por referencia, el número de dígitos, mayúsculas, minúsculas y espacios que hay en la cadena. Implementa unprograma para probar la función anterior. Utiliza funciones de la librería <ctype.h> para determinar si un carácter es dígito, mayúscula, etc.
void estadisticasCadena(char *cad, int *d, int *my, int *mn, int *esp){
	for(int i=0; cad[i]!='\0'; i++){
		if(isspace(cad[i])){
			(*esp)++;
		}
		if(isdigit(cad[i])){
			(*d)++;
		}
		if(isupper(cad[i])){
			(*my)++;
		}
		if(islower(cad[i])){
			(*mn)++;
		}
	}
}
int main(){
	char cad[100];
	int d=0;
	int my=0;
	int mn=0; 
	int esp=0;
	printf("Escribe tu cadena: ");
	gets(cad);
	estadisticasCadena(cad, &d, &my, &mn, &esp);
	printf("\nEstadisticas de la cadena: \n Numero de digitos= %d \n Numero de mayusculas= %d \n Numero de minusculas= %d \n Numero de espacios= %d \n", d, my, mn, esp);
	return 0;
}

