/**
@file funciones.h
@brief Tenemos las siguientes funciones:
	reservaMatriz->Funcion encargada de reservar memoria para una matriz de nfilas y ncolumnas.

	rellenaMatriz->Funcion para introducir los numeros enteros que queramos
	leeMatriz->Funcion para imprimir por pantalla los elementos de la matriz
	divisibles->Funcion que mediante parametros pasados por referencia, devuelve la cantidad de elementos divisibles por 3 en la matriz y la suma estos ultimos.
	liberaMatriz->Libera la reserva de memoria de la matriz.
*/
#ifndef _LIBRERIA_
#define _LILBRERIA_
#include <stdio.h>
#include <stdlib.h>
/**
@fn int **reservaMatriz(int filas, int columnas);
@param filas=n umero de filas de la parametros
@param columnas= numero de filas de la parametros
@param Matriz= Matriz que vamos a escribir
@author Emilio Garcia Gutierrez
@date 13/04/2020
@version 1.0
*/
int **reservaMatriz(int filas, int columnas);
void rellenaMatriz(int **Matriz, int filas, int columnas);
void leeMatriz(int **Matriz, int filas, int columnas);
void divisibles(int **Matriz, int filas, int columnas, int *d, int *suma);
void liberaMatriz(int ***Matriz, int filas);

#endif
