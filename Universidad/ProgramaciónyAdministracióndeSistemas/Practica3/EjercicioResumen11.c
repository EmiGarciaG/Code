#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h> 
#include <string.h> 


int main(){
	//Pid para hacer fork
	pid_t pid;
	int flag;
	int status;
	// Para controlar los valores devueltos por las funciones (control de errores)
	float resultado; 
	float aleatorio;
	//Descriptores de los dos extremos
	int fileDes[2];
	float suma=0;
	//Creacion tuberia
	resultado=pipe(fileDes);
	//Control de errores
	if(resultado==-1){
		printf("\nERROR al crear la tubería.\n");
		exit(1);
	}
	printf("[PADRE]: Mi PID es %d y voy a hacer fork\n", getppid());
	pid=fork();
	switch (pid){
		case -1:
			printf("Error al hacer fork: %s\n", strerror(errno));
            return EXIT_FAILURE;
		case 0:
			printf ("[HIJO]: Mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
			//Lectura del hijo
			close(fileDes[1]);
			//Recibo del numero
			resultado=read(fileDes[0], &suma, sizeof(int));
			//Control de error recibo de numero
			if(resultado!=sizeof(int)){
				printf("\n[HIJO]: ERROR al leer de la tubería...\n");
				exit(EXIT_FAILURE);
			}
			//Salida por pantalla del numero recibido
			printf("[HIJO]: Suma %f de la tubería.\n", suma);		
			printf("[HIJO]: Tubería cerrada ...\n");
			close(fileDes[0]);
			break;
		default:
			printf ("[PADRE]: Mi PID es %d y el PID de mi hijo es %d \n", getpid(), pid);
			//Escritura
			close(fileDes[0]);
			srand48(time(NULL));
			//Creacion y suma de numeros aleatorios
			for(int i=0; i<2; i++){			
				aleatorio=drand48()*100; 
				printf("[PADRE]: Numero aleatorio generado: %f\n", aleatorio);
				suma=suma+aleatorio;
			}
			printf("[PADRE]: Escribo la suma %f en la tubería...\n", suma);
			//Envio del numero
			resultado=write(fileDes[1], &suma, sizeof(float));
			if(resultado!=sizeof(float)){
				printf("\n[PADRE]: ERROR al escribir en la tubería...\n");
				exit(EXIT_FAILURE);
			}
			//Cierre de escritura
			close(fileDes[1]);
			printf("[PADRE]: Tubería cerrada...\n");
			//Espera del hijo
			while((flag=wait(&status))>0){
				if(WIFEXITED(status)){
					printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)flag, WEXITSTATUS(status));
				} 
				else if(WIFSIGNALED(status)){
					printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
				} 		
			}
			if(flag==(pid_t)-1 && errno==ECHILD){
				printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
			}
			else{
				printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
				exit(EXIT_FAILURE);
			}				 
	}
	exit(EXIT_SUCCESS);
}
/*Otra forma parecida de hacer los procesos
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
			while(1){
        		int hijo_status;
        		pid_t hijo_esperado=wait(&hijo_status);
        		if(hijo_esperado>0){
            		if(WIFEXITED(hijo_status)){
                		printf("[%d]Hijo con PID %d ha terminado con %d\n",
               			getpid(), hijo_esperado, WEXITSTATUS(hijo_status));  
            		}
            		else if(WIFSIGNALED(hijo_status)){
                		printf("[%d]Hijo con PID %d ha terminado debido a una señal sin recoger, con codigo %d, correspondiente a \"%s\"\n", getpid(), hijo_esperado, WTERMSIG(hijo_status), strsignal(WTERMSIG(hijo_status)));
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
    		}*/