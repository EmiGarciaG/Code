#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t mutex;
sem_t consume;
sem_t producto;
int *buffer;
void *productor(){
	int bufin=0, datoA;
	for(int i=0; i<10; i++){
		datoA=(drand48()*11);
		sem_wait(&producto);
		sem_wait(&mutex);
		buffer[bufin]=datoA;
		printf("El productor %li, valor producido %d\n", pthread_self(), datoA);
		printf("Produciendo un %d en posicion %d\n", buffer[bufin], bufin);
		printf("\n");
		bufin=(bufin+1)%5;
		sem_post(&mutex);
		sem_post(&consume);
	}
	pthread_exit(NULL);
}
void *consumidor(){
	int bufout=0, datoleido;
	for(int i=0; i<10; i++){
		sem_wait(&consume);
		sem_wait(&mutex);
		datoleido=buffer[bufout];
		printf("El consumidor %li, valor consumido %d\n", pthread_self(), datoleido);
		printf("Consumiendo un %d de la posicion %d\n", buffer[bufout], bufout);
		printf("\n");
		bufout=(bufout+1)%5;
		sem_post(&mutex);
		sem_post(&producto);
	}
	pthread_exit(NULL);
}
int main(){
	pthread_t prod, cons;
	srand48(time(NULL));
	sem_init(&producto, 0, 5);
	sem_init(&consume, 0, 0);
	sem_init(&mutex, 0, 1);
	buffer=(int *)calloc(5, sizeof(int));
	pthread_create(&cons, NULL, consumidor, NULL);
	pthread_create(&prod, NULL, productor, NULL);
	pthread_join(cons, NULL);
	pthread_join(prod, NULL);
	sem_destroy(&mutex);
	sem_destroy(&producto);
	sem_destroy(&consume);
	free(buffer);
	return EXIT_SUCCESS;
}