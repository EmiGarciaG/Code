#include <stdio.h>	//Procesos de entrada y salida
#include <signal.h> //Libreria de señales
#include <unistd.h> //API de POSIX y creacion de un proceso
#include <stdlib.h> //Reserva de memoria, conversion de datos, numeros aleatorios

int numero_timbres;
void manejador_alarma(int signal){
    printf("ALARM!!!\n");
    numero_timbres++;
}
int main(int argc, char **argv){
	if(argc<1){								//Comprobacion argumentos
        printf("Uso incorrecto de argumentos.");
        return EXIT_FAILURE;   
    }
    int n=atoi(argv[1]);
    numero_timbres=0;
    signal(SIGALRM, &manejador_alarma);
    int longitud_alarma[]={n};
    for(int i=0; i<1; i++){
        alarm(longitud_alarma[i]);
        while(numero_timbres<=i){
            printf("%d\n", numero_timbres);
            sleep(1);
        }
    }
    kill(getpid(), SIGKILL);
    return 0;
}
