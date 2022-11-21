//Capacidad de un char
#define MSG_SIZE 250
#define CHAR_SIZE 100

//Estados de un jugador
#define NO_CONECTADO -1
#define CONECTADO 0
#define LOGIN 1
#define LOGUEADO 2
#define ESPERA 3
#define JUGANDO 4
#define ESPERATURNO 5

//Estados de una partida
#define VACIA 0
#define EMPEZADA 1

//Estructura Jugador
typedef struct jugador{
	int socket;
	char usuario[50];
	char password[50];
	int estado;
	int mesa;
	int puntos;
}Jugador;

//Estructura Partida
typedef struct partida{
	int turno;
	int jugador1;
	int jugador2;
	int estado;
	char panel[CHAR_SIZE];
	char resolver[CHAR_SIZE];
}Partida;

//Variables Globales
Jugador listajugadores[30];
Partida partidas[10];
int contador;

//Funciones
void IniciarJuego();
int BuscarUsuario(char * Nombre);
int RegistrarJugador(Jugador j);
Jugador PedirCampos(char * buffer);
void EnviarMensaje(int socket, char *buffer);
int ComprobarPassword(char * Nombre, char * passwd);
void EscribirDatosUsuario(int socket);
int IniciarPartida(int jugador);
void CambiarTurno(int mesa);
void MensajeTurno(int mesa);
Partida BuscarPartida(int jugador);
void DescubrirLetra(Partida p, char aux[CHAR_SIZE], int jugador);
int EsVocal(char letra);
int EsConsonante(char letra);
int CambiarPuntuacion(Partida p, char letra, int jugador);
void EmpiezaJugador1(int mesa);
int EsTurno(int jugador);
int Resolver(Partida p, char aux[CHAR_SIZE], int jugador);
int FinPartida(Partida p, int jugador);