#include "domino.h"
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

//FUNCION PARA ENVIAR UN MENSAJE A UN SOCKET 
void enviarMensaje(int socket, char * buffer)
{
	send(socket,buffer,strlen(buffer),0);
}

//FUNCION PARA INICIALZAR LOS DOS VECTORES GLOBALES DEL JUEGO
void inicializarJuego()
{
	for(int i=0; i<40; i++)
	{
		jugadores[i].estado = NO_CONECTADO;
		jugadores[i].puntos = 0;
		bzero(jugadores[i].nombreUsuario,50);
		bzero(jugadores[i].contrasena,50);
		bzero(jugadores[i].nombreCompleto,100);
		bzero(jugadores[i].ciudad,50);

		for(int j = 0; j< 28; j++)
		{
			jugadores[i].fichas[j].estado = INACTIVA;
		}
	}

	for(int i=0; i<10; i++)
	{
		partidas[i].estado = INACTIVA;
	}
}

//COMPRUEBO SI EXISTE UN NOMBRE DE USUARIO EN LA BD
int buscarUsuarioBD(char * nombreUsuario)
{
	FILE * fich = NULL;

	fich = fopen("bd.txt","r");

	if(fich == NULL)
	{
		printf("-ERR. No se ha podido abrir la base de datos.\n");
		return 0;
	}

	Jugador j;

	while (fscanf(fich,"%s %s\n",j.nombreUsuario,j.contrasena) == 2)
	{
		fgets(j.nombreCompleto,100,fich);
		fgets(j.ciudad,50,fich);

		if(!strcmp(j.nombreUsuario,nombreUsuario))
		{
			fclose(fich);
			return 1;
		}
	}

	fclose(fich);
	return 0;
}

//FUNCION PARA REGISTRAR EN LA BD UN JUGADOR
int registrarJugadorBD(Jugador j)
{
	FILE * fich = NULL;

	fich = fopen("bd.txt","a");

	if(fich == NULL)
	{
		printf("-ERR. No se ha podido abrir la base de datos.\n");
		return 0;
	}

	fprintf(fich, "%s %s\n%s\n%s\n",j.nombreUsuario,j.contrasena,j.nombreCompleto,j.ciudad );

	fclose(fich);
	return 1;
}

//OBTENGO LOS CAMPOS USERNAME, PASS, NOMBRE USUARIO Y CIUDAD DEL MENSAJE DEL CLIENTE
Jugador obtenerCamposRegister(char * buffer)
{
	Jugador j;

	bzero(j.nombreUsuario,50);
	bzero(j.contrasena,50);
	bzero(j.nombreCompleto,100);
	bzero(j.ciudad,50);

	int pos_u, pos_p, pos_n, pos_c;

	for(int i=0;i<strlen(buffer)-1; i++)
	{
		if(buffer[i]=='-' && buffer[i+1]=='u')
			pos_u = i+3;

		if(buffer[i]=='-' && buffer[i+1]=='p')
			pos_p = i+3;

		if(buffer[i]=='-' && buffer[i+1]=='n')
			pos_n = i+3;

		if(buffer[i]=='-' && buffer[i+1]=='c')
			pos_c = i+3;
	}

	memcpy(j.nombreUsuario, buffer+pos_u, pos_p-4-pos_u);
	memcpy(j.contrasena,buffer+pos_p, pos_n-4-pos_p);
	memcpy(j.nombreCompleto, buffer+pos_n, pos_c-4-pos_n);
	memcpy(j.ciudad, buffer+pos_c,strlen(buffer));

	return j;
}

//COMPRUEBO SI LA CONTRASEÑA DE UN USUARIO ES CORRECTA
int comprobarContrasenaBD(char * nombreUsuario, char * contrasena)
{
	FILE * fich = NULL;

	fich = fopen("bd.txt","r");

	if(fich == NULL)
	{
		printf("-ERR. No se ha podido abrir la base de datos.\n");
		return 0;
	}

	Jugador j;

	while (fscanf(fich,"%s %s\n",j.nombreUsuario,j.contrasena) == 2)
	{
		fgets(j.nombreCompleto,100,fich);
		fgets(j.ciudad,50,fich);

		if(strcmp(j.nombreUsuario,nombreUsuario)==0 && strcmp(j.contrasena,contrasena)== 0)
		{
			fclose(fich);
			return 1;
		}
	}

	fclose(fich);
	return 0;
}

