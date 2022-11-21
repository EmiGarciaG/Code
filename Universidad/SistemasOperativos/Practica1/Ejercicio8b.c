#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
    if(argc!=2){
        printf("Uso incorrecto de argumentos.");
        return EXIT_FAILURE;
    }
    int pid_int=atoi(argv[1]);
    if(pid_int<=0){
        printf("PID invalido: %d\n", pid_int);
        return EXIT_FAILURE;
    }
    pid_t pid=(pid_t) pid_int;
    if(kill(pid, SIGUSR1)){
        printf("Error al enviar SIGUSR1; %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    sleep(1);
    if(kill(pid, SIGKILL)){
        printf("Error al enviar SIGKILL: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}