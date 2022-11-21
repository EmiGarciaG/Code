#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <ctype.h>
#include "ruletasuerte.h"

#define MSG_SIZE 250
#define MAX_CLIENTS 30

/*
 * El servidor lee y muestra por pantalla la cadena que le manda el cliente hasta que recibe FIN.
 */
void salirCliente(int socket, fd_set * readfds, int * numClientes, int arrayClientes[]){
    char buffer[250];
    int j; 
    close(socket);
    FD_CLR(socket,readfds);    
    //Re-estructur        ar el array de clientes
    for(j=0; j<(*numClientes)-1; j++){
        if(arrayClientes[j]==socket){
            break;
        }
    }
    for(; j<(*numClientes)-1; j++){
        (arrayClientes[j] = arrayClientes[j+1]);    
    }
    (*numClientes)--;   
    bzero(buffer,sizeof(buffer));
    sprintf(buffer,"Desconexión del cliente: %d\n",socket);    
    for(j=0; j<(*numClientes); j++){
        if(arrayClientes[j]!=socket){
            send(arrayClientes[j],buffer,sizeof(buffer),0);
        }
    }
}
void manejador(int signum){
    printf("Se ha recibido la señal sigint\n");
    signal(SIGINT,manejador);    
    //Implementar lo que se desee realizar cuando ocurra la excepción de ctrl+c en el servidor
}

