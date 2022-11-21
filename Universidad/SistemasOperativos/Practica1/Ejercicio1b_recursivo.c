#include <sys/types.h>  //Define pid_t
#include <unistd.h>     //API de POSIX y creacion de un proceso
#include <sys/wait.h>   //Declaracion de waiting
#include <stdio.h>      //Procesos de entrada y salida
#include <string.h>     //Cadenas
#include <errno.h>      //Errores
#include <stdlib.h>     //Reserva de memoria, conversion de datos, numeros aleatorios

int nuevo_proceso(int hijos_restantes){
    printf("[%d]Proceso hijo con PID y mi padre %d\n", getpid(), getppid());
    if(hijos_restantes==0){
        return EXIT_SUCCESS;
    }
    pid_t pid=fork();
    if(pid==-1){
        printf("[%d]Error fork hijo nº %d: %s\n", getpid(), hijos_restantes, strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        return nuevo_proceso(hijos_restantes-1);
    }

    int hijo_status;
    pid_t hijo_esperado=wait(&hijo_status);
    while(1){
        int hijo_status;
        pid_t hijo_esperado=wait(&hijo_status);
        if(hijo_esperado>0){
            if(WIFEXITED(hijo_status)){
                printf("[%d]Hijo con PID %d ha terminado con %d\n",
                getpid(), hijo_esperado, WEXITSTATUS(hijo_status));  
            }
            else if(WIFSIGNALED(hijo_status)){
                printf("[%d]Hijo con PID %d ha terminado debido a una señal sin recoger, con codigo %d, correspondiente a \"%s\"\n", getpid(), hijo_esperado, 
                WTERMSIG(hijo_status), strsignal(WTERMSIG(hijo_status)));
            }
        }
        else{
            if(errno==ECHILD){
                printf("[%d]Todos los hijos han sido esperados.\n", getpid());
                break;
            }
            else{
                printf("[%d]Error esperando a los hijos: %s\n", getpid(), strerror(errno));
                return EXIT_FAILURE;
            }
        }
    }
}

int main(int argc, char **argv ){

    //Comprobacion de argumentos
    if(argc!=2){
        printf("Uso incorrecto de argumentos. El uso correcto es: \n%s N\nSiendo N el numero de procesos a generar.\n", argv[0]);
        return EXIT_FAILURE;   
    }
    //Evitamos que sea negativo
    int hijos=atoi(argv[1]);
    if(hijos<0){
        printf("Numero invalido");
        return EXIT_FAILURE;
    }
    return nuevo_proceso(hijos-1);
}
