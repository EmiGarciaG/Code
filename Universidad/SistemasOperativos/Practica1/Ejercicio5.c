#include <sys/types.h>	
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int valor_global=0;

int main(int argc, char **argv){
    if(argc!=2){
        printf("Uso incorrecto de argumentos.\n");
        return EXIT_FAILURE;   
    }
    int hijos=atoi(argv[1]);
    if(hijos<0){
        printf("Numero invalido\n");
        return EXIT_FAILURE;
    }
    valor_global=0;
    for(int i=0; i<hijos; i++){
        pid_t pid=fork();
        if(pid==-1){
            printf("[%d]Error fork hijo nº %d: %s\n", getpid(), i, strerror(errno));
            break;
        }
        else if (pid==0) {
            printf("[%d]Proceso hijo con PID %d y mi padre %d\n", getpid(), pid, getppid());
            valor_global++;
        }
        else {
            printf("[%d]Proceso padre: generado hijo con PID %d\n", getpid(), pid);
        }
    }
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
    printf("[%d]El valor global es igual a %d\n", getpid(), valor_global);
    return EXIT_SUCCESS;
}