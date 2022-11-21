#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <mqueue.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAX_SIZE 1024
#define MSG_STOP "exit"
#define QUEUE_NAME  "/mens_cola"

int main(){
	//Cola de mensajes
	mqd_t mq;
	//Atributos de la cola
	struct mq_attr atributo;
	//Intercambio mensajes
	char buffer[MAX_SIZE];
	char mensaje[MAX_SIZE];
	//Nombre cola
    char queue_name[MAX_SIZE];
    //Tamaño del buffer
	int sizebuffer;
	//Flag para la parada con exit
	int must_stop=0;
	//Numero de bytes leidos
	ssize_t bytes;
	//Pid para hacer fork
	pid_t pid;
	int flag;
	int status;
	//Inicializar los atributos de la cola
	atributo.mq_maxmsg=10;	//Maximo numero de mensajes
	atributo.mq_msgsize=MAX_SIZE;	//Maximo tamaño de un mensaje
	//Nombre para la cola
    sprintf(queue_name, "%s-%s", QUEUE_NAME, getenv("USER"));
    //Creacion del hijo
	pid=fork();
	switch(pid){
		//Error
		case -1:
			printf("No he podido crear el proceso hijo \n");
			exit(1);
		//Hijo que se enecargara de escribir el mensaje y recibir la respuesta del padre
		case 0: 
		/* Apertura de la cola
			O_CREAT: si no existe, se crea
			O_RDWR: lectura/escritura
		    O_RDONLY: solo lectura
			O_WRONLY: solo escritura
			0644: permisos rw-r--r--
            permisos de lectura y escritura para el propietario, y de sólo lectura para el grupo y para otros
			attr: estructura con atributos para la cola  */
			mq=mq_open(queue_name, O_CREAT | O_RDWR, 0644, &atributo);
            printf("[HIJO]: El nombre de la cola es: %s\n", queue_name);
            printf("[HIJO]: El descriptor de la cola es: %d\n", (int) mq);
            //Control de error apertura cola
			if(mq==-1){
				perror("[HIJO]: Error en la apertura de la cola");
				exit(-1);
			}
			printf("[HIJO]: Mi PID es %d y el de mi padre es %d\n", getpid(), getppid());
			printf("[HIJO]: Mandando mensajes al padre (escribir \"%s\" para parar):\n", MSG_STOP);
			while(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))){
				printf("> ");
				fgets(buffer, MAX_SIZE, stdin);
				printf("[HIJO]: Generado el mensaje: %s", buffer);
				printf("[HIJO]: Enviando mensaje...\n");
				//Mandamos el mensaje y control de error del envio
				if(mq_send(mq, buffer, MAX_SIZE, 0)==-1){
					perror("[HIJO]: Error al enviar mensaje");
					exit(-1);
				}
				printf("[HIJO]: Mensaje enviado correctamente\n");
				//Recibimos el mensaje del padre con su longitud
				if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))!=0){
					sizebuffer=mq_receive(mq, mensaje, MAX_SIZE, NULL);
					if(sizebuffer<0){
						perror("Error al recibir el mensaje");	
						exit(-1);
					}
					printf("[HIJO]: Recibido el mensaje de %s\n", mensaje);
				}
			}
			if(mq_close(mq)==-1){
				perror("[HIJO]: Error cerrando la cola");
				exit(-1);
			}
            printf("[HIJO]: La cola ha sido cerrada\n");
		break;
		//Padre que se encargara de leer y mandar al hijo la longitud del mensaje
		default: 
			//Apertura de la cola
			mq=mq_open(queue_name, O_CREAT | O_RDWR, 0644, &atributo);
            printf("[PADRE]: El nombre de la cola es: %s\n", queue_name);
            printf("[PADRE]: El descriptor de la cola es:%d\n", (int) mq);
            //Control de error apertura cola
			if(mq==-1){
				perror("[PADRE]: Error en la apertura de la cola");
				exit(-1);
			}
			printf("[PADRE]: Mi PID es %d y de mi hijo es %d \n", getpid(), pid);
			printf("[PADRE]: Recibiendo mensaje (espera bloqueante)...\n");
			//Recibo de mensajes
			while(!must_stop){
					bytes=mq_receive(mq, buffer, MAX_SIZE, NULL);
					if(bytes<0){
						perror("[PADRE]: Error al recibir el mensaje");
						exit(-1);
					} 
					if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0){
						must_stop=1;	
					} 
					else{
							printf("[PADRE]: El mensaje recibido es: %s", buffer);
							sizebuffer=strlen(buffer);
							for(int i=0; i<sizebuffer; i++){
								if(buffer[i]==' ' || buffer[i]=='\n'){
									sizebuffer--;	
								} 
							}
							printf("[PADRE]: Numero de caracteres recibidos->%d\n", sizebuffer);
							sprintf(mensaje, "los caracteres recibidos: %d", sizebuffer);
							if((mq_send(mq, mensaje, MAX_SIZE, 0 ))!=0){
								perror( "Error al enviar el mensaje" );
								exit(-1);
							} 
					} 
			}
			//Control error de cierre de la cola
			if(mq_close(mq)==-1){
				perror("[PADRE]: Error cerrando la cola");
				exit(-1);
			}
			printf("[PADRE]: La cola ha sido cerrada\n");
			//Control error de eliminacion de la cola
			if(mq_unlink(queue_name)==-1){
				perror("[PADRE]: Error eliminando la cola");
				exit(-1);
			}
			//Espera del padre a los hijos
	    	while((flag=wait(&status))>0){
		    	if (WIFEXITED(status)) {
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
	exit(0);
}
