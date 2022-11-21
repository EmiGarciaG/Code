#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Un proyecto informático requiere trabajar con vectores de números enteros generados demanera aleatoria. Para hacer más rápido el acceso, han decidido crear dos índices que les permitan recorrer solamente los divisibles por 3 o los elementos impares. Un índice, es un vector de punteros, que almacena la dirección de los elementos que se quieren recorrer. Escribe un programa que: • Rellene un vector de enteros con números aleatorios (en un rango fijado por el usuario). • Imprima el vector completo. • Cree un índice con las direcciones de los elementos impares del vector original. • Cree un índice con las direcciones de los divisibles por 3 que hay en el vector original. • Imprima, usando los índices, los elementos impares y los divisibles por 3. Implementa, al menos, las funciones: rellenarVectorAleatorio, imprimirVector, crearndiceImpares, crearIndicesDivisibles, imprimeIndice.
void rellenarVectorAleatorio(int *v, int n, int rango){
	int i;
  	time_t t;
  	srand(time(&t));
  	for(i=0; i<n; i++) v[i]=rand()%(rango+1);
}
void imprimirVector(int *v, int n){
 	 int i;
 	 printf("Tu vector aleatorio es: \n |");
  	for(i=0; i<n; i++){
		 printf(" %d |",v[i]);
	}
}
void crearIndiceImpares(int *v, int **ind, int n, int *nIndice){
  	int i;
  	*nIndice=0;
  	for(i=0; i<n; i++){
  		if(v[i]%2!=0){
  			ind[*nIndice]=&v[i];
      			(*nIndice)++;
    		}
  	}
}
void crearIndiceDivisibles(int *v, int **ind, int n, int *nIndice){
  	int i;
  	*nIndice=0;
  	for(i=0; i<n; i++){
    		if(v[i]%3==0){
      			ind[*nIndice]=&v[i];
      			(*nIndice)++;
    		}
  	}
}
void ImprimirIndice(int **ind, int nIndice){
  	int i;
  	printf("Indice: \n |");
  	for(i=0; i<nIndice; i++){
		printf(" %d |",*(ind[i]));
	}
}
void main(){
 	int n,rango,nIndiceImp,nIndiceDiv;
  	printf("¿De cuantos elementos debe ser su vector?\n");
  	scanf("%d", &n);
  	int v[n], *indImp[n], *indDiv[n];
  	printf("Indique el rango: \n");
  	scanf("%d", &rango);
  	rellenarVectorAleatorio(v,n,rango);
  	imprimirVector(v,n);
  	printf("\n");
  	crearIndiceImpares(v,indImp,n,&nIndiceImp);
  	printf("Los numeros impares de su vector son: \n");
  	ImprimirIndice(indImp, nIndiceImp);
  	printf("\n");
  	crearIndiceDivisibles(v,indDiv,n,&nIndiceDiv);
  	printf("Los numeros divisibles por 3 de su vector son: \n");
  	ImprimirIndice(indDiv, nIndiceDiv);
  	printf("\n");
}