int main(){
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
   	int numClientes=0;
	//Contadores
    int i,j,k;
	int recibidos;
    int on, ret;
    /*---------------------------------------------------
        Variables del juego de la ruleta de la suerte
    ----------------------------------------------------*/
    Jugador player;
    char aux[50];
    char aux2[50];
    int buscarMesa;
    char mensaje[MSG_SIZE];
    /* --------------------------------------------------
        INICIALIZO EL JUEGO DEL DOMINO
    ---------------------------------------------------*/
        IniciarJuego();
	/* --------------------------------------------------
		Se abre el socket 
	---------------------------------------------------*/
  	sd=socket (AF_INET, SOCK_STREAM, 0);
	if(sd==-1){
		perror("No se puede abrir el socket cliente\n");
    		exit (1);	
	}
	/*Activaremos una propiedad del socket para permitir· que otros
	sockets puedan reutilizar cualquier puerto al que nos enlacemos.
	Esto permite· en protocolos como el TCP, poder ejecutar un
	mismo programa varias veces seguidas y enlazarlo siempre al
	mismo puerto. De lo contrario habrÌa que esperar a que el puerto
	quedase disponible (TIME_WAIT en el caso de TCP)
	*/
	on=1;
    ret=setsockopt( sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	sockname.sin_family=AF_INET;
	sockname.sin_port=htons(2050);
	sockname.sin_addr.s_addr=INADDR_ANY;
	if(bind(sd, (struct sockaddr *) &sockname, sizeof (sockname))==-1){
		perror("Error en la operación bind");
		exit(1);
	}
   	/*---------------------------------------------------------------------
		Del las peticiones que vamos a aceptar sólo necesitamos el 
		tamaño de su estructura, el resto de información (familia, puerto, 
		ip), nos la proporcionará el método que recibe las peticiones.
   	----------------------------------------------------------------------*/
	from_len=sizeof (from);
	if(listen(sd,1)==-1){
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
            auxfds=readfds;            
            salida=select(FD_SETSIZE,&auxfds,NULL,NULL,NULL);            
            if(salida>0){                              
                for(i=0; i<FD_SETSIZE; i++){
                    //Buscamos el socket por el que se ha establecido la comunicación
                    if(FD_ISSET(i, &auxfds)) {   
                        if(i==sd){
                            if((new_sd=accept(sd, (struct sockaddr *)&from, &from_len))==-1){
								perror("Error aceptando peticiones");
							}
                            else{
                                if(numClientes<MAX_CLIENTS){
                                    arrayClientes[numClientes] = new_sd;
                                    numClientes++;
                                    FD_SET(new_sd,&readfds);
                                    printf("+OK. Usuario conectado.\n");
                                    strcpy(buffer, "Bienvenido a la ruleta de la suerte\n");
                                    send(new_sd,buffer,sizeof(buffer),0);
                                    strcpy(buffer, "Inicie sesion para buscar y empezar una partida, utilizando los comandos: \n USUARIO 'Nombre del usuario' \n PASSWORD 'Password del usuario'\n Sino esta registrado, hagalo con el comando REGISTRO -u 'Nombre del usuario' -p 'Password del usuario'.\n");
                                    send(new_sd,buffer,sizeof(buffer),0);
                                }
                                else{
                                    bzero(buffer,sizeof(buffer));
                                    strcpy(buffer,"-Err. Demasiados clientes conectados\n");
                                    send(new_sd,buffer,sizeof(buffer),0);
                                    close(new_sd);
                                }                        
                            } 
                        }
                        else if(i==0){
                            //Se ha introducido información de teclado
                            bzero(buffer, sizeof(buffer));
                            fgets(buffer, sizeof(buffer),stdin);                      
                            //Controlar si se ha introducido "SALIR", cerrando todos los sockets y finalmente saliendo del servidor. (implementar)
                            if(strcmp(buffer,"SALIR\n") == 0){
                                for(j=0; j<numClientes; j++){
						            bzero(buffer, sizeof(buffer));
						            strcpy(buffer,"-Err. Desconexión servidor\n"); 
                                    send(arrayClientes[j],buffer , sizeof(buffer),0);
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
                            recibidos=recv(i,buffer,sizeof(buffer),0);
                            if(recibidos>0){                                
                                if(strcmp(buffer,"SALIR\n")==0){    
                                    printf("+Ok. %s ha salido de la sesion.\n",listajugadores[i].usuario);
                                    Partida partida=BuscarPartida(i);
                                    if(partidas[listajugadores[i].mesa].estado=EMPEZADA){
                                        partidas[listajugadores[i].mesa].estado=VACIA;
                                        if(i==partidas[listajugadores[i].mesa].jugador1){
                                            EnviarMensaje(partidas[listajugadores[i].mesa].jugador2, "+Ok. Ha salido el otro jugador. Finaliza la partida.");
                                            listajugadores[partidas[listajugadores[i].mesa].jugador1].estado=LOGUEADO;
                                        }
                                        if(i==partidas[listajugadores[i].mesa].jugador2){
                                            EnviarMensaje(partidas[listajugadores[i].mesa].jugador1, "+Ok. Ha salido el otro jugador. Finaliza la partida.");
                                            listajugadores[partidas[listajugadores[i].mesa].jugador2].estado=LOGUEADO;
                                        }
                                    }  
                                    salirCliente(i,&readfds,&numClientes,arrayClientes);                                    
                                }
                                else{
                                    buffer[strlen(buffer)-1]='\0';
                                    /* --------------------------------------------------
                                        Cliente se registra con el comando REGISTRO
                                    ---------------------------------------------------*/
                                    if(!strncmp(buffer,"REGISTRO",8)){
                                        player=PedirCampos(buffer);
                                        if(!BuscarUsuario(player.usuario)){
                                            if(RegistrarJugador(player)){
                                                EnviarMensaje(i,"+OK. Usuario registrado correctamente.");
                                            }
                                            else{
                                             EnviarMensaje(i,"-Err. Error al registrarse, intentelo de nuevo.");   
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i,"-Err. Usuario ya registrado.");
                                        }
                                        EnviarMensaje(i,"¿Que desea realizar?.");
                                    }
                                    /* --------------------------------------------------
                                        Cliente inicia sesion con el comando USUARIO 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"USUARIO",7)){
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        if(BuscarUsuario(aux2)){
                                            EnviarMensaje(i,"+Ok. Usuario correcto.");
                                            listajugadores[i].estado=LOGIN;
                                            strcpy(listajugadores[i].usuario,aux2);
                                        }
                                        else{
                                            EnviarMensaje(i,"-Err. Usuario incorrecto.");
                                        }
                                        EnviarMensaje(i,"¿Que desea realizar?.");
                                    }
                                    /* ---------------------------------------------------------
                                        Cliente continua inicio sesion con el comando PASSWORD
                                    ----------------------------------------------------------*/
                                    else if(!strncmp(buffer,"PASSWORD",7)){
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        if(listajugadores[i].estado==LOGIN){
                                            if(ComprobarPassword(listajugadores[i].usuario,aux2)){
                                                EnviarMensaje(i,"+Ok. Usuario validado.");
                                                listajugadores[i].estado=LOGUEADO;
                                                EscribirDatosUsuario(i);
                                                printf("+Ok. %s ha iniciado sesion.\n",listajugadores[i].usuario);
                                            }
                                            else{
                                                EnviarMensaje(i,"-Err. Error en la validación.");
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i,"-Err. Utilice antes el comando USUARIO 'usuario'.");
                                        }
                                        EnviarMensaje(i,"¿Que desea realizar?.");                                   
                                    }
                                    /* ------------------------------------------------------------
                                        Cliente inicia la partida con el comando INICIAR-PARTIDA
                                    -------------------------------------------------------------*/
                                    else if(!strncmp(buffer,"INICIAR-PARTIDA",15)){
                                        if(listajugadores[i].estado==LOGUEADO){
                                            listajugadores[i].estado=ESPERA;
                                            buscarMesa=IniciarPartida(i);
                                            if(buscarMesa==-1){
                                                EnviarMensaje(i,"+Ok. Espere a que termine una partida.");
                                            }
                                            else if(buscarMesa==0){
                                                EnviarMensaje(i,"+Ok. Petición Recibida. Quedamos a la espera de más jugadores.");
                                                printf("+Ok. El jugador %s ha empezado una partida\n", listajugadores[i].usuario);
                                            }
                                            else{
                                                EmpiezaJugador1(listajugadores[i].mesa);
                                                printf("+Ok. El jugador %s ha empezado una partida con %s\n", listajugadores[i].usuario, listajugadores[partidas[listajugadores[i].mesa].jugador1].usuario);
                                                MensajeTurno(listajugadores[i].mesa);
                                                listajugadores[i].puntos=0;
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i,"-Err. Inicie sesion para comenzar una partida. Para ello introduzca los comandos: \n USUARIO 'Nombre del usuario' \n PASSWORD 'Password del usuario'\n Sino registrese con el comando REGISTRO -u 'Nombre del usuario' -p 'Password del usuario'.\n");
                                        }
                                    }
                                    /* --------------------------------------------------
                                        Cliente introduce una vocal con el comando VOCAL 
                                    ---------------------------------------------------*/
                                    else if(!strncmp(buffer,"VOCAL",5)){
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        char vocal=aux2[0];
                                        if(EsTurno(i)==0){
                                                if(EsVocal(vocal)==1){
                                                    Partida partida=BuscarPartida(i);
                                                    DescubrirLetra(partida, aux2, i);
                                                    partida=BuscarPartida(i);
                                                    EnviarMensaje(partida.jugador1, "REFRAN: ");
                                                    EnviarMensaje(partida.jugador1, partida.resolver);
                                                    EnviarMensaje(partida.jugador2, "REFRAN: ");
                                                    EnviarMensaje(partida.jugador2, partida.resolver);                                      
                                                    if(CambiarPuntuacion(partida, vocal, i)==0){
                                                        sprintf(mensaje, "\n+Ok. %c aparece %d veces.", vocal, contador);
                                                        EnviarMensaje(i, mensaje);
                                                    }
                                                    if(FinPartida(partida, i)==0){
                                                        EnviarMensaje(partida.jugador1, "+Ok. Partida acabada, desconectando del servidor\n");
                                                        EnviarMensaje(partida.jugador2, "+Ok. Partida acabada, desconectando del servidor\n");
                                                        listajugadores[partida.jugador1].estado=LOGUEADO;
                                                        listajugadores[partida.jugador2].estado=LOGUEADO;
                                                        partida.estado=VACIA;
                                                    }
                                                    else if(FinPartida(partida, i)==1){
                                                    CambiarTurno(listajugadores[i].mesa);
                                                    MensajeTurno(listajugadores[i].mesa); 
                                                    }
                                                }
                                            else{
                                                EnviarMensaje(i, "-Err. Eso no es una vocal");
                                                CambiarTurno(listajugadores[i].mesa);
                                                MensajeTurno(listajugadores[i].mesa); 
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i, "-Err. Debe esperar su turno");
                                        }
                                    }
                                    /* ------------------------------------------------------------
                                        Cliente introduce una consonante con el comando CONSONANTE 
                                    --------------------------------------------------------------*/
                                    else if(!strncmp(buffer,"CONSONANTE",10)){
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        char consonante=aux2[0];
                                        if(EsTurno(i)==0){
                                            if(EsConsonante(consonante)==1){
                                                Partida partida=BuscarPartida(i);
                                                DescubrirLetra(partida, aux2, i);
                                                partida=BuscarPartida(i);
                                                EnviarMensaje(partida.jugador1, "REFRAN: ");
                                                EnviarMensaje(partida.jugador1, partida.resolver);
                                                EnviarMensaje(partida.jugador2, "REFRAN: ");
                                                EnviarMensaje(partida.jugador2, partida.resolver);     
                                                if(CambiarPuntuacion(partida, consonante, i)==0){
                                                    sprintf(mensaje, "\n+Ok. %c aparece %d veces.", consonante, contador);
                                                    EnviarMensaje(i, mensaje);
                                                }
                                                if(FinPartida(partida, i)==0){
                                                    EnviarMensaje(partida.jugador1, "+Ok. Partida acabada, desconectando del servidor\n");
                                                    EnviarMensaje(partida.jugador2, "+Ok. Partida acabada, desconectando del servidor\n");
                                                    listajugadores[partida.jugador1].estado=LOGUEADO;
                                                    listajugadores[partida.jugador2].estado=LOGUEADO;
                                                    partida.estado=VACIA;
                                                }
                                                else if(FinPartida(partida, i)==1){
                                                    CambiarTurno(listajugadores[i].mesa);
                                                    MensajeTurno(listajugadores[i].mesa); 
                                                }
                                            }
                                            else{
                                                EnviarMensaje(i, "-Err. Eso no es una consonante");
                                                CambiarTurno(listajugadores[i].mesa);
                                                MensajeTurno(listajugadores[i].mesa); 
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i, "-Err. Debe esperar su turno");
                                        }
                                    }
                                    /* ------------------------------------------------------
                                        Cliente mira su puntuacion con el comando PUNTUACION 
                                    -------------------------------------------------------*/
                                    else if(!strncmp(buffer,"PUNTUACION",10)){
                                        sscanf(buffer,"%s",aux);
                                        sprintf(mensaje,"PUNTUACION: %i.", listajugadores[i].puntos);
                                        EnviarMensaje(i, mensaje);
                                    }
                                    /* ------------------------------------------------------
                                        Cliente resuelve la frase con el comando RESOLVER 
                                    -------------------------------------------------------*/
                                    else if(!strncmp(buffer,"RESOLVER", 8)){
                                        sscanf(buffer,"%s %s",aux,aux2);
                                        if(EsTurno(i)==0){
                                            Partida partida=BuscarPartida(i);
                                            partida=BuscarPartida(i);
                                            if(Resolver(partida, aux2, i)==1){
                                                sprintf(buffer, "+Ok. Partida finalizada %s. No se ha acertado la frase.", partida.panel);
                                                EnviarMensaje(partida.jugador1, buffer);
                                                EnviarMensaje(partida.jugador2, buffer);
                                                listajugadores[partida.jugador1].estado=LOGUEADO;
                                                listajugadores[partida.jugador2].estado=LOGUEADO;
                                                partida.estado=VACIA;
                                            }
                                            else if(Resolver(partida, aux2, i)==0){
                                                EnviarMensaje(partida.jugador1, "+Ok. Partida acabada, desconectando del servidor\n");
                                                EnviarMensaje(partida.jugador2, "+Ok. Partida acabada, desconectando del servidor\n");
                                                listajugadores[partida.jugador1].estado=LOGUEADO;
                                                listajugadores[partida.jugador2].estado=LOGUEADO;
                                                partida.estado=VACIA;
                                            }
                                        }
                                        else{
                                            EnviarMensaje(i, "-Err. Debe esperar su turno");
                                        }
                                    }
                                }                                                                                            
                            }
                            //Señal Ctrl+C
                            if(recibidos==0){
                                printf("+Ok. El socket %d, ha introducido ctrl+c\n", i);
                                //Eliminar socket
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
