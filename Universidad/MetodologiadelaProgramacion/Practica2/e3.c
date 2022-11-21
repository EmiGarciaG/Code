#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Escribe un programa que permita gestionar los jugadores de baloncesto del equipo de una ciudad. Para ello se guardará la información de cada jugador en la siguiente estructura:
struct Ficha_jugador {
	char nombre[50];
	int dorsal;
	/* No entero */
	float peso;
	/* Expresado en kilos */
	int estatura;
	/* Expresado en centímetros*/
};
//El programa realizará secuencialmente las siguientes operaciones: a) Crear un vector dinámico de jugadores. b) Listar los jugadores registrados en el equipo, con las características de cada uno de ellos (dorsal, peso, estatura). c) Borrar todos los jugadores con una 'a' en su nombre. d) Listar de nuevo los jugadores. e) Liberar memoria al terminar. Deberás implementar al menos las siguientes funciones (también puede utilizar otras funciones auxiliares que considere oportunas): ● Función para reservar memoria para un vector de estructuras de jugador. ● Función para leer un nuevo jugador. La función pedirá al usuario los datos de un jugador y los devolverá en una estructura struct Ficha_jugador. ● Función para rellenar un vector de jugadores usando la función para leer un jugador. ● Función para listar los jugadores del equipo. ● Función para borrar jugadores cuyo nombre contenga un carácter que se pasará como argumento. ◦ Al terminar la ejecución, el vector de jugadores habrá reducido su tamaño usando la función realloc. ◦ La función devolverá el número de jugadores que quedan en el vector.
struct Ficha_jugador * reserva_memoria(int n){
	struct Ficha_jugador * jugadores;
	jugadores=(struct Ficha_jugador*)calloc(n,sizeof(struct Ficha_jugador));
	if(jugadores==NULL){
		printf("Error, no se pudo reservar la memoria...\n");
		exit -1;
	}
	return jugadores;
}
void lee_jugadores(struct Ficha_jugador * jugadores, int n){
	for(int i=0; i<n; i++){
	printf("Datos del jugador[%i]: \n", i+1);
	printf("Introduzca el nombre: \n");
	scanf("%s", jugadores[i].nombre);
	printf("Introduzca el dorsal: \n");
	scanf("%i", &jugadores[i].dorsal);
	printf("Introduzca el peso(kg): \n");
	scanf("%f", &jugadores[i].peso);
	printf("Introduzca la estatura(cm): \n");
	scanf("%i", &jugadores[i].estatura);
	printf("<---------------------------------------->\n");
	}
}
void imprime_jugadores(struct Ficha_jugador * jugadores, int n){
	for(int i=0; i<n; i++){
	printf("Datos del jugador[%i]: \n", i+1);
	printf("Nombre: %s\n", jugadores[i].nombre);
	printf("Dorsal: %i\n", jugadores[i].dorsal);
	printf("Peso: %f\n", jugadores[i].peso);
	printf("Estatura: %i\n", jugadores[i].estatura);
	printf("<---------------------------------------->\n");
	}
}
void libera_memoria(struct Ficha_jugador ** jugadores, int n){
	free(*jugadores);
	*jugadores=NULL;
}
void elimina_jugadores(struct Ficha_jugador * jugadores, int n){
	int k;
	for(int i=0; i<n; i++){
		for(int m=0; jugadores[i].nombre[m] != '\0'; m++ ){ 
			if(toupper(jugadores[i].nombre[m])=='A'){
				k=i;
				while(k<n){
					jugadores[k]=jugadores[k+1];
					k++;
				}
				n--;
			}
		}
	}
	jugadores=(struct Ficha_jugador*)realloc(jugadores, n*sizeof(struct 		Ficha_jugador));
	if(jugadores == NULL){
		printf("Error, no se pudo asignar la nueva memoria...");
		exit -1;
	}
	printf("Los nuevos jugadores son: \n");
	imprime_jugadores(jugadores, n);
	libera_memoria(&jugadores, n);
}
int main(){
	struct Ficha_jugador * jugadores;
	int n;
	printf("Introduzca el numero de jugadores: \n");
	scanf("%i", &n);
	jugadores=reserva_memoria(n);
	printf("Memoria reservada correctamente...\n");
	lee_jugadores(jugadores, n);
	imprime_jugadores(jugadores, n);
	elimina_jugadores(jugadores, n);
return 0;
}
