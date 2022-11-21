#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
    if(argc!=2){
        printf("Uso incorrecto de argumentos.");        
        return EXIT_FAILURE;   
    }
    int n=atoi(argv[1]);
    int factorial=1;
    for(int i=1; i<=n; i++){
        factorial=factorial*i;
        printf("[%d]    %d\n", getpid(), factorial);
        sleep(1);
    }
    printf("[%d] %d\n", getpid(), factorial);
    return EXIT_SUCCESS;
}