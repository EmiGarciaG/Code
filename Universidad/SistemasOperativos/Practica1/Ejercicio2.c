#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    pid_t pid=fork();
    if(pid==-1){
        printf("Error al hacer fork: %s", strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d] Soy el hijo\n", getpid());
    }
    else{
        int segundos=10;
        printf("[%d] Soy el padre. Espero %d segunods\n", getpid(), segundos);
        sleep(segundos);
        printf("[%d]Espero a que el hijo acabe\n", getpid());
        if(wait(NULL)==-1){
            return EXIT_FAILURE;
        }
        printf("[%d]Espero otros %d segundos\n", getpid(), segundos);
        sleep(segundos);
    }
    return EXIT_SUCCESS;
}