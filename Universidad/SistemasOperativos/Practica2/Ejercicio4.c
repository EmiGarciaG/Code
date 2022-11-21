//Declaracion includes para bibliotecas y ficheros.h 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>


//Declaración variable global
int global=0;
//Declaración de la función para los dos números aleatorios de la hebra
void *sumadiezmil(){
    for(int i=0; i<10000; i++){
        global++;
    }
    pthread_exit(NULL);
}
//Declaración del main
int main(){
    printf("Cantidad de hebras: 2 \n");
    pthread_t thd [2];
    for(int i=0; i<2;  i++){
        //Creación de las hebras
        if(pthread_create(&thd[i], NULL, (void *) sumadiezmil, NULL)){
            fprintf(stderr, "Error creando thread\n");
            exit(EXIT_FAILURE); 
        }     
    }
    for(int i=0; i<2;  i++){
        if(pthread_join(thd[i], NULL)){
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE); 
        }
    }
	printf("Han finalizado las hebras.\n");
    printf("La variable global total de las hebras es: %i \n", global);
	exit(EXIT_SUCCESS);
}
