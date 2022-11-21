#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct alumno
{
    char nombre[50];
    int DNI;
    float nota;
};
struct alumno * reservarVector(int nElementos)
{
    struct alumno * V;
    V = (struct alumno*) calloc(nElementos, sizeof(struct alumno));
    if(V == NULL)
    {
        printf("\n Error en la reserva de memoria");
        exit(-1);
    }

    return V;
}
int numero_alumnos(char * fichero){
    FILE * pFichero;
    int numeroRegistros;

    pFichero = fopen(fichero, "rb");

    fseek(pFichero, 0L, SEEK_END);
    numeroRegistros = ftell(pFichero)/sizeof(struct alumno);

    fclose(pFichero);
    return numeroRegistros;
}

struct alumno * fichero_vector(char* fichero)
{
    struct alumno* Vector;
    FILE * pFichero;
    int nElementos = numero_alumnos(fichero);
    Vector = reservarVector(nElementos);
    pFichero = fopen(fichero, "rb");
    fread(Vector, sizeof(struct alumno), nElementos, pFichero);
    fclose(pFichero);
    return Vector;
}
int compararNombres(const void* nombre1, const void* nombre2){
    struct alumno *a, *b;
    a=(struct alumno*)nombre1;
    b=(struct alumno*)nombre2;
    return strcmp((a->nombre),(b->nombre));
}

int compararNotas(const void* nota1, const void* nota2){
    struct alumno *a, *b;
    a=(struct alumno*)nota1;
    b=(struct alumno*)nota2;
    if((a->nota)>(b->nota))
    {
        return 1;
    }
    else
    {
        if((a->nota)<(b->nota))
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int opcion, i;
    char fichero[50];
    struct alumno * Vector;

    printf("Introduce el nombre del fichero: ");
    scanf("%s", fichero);

    Vector = fichero_vector(fichero);

    int nElementos = numero_alumnos(fichero);

    for(i=0;i<nElementos;i++)
    {
        printf("\nVector.nombre[%i] = %s", i, Vector[i].nombre);
        printf("Vector.nota[%i] = %f\n", i, Vector[i].nota);
    }

    printf("\n\nNota: 1\n");
    printf("Nombre: 2\n");
    scanf("%i", &opcion);

    if(opcion == 1)
    {
        qsort(Vector, nElementos, sizeof(struct alumno), &compararNotas);
        for(i=0;i<nElementos;i++)
        {
            printf("\nVector.nota[%i] = %f", i, Vector[i].nota);
        }
    }
    else
    {
        qsort(Vector, nElementos, sizeof(struct alumno), &compararNombres);
        for(i=0;i<nElementos;i++)
        {
            printf("\nVector.nombre[%i] = %s", i, Vector[i].nombre);
        }
    }

    free(Vector);
    return 0;
}
