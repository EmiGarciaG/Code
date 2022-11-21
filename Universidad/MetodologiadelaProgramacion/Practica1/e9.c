#include <stdio.h>
#include <math.h>
//Un monomio (5x^3) puede codificarse en C mediante una estructura con dos campos enteros coeficiente y grado (ej. coeficiente=5, grado=3). Por su parte, un polinomio es una sucesión de monomios de diferente grado (5x^3 + 7x^2 + 4x^5). a) Implementa una función denominada leerMonomio, que reciba una estructura pasada por referencia y permita leer los datos de un monomio. b) Implementa una función denominada imprimirMonomio, que reciba una estructura por valor y muestre el coeficiente y el grado del monomio. c) Utilizando las funciones anteriores, en el programa principal lee y escribe un polinomio (vector de monomios). d) Crea una función que, usando paso de parámetros por referencia, devuelva el monomio de mayor grado y el de menor grado. Utilízala en tu programa. e) Crea un función que evalúe un polinomio en un punto X. Utilízala en tu programa.
struct Monomio{
	int coeficiente;
	int grado;
};
void leerMonomio(struct Monomio *m){
	printf("Escribe el coeficiente: ");
	scanf("%i", &m->coeficiente);
	printf("Escribe el grado: ");
	scanf("%i", &m->grado);
}
void imprimirMonomio(struct Monomio m){
	printf("%ix^%i", m.coeficiente, m.grado);
}
void mayormenor(struct Monomio *m, int size, struct Monomio *mayor, struct Monomio *menor){
	for(int i=0; i<size; i++){
		for (int j=i+1; j<size; j++){
			if((m+i)->grado<(m+j)->grado){
				struct Monomio aux=m[i];
				m[i]=m[j];
				m[j]=aux;
			}
		}
	}
	*mayor=m[0];
	*menor=m[size-1];
}
int solvefunc(struct Monomio *m, int size, int val){
	int res=0;
	for(int i=0; i<size; i++){
		res+=(m+i)->coeficiente*(pow((val), (m+i)->grado));
	}
	return res;
}
int main(){
	int n, val;
	printf("Numero de monomios:");
	scanf("%d",&n);
	struct Monomio polinomio[n], mayor, menor;
	for(int i=0; i<n; i++){
		leerMonomio(polinomio+i);
	}
	printf("Tu polinomio es:\n");
	for(int j=0; j<n; j++){
		imprimirMonomio(polinomio[j]);
		printf("\n");
	}
	mayormenor(polinomio,n,&mayor,&menor);
	printf("El mononomio mayor es: %d(x)^%d \n", mayor.coeficiente, mayor.grado);
	printf("El mononomio menor es: %d(x)^%d\n", menor.coeficiente, menor.grado);
	printf("Introduzca valor x:");
scanf("%d", &val);
	printf("El resultado de ' ");
	for(int k=0; k<n; k++){
		imprimirMonomio(polinomio[k]);
	}
	printf("' con x=%d es = %d\n", val, solvefunc(polinomio,n,val));
}
