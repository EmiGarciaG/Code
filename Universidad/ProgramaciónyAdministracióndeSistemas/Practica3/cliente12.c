#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include "common.h"

//Prototipo de funcion
FILE *fLog=NULL;
void funcionLog(char *mensaje){
	int resultado;
	char nombreFichero[100];
	char mensajeAEscribir[300];
	time_t t;
	//Abrir el fichero
	sprintf(nombreFichero,"log-cliente.txt");
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
// Cola del servidor
mqd_t servidor;
mqd_t cliente;
void SigInt(int signal){
	//Guardar SIGINT
	char buffer[100];
	sprintf(buffer, "[Cliente]: Se ha recibido la señal SIGINT con codigo entero %d\n", signal);
	funcionLog(buffer);
	//Recibo de la señal
	if(mq_send(servidor, "SIGINT", strlen("SIGINT"), 0)!=0){
		perror( "Error al enviar mensaje");
		exit(-1);
	}
	//Cierre cola
	if((mq_close(servidor)==(mqd_t)-1) || ((mq_close(cliente))==(mqd_t)-1)){
		perror( "Error al cerrar la cola del servidor" );
		funcionLog( "Error al cerrar la cola del servidor" );
		exit(-1);
	}
	//Fin
	exit(-1);
}
void SigTerm(int signal){
	//Guardar SIGTERM
	char buffer[100];
	sprintf(buffer, "[Cliente]: Se ha recibido la señal SIGTERM con codigo entero %d\n", signal);
	funcionLog(buffer);
	//Recibo de la señal
	if(mq_send(servidor, "SIGTERM", strlen("SIGTERM"), 0)!=0){
		perror( "Error al enviar mensaje");
		exit(-1);
	}
	//Cierre cola
	if((mq_close(servidor)==(mqd_t)-1) || ((mq_close(cliente))==(mqd_t)-1)){
		perror( "Error al cerrar la cola del servidor" );
		funcionLog( "Error al cerrar la cola del servidor" );
		exit(-1);
	}
	//Fin
	exit(-1);
}
int main(int argc, char **argv){
	//Recogida de señales
	signal(SIGINT, &SigInt);
	signal(SIGTERM, &SigTerm);
	//Lectura de bytes
	ssize_t bytes_read;  
	//Intercambio mensajes
	char buffer[MAX_SIZE]; 
	char mensaje[MAX_SIZE];
    //Nombre colas
    char serverQueue[MAX_SIZE], clientQueue[MAX_SIZE];
	sprintf(serverQueue, "%s-%s", SERVER_QUEUE, getenv("USER"));
    sprintf (mensaje,"[Cliente]: El nombre de la cola server es: %s\n", serverQueue);
    funcionLog(mensaje);
    sprintf(clientQueue, "%s-%s", CLIENT_QUEUE, getenv("USER"));
    printf("[Cliente]: El nombre de la cola client es: %s\n", clientQueue);
    sprintf(mensaje, "[Cliente]: El nombre de la cola client es: %s\n", clientQueue);
    funcionLog(mensaje);
    //Apertura de las colas
    servidor=mq_open(serverQueue, O_WRONLY);
    cliente=mq_open(clientQueue, O_RDONLY);
    //Control de errores apertura
	if(servidor==(mqd_t)-1 || cliente==(mqd_t)-1){
      	perror("Error al abrir las colas");
      	funcionLog("Error al abrir las colas");
      	exit(-1);
	}
	//Descriptor y envío de mensajes
    printf ("[Cliente]: El descriptor de la cola server es: %d\n", (int) servidor);
    sprintf(mensaje, "[Cliente]: El descriptor de la cola server es: %d\n", (int) servidor);
    funcionLog(mensaje);
    printf("[Cliente]: El descriptor de la cola cliente es: %d\n", (int) cliente);
    sprintf(mensaje, "[Cliente]: El descriptor de la cola cliente es: %d\n", (int) cliente);
    funcionLog(mensaje);
	printf("Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	sprintf(mensaje, "Mandando mensajes al servidor (escribir \"%s\" para parar):\n", MSG_STOP);
	//Entrada por teclado
	while(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))){	
		printf(">");
		/* Leer por teclado. Según la documentación, fgets lo hace de esta manera:
		It stops when either (n-1) characters are read, the newline character is read,
		or the end-of-file is reached, whichever comes first.
		Automáticamente fgets inserta el fin de cadena '\0'
		*/
		fgets(buffer, MAX_SIZE, stdin);
		//Control envio de mensaje
		if(mq_send(servidor, buffer, MAX_SIZE, 0)!=0){
			perror("Error al enviar el mensaje");
			funcionLog("Error al enviar el mensaje");
			exit(-1);
		}
		//Recibo de mensajes del servidor
		if(strncmp(buffer, MSG_STOP, strlen(MSG_STOP))!=0){
			bytes_read=mq_receive(cliente, mensaje, MAX_SIZE, NULL);
			if(bytes_read<0){
				perror("Error al recibir el mensaje");
				funcionLog("Error al enviar el mensaje");
				exit(-1);
			}
			printf("Numero de caracteres recibidos: %s\n", mensaje);
			funcionLog("Numero de caracteres recibidos: ");
			funcionLog(mensaje);
		}
	}
	//Control de errores cierre de las colas
	if(mq_close(servidor)==(mqd_t)-1 || mq_close(cliente)==(mqd_t)-1){
		perror("Error al cerrar la cola del servidor");
		funcionLog("Error al cerrar la cola del servidor");
		exit(-1);
	}
	return 0;
}