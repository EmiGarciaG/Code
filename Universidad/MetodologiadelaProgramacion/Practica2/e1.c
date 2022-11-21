#include <stdio.h>
#include <stdlib.h>
//Supón una matriz dinámica (float ** tabla) de 2x3 elementos, con los siguientes valores.{ {1.1, 1.2, 1.3}, {2.1.,2.2, 2.3}} 
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
int main(){
	float **matriz;
	matriz=reservaMatriz(2, 3);
	rellenaMatriz(matriz, 2, 3);
	escribeMatriz(matriz, 2, 3);	
	liberaMatriz(&matriz, 2);
	return 0;
	
}




