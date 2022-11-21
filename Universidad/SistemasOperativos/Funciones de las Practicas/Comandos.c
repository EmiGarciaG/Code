#include <sys/types.h>	//Define pid_t
#include <unistd.h>     //API de POSIX y creacion de un proceso
#include <sys/wait.h>   //Declaracion de waiting
#include <stdio.h>      //Procesos de entrada y salida
#include <string.h>     //Cadenas
#include <errno.h>      //Errores
#include <stdlib.h>     //Reserva de memoria, conversion de datos, numeros aleatorios

int comando1(char *comando){																			
    execlp(comando, comando, (char *) NULL);															//Lanzamiento del programa
    printf("[%d] El comando fallo con el siguiente error [%d]: %s", getpid(), errno, strerror(errno));  //Error
    return EXIT_FAILURE;
}
int comando2(char *comando){																			
    execlp(comando, comando, (char *) NULL);															//Lanzamiento del programa
    printf("[%d] El comando fallo con el siguiente error [%d]: %s", getpid(), errno, strerror(errno));  //Error
    return EXIT_FAILURE;
}
int comando3(char **comando){																			
    execvp(comando[0], comando);																		//Lanzamiento del programa
    printf("[%d] El comando fallo con el siguiente error [%d]: %s", getpid(), errno, strerror(errno));	//Error
    return EXIT_FAILURE;
}
int esperar_hijos(){									//Funcion para esperar los procesos
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
int main(int argc, char **argv){
     if(argc<4){								//Comprobacion al escribir el .exe junto a los otros dos programas
        printf("Uso incorrecto de argumentos.");
        return EXIT_FAILURE;   
    }
    pid_t pid=fork();							//Creacion de proceso 1(primer programa)
    if(pid==-1){
        printf("[%d] Error al crear el hijo del primer comando: %s\n", getpid(), strerror(errno));
        return EXIT_FAILURE;					
    }
    else if(pid==0){
        printf("[%d]Soy el primer hijo.El PID de mi padre es %d\n", getpid(), getppid());
        return comando1(argv[1]);				//Posicion1
    }
    pid=fork();									//Creacion de proceso 3(tercer programa)
    if(pid==-1){
        printf("[%d]Error al crear el hijo del tercer comando: %s\n",getpid(), strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d]Soy el tercer hijo.El PID de mi padre es %d\n", getpid(), getppid());
        return comando2(argv[2]);				//Posicion2
    }
     pid=fork();									//Creacion de proceso 2(segundo programa)
    if(pid==-1){
        printf("[%d]Error al crear el hijo del segundo comando: %s\n",getpid(), strerror(errno));
        return EXIT_FAILURE;
    }
    else if(pid==0){
        printf("[%d]Soy el segundo hijo.El PID de mi padre es %d\n", getpid(), getppid());
        return comando3(&argv[3]);				//Posicion2
    }
    return esperar_hijos(0);
}
