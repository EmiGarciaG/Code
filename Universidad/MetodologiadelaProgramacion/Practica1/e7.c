#include <stdio.h>
#include <math.h>
//Codifica una función denominada estadisticasVector que reciba un vector de enteros y calcule, devolviendo mediante paso de parámetros por referencia, la media, la varianza y la desviación típica de los datos del vector. Implementa un programa que mediante funciones lea un vector de enteros, lo imprima por pantalla, calcule las estadísticas y finalmente muestre los resultados.
void estadisticasVector(float *v, int n, float *media, float *varianza, float *desviacion){
	float suma=0;
	for(int i=0; i<n; i++){
		suma+=*(v+i);
	}
	*media=suma/n;
	suma=0;
	for(int j=0; j<n; j++){	
		suma+=pow((*(v+j)-*media),2);
	}
	*varianza=suma/n;
	*desviacion=sqrt(*varianza);
}
void escribeVector(float *v, int n){
	for(int i=0; i<n; i++){
		printf("V[%i]:", i);
		scanf("%f", &(*(v+i)));
	}
}
void leeVector(float *v, int n){
	for(int i=0; i<n; i++){
		printf("%f\n", *(v+i));
	}
}
int main(){
	float v[5];
	escribeVector(v, 5);
	leeVector(v, 5);
	float media, varianza, desviacion;
	estadisticasVector(v, 5, &media, &varianza, &desviacion);
	printf("\nEstadisticas del Vector:\n Media=%f \n Varianza=%f \n Desviacion=%f \n", media, varianza, desviacion);
	return 0;
}

