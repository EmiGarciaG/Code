#include <stdio.h>
#include <math.h>
//Dada una función, se desea conocer su valor medio en un intervalo [0, N(. Para ello, se calcularáel valor de la función en todos los valores de x en el intervalo [0, N( con incremento de 0.2 y se obtendrá el valor medio. Realiza un programa que: a) Solicite al usuario el valor de N. b) Solicite una función a evaluar: f (x), g(x) ó z(x). •f(x) = 3*e x – 2x •g(x) = -x * sin(x) +1.5 •z(x) = x 3 -2x +1 c) Muestre el valor medio de la función elegida en el intervalo indicado. Utiliza un puntero a función para hacer la llamada a la función en el programa principal.

float fx (float val){
    return (3*pow(2.71828,val)-2*val);
}

float gx (float val){
    return ( (-val)*sin(val)+1.5 );
}

float zx (float val){
    return ( pow(val,3)-2*val+1 );
}

float operacion(float val, float (*p) (float) ){
    float sumavalor=0, sumafuncion=0;

    for (float i=0.2;i<=val;i+=0.2) {
        sumafuncion+=p(i);
        sumavalor+=i;
    }

    return sumafuncion/sumavalor;
}

int main(){
    int eleccion;
    float N, (*p) (float);

    printf("Introduzca un número:\n");
    scanf("%f",&N);
    getchar();

    printf("Introduzca la función a evaluar:\n1) f(x)\n2) g(x)\n3) z(x)\n");
    scanf("%d",&eleccion);

    switch (eleccion) {
        case 1:
            p=&fx;
            printf("Resultado %f\n", operacion(N, p ) );
        break;
        case 2:
            p=&gx;
            printf("Resultado %f\n", operacion(N, p ) );
        break;
        case 3:
            p=&zx;
            printf("Resultado %f\n", operacion(N, p ) );
        break;
        default:
            printf("No se ha reconocido ninguna funcion.\n");
    }
}