//VUELVO LOS DATOS NOMBRE USUARIO Y CIUDAD A MEMORIA
void volcarDatosUsuarioMemoria(int socket)
{
	FILE * fich = NULL;

	fich = fopen("bd.txt","r");

	if(fich == NULL)
	{
		printf("-ERR. No se ha podido abrir la base de datos.\n");
		return;
	}

	Jugador j;

	while (fscanf(fich,"%s %s\n",j.nombreUsuario,j.contrasena) == 2)
	{
		fgets(j.nombreCompleto,100,fich);
		j.nombreCompleto[strlen(j.nombreCompleto)-1] = '\0';
		fgets(j.ciudad,50,fich);
		j.ciudad[strlen(j.ciudad)-1] = '\0';

		if(!strcmp(jugadores[socket].nombreUsuario,j.nombreUsuario))
		{
			strcpy(jugadores[socket].nombreCompleto,j.nombreCompleto);
			strcpy(jugadores[socket].ciudad,j.ciudad);
			fclose(fich);
			return;
		}
	}

	fclose(fich);
	return;
}

//COMPRUEBO SI HAY DOS JUGADORES PARA INICIAR LA PARTIDA
int iniciarPartida(int jugador2)
{
	for(int i=0; i<40; i++)
	{
		if(jugadores[i].estado == ESPERA && i!=jugador2)
		{
			//Busco mesa para sentar a i y a jugador2
			for(int j=0; j<10; j++)
			{
				if(partidas[j].estado == INACTIVA)
				{
					//Cambio estado del jugador 1 y guardo la mesa en la que va a jugar
					jugadores[i].estado = JUGANDO;
					jugadores[i].mesa = j;
					char mensaje[250];
					sprintf(mensaje,"+OK. Comienza a jugar en la mesa %d.",j);
					enviarMensaje(i,mensaje);

					//Cambio estado del jugador 2 y guardo la mesa en la que va a jugar
					jugadores[jugador2].estado = JUGANDO;
					jugadores[jugador2].mesa = j;

					//Cambio el estado de la mesa y guardo los socket de los jugadores que juegan en ella
					partidas[j].estado = ACTIVA;
					partidas[j].jugador1 = i;
					partidas[j].jugador2 = jugador2;

					return 1;
				}
			}
			return -1;
		}
	}
	return 0;
}

//REPARTO FICHAS DEL MONTON A LOS DOS JUGADORES DE UNA MESA
void repartirFichas(int mesa)
{
	Ficha f;
	f.estado = ACTIVA;
	int c = 0;
	int pos;

	srand(time(NULL));

	for(int i=0; i<7; i++)
	{
		f.n1 = i;
		for(int j=i; j<7; j++)
		{
			f.n2 = j;
			partidas[mesa].monton[c] = f;
			c++;
		}
	}

	//
	for(int i=0; i<7; i++)
	{
		do{
			pos = rand()%28;
		}while( partidas[mesa].monton[pos].estado != ACTIVA );

		for(int j=0; j<28; j++)
		{
			if(jugadores[partidas[mesa].jugador1].fichas[j].estado == INACTIVA)
			{
				jugadores[partidas[mesa].jugador1].fichas[j] = partidas[mesa].monton[pos];
				//printf("|%d|%d| al jugador %d\n",partidas[mesa].monton[pos].n1,partidas[mesa].monton[pos].n2,partidas[mesa].jugador1);
				partidas[mesa].monton[pos].estado = INACTIVA;
				break;
			}
		}

		do{
			pos = rand()%28;
		}while( partidas[mesa].monton[pos].estado != ACTIVA );

		for(int j=0; j<28; j++)
		{
			if(jugadores[partidas[mesa].jugador2].fichas[j].estado == INACTIVA)
			{
				jugadores[partidas[mesa].jugador2].fichas[j] = partidas[mesa].monton[pos];
				//printf("|%d|%d| al jugador %d\n",partidas[mesa].monton[pos].n1,partidas[mesa].monton[pos].n2,partidas[mesa].jugador2);
				partidas[mesa].monton[pos].estado = INACTIVA;
				break;
			}
		}
	}

	

}

