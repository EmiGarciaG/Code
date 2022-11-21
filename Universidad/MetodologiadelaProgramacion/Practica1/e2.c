#include <stdio.h>
//Valor de cada variable
int main(){
	int *px; //Puntero sin valor asignado	
	printf("\nValor px: \n %p", px);    
	float a=0, b=0;	//Variables sin valor asignados
	printf("\nValor a y b: \n %f \n %f", a, b);
	float *pa=&a, *pb;		//Punteros sin valor asignados
	printf("\nValor pa y pb: \n %p \n %p", pa, pb);
	a=-0.167;		//Variable a con valor -0.167		
	printf("\nValor a: \n %f", a);		//Puntero con valor a
	printf("\nValor pa: \n %p", pa);
	char c1=' ', c2=' ', c3=' ';	//Caracteres sin valor asignados
	printf("\nValor c1, c2 y c3: \n %c \n %c \n %c", c1, c2, c3);
	char *pcl=0, *pc2=0, *pc3=&c1;		//Punteros sin valor asignados excepto el último con valor cl sin asignar
	printf("\nValor pcl, pc2 y pc3: \n %p \n %p \n %p", pcl, pc2, pc3);
	return 0;
}
