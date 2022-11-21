#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Escribe un programa que implemente las siguientes funciones sobre matrices dinámicas y las llame de manera secuencial mostrando, de manera adecuada, la salida por pantalla. ● int ** reservarMemoria (int nFil, int nCol). Reserva memoria para una matriz de nFil filas y nCol columnas. ● void rellenaMatriz (int **matriz, int nFil, int nCol). aleatorios en el intervalo [1,20]. Rellena una matriz con valores ● void imprimeMatriz (int **matriz, int nFil, int nCol). Imprime una matriz por pantalla. Usa la notación de aritmética de punteros para recorrer la matriz. ● int * minCol (int **matriz, int nFil, int nCol). Devuelve un vector dinámico con los mínimos de cada columna. ● void liberarMemoria(int ***matriz, int nFil). Libera la memoria de una matriz reservada dinámicamente. La función pondrá el puntero matriz a NULL antes de terminar.
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
			*(*(Matriz+i)+j)=rand()%21;
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

