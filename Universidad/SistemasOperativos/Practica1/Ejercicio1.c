#include <sys/types.h>	
#include <unistd.h>     
#include <sys/wait.h>   
#include <stdio.h>      
#include <string.h>     
#include <errno.h>      
#include <stdlib.h>     

int main(int argc, char **argv ){
    pid_t pid;                                 
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
    for(int i=0; i<hijos; i++){                                    
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
        pid=wait(&status);                          
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
    }
    return EXIT_SUCCESS;                            
}
