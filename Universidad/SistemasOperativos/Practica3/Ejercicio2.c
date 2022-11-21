#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

int par=0;
int impar=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;

void *threadRoutine(void *arg){
	int *sumaHebra=(int *)calloc(1, sizeof(int));
	int aux;
	if(pthread_mutex_lock(&mtx)!=0){
		printf("Error al bloquear el semaforo\n");
		pthread_exit(NULL);
	}
	if(*((int *)arg)%2==0){
		for(int i=0; i<5; i++){
			aux=rand()%10+1;
			*sumaHebra=*sumaHebra+aux;
			par=par+aux;
		}
	}
	else{
		for(int i=0; i<5; i++){
			aux=rand()%10+1;
			*sumaHebra=*sumaHebra+aux;
			impar=impar+aux;
		}
	}
	if(pthread_mutex_unlock(&mtx)){
		printf("Error al desbloquear el semaforo\n");
		pthread_exit(NULL);
	}
	pthread_exit((void *)sumaHebra);
}
int main(int argc, char** argv){
	if(argc!=2){
		printf("Error argumentos\n");
		return EXIT_FAILURE;
	}
	int sumaPar=0, sumaImpar=0, *ret;//Suma de los hilos
	int n=atoi(argv[1]);
	int referencia[n];
	for(int i=0; i<n; i++){
		referencia[i]=i+1;
	}
	pthread_t hilo[n];
	srand(time(NULL));
	for(int i=0; i<n; i++){
		if(pthread_create(&hilo[i], NULL, (void *)threadRoutine, (void *)&referencia[i])!=0){
			printf("Error al crear hebra\n");
			return EXIT_FAILURE;
		}
	}
	for(int i=0; i<n; i++){
		if(pthread_join(hilo[i], (void **)&ret)!=0){
			printf("Error al terminar hebra\n");
			return EXIT_FAILURE;
		}
		else if((i+1)%2==0){
			sumaPar=sumaPar+*ret;
		}
		else{
			sumaImpar=sumaImpar+*ret;
		}
		printf("La hebra %d devolvio la suma %d\n", i+1, *ret);
	}	
	printf("Suma hebras impares: %d\n", sumaPar);
	printf("Suma hebras impares: %d\n", sumaImpar);
	printf("Valor par: %d\n", par);
	printf("Valor impar: %d\n", impar);
	pthread_mutex_destroy(&mtx);
	return EXIT_SUCCESS;
}