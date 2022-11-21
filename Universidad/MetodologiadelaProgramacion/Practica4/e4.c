#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct lista{
 int a,e;
 struct lista *sig;
};
int menu(){
 int opcion;
 printf(" \n OPERACIONES SOBRE LISTAS \n");
 printf("\n  1. Crear polinomio");   
 printf("\n  2. Tabla de valores");
 printf("\n  3. Eliminar monomio"); 
 printf("\n  4. Buscar monomio");
 printf("\n  5. Insertar monomio");
 printf("\n  6. Evalua polinomio ");
 printf("\n  7. Muestra polinomio");
 printf("\n  0. Salir. ");
 printf("\n \n    Introduzca una opcion :");
 scanf("%d", &opcion);
 return opcion;
} 
struct lista *nuevoElemento()
{
 return ((struct lista *)malloc(sizeof(struct lista)));
}
void insertarMonomio(struct lista **cabeza, int a, int e){
 struct lista *nuevo = NULL;
 nuevo=nuevoElemento();
 nuevo->a=a;
 nuevo->e=e;
 nuevo->sig=*cabeza;
 *cabeza=nuevo;
}
void imprimirPolinomio(struct lista *cabeza){
 struct lista *aux = NULL;
 aux=cabeza;
 while(aux!=NULL)
 {
   if(aux->sig==NULL){
	printf("(%d)^%d", aux->a, aux->e);
   }
   else{	
   	printf("(%d)^%d+", aux->a, aux->e);
   }
   aux=aux->sig;
  }
}
float TablaValores(struct lista **cabeza, float x){
 struct lista *aux = NULL;
 aux=*cabeza;
 float suma=0;
 while(aux!=NULL)
  {
	suma+=(aux->a*pow(x,aux->e));
   	aux=aux->sig;
  }
	return suma;
}
int buscarMonomio(struct lista *cabeza,int e){
 int encontrado=0;
 struct lista *aux = NULL;
 aux=cabeza;
 while(aux!=NULL && encontrado==0){
   if(aux->e==e){
    encontrado=1;
   }
   else{
    aux=aux->sig;
   }
  }
 return encontrado;
}
void borrarMonomio(struct lista **cabeza, int e){
 struct lista *ant=NULL;  
 struct lista *aux=NULL; 
 aux=*cabeza;
 while(aux->e!=e){
   ant=aux;
   aux=aux->sig;
 } 
 if(aux==*cabeza){
   *cabeza = aux->sig; 
   free(aux); 
 }
 else{
   ant->sig = aux->sig; 
   free(aux); 
 }
}
void borrarLista(struct lista **cabeza){
   struct lista * aux, * sig;
   aux=*cabeza;
   while(aux!=NULL)
   {
     sig=aux->sig;
     free(aux);
     aux=sig;
   }
   *cabeza=NULL;
}
int main(){
 int opc, n, a, e, encontrado;
 float x=0;
 struct lista *cabeza = NULL;
 do{
   opc=menu();
   switch (opc)
   {
      case 1: 
      borrarLista(&cabeza);
      printf("\nPolinomio y numero de elementos:");
      scanf("%d", &n);
      for(int i=0; i<n; i++){
	printf("Coeficiente:");
	scanf("%d", &a);
	printf("Exponente:");
	scanf("%d", &e);
      	encontrado=buscarMonomio(cabeza, e);
      	if(!encontrado){
        insertarMonomio(&cabeza, a, e);
	printf("Elemento insertado\n");
      	}
      	else
      	printf("\n Elemento existente");
      }
      printf("\n Pulse intro para seguir"); 
      getchar();
      getchar();        
      break;
      case 2:
	for(float i=0; i<=10; i++){
		printf("\n Valor x=%f:", x);
		printf("%f", TablaValores(&cabeza, x));
		x+=(0.5);
	}
      break;
      case 3: 
      printf("Monomio a borrar :");
      scanf("%d", &e);
      encontrado=buscarMonomio(cabeza, e);
      if(encontrado){
        borrarMonomio(&cabeza, e);
        printf("\n Monomio borrado");
      }
      else
      printf("\n El Elemento no encontrado");
      printf("\n Pulse intro para seguir");
      getchar();
      getchar();
      break;
     case 4: 
      printf("Elemento a buscar :");
      scanf("%d", &n);
      encontrado=buscarMonomio(cabeza, n);
      if (encontrado)
       printf("Elemento encontrado\n");
      else
       printf("Elemento no encontrado \n");
      printf("\n Pulse intro para seguir");
      getchar();
      getchar();
      break;	
     case 5: 
      printf("\nInserte monomio");
      printf("\nCoeficiente:");
      scanf("%d", &a);
      printf("Exponente:");
      scanf("%d", &e);
      encontrado=buscarMonomio(cabeza, e);
      if(!encontrado){
        insertarMonomio(&cabeza, a, e);
	printf("\n Elemento insertado");
      }
      else
      	printf("\n Elemento existente");
      printf("\n Pulse intro para seguir"); 
      getchar();
      getchar();        
      break;
     case 6:
	printf("\n Valor x:");
	scanf("%f", &x);
	printf("\n Para x=%f:", x);
	printf("%f", TablaValores(&cabeza, x));
	printf("\n Pulse intro para seguir"); 
        getchar();
        getchar();        
     break;
     case 7: 
      printf("Polinomio \n");
      imprimirPolinomio(cabeza);
      printf("\n Pulse intro para seguir");
      getchar();
      getchar();
      break;  
  }      
 } while (opc!=0);
 return 0;
}

