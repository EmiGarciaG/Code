#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

void *Forma1(void *v){
    int *sumatorio=malloc(sizeof(int));
    int *vector=(int *)v;
    for(int i=0; i<5; i++){
        *sumatorio+=vector[i];
    }
    pthread_exit((void *) sumatorio); 
}
void *Forma2(void *v){
    int *sumatorio=malloc(sizeof(int));
    int *vector=(int *)v;
    for(int i=0; i<2; i++){
        *sumatorio+=vector[i];
    }
    pthread_exit((void *) sumatorio); 
}
void rellenaVector(int *v){
    for(int i=0; i<10; i++){
        v[i]=(rand()%9)+1;
    }
}
int main(int argc, char **argv){
    //Declaracion hebras
    if(argc!=2){
        printf("Error numero de argumentos\n");
        exit(EXIT_FAILURE);
    }
    else if(atoi(argv[1])!=2 && atoi(argv[1])!=5){
        printf("Error formato de argumentos\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    int *suma, sumatotal=0;
    int nhebras=atoi(argv[1]);
    printf("Numero de hebras: %i \n", nhebras);
    int iterador[nhebras];
    for(int i=0; i<10; i++){
        iterador[i]=i;
    }
    int *v=(int*)malloc(10*sizeof(int));
    rellenaVector(v);
    printf("Numeros del vector: ");
    for(int i=0; i<10; i++){
        printf("%i ", v[i]);
    }
    printf("\n");
    pthread_t thd [nhebras];
    for(int i=0; i<nhebras;  i++){
        if(nhebras==2){
            if(pthread_create(&thd[i], NULL, (void *)Forma1, (void *) (v+(5*iterador[i])))){
                fprintf(stderr, "Error creating thread\n");
                exit(EXIT_FAILURE); 
            }
        }
        else if(pthread_create(&thd[i], NULL, (void *)Forma2, (void *) (v+(2*iterador[i])))){
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE); 
        }
    }
    //Finalizacion de las hebras
	for(int i=0; i<nhebras;  i++){
        if(pthread_join(thd[i], (void **) &suma)){
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE); 
        }
        printf("Suma hebra [%i]: %i\n", i+1, *suma);
        sumatotal+=*suma;
    }
	printf("Han finalizado las hebras.\n");
    printf("La suma total de las hebras es: %i \n", sumatotal);
	exit(EXIT_SUCCESS);
}