#include <stdio.h>
#include <string.h>
//Dada una cadena c, diseña una función recursiva que cuente la cantidad de veces que aparece un carácter x en c. Ejemplo: para c = “elementos de programacion” y x = 'e', el resultado es 4.
int contarcaracteres(char *cad, char *caract, int tam){
	if(tam==0){
		if(cad[tam]==caract[0]){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(cad[tam]==caract[0]){
		return 1+ contarcaracteres(cad, caract, tam-1);
	}
	else{
		return 0 + contarcaracteres(cad, caract, tam-1);
	}
}
int main(){
	char cad[200], caract[10];
	int cont;
	printf("Escribe una cadena de caracteres: ");
	fgets(cad, 200, stdin);
	printf("Escribe el caracter a buscar: ");
	scanf("%s", caract);
	int tam=strlen(cad);
	cont=contarcaracteres(cad, caract, tam);
	printf("El caracter elegido %s aparece %i veces en la cadena. \n", caract, cont);
	return(0);
}
