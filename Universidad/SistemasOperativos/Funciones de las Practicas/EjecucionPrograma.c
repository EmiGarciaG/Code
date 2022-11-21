#include <sys/types.h>  //Define pid_t
#include <unistd.h>     //API de POSIX y creacion de un proceso
#include <sys/wait.h>   //Declaracion de waiting
#include <stdio.h>      //Procesos de entrada y salida
#include <string.h>     //Cadenas
#include <errno.h>      //Errores
#include <stdlib.h>     //Reserva de memoria, conversion de datos, numeros aleatorios

int esperar_hijos(){                        //Funcion para esperar los procesos
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

int main(int argc, char **argv){
    if(argc!=3){
        printf("Uso incorrecto de argumentos.");
        return EXIT_FAILURE;   
    }
    pid_t pid;
    pid=fork();
    if(pid==-1){
        printf("Error al hacer fork: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        execl("./Fibonacci.exe", "./Fibonacci.exe", argv[1], (char *) NULL); //Ejecucion factorial primer argumento 
        printf("Error al ejecutar: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    pid=fork();
    if(pid==-1){
        printf("Error al hacer fork: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        execl("./Fibonacci.exe", "./Fibonacci.exe", argv[2], (char *) NULL);  //Ejecucion factorial segundo argumento 
        printf("Error al ejecutar: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    return esperar_hijos();
}
