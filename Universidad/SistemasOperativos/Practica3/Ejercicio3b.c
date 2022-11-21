#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t consume;
sem_t mutex;
sem_t producto;

int *buffer;
int bufout=0; 
int bufin=0;

void *productor(){
	int datoA;
	datoA=(drand48()*11);
	sem_wait(&producto);
	sem_wait(&mutex);
	buffer[bufin]=datoA;
	printf("El productor %li, valor producido %d\n", pthread_self(), datoA);
	printf("Produciendo un %d en posicion %d\n", buffer[bufin], bufin);
	bufin=(bufin+1)%3;
	sem_post(&mutex);
	sem_post(&consume);
	pthread_exit(NULL);
}
void *consumidor(){
	int datoleido;
	sem_wait(&consume);
	sem_wait(&mutex);
	datoleido=buffer[bufout];
	printf("El consumidor %li, valor consumido %d\n", pthread_self(), datoleido);
	printf("Consumiendo un %d de la posicion %d\n", buffer[bufout], bufout);
	bufout=(bufout+1)%3;
	sem_post(&mutex);
	sem_post(&producto);
	pthread_exit(NULL);
}
int main(){
	pthread_t prod[3], cons[3];
	srand48(time(NULL));
	sem_init(&producto, 0, 3);
	sem_init(&consume, 0, 0);
	sem_init(&mutex, 0, 1);
	buffer=(int *)calloc(3, sizeof(int));
	for(int i=0; i<3; i++){
		pthread_create(&cons[i], NULL, consumidor, NULL);
	}
	for(int i=0; i<3; i++){
		pthread_create(&prod[i], NULL, productor, NULL);
	}
	for(int i=0; i<3; i++){
		pthread_join(prod[i], NULL);
	}
	for(int i=0; i<3; i++){
		pthread_join(cons[i], NULL);
	}
	sem_destroy(&mutex);
	sem_destroy(&producto);
	sem_destroy(&consume);
	free(buffer);
	return EXIT_SUCCESS;
}