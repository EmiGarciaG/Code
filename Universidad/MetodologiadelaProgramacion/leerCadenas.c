#include <stdio.h>
#include <string.h>
#define TAM_MAX 100

int main()
{
    char cadena[TAM_MAX];
    
    //scanf %s no acepta espacios en blanco
    printf("\nIntroduzca valor para la cadena: ");
    scanf("%s", cadena);
    printf("La cadena leida con scanf %%s es: <%s>\n", cadena);
    getchar(); //scanf no quita el \n del buffer de entrada => limpia \n
    
    //scanf %100[^\n] si acepta espacios en blanco
    printf("\nIntroduzca valor para la cadena: ");
    scanf("%100[^\n]", cadena);
    printf("La cadena leida con scanf %%100[^\\n] es: <%s>\n", cadena);
    getchar();  //scanf no quita el \n del buffer de entrada => limpia \n    
    
    //gets si acepta espacios en blanco
    printf("\nIntroduzca valor para la cadena: ");
    gets(cadena);
    printf("La cadena leida con gets es: <%s>\n", cadena);
    //gets si quita el \n del buffer de entrada
    
    //fgets si acepta espacios en blanco
    printf("\nIntroduzca valor para la cadena: ");
    fgets(cadena, TAM_MAX, stdin);
    //Quita el \n final
    if(cadena[strlen(cadena)-1]=='\n')
       cadena[strlen(cadena)-1] = '\0';
    printf("La cadena leida con fgets es: <%s>\n", cadena);
    //fgets si quita el \n del buffer de entrada 
    
}
