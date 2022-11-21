#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include "common.h"

//Prototipo de funcion
FILE *fLog=NULL;
void funcionLog(char *mensaje){
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;
	//Abrir el fichero
	sprintf(nombreFichero,"log-servidor.txt");
	if(fLog==NULL){
		fLog=fopen(nombreFichero,"at");	
		if(fLog==NULL){	
			perror("Error abriendo el fichero de log");	
			exit(1);
		}
	}
	// Obtener la hora actual
	t=time(NULL);
	struct tm *p=localtime(&t);
	strftime(mensajeAEscribir, 1000, "[%Y-%m-%d, %H:%M:%S]", p);
	// Vamos a incluir la hora y el mensaje que nos pasan
	sprintf(mensajeAEscribir, "%s --> %s\n", mensajeAEscribir, mensaje);
	// Escribir finalmente en el fichero
	resultado=fputs(mensajeAEscribir,fLog);
	if(resultado<0){
		perror("Error escribiendo en el fichero de log");
	}
	fclose(fLog);
	fLog=NULL;
}
int main(int argc, char **argv){
	//Cola de servidor-cliente
	mqd_t servidor, cliente;
	//Atributos de la cola
	struct mq_attr atributo;
	//Intercambio de mensajes
	char buffer[MAX_SIZE];
	char mensaje[MAX_SIZE];
	//Tamaño del buffer
	int sizebuffer;
	//Flag para la parada con exit
	int must_stop=0;
	//Inicializar los atributos de la cola
	atributo.mq_maxmsg=10;	//Maximo numero de mensajes
	atributo.mq_msgsize=MAX_SIZE;	//Maximo tamaño de un mensaje
	//Nombre para la cola
    char serverQueue[MAX_SIZE], clientQueue[MAX_SIZE];
	sprintf(serverQueue, "%s-%s", SERVER_QUEUE, getenv("USER"));
    printf ("[Servidor]: El nombre de la cola servidor es: %s\n", serverQueue);
    sprintf(mensaje, "[Servidor]: El nombre de la cola servidor es: %s\n", serverQueue );
    funcionLog(mensaje);
    sprintf(clientQueue, "%s-%s", CLIENT_QUEUE, getenv("USER"));
    printf("[Servidor]: El nombre de la cola client es %s\n", clientQueue);
    sprintf(mensaje, "[Servidor]: El nombre de la cola client es %s\n", clientQueue);
    funcionLog(mensaje);
    //Apertura de la colas
	servidor=mq_open(serverQueue, O_CREAT | O_RDONLY, 0644, &atributo);
    cliente=mq_open(clientQueue, O_CREAT | O_WRONLY, 0644, &atributo);
    //Control de errores apertura de las colas
	if(servidor==(mqd_t)-1 || cliente==(mqd_t)-1 ){	
   		perror("Error al abrir la cola del servidor");
   		funcionLog("Error al abrir la cola del servidor");
    	exit(-1);
	}
	//Descriptor y envío de mensajes
    printf("[Servidor]: El descriptor de la cola servidor es: %d\n", (int) servidor);
    sprintf(mensaje, "[Servidor]: El descriptor de la cola servidor es: %d\n", (int) servidor );
    printf("[Servidor]: El descriptor de la cola cliente es: %d\n", (int) cliente);
    sprintf(mensaje, "[Servidor]: El descriptor de la cola cliente es: %d\n", (int) cliente );
    funcionLog(mensaje);
    //Recibo de mensajes
	while(!must_stop){
		//Numero de bytes leidos
		ssize_t bytes;
		//Recibo del mensaje
		bytes=mq_receive(servidor, buffer, MAX_SIZE, NULL );
		//Comprobacion de la recepcion
		if(bytes<0){
			perror( "Error al recibir el mensaje\n" );
			funcionLog( "Error al recibir el mensaje\n" );
			exit(-1);
		}
		//Recogida de las señales SIGTINT, SIGTERM y exit 
		if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))==0){
			must_stop=1;
		}
		else if(strncmp(buffer, "SIGINT", strlen("SIGINT"))==0){
			must_stop=1;
		}
		else if(strncmp(buffer, "SIGTERM", strlen("SIGTERM"))==0){
			must_stop=1;
		}
		//Recibo de mensajes del cliente
		else{
			printf("Recibido el mensaje del cliente: %s", buffer);
			sprintf(mensaje, "Recibido el mensaje del cliente: %s\n", buffer );
			funcionLog(mensaje);
			sizebuffer=strlen(buffer);
			for(int i=0; i<sizebuffer; i++){
				if(buffer[i]==' ' || buffer[i]=='\n' ){
					sizebuffer--;
				}
			}
			sprintf(mensaje, "%d", sizebuffer);
			//Control de error
			if((mq_send(cliente, mensaje, MAX_SIZE, 0))!=0){
				perror("Error al enviar el mensaje" );
				funcionLog("Error al enviar el mensaje" );
				exit(-1);
			}
		}
	} 
	//Control de errores cierre
	if((mq_close(servidor)==(mqd_t)-1) || ((mq_close(cliente))==(mqd_t)-1)){
		perror( "Error al cerrar la cola del servidor" );
		funcionLog( "Error al cerrar la cola del servidor" );
		exit(-1);
	}
	//Control de errores eliminacion
	if((mq_unlink(serverQueue)==(mqd_t)-1) || ((mq_unlink(clientQueue))==(mqd_t)-1)){
		perror("Error al eliminar la cola del servidor");
		funcionLog("Error al eliminar la cola del servidor");
		exit(-1);
	}
	return 0;
}
