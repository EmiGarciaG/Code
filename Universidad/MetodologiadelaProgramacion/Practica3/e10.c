#include <stdio.h>
#include <stdlib.h>
//Codifica un programa en C que, utilizando funciones, lea números enteros desde un fichero binario generado en el ejercicio anterior, almacene sus valores en un vector dinámico y calcule la media de los números pares. El nombre del fichero se le preguntará al usuario.
void calculaElementos(char *nombreFichero, int *numEle){
  	int tam;
  	FILE *f;
  	if((f=fopen(nombreFichero,"rb"))==NULL){ 
      		printf("Error: No se pudo abrir el fichero.\n");
      		exit(-1);
  	}
  	fseek(f,0,SEEK_END); 
  	tam=ftell(f); 
  	*numEle=tam/sizeof(int); 
  	fclose(f);
}
int *reservaMemoria(int numEle){
  	int *v;
  	if((v=(int*)malloc(numEle*sizeof(int)))==NULL){
      		printf("Error: No se pudo reservar memoria.\n");
      		exit(-1);
  	}
  	return v;
}
void rellenaVector(char *nombreFichero, int *v, int numEle){
  	FILE *f;
  	if((f=fopen(nombreFichero,"rb"))==NULL){
       		printf("Error: No se pudo abrir el fichero.\n");
       		exit(-1);
  	}
  	fread(v,sizeof(int),numEle,f);
  	fclose(f);
}
void calculaMedia(int *v, int numEle, int *media){
  	int suma=0;
	int contador=0;
  	*media=0;
  	for(int i=0; i<numEle; i++){
     		if(v[i]%2==0){
       			suma+=v[i];
			contador++;
		}
  	}
  	*media = suma/contador;
}
void muestraFichero(char *nombreFichero, int numEle){ 
  	int aux;
  	FILE *f;
  	if((f=fopen(nombreFichero,"rb"))==NULL){
    		printf("Error: No se pudo abrir el fichero.\n");
    		exit(-1);
  	}
  	for(int i=0; i<numEle; i++){
     		fread(&aux,sizeof(int),1,f);
     		printf("Elemento[%d]= %d\n",i,aux);
  	}
  	fclose(f);
}
int main(){
  	int media;
  	int numEle;
  	int *v; 
  	char nombreFichero[100];
  	printf("Introduzca el nombre de su fichero: ");
  	gets(nombreFichero);
  	calculaElementos(nombreFichero,&numEle);
  	printf("Su fichero es: \n");
  	muestraFichero(nombreFichero,numEle);
  	printf("\n");
  	v=reservaMemoria(numEle);
  	rellenaVector(nombreFichero,v,numEle);
  	calculaMedia(v,numEle,&media);
  	printf("La media de los elementos pares del fichero es: %d\n",media);
  	free(v); 
  	return 0;
}
