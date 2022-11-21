#include <sys/types.h>	//Define pid_t
#include <unistd.h>     //API de POSIX y creacion de un proceso
#include <sys/wait.h>   //Declaracion de waiting
#include <stdio.h>      //Procesos de entrada y salida
#include <string.h>     //Cadenas
#include <errno.h>      //Errores
#include <stdlib.h>     //Reserva de memoria, conversion de datos, numeros aleatorios

int main(int argc, char **argv ){
    pid_t pid;                                  //Declaracion de procesos
    int hijos=atoi(argv[1]);
    if(hijos<0){
        printf("Numero invalido");
        return EXIT_FAILURE;
    }
    if(argc!=2){
        printf("Error numero de argumentos\n");
        return EXIT_FAILURE;
    }
    printf("Proceso padre con PID %d\n", getppid());
    for(int i=0; i<hijos; i++){                                    //Declaracion de hijos simultaneos
        pid=fork();
        switch(pid){
            case -1:
                printf("Error al hacer fork: %s\n", strerror(errno));
                return EXIT_FAILURE;
            case 0:
                printf("Soy el proceso hijo con PID %d\n", getpid());
                return EXIT_SUCCESS;
            default:
                printf("Soy el proceso padre con PID %d\n", getpid());
                break;
        }
    }
    int status;
    for(int i=0; i<hijos; i++){
        pid=wait(&status);                          //Declaracion estado hijos
        if(pid>0){
            if(WIFEXITED(status)){
                printf("Hijo con PID %d ha terminado con %d\n", pid, WEXITSTATUS(status));  
            }
            else if(WIFSIGNALED(status)){
                printf("Hijo con PID %d ha terminado debido a una señal sin recoger, con codigo %d, correspondiente a \"%s\"\n", pid, 
                WTERMSIG(status), strsignal(WTERMSIG(status)));
            }
        }
        else{
            printf("Fallo del wait: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }                                                               //Hijos esperados correctamente
    for(int i=0; i<hijos; i++){                                     //Declaracion de hijos en linea
        pid_t pid=fork();
        if(pid==-1){
            printf("[%d]Error fork hijo nº %d: %s\n", getpid(), i, strerror(errno));
            return EXIT_FAILURE;
        }
        else if (pid==0) {
            printf("[%d]Proceso hijo con PID %d y mi padre %d\n", getpid(), pid, getppid());
        }
        else {
            printf("[%d]Proceso padre: generado hijo con PID %d\n", getpid(), pid);
            break;
        }
    }
    while(1){                                                       //Espera de hijos en inea
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
        }                                                           //Se han esperado correctamente
    }                           
    return EXIT_SUCCESS;                            
}