//CUANDO EMPIEZA UNA PARTIDA, BUSCO QUIEN EMPIEZA Y MUESTRO TABLERO Y FICHAS DE CADA JUGADOR
void enviarFichasJugador(int mesa) 
{
	

	//Buscar quien empieza
	int encontrado = 0;

	for(int j=6; j>=0 && encontrado==0; j--)
	{
		for(int i=0; i<28 && encontrado==0; i++)
		{
			if(jugadores[partidas[mesa].jugador1].fichas[i].estado == ACTIVA && jugadores[partidas[mesa].jugador1].fichas[i].n1 == j && jugadores[partidas[mesa].jugador1].fichas[i].n2 == j)
			{
				partidas[mesa].turno = partidas[mesa].jugador2;
				partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador1].fichas[i];
				jugadores[partidas[mesa].jugador1].fichas[i].estado = INACTIVA;
				enviarMensaje(partidas[mesa].jugador1,"+OK. Turno del otro jugador.");
				enviarMensaje(partidas[mesa].jugador2,"+OK. Turno de partida.");
				encontrado = 1;
			}
			else if(jugadores[partidas[mesa].jugador2].fichas[i].estado == ACTIVA && jugadores[partidas[mesa].jugador2].fichas[i].n1 == j && jugadores[partidas[mesa].jugador2].fichas[i].n2 == j)
			{
				partidas[mesa].turno = partidas[mesa].jugador1;
				partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador2].fichas[i];
				jugadores[partidas[mesa].jugador2].fichas[i].estado = INACTIVA;
				enviarMensaje(partidas[mesa].jugador2,"+OK. Turno del otro jugador.");
				enviarMensaje(partidas[mesa].jugador1,"+OK. Turno de partida.");
				encontrado = 1;
			}
		}
	}

	//sino hay doble, busco la más alta
	if(encontrado == 0)
	{
		for(int i=6; i>=0 && encontrado==0; i--)
		{
			for(int j=i; j>=0 && encontrado==0; j--)
			{
				for(int k=0; k<28 && encontrado==0; k++)
				{
					if(jugadores[partidas[mesa].jugador1].fichas[k].estado == ACTIVA && jugadores[partidas[mesa].jugador1].fichas[k].n1 == j && jugadores[partidas[mesa].jugador1].fichas[k].n2 == i)
					{
						partidas[mesa].turno = partidas[mesa].jugador2;
						partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador1].fichas[k];
						jugadores[partidas[mesa].jugador1].fichas[k].estado = INACTIVA;
						enviarMensaje(partidas[mesa].jugador1,"+OK. Turno del otro jugador.");
						enviarMensaje(partidas[mesa].jugador2,"+OK. Turno de partida.");
						encontrado = 1;
					}
					else if(jugadores[partidas[mesa].jugador1].fichas[k].estado == ACTIVA && jugadores[partidas[mesa].jugador1].fichas[k].n1 == i && jugadores[partidas[mesa].jugador1].fichas[k].n2 == j)
					{
						partidas[mesa].turno = partidas[mesa].jugador2;
						partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador1].fichas[k];
						jugadores[partidas[mesa].jugador1].fichas[k].estado = INACTIVA;
						enviarMensaje(partidas[mesa].jugador1,"+OK. Turno del otro jugador.");
						enviarMensaje(partidas[mesa].jugador2,"+OK. Turno de partida.");
						encontrado = 1;
					}
					else if(jugadores[partidas[mesa].jugador2].fichas[k].estado == ACTIVA && jugadores[partidas[mesa].jugador2].fichas[k].n1 == j && jugadores[partidas[mesa].jugador2].fichas[k].n2 == i)
					{
						partidas[mesa].turno = partidas[mesa].jugador1;
						partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador2].fichas[k];
						jugadores[partidas[mesa].jugador2].fichas[k].estado = INACTIVA;
						enviarMensaje(partidas[mesa].jugador2,"+OK. Turno del otro jugador.");
						enviarMensaje(partidas[mesa].jugador1,"+OK. Turno de partida.");
						encontrado = 1;
					}
					else if(jugadores[partidas[mesa].jugador2].fichas[k].estado == ACTIVA && jugadores[partidas[mesa].jugador2].fichas[k].n1 == i && jugadores[partidas[mesa].jugador2].fichas[k].n2 == j)
					{
						partidas[mesa].turno = partidas[mesa].jugador1;
						partidas [mesa].fichas_puestas[0] = jugadores[partidas[mesa].jugador2].fichas[k];
						jugadores[partidas[mesa].jugador2].fichas[k].estado = INACTIVA;
						enviarMensaje(partidas[mesa].jugador2,"+OK. Turno del otro jugador.");
						enviarMensaje(partidas[mesa].jugador1,"+OK. Turno de partida.");
						encontrado = 1;
					}
				}
			}
		}
	}

	//Muestro fichas en ambos jugadores
	char mensaje[255];

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(partidas[mesa].fichas_puestas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,partidas[mesa].fichas_puestas[i].n1,partidas[mesa].fichas_puestas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}

	enviarMensaje(partidas[mesa].jugador1,"\nTABLERO:");
	enviarMensaje(partidas[mesa].jugador1,mensaje);
	enviarMensaje(partidas[mesa].jugador2,"\nTABLERO:");
	enviarMensaje(partidas[mesa].jugador2,mensaje);

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(jugadores[partidas[mesa].jugador1].fichas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,jugadores[partidas[mesa].jugador1].fichas[i].n1,jugadores[partidas[mesa].jugador1].fichas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}
	
	enviarMensaje(partidas[mesa].jugador1,"\nTUS FICHAS:");
	enviarMensaje(partidas[mesa].jugador1,mensaje);

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(jugadores[partidas[mesa].jugador2].fichas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,jugadores[partidas[mesa].jugador2].fichas[i].n1,jugadores[partidas[mesa].jugador2].fichas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}
	
	enviarMensaje(partidas[mesa].jugador2,"\nTUS FICHAS:");
	enviarMensaje(partidas[mesa].jugador2,mensaje);
	

}

