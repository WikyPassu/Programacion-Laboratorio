#include <stdio.h>
#include <stdlib.h>

int main()
{
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

    //Vectores.

    int* pNumeros;
    int i;

    pNumeros = (int*) malloc(sizeof(int)*5); //Pido 20 bytes de memoria consecutiva en el Heap.

    if(pNumeros != NULL)
    {
        for(i=0; i<5; i++)
        {
            printf("%d. Ingrese un numero: ", i+1);
            scanf("%d", pNumeros+i);
        }
        printf("\n");
        for(i=0; i<5; i++)
        {
            printf("%d ", *(pNumeros+i));
        }
        printf("\n");
    }

    return 0;
}
