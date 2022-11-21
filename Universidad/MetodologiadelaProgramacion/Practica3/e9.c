#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Codifica un programa en C que, utilizando funciones, cree un fichero binario con números enteros generados aleatoriamente en un intervalo especificado por el usuario. El programa guardará los números en un vector dinámico antes de volcarlo a disco. El programa recibirá 4 parámetros como argumentos en la línea de órdenes: nombre del fichero a crear, número de elementos que contendrá el fichero y los extremos superior e inferior del intervalo.
int generarnumeros(int superior,int inferior){
	return (rand()%(superior-inferior+1)+(inferior));
}
void crearfichero(char *fichero, int nEle,int superior,int inferior){
     	FILE *f;
     	int i;
     	time_t t;
     	srand ((int) time(&t));
     	f=fopen(fichero, "wb");
          	if (f==NULL){
               		printf("\nError, no se puede crear el archivo <%s>", fichero);
               		exit(-1);
          	}
          	for(i=0; i<nEle; i++){
			int num=generarnumeros(superior, inferior);
               		fwrite(&num, sizeof(int), 1, f);
		}
        fclose(f);
}
int main(int argc,char *argv[]){
	if(argc!=5){
		printf("Sintaxis incorrecta: %s <nombreFichero>\n",argv[0]);
		exit(-1);
        }
     	int nEle, superior, inferior;
	nEle=atoi(argv[2]);
	superior=atoi(argv[3]);
	inferior=atoi(argv[4]);
        crearfichero(argv[1], nEle, superior, inferior);
     	return 0;
}