void insertarIzquierda(int mesa,Ficha f)
{
	for(int i=27; i>0; i--)
	{
		partidas[mesa].fichas_puestas[i] = partidas[mesa].fichas_puestas[i-1];
	}
	partidas[mesa].fichas_puestas[0] = f;
	
}

void insertarDerecha(int mesa,Ficha f)
{
	
	int i;
	for(i=0; i<28;i++)
	{
		if(partidas[mesa].fichas_puestas[i].estado == INACTIVA)
			break;
	}

	partidas[mesa].fichas_puestas[i] = f;
	printf("Puesta en posicion %d\n",i );

}

void quitarFichaJugador(int jugador,Ficha f)
{
	printf("quitando |%d|%d|\n", f.n1,f.n2);
	for(int i=0; i<28; i++)
	{
		if(jugadores[jugador].fichas[i].estado == ACTIVA)
		{
			if( jugadores[jugador].fichas[i].n1 == f.n1)
			{
				if(jugadores[jugador].fichas[i].n2 == f.n2 )
				{
					printf("%d == %d\t%d==%d\t%d==%d\n",jugadores[jugador].fichas[i].estado, ACTIVA, jugadores[jugador].fichas[i].n1, f.n1, jugadores[jugador].fichas[i].n2, f.n2 );
					jugadores[jugador].fichas[i].estado = INACTIVA;
					printf("Quitando ficha |%d|%d| y estado %d\n",jugadores[jugador].fichas[i].n1,jugadores[jugador].fichas[i].n2,jugadores[jugador].fichas[i].estado );
					return;
				}
			}
			else if(jugadores[jugador].fichas[i].n2 == f.n1)
			{
				if(jugadores[jugador].fichas[i].n1 == f.n2 )
				{
					printf("%d == %d\t%d==%d\t%d==%d\n",jugadores[jugador].fichas[i].estado, ACTIVA, jugadores[jugador].fichas[i].n1, f.n2 ,jugadores[jugador].fichas[i].n2, f.n1 );
					jugadores[jugador].fichas[i].estado = INACTIVA;
					printf("Quitando ficha |%d|%d| y estado %d\n",jugadores[jugador].fichas[i].n1,jugadores[jugador].fichas[i].n2,jugadores[jugador].fichas[i].estado );
					return;
				}
			}
		}
	}
}

