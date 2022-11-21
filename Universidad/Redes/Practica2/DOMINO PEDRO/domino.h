

//ESTADOS DE UN JUEGADOR
#define NO_CONECTADO -1
#define CONECTADO 0
#define LOGIN_USUARIO 1
#define LOGUEADO 2
#define ESPERA 3
#define JUGANDO 4

//ESTADOS DE UNA PARTIDA Y UNA FICHA
#define INACTIVA 0
#define ACTIVA 1

//ESTRUCTURA FICHA
typedef struct ficha
{
	int n1;
	int n2;
	int estado;
}Ficha;

//ESTRUCTURA JUGADOR
typedef struct jugador
{
	int socket;
	char nombreUsuario[50];
	char contrasena[50];
	char nombreCompleto[50];
	char ciudad[50];
	int estado;
	int mesa;
	Ficha fichas[28];
	int puntos;
}Jugador;

//ESTRUCTURA PARTIDA
typedef struct partida
{
	int turno;
	int jugador1;
	int jugador2;
	int estado;
	Ficha monton[28];
	Ficha fichas_puestas[28];
}Partida;

//VARIABLES GLOBALES DEL JUEGO
Jugador jugadores[40];
Partida partidas[10];

void inicializarJuego();
int buscarUsuarioBD(char * nombreUsuario);
int registrarJugadorBD(Jugador j);
Jugador obtenerCamposRegister(char * buffer);
void enviarMensaje(int socket, char * buffer);
int comprobarContrasenaBD(char * nombreUsuario, char * contrasena);
void volcarDatosUsuarioMemoria(int socket);
int iniciarPartida(int jugador2);
void repartirFichas(int mesa);
void mostrarMonton(int mesa);
void enviarFichasJugador(int mesa);
int colocarFicha(int mesa,int jugador, char * buffer);
void insertarIzquierda(int mesa,Ficha f);
void insertarDerecha(int mesa,Ficha f);
void quitarFichaJugador(int jugador,Ficha f);
void cambiarTurno(int mesa);
void enviarMensajePartida(int mesa);
void mensajeTurno(int mesa);
void robarFicha(int jugador);
int contarFichasMonton(int mesa);
int tieneFicha(int jugador);
void comprobarFinPartida(int mesa);
int contarFichaJugador(int jugador);