#include <sys/types.h>  //Define pid_t
#include <unistd.h>     //API de POSIX y creacion de un proceso
#include <sys/wait.h>   //Declaracion de waiting
#include <stdio.h>      //Procesos de entrada y salida
#include <string.h>     //Cadenas
#include <errno.h>      //Errores
#include <stdlib.h>     //Reserva de memoria, conversion de datos, numeros aleatorios

int main(){
    pid_t pid=fork();                                           //Declaracion de proceso
    if(pid==-1){
        printf("Error al hacer fork: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d] Soy el hijo\n", getpid());                //Proceso hijo generado
    }
    else{                                       
        int segundos=10;
        printf("[%d] Soy el padre. Espero %d segunods\n", getpid(), segundos);          
        sleep(segundos);                                                    //Pausa del proceso
        printf("[%d]Espero a que el hijo acabe\n", getpid());           
        if(wait(NULL)==-1){                                                 //Espera del proceso hijo
            return EXIT_FAILURE;
        }
        printf("[%d]Espero otros %d segundos\n", getpid(), segundos);
        sleep(segundos);
    }
    return EXIT_SUCCESS;
}