int colocarFicha(int mesa,int jugador, char * buffer)
{
	char extremo[20];
	Ficha f;
	int aux;

	// |1|2|,izquierda
	f.n1 = (int)buffer[1]-48;
	f.n2 = (int)buffer[3]-48;
	f.estado = ACTIVA;
	memcpy(extremo,buffer+6,strlen(buffer));

	//Extremo izquierdo del tablero
	if(!strcmp(extremo,"izquierda"))
	{
		int extremo_izquierdo = partidas[mesa].fichas_puestas[0].n1;

		if(extremo_izquierdo == f.n1)
		{
			aux = f.n1;
			f.n1 = f.n2;
			f.n2 = aux;
			insertarIzquierda(mesa,f);
			quitarFichaJugador(jugador,f);
			printf("Gira -- |%d|%d| puesta por la %s por %s\n", f.n1,f.n2,extremo,jugadores[jugador].nombreUsuario);
			return 1;
		}
		else if(extremo_izquierdo == f.n2)
		{
			printf("insertando izquierda |%d|%d|\n", f.n1,f.n2);
			insertarIzquierda(mesa,f);
			printf("quitando |%d|%d|\n", f.n1,f.n2);
			quitarFichaJugador(jugador,f);
			printf("No gira -- |%d|%d| puesta por la %s por %s\n", f.n1,f.n2,extremo,jugadores[jugador].nombreUsuario);
			return 1;
		}

		return 0;
	}

	//Extremo derecho del tablero
	if(!strcmp(extremo,"derecha"))
	{
		int pos;
		for(int i=0; i<28; i++)
		{
			if(partidas[mesa].fichas_puestas[i].estado == INACTIVA)
			{
				pos = i-1;
				break;
			}
		}
		int extremo_derecho = partidas[mesa].fichas_puestas[pos].n2;

		if(extremo_derecho == f.n1)
		{
			insertarDerecha(mesa,f);
			quitarFichaJugador(jugador,f);
			printf("|%d|%d| puesta por la %s por %s\n", f.n1,f.n2,extremo,jugadores[jugador].nombreUsuario);
			return 1;
		}
		else if(extremo_derecho == f.n2)
		{
			aux = f.n1;
			f.n1 = f.n2;
			f.n2 = aux;
			insertarDerecha(mesa,f);
			quitarFichaJugador(jugador,f);
			printf("|%d|%d| puesta por la %s por %s\n", f.n1,f.n2,extremo,jugadores[jugador].nombreUsuario);
			return 1;
		}

		return 0;
	}

}

void cambiarTurno(int mesa)
{
	if(partidas[mesa].turno == partidas[mesa].jugador1)

		partidas[mesa].turno = partidas[mesa].jugador2;

	else

		partidas[mesa].turno = partidas[mesa].jugador1;
}

void enviarMensajePartida(int mesa)
{
	//Muestro fichas en ambos jugadores
	char mensaje[255];

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(partidas[mesa].fichas_puestas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,partidas[mesa].fichas_puestas[i].n1,partidas[mesa].fichas_puestas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}

	enviarMensaje(partidas[mesa].jugador1,"\nTABLERO:");
	enviarMensaje(partidas[mesa].jugador1,mensaje);
	enviarMensaje(partidas[mesa].jugador2,"\nTABLERO:");
	enviarMensaje(partidas[mesa].jugador2,mensaje);

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(jugadores[partidas[mesa].jugador1].fichas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,jugadores[partidas[mesa].jugador1].fichas[i].n1,jugadores[partidas[mesa].jugador1].fichas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}
	
	enviarMensaje(partidas[mesa].jugador1,"\nTUS FICHAS:");
	enviarMensaje(partidas[mesa].jugador1,mensaje);

	bzero(mensaje,255);
	mensaje[1] = '\0';

	for(int i=0; i<28; i++)
	{
		if(jugadores[partidas[mesa].jugador2].fichas[i].estado == ACTIVA)
		{
			sprintf(mensaje,"%s|%d|%d||",mensaje,jugadores[partidas[mesa].jugador2].fichas[i].n1,jugadores[partidas[mesa].jugador2].fichas[i].n2);
			mensaje[strlen(mensaje)-1] = '\0';
		}
	}
	
	enviarMensaje(partidas[mesa].jugador2,"\nTUS FICHAS:");
	enviarMensaje(partidas[mesa].jugador2,mensaje);
}

void mensajeTurno(int mesa)
{
	if(partidas[mesa].turno == partidas[mesa].jugador1)
	{
		enviarMensaje(partidas[mesa].jugador1,"\n+OK. Es tu turno.");
		enviarMensaje(partidas[mesa].jugador2,"\n+OK. Turno del otro jugador.");
	}
	else
	{
		enviarMensaje(partidas[mesa].jugador2,"\n+OK. Es tu turno.");
		enviarMensaje(partidas[mesa].jugador1,"\n+OK. Turno del otro jugador.");
	}
}

