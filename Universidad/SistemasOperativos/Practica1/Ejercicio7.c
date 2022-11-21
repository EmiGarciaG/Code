#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int senales_recibidas;

void tratarSenal(int signo){
    printf("[%d] Recibida %s\n", getpid(), strsignal(signo));
    senales_recibidas++;
}
int main(){
    int n_senales=5;
    signal(SIGUSR1, tratarSenal);
    pid_t pid=fork();
    if(pid==-1){
        printf("[%d]Error al hacer fork: %s\n", getpid(), strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d] Hijo. PID de padre es %d\n", getpid(), getppid());
        senales_recibidas=0;
        while(senales_recibidas<n_senales){
            //pause();
        }
        return EXIT_SUCCESS;
    }
    printf("[%d] Padre. Proceso hijo lanzado con PID %d\n", getpid(), pid);
    for(int i=0; i<n_senales; i++){
        sleep(1);
        if(kill(pid,SIGUSR1)){
            printf("Error al enviar señal: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }
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
            else{
                printf("[%d]Hijo con PID %d ha terminado de forma inesperada\n",
                getpid(), hijo_esperado);
            }
        }
        else{
            if(errno==ECHILD){
                printf("[%d]Todos los hijos han sido esperados.\n", getpid());
            }
            else{
                printf("[%d]Error esperando a los hijos: %s\n", getpid(), strerror(errno));
                return EXIT_FAILURE;
            }
        }
    return EXIT_SUCCESS;
}