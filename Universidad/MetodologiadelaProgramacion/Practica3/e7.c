#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Codifica un programa en C que, utilizando funciones, calcule la media de los elementos pares que hay en un fichero de texto generado por el ejercicio anterior. El nombre del fichero se pasará como argumento en la línea de órdenes.
float media(char *nombre){
	FILE *f;
	int suma=0,c=0;
	int num,ok;
	float m=0;
	f=fopen(nombre,"r");
        if(f==NULL) {
		printf("El fichero %s no se ha podido abrir\n",nombre);
                exit(-1);
        }
        ok=fscanf(f,"%d",&num);
        while(ok==1){
                if(num%2==0){
			suma=suma+num;
			c++;
                }
                ok=fscanf(f,"%d",&num);
	}
        m=suma/c;
        return m;
	fclose(f); 
}
int main(int argc,char *argv[]){
        if(argc!=2){
		printf("Sintaxis incorrecta: %s <nombreFichero>\n",argv[0]);
		exit(-1);
        }
        printf("La media de los elementos del fichero <%s> es: %f",argv[1],media(argv[1]));
        printf("\n");
	return 0;
}