void robarFicha(int jugador)
{
	int mesa = jugadores[jugador].mesa;
	int pos;

	srand(time(NULL));

	//cuando no haya fichas en el monton o si ya tiene el jugador, salgo
	printf("Hay %d fichas en el monton\n",contarFichasMonton(mesa) );
	printf("El jugador (%d) tiene ficha para poner\n", tieneFicha(jugador));
	while(contarFichasMonton(mesa)!=0 && tieneFicha(jugador)==0) 
	{

		//selecciono una ficha random del monton
		do
		{
			pos = rand() % 28;

		}while(partidas[mesa].monton[pos].estado != ACTIVA);
		
		//se la pongo al jugador y la quito del monton
		for(int j=0; j<28; j++)
		{
			if(jugadores[jugador].fichas[j].estado == INACTIVA)
			{
				jugadores[jugador].fichas[j] = partidas[mesa].monton[pos];
				partidas[mesa].monton[pos].estado = INACTIVA;
				printf("El jugador %d ha robado |%d|%d|\n",jugador,partidas[mesa].monton[pos].n1,partidas[mesa].monton[pos].n2);
			}
		}
	}
}

int contarFichasMonton(int mesa)
{
	int cont = 0;

	for(int i=0; i<28; i++)
	{
		if(partidas[mesa].monton[i].estado == ACTIVA)
			cont ++;
	}

	return cont;
}

int tieneFicha(int jugador)
{
	int mesa = jugadores[jugador].mesa;

	int extremo_izquierdo = partidas[mesa].fichas_puestas[0].n1;

	int pos;
	for(int i=0; i<28; i++)
	{
		if(partidas[mesa].fichas_puestas[i].estado == INACTIVA)
		{
			pos = i-1;
			break;
		}
	}
	int extremo_derecho = partidas[mesa].fichas_puestas[pos].n2;

	printf("izquierda %d y derecha %d\n",extremo_izquierdo,extremo_derecho);

	for(int i=0; i<28; i++)
	{
		if(jugadores[jugador].fichas[i].estado == ACTIVA)
		{
			if(jugadores[jugador].fichas[i].n1 == extremo_izquierdo || jugadores[jugador].fichas[i].n2 == extremo_izquierdo)
				return 1;
			if(jugadores[jugador].fichas[i].n1 == extremo_derecho || jugadores[jugador].fichas[i].n2 == extremo_derecho)
				return 1;
		}
	}

	return 0;

}

int contarFichaJugador(int jugador)
{
	int cont = 0;
	for(int i=0; i<28; i++)
	{
		if(jugadores[jugador].fichas[i].estado == ACTIVA)
			cont++;
	}

	return cont;
}

