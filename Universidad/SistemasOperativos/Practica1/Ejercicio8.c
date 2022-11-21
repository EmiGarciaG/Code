#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void manejar_senal(int signo){
    printf("Mi PID es %d\n", getpid());
}
int main(){
    signal(SIGUSR1, manejar_senal);
     printf("Mi PID es %d\n", getpid());
     while(1){
        pause();
     }
     return EXIT_SUCCESS;
}