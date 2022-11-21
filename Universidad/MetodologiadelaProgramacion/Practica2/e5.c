#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Escribe un programa que lea una frase y, a partir de ella, cree un vector dinámico de cadenas con las diferentes palabras de la frase. A partir de este vector, el programa deberá: ● Calcular la longitud media de las palabras de la frase, así como la longitud mayor y menor (usando paso de parámetros por referencia). ● Construir un vector dinámico con la frecuencia de aparición de cada longitud. Realiza una adecuada modularización, implementando todas las funciones que sean necesarias. Suponer que las palabras de la frase están separadas por un único espacio en blanco.
void leerFrase(char *res){
  	scanf("%[^\n]%*c",res);
  	strcat(res,"\n");
}
char **separeWords(char *phrase, int *nwords){
  	int aux=0,nspace=0,nspace2=-2,size=strlen(phrase);
  	*nwords=1;
  	char **words;
  	for(int i=0; i<size; i++){
  		if(phrase[i]==32||phrase[i]=='\n'){
       			if(aux==0){
        			words=(char**) calloc ((*nwords),sizeof(char*));
         			aux=1;
       			}
       		else{
         		(*nwords)++;
         		words = (char**) realloc (words, (*nwords)*sizeof(char*));
       		}
       			nspace=nspace2+2;
       			nspace2=i-1;
       			int wordsize=(nspace2-nspace+1);
       			words[(*nwords)-1]=(char*) calloc(wordsize+1,sizeof(char));
       			for(int j=0; j<wordsize; j++){
         			words[(*nwords)-1][j]=phrase[nspace+j];
       			}
       			words[(*nwords)-1][wordsize]='\0';
    		}
  	}
  	return words;
}
void readWords(int nwords, char **words){
  	int i;
  	for (i=0; i<nwords; i++){
   		printf("%s\n",words[i]);
	}
}
void statsWords(int nwords, char **words, float *media, int *lmayor, int *lmenor){
  	*media=0,*lmayor=strlen(words[0]), *lmenor=strlen(words[0]);
  	for(int i=0; i<nwords; i++){
    		int aux=strlen(words[i]);
    		(*media)+=aux;
    		if(*lmayor<aux){
			*lmayor=aux;
		}
    		if(*lmenor>aux){
	 		*lmenor=aux;
		}
  	}
  	*media=(*media)/nwords;
}
int *frVector(int nwords, char **words, int lmayor){
  	int *res = (int*)calloc(lmayor, sizeof(int));
  	for(int i=0; i<nwords; i++){
   		int size=strlen(words[i]);
    		res[size]++;
  	}
	return res;
}
void printvector(int *v,int n){
  	for (int i=1; i<n+1; i++){
		printf("|%d= '%d' ",i,v[i]);
		  printf("|\n");
	}
}
int main(){
  	char phrase[500];
	printf("\nEscribe tu frase: \n ");
  	leerFrase(phrase);
  	printf("%s",phrase);
  	int nwords, lmayor, lmenor;
  	float media;
  	char **words=separeWords(phrase, &nwords);
  	readWords(nwords,words);
  	statsWords(nwords, words, &media, &lmayor, &lmenor);
  	printf("%.2f %d %d\n",media,lmayor,lmenor);
  	int *frv=frVector(nwords, words, lmayor);
  	printvector(frv, lmayor);
	return 0;
}
