#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
    if(argc!=2){
        printf("Uso incorrecto de argumentos.");        
        return EXIT_FAILURE;   
    }
    int n=atoi(argv[1]);
    int x=0;
    int y=1;
    int aux;
    if(n==0){
        sleep(1);
        return EXIT_FAILURE;
    }
    else if(n==1){
        printf("[%d]    %d\n", getpid(), x);
        sleep(1);
        return EXIT_SUCCESS;
    }
    else if(n==2){
        printf("[%d]    %d\n", getpid(), x);
        sleep(1);
        printf("[%d]    %d\n", getpid(), y);
        return EXIT_SUCCESS;
    }
    printf("[%d]    %d\n", getpid(), x);
    sleep(1);
    printf("[%d]    %d\n", getpid(), y);
    sleep(1);
    for(int i=2; i<n; i++){
        aux=y+x;
        x=y;
        y=aux;
        printf("[%d]    %d\n", getpid(), aux);
        sleep(1);
    }
    printf("[%d] %d\n", getpid(), aux);
    return EXIT_SUCCESS;
}