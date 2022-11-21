#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *leerarchivo(void *fichero){
    printf("Fichero %s\n", (char *)fichero);
    FILE *f=fopen((char *)fichero, "r");
    char linea[256];
    if(f==NULL){
        printf("No existe fichero, o fichero vacio");
        exit(EXIT_FAILURE);
    }
    int *lineas=malloc(sizeof(float));
    while(fgets(linea, 256,f)){
        (*lineas)++;
    }
    printf("Hebra %lu ha contado %i lineas del fichero %s\n", pthread_self(), *lineas, (char *) fichero);
    pthread_exit((void *) lineas);
}
int main(int argc, char **argv){
    //Comprobacion argumentos
    if(argc<2){                             
        printf("Uso incorrecto de argumentos, minimo un fichero\n");
        return EXIT_FAILURE;   
    }
    //Declaracion hebras
    int nficheros=(argc-1), total=0;
    int *nlineas;
    printf("Numero de hebras: %i \n", nficheros);
    pthread_t thd [nficheros];
    for(int i=0; i<nficheros;  i++){
        if(pthread_create(&thd[i], NULL, (void *)leerarchivo, (void *) argv[i+1])){
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE); 
        }
    }
    //Finalizacion de las hebras
	for(int i=0; i<nficheros;  i++){
        if(pthread_join(thd[i], (void**) &nlineas)){
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE); 
        }
        printf("Numero de lineas fichero %s: %i\n", argv[i+1], *nlineas);
        total+=*nlineas;
    }
	printf("Han finalizado las hebras.\n");
    printf("El numero de lineas totales es: %i \n", total);
	exit(EXIT_SUCCESS);
}
