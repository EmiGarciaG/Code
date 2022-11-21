//Declaracion includes para bibliotecas y ficheros.h 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//Declaración de la función para los dos números aleatorios de la hebra
void *aleatorio(){
    float n1=drand48()*100;
    printf("Numero aleatorio 1 hebra hija %lu: %f\n", pthread_self(), n1);
    float n2=drand48()*100; 
    printf("Numero aleatorio 2 hebra hija %lu: %f\n", pthread_self(), n2);
    float *n3=malloc(sizeof(float)); //Al ser un puntero tenemos que localizar la zona de memoria al terminar la hebra
    *n3=n1+n2;
    printf("Suma hebra hija %lu: %f\n", pthread_self(), *n3);
    pthread_exit((void *)n3); 
}
//Declaración del main
int main(int argc, char **argv){
    if(argc!=2){
        printf("Error numero de argumentos\n");
        exit(EXIT_FAILURE);
    }
    srand48(time(NULL));
    float sumatotal=0, *suma;
    int nhebras=atoi(argv[1]);
    printf("Cantidad de hebras: %i \n", nhebras);
    pthread_t thd [nhebras];
    for(int i=0; i<nhebras;  i++){
        //Creación de las hebras
        if(pthread_create(&thd[i], NULL, (void *) aleatorio, NULL)){
            fprintf(stderr, "Error creando thread\n");
            exit(EXIT_FAILURE); 
        }       
    }
    for(int i=0; i<nhebras;  i++){
        if(pthread_join(thd[i], (void **) &suma)){
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE); 
        }
        printf("Suma: %f \n", *suma);
        sumatotal+=*suma;
    }
	printf("Han finalizado las hebras.\n");
    printf("La suma total de las hebras es: %f \n", sumatotal);
	exit(EXIT_SUCCESS);
}
