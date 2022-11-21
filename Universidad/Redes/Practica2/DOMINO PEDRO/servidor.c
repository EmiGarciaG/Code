#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include<signal.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include "domino.h"


#define MSG_SIZE 250
#define MAX_CLIENTS 50


/*
 * El servidor ofrece el servicio de un chat
 */

void manejador(int signum);
void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]);



int main ( )
{
  
	/*---------------------------------------------------- 
		Descriptor del socket y buffer de datos                
	-----------------------------------------------------*/
	int sd, new_sd;
	struct sockaddr_in sockname, from;
	char buffer[MSG_SIZE];
	socklen_t from_len;
    fd_set readfds, auxfds;
    int salida;
    int arrayClientes[MAX_CLIENTS];
    int numClientes = 0;
    //contadores
    int i,j,k;
	int recibidos;
    char identificador[MSG_SIZE];
    
    int on, ret;


    /* --------------------------------------------------
        VARIABLES QUE NECESITO PARA EL JUEGO DEL DOMINO
    ---------------------------------------------------*/
    Jugador jug;
    char aux[50];
    char aux2[50];
    int buscarMesa;
    char mensaje[MSG_SIZE];
    char * mensaje2;
    Ficha f;
    int robar;

    /* --------------------------------------------------
        INICIALIZO EL JUEGO DEL DOMINO
    ---------------------------------------------------*/
    inicializarJuego();
    
    
	/* --------------------------------------------------
		Se abre el socket 
	---------------------------------------------------*/
  	sd = socket (AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("No se puede abrir el socket cliente\n");
    		exit (1);	
	}
    
    // Activaremos una propiedad del socket que permitir· que otros
    // sockets puedan reutilizar cualquier puerto al que nos enlacemos.
    // Esto permitir· en protocolos como el TCP, poder ejecutar un
    // mismo programa varias veces seguidas y enlazarlo siempre al
    // mismo puerto. De lo contrario habrÌa que esperar a que el puerto
    // quedase disponible (TIME_WAIT en el caso de TCP)
    on=1;
    ret = setsockopt( sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));



	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(2000);
	sockname.sin_addr.s_addr =  INADDR_ANY;

	if (bind (sd, (struct sockaddr *) &sockname, sizeof (sockname)) == -1)
	{
		perror("Error en la operación bind");
		exit(1);
	}
	

   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el 
		tamaño de su estructura, el resto de información (familia, puerto, 
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
		from_len = sizeof (from);


		if(listen(sd,1) == -1){
			perror("Error en la operación de listen");
			exit(1);
		}
    
    //Inicializar los conjuntos fd_set
    FD_ZERO(&readfds);
    FD_ZERO(&auxfds);
    FD_SET(sd,&readfds);
    FD_SET(0,&readfds);
    
   	
    //Capturamos la señal SIGINT (Ctrl+c)
    signal(SIGINT,manejador);
    
	/*-----------------------------------------------------------------------
		El servidor acepta una petición
	------------------------------------------------------------------------ */
		while(1){
            
            //Esperamos recibir mensajes de los clientes (nuevas conexiones o mensajes de los clientes ya conectados)
            
            auxfds = readfds;
            
            salida = select(FD_SETSIZE,&auxfds,NULL,NULL,NULL);
            
            if(salida > 0){
                
                
                for(i=0; i<FD_SETSIZE; i++){
                    
                    //Buscamos el socket por el que se ha establecido la comunicación
                    if(FD_ISSET(i, &auxfds)) {
                        
                        if( i == sd){
                            
                            if((new_sd = accept(sd, (struct sockaddr *)&from, &from_len)) == -1){
                                perror("Error aceptando peticiones");
                            }
                            else
                            {
                                if(numClientes < MAX_CLIENTS){
                                    arrayClientes[numClientes] = new_sd;
                                    numClientes++;
                                    FD_SET(new_sd,&readfds);
                                
                                    strcpy(buffer, "Bienvenido al Juego del Dominó\n");
                                
                                    send(new_sd,buffer,strlen(buffer),0);


                                
                                    
                                }
                                else
                                {
                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"Demasiados clientes conectados\n");
                                    send(new_sd,buffer,strlen(buffer),0);
                                    close(new_sd);
                                }
                                
                            }
                            
                            
                        }
                        else if (i == 0){
                            //Se ha introducido información de teclado
                            bzero(buffer, sizeof(buffer));
                            fgets(buffer, sizeof(buffer),stdin);
                            
                            //Controlar si se ha introducido "SALIR", cerrando todos los sockets y finalmente saliendo del servidor. (implementar)
                            if(strcmp(buffer,"SALIR\n") == 0){
                             
                                for (j = 0; j < numClientes; j++){
                                    send(arrayClientes[j], "Desconexion servidor\n", strlen("Desconexion servidor\n"),0);
                                    close(arrayClientes[j]);
                                    FD_CLR(arrayClientes[j],&readfds);
                                }
                                    close(sd);
                                    exit(-1);
                                
                                
                            }
                            //Mensajes que se quieran mandar a los clientes (implementar)
                            
                        } 
                        else{
                            bzero(buffer,sizeof(buffer));
                            
                            recibidos = recv(i,buffer,sizeof(buffer),0);
                            
                            if(recibidos > 0){
                                
                                if(strcmp(buffer,"SALIR\n") == 0){
                                    
                                    salirCliente(i,&readfds,&numClientes,arrayClientes);
                                    
                                }
                                else{

                                    buffer[strlen(buffer)-1] = '\0';

                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO REGISTER
                                    ---------------------------------------------------*/
                                    if(!strncmp(buffer,"REGISTER",8))
                                    {
                                        jug = obtenerCamposRegister(buffer);

                                        if(!buscarUsuarioBD(jug.nombreUsuario))
                                        {
                                            if(registrarJugadorBD(jug))

                                                enviarMensaje(i,"+OK. Se ha registrado correctamente.");
                                            else

                                                enviarMensaje(i,"-ERR. Se ha producido un error al registrarse, intentelo de nuevo.");
                                        }
                                        else
                                            enviarMensaje(i,"-ERR. El nombre de usuario ya existe.");
                                        
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO USUARIO 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"USUARIO",7))
                                    {
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        if(buscarUsuarioBD(aux2))
                                        {
                                            enviarMensaje(i,"+OK. Usuario correcto.");
                                            jugadores[i].estado = LOGIN_USUARIO;
                                            strcpy(jugadores[i].nombreUsuario,aux2);
                                        }
                                        else
                                            enviarMensaje(i,"-ERR. Usuario incorrecto.");
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO PASSWORD 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"PASSWORD",7))
                                    {
                                        sscanf(buffer,"%s %s",aux,aux2);

                                        if(jugadores[i].estado == LOGIN_USUARIO)
                                        {
                                            if(comprobarContrasenaBD(jugadores[i].nombreUsuario,aux2))
                                            {
                                                enviarMensaje(i,"+OK. Usuario validado.");
                                                jugadores[i].estado = LOGUEADO;
                                                volcarDatosUsuarioMemoria(i);
                                                printf("%s se la logueado.\n\n",jugadores[i].nombreCompleto);
                                            }
                                            else
                                                enviarMensaje(i,"-ERR. Error en la validación.");
                                        }
                                        else
                                            enviarMensaje(i,"-ERR. Debe primero introducir el usuario.");
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO INICIAR-PARTIDA 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"INICIAR-PARTIDA",15))
                                    {
                                        if(jugadores[i].estado == LOGUEADO)
                                        {
                                            jugadores[i].estado = ESPERA;

                                            buscarMesa = iniciarPartida(i);
                                            if(buscarMesa == -1)
                                                enviarMensaje(i,"+OK. Debe esperar a que quede una mesa libre.");
                                            else if(buscarMesa == 0)
                                                enviarMensaje(i,"+OK. Petición Recibida. Quedamos a la espera de más jugadores.");
                                            else
                                            {
                                                sprintf(mensaje,"+OK. Comienza a jugar en la mesa %d.",jugadores[i].mesa);
                                                enviarMensaje(i,mensaje);
                                                repartirFichas(jugadores[i].mesa);
                                                enviarFichasJugador(jugadores[i].mesa);
                                                
                                            }
                                        }
                                        else
                                            enviarMensaje(i,"-ERR. Debe estar logueado para iniciar una partida.");
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO COLOCAR-FICHA 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"COLOCAR-FICHA",13))
                                    {
                                        sscanf(buffer,"%s %s",aux,aux2);

                                        if(colocarFicha(jugadores[i].mesa,i,aux2))
                                        {
                                            cambiarTurno(jugadores[i].mesa);
                                            enviarMensajePartida(jugadores[i].mesa);
                                            mensajeTurno(jugadores[i].mesa);
                                            //comprobarFinPartida(jugadores[i].mesa);
                                        }
                                        comprobarFinPartida(jugadores[i].mesa);
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO ROBAR-FICHA 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"ROBAR-FICHA",11))
                                    {
                                        robarFicha(i);

                                        enviarMensajePartida(jugadores[i].mesa);

                                        comprobarFinPartida(jugadores[i].mesa);
                                    }
                                    /* --------------------------------------------------
                                        UN CLIENTE INTRODUCE EL COMANDO ROBAR-FICHA 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"PASAR-TURNO",11))
                                    {
                                        if(partidas[jugadores[i].mesa].turno == i)
                                        {

                                            if(tieneFicha(i) ==0 && contarFichasMonton(jugadores[i].mesa)==0 )
                                            {
                                                cambiarTurno(jugadores[i].mesa);
                                                enviarMensajePartida(jugadores[i].mesa);
                                                mensajeTurno(jugadores[i].mesa);
                                            }
                                            else if(tieneFicha(i)==1)
                                            {
                                                enviarMensaje(i,"-ERR. Tiene ficha par poner.");
                                            }
                                            else if (contarFichasMonton(jugadores[i].mesa)!=0)
                                            {
                                                enviarMensaje(i,"-ERR. Hay fichas para que pueda robar.");
                                            }
                                        }
                                    }
                                }
                                                                
                                
                            }
                            //Si el cliente introdujo ctrl+c
                            if(recibidos== 0)
                            {
                                printf("El socket %d, ha introducido ctrl+c\n", i);
                                //Eliminar ese socket
                                salirCliente(i,&readfds,&numClientes,arrayClientes);
                            }
                        }
                    }
                }
            }
		}

	close(sd);
	return 0;
	
}

void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]){
  
    char buffer[250];
    int j;
    
    close(socket);
    FD_CLR(socket,readfds);
    
    //Re-estructurar el array de clientes
    for (j = 0; j < (*numClientes) - 1; j++)
        if (arrayClientes[j] == socket)
            break;
    for (; j < (*numClientes) - 1; j++)
        (arrayClientes[j] = arrayClientes[j+1]);
    
    (*numClientes)--;
    
    bzero(buffer,sizeof(buffer));
    sprintf(buffer,"Desconexión del cliente: %d\n",socket);
    
    for(j=0; j<(*numClientes); j++)
        if(arrayClientes[j] != socket)
            send(arrayClientes[j],buffer,strlen(buffer),0);


}


void manejador (int signum){
    printf("\nSe ha recibido la señal sigint\n");
    signal(SIGINT,manejador);
    exit(1);
    //Implementar lo que se desee realizar cuando ocurra la excepción de ctrl+c en el servidor
}
