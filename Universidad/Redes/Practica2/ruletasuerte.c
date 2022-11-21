#include "ruletasuerte.h"
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

//Inicializar valores globales
void IniciarJuego(){
	for(int i=0; i<30; i++){
		listajugadores[i].estado=NO_CONECTADO;
		listajugadores[i].puntos=0;
		bzero(listajugadores[i].usuario,50);
		bzero(listajugadores[i].password,50);
	}
	for(int i=0; i<10; i++){
		partidas[i].estado=VACIA;
	}
}

//Buscar usuarios en el registro
int BuscarUsuario(char * Nombre){
	FILE *f=NULL;
	f=fopen("usuarios.txt","r");
	if(f==NULL){
		printf("-ERR. No se ha podido abrir la base de datos.\n");
		return 0;
	}
	Jugador j;
	while(fscanf(f,"%s %s\n",j.usuario,j.password)==2){		
		if(!strcmp(j.usuario,Nombre)){
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}

//Registro de un jugador
int RegistrarJugador(Jugador j){
	FILE * f = NULL;
	f=fopen("usuarios.txt","a");
	if(f==NULL){
		printf("-ERR. No se ha podido abrir la lista de usuarios registrados.\n");
		return 0;
	}
	fprintf(f, "%s %s\n",j.usuario,j.password);
	fclose(f);
	return 1;
}

//Obtener variables de los registros(Nombre y Password)
Jugador PedirCampos(char * buffer){
	Jugador j;
	bzero(j.usuario,50);
	bzero(j.password,50);
	int pos_u, pos_p, pos_n, pos_c;
	for(int i=0;i<strlen(buffer)-1; i++){
		if(buffer[i]=='-' && buffer[i+1]=='u'){
			pos_u = i+3;
		}
		if(buffer[i]=='-' && buffer[i+1]=='p'){
			pos_p = i+3;
		}
	}
	memcpy(j.usuario, buffer+pos_u, pos_p-4-pos_u);
	memcpy(j.password,buffer+pos_p,strlen(buffer));
	printf("+Ok. Se ha registrado el usuario %s con la contraseña %s\n",j.usuario,j.password);
	return j;
}

//Enviar mensaje a los usuarios
void EnviarMensaje(int socket, char *buffer){
	send(socket,buffer,strlen(buffer),0);
}

//Comprobar password
int ComprobarPassword(char * Nombre, char * passwd){
	FILE * f=NULL;
	f=fopen("usuarios.txt","r");
	if(f==NULL){
		printf("-Err. No se ha podido abrir la lista de usuarios registradosº.\n");
		return 0;
	}
	Jugador j;
	while(fscanf(f,"%s %s\n",j.usuario,j.password) == 2){
		if(strcmp(j.usuario,Nombre)==0 && strcmp(j.password,passwd)==0){
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}

//Iniciar partida entre dos jugadores
int IniciarPartida(int jugador){
	//Generar numero aleatorio para elegir un refran al azar
	srand(time(NULL));
	int numero=rand()%4;
	//Listado de refranes
	char listado[10][CHAR_SIZE]={ 
		"EN PRIMAVERA, LA SANGRE CORRE LIGERA",
		"AGUA POR SAN JUAN QUITA VINO Y NO DA PAN",
		"HORMIGA Y",
		"AGUA DE MAYO, EL BIEN DESEADO",
		"DE TAL PALO, TAL ASTILLA",
		"NO ES ORO TODO LO QUE RELUCE",
		"DINERO LLAMA DINERO",
		"A LA TERCERA VA LA VENCIDA",
		"AL QUE MADRUGA, DIOS LE AYUDA",
		"EL HABITO NO HACE EL MONJE"
	};
	char panel [CHAR_SIZE];
	strcpy(panel, listado[2]);
	char oculto[CHAR_SIZE];
	int i;
	//Creamos un variable para la adivinanza
	strcpy(oculto, panel);
	for(i=0; listado[2][i]!='\0'; i++){
		/*if(panel[i]!=' ' && panel[i]!=','){
			oculto[i]='_';
		}*/
		if(panel[i]==' '){
            oculto[i]=' ';
        }
        else if(panel[i]==','){
            oculto[i]=',';
        }
        else{
            oculto[i]='_';

        }
	}
	oculto[i]='\0';
	//Los jugadores que buscan partida son emparejados
	for(int i=0; i<30; i++){
		if(listajugadores[i].estado==ESPERA && i!=jugador){
			for(int j=0; j<10; j++){
				if(partidas[j].estado==VACIA){
					listajugadores[i].estado=JUGANDO;
					listajugadores[i].mesa=j;
					char mensaje[250];
					sprintf(mensaje,"+OK. Empieza la partida. FRASE: %s\nQuien adivine el refran es el ganador. ¡Suerte jugadores!", oculto);
					EnviarMensaje(i,mensaje);
					EnviarMensaje(jugador,mensaje);
					listajugadores[jugador].estado=JUGANDO;
					listajugadores[jugador].mesa=j;
					partidas[j].estado=EMPEZADA;
					partidas[j].jugador1=i;
					partidas[j].jugador2=jugador;
					strcpy(partidas[j].panel, panel);
					strcpy(partidas[j].resolver, oculto);
					return 1;
				}
			}
			return -1;
		}
	}
	return 0;
}

//Cambio de turno entre jugadores
void CambiarTurno(int mesa){
	if(partidas[mesa].turno==partidas[mesa].jugador1){
		partidas[mesa].turno=partidas[mesa].jugador2;
		listajugadores[partidas[mesa].jugador1].estado=ESPERATURNO;
		listajugadores[partidas[mesa].jugador2].estado=JUGANDO;
	}
	else{
		partidas[mesa].turno=partidas[mesa].jugador1;
		listajugadores[partidas[mesa].jugador1].estado=JUGANDO;
		listajugadores[partidas[mesa].jugador2].estado=ESPERATURNO;
	}
}

//Mensaje del cambio de turno
void MensajeTurno(int mesa){
	if(partidas[mesa].turno==partidas[mesa].jugador1){
		EnviarMensaje(partidas[mesa].jugador1,"\n+Ok. Turno de partida.");
		EnviarMensaje(partidas[mesa].jugador2,"\n+Ok. Turno del otro jugador.");
	}
	else{
		EnviarMensaje(partidas[mesa].jugador2,"\n+Ok. Turno de partida.");
		EnviarMensaje(partidas[mesa].jugador1,"\n+Ok. Turno del otro jugador.");
	}
}

//Escribir en archivos datos de usuario
void EscribirDatosUsuario(int socket){
	FILE * f=NULL;
	f=fopen("usuarios.txt","r");
	if(f==NULL){
		printf("-Err. No se ha podido abrir la base de datos.\n");
		return;
	}
	Jugador j;
	while(fscanf(f,"%s %s\n",j.usuario,j.password)==2){
		if(!strcmp(listajugadores[socket].usuario,j.usuario)){
			fclose(f);
			return;
		}
	}
	fclose(f);
	return;
}

//Comprobar que una letra es correcta
void DescubrirLetra(Partida p, char aux[50], int jugador){
	contador=0;
	char c=aux[0];
	for(int i=0; i<10; i++){
		if(partidas[i].jugador2==p.jugador2){
			for(int j=0; j<CHAR_SIZE; j++){
				if(partidas[i].panel[j]==c){
					if(EsVocal(c)&&listajugadores[jugador].puntos>=50){
						partidas[i].resolver[j]=c;
						contador++;
					}
					else if(EsConsonante(c)){
						partidas[i].resolver[j]=c;
						contador++;
					}
				}
			}
		}
	}
}

//Cambiar puntuacion de los jugadores 
int CambiarPuntuacion(Partida p, char letra, int jugador){
	for(int i=0; i<10; i++){			
		if(partidas[i].jugador2==p.jugador2){
			if(EsConsonante(letra)==1){
				listajugadores[jugador].puntos+=(50*contador);
				return 0;
			}
			if(EsVocal(letra)==1){
				if(listajugadores[jugador].puntos>=50){
					listajugadores[jugador].puntos-=50;
					return 0;
				}
				else{
					EnviarMensaje(jugador, "\n+Ok. No tienes puntuación suficiente");
					return 1;
				}
			}
		}
	}
}

//Busqueda de la partida para realizar cambios
Partida BuscarPartida(int jugador){
	Partida p;
	for(int i=0; i<10; i++){
		if(partidas[i].jugador1==jugador || partidas[i].jugador2==jugador){
			 p.turno=partidas[i].turno;
			 p.jugador1=partidas[i].jugador1;
			 p.jugador2=partidas[i].jugador2;
			 p.estado=partidas[i].estado;
			 strcpy(p.panel, partidas[i].panel);
			 strcpy(p.resolver, partidas[i].resolver);
		}
	}
	return p;
}

//Comprobar Vocal
int EsVocal(char letra){
    char vocales[]="aeiouAEIOU";
    for(int i=0; vocales[i];i++){
        if(letra==vocales[i]){
            return 1;
        }
    }
    return 0;
}

//Comprobar Consonante
int EsConsonante(char letra){
    return isalpha(letra)&&!EsVocal(letra);
}

//Comienza el jugador 1
void EmpiezaJugador1(int mesa){
	listajugadores[partidas[mesa].jugador2].estado=ESPERATURNO;
    partidas[mesa].turno=partidas[mesa].jugador1;
}

//Comprobar el turno de un jugador
int EsTurno(int jugador){
    if(listajugadores[jugador].estado==JUGANDO){
		return 0;
	}
	else{
		return 1;
	}
}

//Resolver refran
int Resolver(Partida p, char aux[50], int jugador){
	char ganador[250];
    for(int i=0; i<10; i++){
        if(partidas[i].jugador2==p.jugador2){
            if(strcmp(partidas[i].panel,aux)==0){
				sprintf(ganador, "+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n", partidas[i].panel, listajugadores[jugador].usuario, listajugadores[jugador].puntos);
				EnviarMensaje(partidas[i].jugador1, ganador);
				EnviarMensaje(partidas[i].jugador2, ganador);
				return 0;      
            }
        }
    }
	return 1;
}

//Comprobar que todas las letras se han adivinado y devolver el ganador por puntos
int FinPartida(Partida p, int jugador){
	char finpartida[250];
    for(int i=0; i<10; i++){
        if(partidas[i].jugador2==p.jugador2){
            if(strcmp(partidas[i].panel,partidas[i].resolver)==0){
				sprintf(finpartida, "+Ok. Partida finalizada. FRASE: %s. Ha ganado el jugador %s con %d puntos.\n", partidas[i].panel, listajugadores[jugador].usuario, listajugadores[jugador].puntos);
				EnviarMensaje(partidas[i].jugador1, finpartida);
				EnviarMensaje(partidas[i].jugador2, finpartida);
				return 0;     
            }
        }
    }
	return 1;
}