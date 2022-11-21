#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Codifica un programa en C que, utilizando funciones, cree un fichero texto con números enteros generados aleatoriamente en un intervalo especificado por el usuario. El programa le preguntará al usuario el nombre del fichero a crear, el número de elementos que contendrá el fichero y los extremos superior e inferior del intervalo.
int generarnumeros(int superior,int inferior){
	return (rand()%(superior-inferior+1)+(inferior));
}
void crearfichero(char *fichero, int nEle,int superior,int inferior){
     	FILE *f;
     	int i;
     	time_t t;
     	srand ((int) time(&t));
     	f=fopen(fichero, "w");
          	if (f==NULL){
               		printf("\nError, no se puede crear el archivo <%s>", fichero);
               		exit(-1);
          	}
          	for(i=0; i<nEle; i++){
               		fprintf(f, "%i\n", generarnumeros(superior, inferior));
		}
          	fclose(f);
}
int main(){
     	char fichero[64];
     	int nEle, superior, inferior;
        printf("Introduce el nombre del archivo a crear: \n");
        scanf("%s", fichero);
        printf("Introduce el numero de elementos que contendra el archivo: \n");
        scanf("%i", &nEle);
        printf("Introduce el extremo superior: \n");
        scanf("%i", &superior);
        printf("Introduce el extremo inferior: \n");
        scanf("%i", &inferior);
        crearfichero(fichero, nEle, superior, inferior);
     	return 0;
}