void comprobarFinPartida(int mesa)
{
	int puntos = 0;

	if(contarFichaJugador(partidas[mesa].jugador1) == 0) //ha ganado el jugador 1
	{
		for(int i=0;i<28;i++)
		{
			if(jugadores[partidas[mesa].jugador2].fichas[i].estado == ACTIVA)
			{
				puntos += jugadores[partidas[mesa].jugador2].fichas[i].n1;
				puntos += jugadores[partidas[mesa].jugador2].fichas[i].n2;
			}
		}

		jugadores[partidas[mesa].jugador2].puntos += puntos;

		//mensaje al que ha perdido con los puntos acumulados
		char mensaje[255];
		sprintf(mensaje,"Has acumulado %d puntos, y tienes actualmente %d puntos.",puntos,jugadores[partidas[mesa].jugador2].puntos);
		enviarMensaje(partidas[mesa].jugador2,"+OK. Has perdido la partida");

		//mensaje al que ha ganado con los puntos que tiene globales
		enviarMensaje(partidas[mesa].jugador1,"+OK. Has ganado la partida");
		sprintf(mensaje,"Has acumulado 0 puntos, y tienes actualmente %d puntos.",jugadores[partidas[mesa].jugador1].puntos);
		enviarMensaje(partidas[mesa].jugador1,mensaje);
		

		partidas[mesa].estado = INACTIVA;
		jugadores[partidas[mesa].jugador1].estado = LOGUEADO;
		jugadores[partidas[mesa].jugador2].estado = LOGUEADO;
	}
	else if(contarFichaJugador(partidas[mesa].jugador2) == 0) //ha ganado el jugador 2
	{
		for(int i=0;i<28;i++)
		{
			if(jugadores[partidas[mesa].jugador1].fichas[i].estado == ACTIVA)
			{
				puntos += jugadores[partidas[mesa].jugador1].fichas[i].n1;
				puntos += jugadores[partidas[mesa].jugador1].fichas[i].n2;
			}
		}

		jugadores[partidas[mesa].jugador1].puntos += puntos;

		//mensaje al que ha perdido con los puntos acumulados
		char mensaje[255];
		sprintf(mensaje,"Has acumulado %d puntos, y tienes actualmente %d puntos.",puntos,jugadores[partidas[mesa].jugador1].puntos);
		enviarMensaje(partidas[mesa].jugador1,"+OK. Has perdido la partida");

		//mensaje al que ha ganado con los puntos que tiene globales
		enviarMensaje(partidas[mesa].jugador2,"+OK. Has ganado la partida");
		sprintf(mensaje,"Has acumulado 0 puntos, y tienes actualmente %d puntos.",jugadores[partidas[mesa].jugador2].puntos);
		enviarMensaje(partidas[mesa].jugador1,mensaje);

		partidas[mesa].estado = INACTIVA;
		jugadores[partidas[mesa].jugador1].estado = LOGUEADO;
		jugadores[partidas[mesa].jugador2].estado = LOGUEADO;
	}
	else if(contarFichasMonton(mesa) == 0 && tieneFicha(partidas[mesa].jugador1) == 0 && tieneFicha(partidas[mesa].jugador2 == 0) )
	{
		//LOS LEVANTO DE LA MESA Y LOS PONGO CON ESTADO LOGUEADO
		partidas[mesa].estado = INACTIVA;
		jugadores[partidas[mesa].jugador1].estado = LOGUEADO;
		jugadores[partidas[mesa].jugador2].estado = LOGUEADO;

		//CUENTO LOS PUNTOS DEL JUGADOR 2
		int puntos1 = 0;
		for(int i=0;i<28;i++)
		{
			if(jugadores[partidas[mesa].jugador1].fichas[i].estado == ACTIVA)
			{
				puntos1 += jugadores[partidas[mesa].jugador1].fichas[i].n1;
				puntos1 += jugadores[partidas[mesa].jugador1].fichas[i].n2;
			}
		}
		jugadores[partidas[mesa].jugador1].puntos += puntos1;

		//CUENTO LOS PUTNOS DEL JUGADOR 1
		int puntos2 = 0;
		for(int i=0;i<28;i++)
		{
			if(jugadores[partidas[mesa].jugador2].fichas[i].estado == ACTIVA)
			{
				puntos2 += jugadores[partidas[mesa].jugador2].fichas[i].n1;
				puntos2 += jugadores[partidas[mesa].jugador2].fichas[i].n2;
			}
		}
		jugadores[partidas[mesa].jugador2].puntos += puntos2;

		char mensaje[255];

		sprintf(mensaje,"Has acumulado %d puntos, y tienes actualmente %d puntos.",puntos1,jugadores[partidas[mesa].jugador1].puntos);
		enviarMensaje(partidas[mesa].jugador1,mensaje);

		sprintf(mensaje,"Has acumulado %d puntos, y tienes actualmente %d puntos.",puntos2,jugadores[partidas[mesa].jugador2].puntos);
		enviarMensaje(partidas[mesa].jugador2,mensaje);

		

		//MIRO QUIEN HA GANADO 
		if(puntos1 < puntos2 )
		{
			enviarMensaje(partidas[mesa].jugador1,"+OK. Has ganado la partida");
			enviarMensaje(partidas[mesa].jugador2,"+OK. Has perdido la partida");
		}
		else
		{
			enviarMensaje(partidas[mesa].jugador2,"+OK. Has ganado la partida");
			enviarMensaje(partidas[mesa].jugador1,"+OK. Has perdido la partida");
		}

		return;
	}
}



//esta funcion es para ir probando el codigo
void mostrarMonton(int mesa)
{
	for (int i = 0; i < 28; i++)
	{
		if(partidas[mesa].estado == ACTIVA)
			printf("|%d|%d|",partidas[mesa].monton[i].n1,partidas[mesa].monton[i].n2);
	}
	printf("\n");
}