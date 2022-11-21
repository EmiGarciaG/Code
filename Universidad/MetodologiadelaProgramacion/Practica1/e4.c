#include <stdio.h>
//Si el valor asignado a la variable a empieza en la dirección 1130 (hexadecimal) , el valor asignado a la variable b empieza en 1134, y el valor asignado a la variable c empieza en 1138, entonces, tras ejecutar todas las sentencias:
float main(){

	float a = 0.001;
	float b = 0.003;
	float c, *pa, *pb;
	pa=&a;
	*pa=2*a;
	pb=&b;
	c=3*(*pb+*pa);
//a) ¿Qué valor es representado por &a?
	printf("\nValor de &a: \n %p", &a);
//b) ¿Qué valor es representado por &b?
	printf("\nValor de &b: \n %p", &b);
//c) ¿Qué valor es representado por &c?
	printf("\nValor de &c: \n %p", &c);
//d) ¿Qué valor es asignado a pa?
	printf("\nValor de pa: \n %p", pa);
//e) ¿Qué valor es representado por *pa?
	printf("\nValor de pa: \n %f", *pa);
//f) ¿Qué valor es representado por &(*pa)?
	printf("\nValor de &(*pa): \n %p", &(*pa));
//g) ¿Qué valor es asignado a pb?
	printf("\nValor de pb: \n %p", pb);
//h) ¿Qué valor es representado por *pb?
	printf("\nValor de *pb: \n %f", *pb);
//i) ¿Qué valor es asignado a c?
	printf("\nValor de c: \n %f \n", c);
	return 0;
}
