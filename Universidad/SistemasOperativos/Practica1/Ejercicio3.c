#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int comando1(char *comando);
int comando2(char **comando);
int esperar_hijos();

int main(int argc, char **argv){
    if(argc<3){
        printf("Uso incorrecto de argumentos.");
        return EXIT_FAILURE;   
    }
    pid_t pid=fork();
    if(pid==-1){
        printf("[%d] Error al crear el hijo del primer comando: %s\n", getpid(), strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d]Soy el primer hijo.El PID de mi padre es %d\n", getpid(), getppid());
        return comando1(argv[1]);
    }
    pid=fork();
    if(pid==-1){
        printf("[%d]Error al crear el hijo del segundo comando: %s\n",getpid(), strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d]Soy el segundo hijo.El PID de mi padre es %d\n", getpid(), getppid());
        return comando2(&argv[2]);
    }
    return esperar_hijos(0);
}
int comando1(char *comando){
    execlp(comando, comando, (char *) NULL);
    //Error
    printf("[%d] El comando fallo con el siguiente error [%d]: %s", getpid(), errno, strerror(errno));
    return EXIT_FAILURE;
}
int comando2(char **comando){
    execvp(comando[0], comando);
    //Error
    printf("[%d] El comando fallo con el siguiente error [%d]: %s", getpid(), errno, strerror(errno));
    return EXIT_FAILURE;
}
int esperar_hijos(){
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