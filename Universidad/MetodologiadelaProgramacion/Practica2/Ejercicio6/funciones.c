/**
@file funciones.c
@brief Funciones utilizadas en el main(explicado en "funciones.h")
*/
#include "funciones.h"
int **reservaMatriz(int filas, int columnas){

	int **Matriz;
	Matriz=(int**)malloc(filas*sizeof(int*));
	if(Matriz==NULL){
		printf("Error : no se pudo reservar memoria");
		exit(-1);
	}
	for(int i=0; i<filas; i++){
		Matriz [i]=(int*)malloc(columnas*sizeof(int));
	}
	return(Matriz);	

}
void rellenaMatriz(int **Matriz, int filas, int columnas){

	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("\nM[%d][%d]: ", i, j);
			scanf("%i", &*(*(Matriz+i)+j));
		}
	}
}
void leeMatriz(int **Matriz, int filas, int columnas){

	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("\nM[%i][%i]: %i", i, j, *(*(Matriz+i)+j));
		}
	}
}
void divisibles(int **Matriz, int filas, int columnas, int *d, int *suma){
	*d=0;
	*suma=0;
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			if((*(*(Matriz+i)+j)%3)==0){
				(*d)++;
				(*suma)+=*(*(Matriz+i)+j);
			}
		}
	}
}
void liberaMatriz(int ***Matriz, int filas){

	for(int i=0; i<filas; i++){
		free((*Matriz) [i]);
	}
	free(*Matriz);
	(*Matriz)=NULL;
}
