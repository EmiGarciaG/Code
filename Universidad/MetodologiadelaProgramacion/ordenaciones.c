#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void burbuja(int* V, int izda, int dcha, int(*comparacion)(int, int)){
	for(int i=izda+1; i<=dcha; i++){
   		for(int j=dcha; j>=i; j--){
        		if((*comparacion)(V[j-1],V[j])){
				int aux=0;
          			aux=V[j];
          			V[j]=V[j-1];
          			V[j-1]=aux;
        		}
     		}
   	}   
}
void seleccion(int* V, int izda, int dcha, int(*comparacion)(int, int)){
   	int pmenor;
   	int menor;
   	for(int i=izda; i<dcha;i++){
      		pmenor = i;
      		menor=*(V+i);
      		for(int j=i+1; j<=dcha; j++){
      			if((*comparacion)(V[j],menor)){
      	   			pmenor = j;
      	   			menor = *(V+j); //V[j]
      			}
      		}
      		*(V+pmenor) = *(V+i); 
      		*(V+i)=menor; 
   	}
}
int mayor(int a, int b){
   	if(a>b){
   		return(1);
		}
	else{
   		return(0);
	}
}
int menor(int a, int b){
   
   if(a<b){
   	return(1);
	}
   else{
   	return(0);
	}  
}
