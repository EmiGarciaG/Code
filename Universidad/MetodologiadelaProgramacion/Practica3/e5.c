#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Codifica un programa en C que, utilizando funciones, abra un fichero de texto, cuyo nombre se pedirá al usuario, y genere un nuevo fichero llamado mayusculas-nombreFicheroDeEntrada.txt, que tenga el mismo contenido que el fichero original pero en mayúsculas.
void FicheroMayusculas(char* FicheroEntrada,char* FicheroSalida){
	FILE *f_entrada,* f_salida;
	int c;
	if((f_entrada=fopen(FicheroEntrada,"r"))==NULL){
      		printf("Error al abrir el fichero %s\n",FicheroEntrada);
      		exit(-1);
	}
	if((f_salida=fopen(FicheroSalida,"w"))==NULL){
      		printf("Error al abrir el fichero %s\n",FicheroSalida);
      		exit(-1);
	}
	c=fgetc(f_entrada);
	while(c!=EOF){
		fputc(toupper(c),f_salida);
      		c=fgetc(f_entrada);
	}
	fclose(f_entrada);
	fclose(f_salida);
}
int main(){
	char FicheroEntrada[256];
	char FicheroSalida[256]="mayusculas-";
	printf("Introduce el nombre del fichero: ");
	scanf("%s",FicheroEntrada);
	strcat(FicheroSalida,FicheroEntrada);
	FicheroMayusculas(FicheroEntrada,FicheroSalida);
	return 0;
}
