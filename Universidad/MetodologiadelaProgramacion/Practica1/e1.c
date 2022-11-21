#include <stdio.h>
//Programa  que escribe el tamaño de los siguientes tipos de variables
int main(){
	int a, *b, **c;
	double d, *e, **f;
	char g, *h, **i;
	printf("Tamaño de a, b y c; \n %lu \n %lu \n %lu \n", sizeof(a), sizeof(*b), sizeof(**c));
	printf("Tamaño de d, e y f; \n %lu \n %lu \n %lu \n", sizeof(d), sizeof(*e), sizeof(**f));
	printf("Tamaño de g, h y i; \n %lu \n %lu \n %lu \n", sizeof(g), sizeof(*h), sizeof(**i));
	return 0;
}
