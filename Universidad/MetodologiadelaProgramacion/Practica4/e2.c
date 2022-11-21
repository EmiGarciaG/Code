#include <stdlib.h>
#include <stdio.h>
#include<string.h>

struct alumno {
              	char nombre[50];
                int DNI;
                float nota;

};
struct alumno *reservarVector(int nEle){
                struct alumno *v;
                v=(struct alumno*)calloc(nEle, sizeof(struct alumno));
                if(v==NULL){
                               printf("ERROR. No se ha podido reservar la memoria\n");
                               exit(-1);
                }
                return v;
}
int numeroDeAlumnos(char* fichero){
                FILE* f;
                int nAlumnos;
                if((f=fopen(fichero,"rb"))==NULL){
                               printf("No se pudo leer el fichero\n");
                               exit(-1);
                }
                //Para saber cuantos alumnos hay, primero nos colocamos al final del fichero con fseek
                fseek(f, 0L, SEEK_END);
                //Como ftell devuelve el nº de bytes desde el principio del fichero hasta la posicion
                //actual del cursor(final), vamos a saber cuantos bytes tiene el fichero en total
                //Por tanto el numero de alumnos registrados es el resultado de dividir el nº de bytes
                // entre el tamaño de struct alumno
                nAlumnos=ftell(f)/sizeof(struct alumno);
                fclose(f); //Importante cerrar el fichero una vez que hemos acabado
                return nAlumnos;
}
struct alumno * PasarDeFicheroAVector(char* fichero){
                struct alumno *v;
                FILE* f;
                int nEle=numeroDeAlumnos(fichero);
                v=reservarVector(nEle);
                if((f=fopen(fichero,"rb"))==NULL){
                               printf("No se pudo crear el fichero\n");
                               exit(-1);
                }
                fread(v, sizeof(struct alumno), nEle, f); //Se lee todo el fichero
                fclose(f);
                return v;
}
int ascendente(int a, int b){
                if(a>b){
                               return 1;
                }
                else{ return 0;
                }
}
int descendente(int a, int b){
                if (a<b){
                               return 1;
                }
                else{ 
			return 0;
                }
}
void OrdenarPorSeleccion(struct alumno* v, int nEle, int (*cmp)(int a,int b)){
                int menor, aux;
                //Algoritmo de ordenacion por seleccion
                for(int i=0; i<nEle; i++){
                               menor=i;
                               for(int j=i+1; j<nEle; j++){
                                               if((*cmp)(v[j].DNI, v[menor].DNI)){
          	                                     menor=j;
                                               }
                               }
                               aux=v[menor].DNI;
                               v[menor].DNI=v[i].DNI;
                               v[i].DNI=aux;
                }
}
int main(int argc, char *argv[]){
                if(argc!=3){
                               printf("Error en los parametros\n");
                               exit(-1);
                }
                struct alumno *v;
                int nEle=numeroDeAlumnos(argv[1]);
                v=reservarVector(nEle);
                v=PasarDeFicheroAVector(argv[1]); //Rellenamos el vector con los datos del fichero
                //Vemos si el numero introducido por teclado es 1 o 2
                if( strcmp (argv[2], "1")==0){
                               OrdenarPorSeleccion(v, nEle, &ascendente);
                }
                if( strcmp (argv[2], "2")==0){
                               OrdenarPorSeleccion(v, nEle, &descendente);
                }
                free(v); //Liberamos el vector
                return 0;
}
