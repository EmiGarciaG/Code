#include <stdio.h>
#include <stdlib.h>
//Implementa una función que permita multiplicar matrices dinámicas. Utiliza las funciones incluidas en la biblioteca libMatrices.a para implementar el programa que te permita probar la función.
float **reservaMatriz(int filas, int columnas){
	float **Matriz;
	Matriz=(float**)malloc(filas*sizeof(float*));
	if(Matriz==NULL){
		printf("Error : no se pudo reservar memoria");
		exit(-1);
	}
	for(int i=0; i<filas; i++){
		Matriz [i]=(float*)malloc(columnas*sizeof(float));
	}
	return(Matriz);	
}
void rellenaMatriz(float **Matriz, int filas, int columnas){
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("\nM[%d][%d]: ", i, j);
			scanf("%f", &*(*(Matriz+i)+j));
		}
	}
}
void escribeMatriz(float **Matriz, int filas, int columnas){
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("\nM[%i][%i]: %f \n", i, j, *(*(Matriz+i)+j));
		}
	}
}
void liberaMatriz(float ***Matriz, int filas){
	for(int i=0; i<filas; i++){
		free((*Matriz) [i]);
	}
	free(*Matriz);
	(*Matriz)=NULL;
}
float **multiplicaMatriz(float **Matriz, float **Matriz2, int filas, int columnas2, int columnas){
	float **Matriz3;
	Matriz3=(float**)malloc(filas*sizeof(float*));
	if(Matriz3==NULL){
		printf("Error : no se pudo reservar memoria");
		exit(-1);
	}
	for(int i=0; i<filas; i++){
		Matriz3 [i]=(float*)malloc(columnas*sizeof(float));
	}
	for(int a=0; a<columnas2; a++){
    		for(int i=0; i<filas; i++){
       		int suma=0;
        		for (int j=0; j<columnas; j++){
            			suma+=(*(*(Matriz+i)+j)) * (*(*(Matriz2+j)+a));
        		}
        		*(*(Matriz3+i)+a)=suma;
    		}
	}
	return(Matriz3);
}
int main(){
	float **matriz, **matriz2, **matriz3;
	matriz=reservaMatriz(2, 3);
	matriz2=reservaMatriz(3, 2);
	rellenaMatriz(matriz, 2, 3);
	rellenaMatriz(matriz2, 3, 2);
	escribeMatriz(matriz, 2, 3);
	escribeMatriz(matriz2, 3, 2);
	matriz3=multiplicaMatriz(matriz, matriz2, 2, 2, 3);
	escribeMatriz(matriz3, 3, 3);	
	liberaMatriz(&matriz, 2);
	liberaMatriz(&matriz2, 3);
	liberaMatriz(&matriz3, 3);
	return 0;
}
