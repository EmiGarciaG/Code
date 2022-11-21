#include <stdio.h>
#include <string.h>
//Implementa una programa que permita determinar si una cadena es prefijo o sufijo de otra.Utiliza la función strstr de la biblioteca <string.h> para implementar: •Una función que responda al siguiente prototipo: int es_prefijo(char *cadena, char*prefijo), que compruebe si una cadena es prefijo de otra. La función devolverá 1 si es prefijo y 0 en otro caso. •Una función que responda al siguiente prototipo: int es_sufijo(char *cadena, char *sufijo), que compruebe si una cadena es sufijo de otra. La función devolverá 1 si es sufijo y 0 en otro caso.
int es_prefijo(char *cadena, char *prefijo){
   	char *posicion=strstr(cadena, prefijo);
   	int i,size_prefijo=strlen(prefijo);
   	if(posicion!=NULL){
      		for(i=0;i<size_prefijo;i++){
         		if(cadena[i]!=prefijo[i]){
            			return 0;
         		}
      		}
      		return 1;
   	}
   	return 0;
}
int es_sufijo(char *cadena, char *sufijo){
  	int i, size_sufijo=strlen(sufijo), size_cadena = strlen(cadena);
   	char *posicion=strstr(cadena, sufijo);
	if(posicion!=NULL){
      		for(i=(size_cadena);i>(size_cadena-size_sufijo);i--){
        		 if(cadena[i]!=sufijo[i-(size_cadena-size_sufijo)]){
           			 return 0;
         		}
      		}
      		return 1;
	}
   	return 0;
}

int main(){
	char cadena1[100], prefijo[100], cadena2[100], sufijo[100];
   	printf("Introduzca una cadena: \n");
   	scanf("%s", cadena1);
   	printf("Introduzca otra cadena para saber si es prefijo o no: \n");
   	scanf("%s", prefijo);
   	if(es_prefijo(cadena1, prefijo)==1){
      		printf("La cadena introducida es prefijo\n");
  	}
   	else{
      		printf("La cadena introducida no es prefijo\n");
   	}
   	printf("Introduzca una cadena: \n");
  	scanf("%s", cadena2);
  	printf("Introduzca otra cadena para saber si es sufijo o no: \n");
   	scanf("%s", sufijo);
  	if(es_sufijo(cadena2, sufijo)==1){
      		printf("La cadena introducida es sufijo\n");
   	}
  	else{
      		printf("La cadena introducida no es sufijo\n");
   	}
	return 0;
}
