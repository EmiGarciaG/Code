#include <stdio.h>
#include <stdlib.h>
//Escribe una función que, dado un vector dinámico, su longitud y un número entero (num), devuelva dos vectores dinámicos. Uno contendrá los elementos mayores que num y otro los elementos menores o iguales que num. Implementa un pequeño programa para probar la función.
void rellenarVector(int * v, int longitud){
	int x;
  	for(int i=0;i<longitud;i++){
    		scanf("%i",x);
		v[i]=x;
  	} 
	for(int i=0;i<longitud;i++){
		printf("V[%d] = %d\n",i,*(v+i));
	}
}
void reservaVectores(int ** v1, int ** v2, int longitud){
  	if((*v1=(int*)malloc(longitud*sizeof(int))) == NULL){
     		printf("Error al reservar memoria.\n");
     		exit(-1);
  	}
  	if((*v2=(int*)malloc(longitud*sizeof(int)))==NULL){
     		printf("Error al reservar memoria.\n");
     		exit(-1);
  	}
}
void ej2(int * v, int longitud, int n, int *nEle1, int * nEle2, int ** v1, int ** v2){
  	int contador1=0, contador2=0;
  	for(int i=0;i<longitud;i++){
  		if(v[i]>n){
       			(*(v1+contador1))=(*(v+i));
        		contador1++;
    		}
		else{
       			(*(v2+contador2))=(*(v+i));
        		contador2++;
     		}
     		*nEle1 = contador1;
     		*nEle2 = contador2;
  	}
  	if((*v1=(int*)realloc(*v1,(*nEle1)*sizeof(int)))==NULL){
    		printf("Error al cambiar el vector.\n");
    		exit(-1);
  	}
  	if((*v2=(int*)realloc(*v2,(*nEle2)*sizeof(int)))==NULL){
      		printf("Error al cambiar el vector.\n");
      		exit(-1);
  	}
}
void mostrar(int * v1, int * v2, int nEle1, int nEle2){
  	for(int i=0;i<nEle1;i++){
     		printf("V1[%d] = %d\n",i,v1[i]);
  	}
  	for(int j=0;j<nEle2;j++){
     		printf("V2[%d] = %d\n",j,v2[j]);
  	}
}
int main(){
  	int n,longitud,nEle1,nEle2;
  	printf("Introducir la longitud del vector: \n");
  	scanf("%d",&longitud);
  	int v[longitud];
  	int *v1, *v2;
	reservaVectores(&v1,&v2,longitud);
  	rellenarVector(v,longitud);
  	printf("Introducir un numero: \n");
  	scanf("%d",&n);
  	if(n<0){
    		printf("Numero no valido.\n");
    		exit(-1);
  	}
  	ej2(v,longitud,n,&nEle1,&nEle2,&v1,&v2);
  	mostrar(v1,v2,nEle1,nEle2);
  	free(v1);
  	free(v2);
	return 0;
}
