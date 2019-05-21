#include <stdio.h>
#include <stdlib.h>
#define T 5

int cargarVector(int* pArray, int sizeA);
int mostrarVector(int* pArray, int sizeA);

int main()
{
    //Vectores.
    int* pNumeros;
    int* aux;
    int i, t = T+5;

    pNumeros = (int*) malloc(sizeof(int)*5); //Pido 20 bytes de memoria consecutiva en el Heap.

    for(i=0; i<T; i++)
        {
            *(pNumeros+i) = i+1;
        }

    aux = (int*) realloc(pNumeros, sizeof(int)*t);

    if(aux != NULL)
    {
        pNumeros = aux;
        cargarVector(pNumeros, t);
        mostrarVector(pNumeros, t);
    }

    printf("\n");


    //pNumeros = realloc(pNumeros, sizeof(int)*(T+5));
    /*if(pNumeros != NULL)
    {
        for(i=0; i<T; i++)
        {
            printf("%d. Ingrese un numero: ", i+1);
            scanf("%d", pNumeros+i);
        }
        printf("\n");

        for(i=0; i<T; i++)
        {
            printf("%d ", *(pNumeros+i));
        }
        printf("\n");
    }
    */
    return 0;
}

int cargarVector(int* pArray, int sizeA)
{
    int i, estado = 0;
    if(pArray != NULL)
    {
        for(i=0; i<sizeA; i++)
        {
            printf("%d. Ingrese un numero: ", i+1);
            scanf("%d", pArray+i);
        }
        estado = 1;
    }
    return estado;
}

int mostrarVector(int* pArray, int sizeA)
{
    int i, estado = 0;
    if(pArray != NULL)
    {
        for(i=0; i<sizeA; i++)
        {
            printf("%d ", *(pArray+i));
        }
        estado = 1;
    }
    return estado;
}

/*
    int* pNumero; //Esta en la pila.

    //Malloc devuelve void, lo casteo a int para poder guardarlo en pNumero y le paso el sizeof de un int.
    pNumero = (int*) malloc(sizeof(int));
    //pNumero = (int*) calloc(sizeof(int),1);

    *pNumero = 99;
    printf("Heap  ->  pNumero: %p\n", pNumero); //Muestra direccion del puntero en pila.
    printf("Stack -> &pNumero: %p\n", &pNumero); //Muestra direccion del puntero en monton.

    if(pNumero != NULL)
    {
        printf("Valor -> *pNumero: %d\n", *pNumero); //Muestra valor.
        printf("\nLuego de hacer un free:\n\n");
        free(pNumero); //Libero/Optimizo el espacio en memoria.
        printf("Heap  ->  pNumero: %p\n", pNumero); //Muestra direccion del puntero en pila.
        printf("Stack -> &pNumero: %p\n", &pNumero); //Muestra direccion del puntero en monton.
        printf("Valor -> *pNumero: %d\n", *pNumero); //Muestra valor.
    }
    */
