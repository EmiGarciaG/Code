#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
//Construye un programa que gestione, mediante ficheros binarios, el stock de libros de una librería. Para cada libro se almacenará la siguiente estructura:
struct libro {
	char titulo[100];
	char autor[50];
	float precio;
	int unidades;
}
//El programa contará con un menú que permitirá realizar las siguientes operaciones: • Comprobar la existencia de un determinado libro buscando por su título. • Introducir un nuevo libro en el stock. • Contar el número de libros (títulos) diferentes que hay en el stock. Considera que no puede haber títulos de libros repetidos en el fichero. • Listar los libros en el stock almacenándolos previamente en un vector dinámico • Vender n unidades de un libro buscándolo por su título. Si hay menos de n unidades en el stock, se venderán solo las unidades disponibles. • Borrar aquellos registros con 0 unidades disponibles. • Salir. El nombre del fichero se pasará como argumento en la línea de órdenes.
void comprueba(struct libro *l){

}
void introducir(struct libro *l){
	printf("\nIntroduzca el titulo del libro: ");
	scanf("%s", l->titulo);
	printf("\nIntroduzca el autor del libro: ");
	scanf("%s", l->autor);
	printf("\nIntroduzca el precio del libro: ");
	scanf("%f", &l->precio);
	printf("\nIntroduzca cuantas unidades hay del libro: ");
	scanf("%i", &l->unidades);
}
void contar(){

}
void stock(){

}
void vende(){

}
void borrar(){

}
int main(int argc,char *argv[]){
	int opcion=0;
	while(option!=7){
		printf("Seleccione una opcion: \n");
		printf("1.Comprobar existencia de un libro. \n");
		printf("2.Introducir un nuevo libro. \n");
		printf("3.Contar el número de libros diferentes que hay. \n");
		printf("4.Listar los libros en el stock. \n");
		printf("5.Vender n unidades de un libro buscándolo por su título. \n");
		printf("6.Borrar registro con 0 unidades. \n");
		printf("7.Salir \n");
		scanf("%i", &opcion);
		switch(option){
			case(1):
				char libro[50];
				printf("Escribe el libro que buscas: ");
				scanf("%s", libro);
				comprueba();
			break;
			case(2):
				introducir();
			break;
			case(3):
				contar();
			break;
			case(4):
				for(int i=0; i<n; i++){
		stock(polinomio[k]);
	}
				stock();
			break;
			case(5):
				vende();
			break;
			case(6):
				borrar();
			break;
			default:
				printf("No existe dicha opción\n");
	}
	return 0;
}
