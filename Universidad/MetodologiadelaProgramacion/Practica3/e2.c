#include <stdio.h>
#include <stdlib.h>
//Construye una función recursiva que calcule la división entera de dos números mediante el métodos de restas sucesivas. Implementa un pequeño programa para probarla.
int divisionentera(int dividendo, int divisor){
    if(divisor>dividendo){
        return 0;    
    }
    else{
        return 1+divisionentera(dividendo-divisor, divisor);
    }

}
void main(int argc, char *argv[]){
    int x,y;
    if(argc!=3){
        printf("Error en la sintesis: ./%s <dividendo> <divisor>", argv[0]);
    }
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    printf("La division entera de %d y %d es %d\n",x,y,divisionentera(x,y));
}
