#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct libro{
	char titulo[100];
	char autor[50];
	float precio;
	int unidades;
};
void limpiarlinea(char *libro){
	if(libro[strlen(libro)-1]=='\n'){
		 libro[strlen(libro)-1]='\0';
	}
}
void comprueba(char *fichero, char *libro){
	FILE *f;
	int encontrado=0;
	char libroaux[150];
	if((f=fopen(fichero, "r"))==NULL){
		printf("\nError al abrir fichero <%s>", fichero);
		exit(-1);
	}
	while(fgets(libroaux, 50, f)!=NULL && !encontrado){
		limpiarlinea(libroaux);
		if(strcmp(libro, libroaux)==0){
			encontrado=1;
			printf("El libro esta en el stock\n");
		}
		fgets(libroaux, 50, f);
		limpiarlinea(libro);
	}	
	fclose(f);
	if(encontrado!=1){
	printf("El libro no esta en el stock\n");
	}
}
void introducir(char *fichero){
	struct libro l; 
	FILE *f;
	if((f=fopen(fichero, "a"))==NULL){
		printf("\nError al abrir fichero <%s>", fichero);
		exit(-1);
	}
	printf("\nIntroduzca el titulo del libro: ");
	fgets(l.titulo, 100, stdin);
	limpiarlinea(l.titulo);
	fprintf(f, "%s\n", l.titulo);
	printf("\nIntroduzca el autor del libro: ");
	fgets(l.autor, 50, stdin);
	limpiarlinea(l.autor);
	fprintf(f, "%s\n", l.autor);
	printf("\nIntroduzca el precio del libro: ");
	scanf("%f", &l.precio);
	fprintf(f, "%f ", l.precio);
	printf("\nIntroduzca cuantas unidades hay del libro: ");
	scanf("%i", &l.unidades);
	fprintf(f, "%i\n", l.unidades);
	fclose(f);
}
int contar(char *fichero){
	FILE *f;
	int registros=0;
	char linea[50];
	f=fopen(fichero, "r");
	while(fgets(linea, 50, f)!=NULL){
		registros++;
		limpiarlinea(linea);
	}
	fclose(f);
	return (registros/3);
}
struct libro *reservaMemoria(int numEle){
  	struct libro *v;
  	if((v=(struct libro*)malloc(numEle*sizeof(struct libro)))==NULL){
      		printf("Error: No se pudo reservar memoria.\n");
      		exit(-1);
  	}
  	return v;
}
struct libro *stock(char *fichero){
	FILE *f;
	struct libro *v;
	if((f=fopen(fichero, "r"))==NULL){
		printf("\nError al abrir fichero <%s>", fichero);
		exit(-1);
	}
	char linea[50];
	int nEle=contar(fichero);
	v=(reservaMemoria(nEle));
	for(int i=0; i<nEle; i++){
		fgets(v[i].titulo, 50, f);
		limpiarlinea(linea);
		fgets(v[i].autor, 50, f);
		limpiarlinea(linea);
		fscanf(f, "%f ", &v[i].precio);	
		fscanf(f, "%i", &v[i].unidades);
	}
	return v;
}
int existeFichero(char *fichero){
	FILE *f;
	f=fopen(fichero, "r");
	if(f==NULL){
		return 0;
	}
	else{
		fclose(f);
		return 1;
	}
}
int main(int argc, char *argv[]){
	char fichero[500];
	char *busca;
	strcpy(fichero, argv[1]);
	if(existeFichero(fichero)==0){
		FILE *f;
		f=fopen(fichero, "w");
		fclose(f); 
	}
	int *v;
	int opcion=0;
	while(opcion!=7){
		printf("Seleccione una opcion: \n");
		printf("1.Comprobar existencia de un libro. \n");
		printf("2.Introducir un nuevo libro. \n");
		printf("3.Contar el número de libros diferentes que hay. \n");
		printf("4.Listar los libros en el stock. \n");
		printf("5.Vender n unidades de un libro buscándolo por su título. \n");
		printf("6.Borrar registro con 0 unidades. \n");
		printf("7.Salir \n");
		scanf("%i", &opcion);
		switch(opcion){
			case(1):
				printf("Escribe el libro que buscas: ");
				getchar();
				fgets(busca, 50, stdin);
				limpiarlinea(busca);
				comprueba(fichero, busca);
			break;
			case(2):
				getchar();
				introducir(fichero);
			break;
			case(3):
				getchar();
				printf("Numero de libros: %i \n", contar(fichero));
			break;
			case(4):
				getchar();
				stock(fichero);
			break;
			
			case(7):
				printf("Saliendo...\n");
			break;
			default:
				printf("No existe dicha opción\n");
		}
	}
	return 0;
}
