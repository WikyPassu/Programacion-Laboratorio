#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;
} eDato;

//Hacer funcion que muestre todo el array a traves de un puntero.
//Hacer funcion que ordene por letra.

int mostrarArray(eDato*, int);
void mostrarUno(eDato*, int);
int ordenarArray(eDato*, int);

int main()
{   //Estamos en la pila porque todavia no pedimos memoria.
    //eDato unDato = {1,'C'};
    //int i;
    eDato muchosDatos[3] = {{1,'C'},{2,'B'},{3,'A'}};
    //eDato* pDato;

    //pDato = &unDato;
    //pDato = muchosDatos;

    //printf("%d--%c\n", (*pDato).numero, (*pDato).letra);
    //printf("%d--%c\n", pDato->numero, pDato->letra);

    /*for(i=0; i<3; i++)
    {
        //printf("%d--%c\n", (*(pDato+i)).numero, (*(pDato+i)).letra);
        printf("%d--%c\n", (pDato+i)->numero, (pDato+i)->letra);
    }*/
    printf("Array desordenado:\n\n");
    mostrarArray(muchosDatos, 3);
    printf("\nArray ordenado:\n\n");
    ordenarArray(muchosDatos, 3);
    mostrarArray(muchosDatos, 3);

    return 0;
}

int mostrarArray(eDato* listD, int tam)
{
    int i, estado = 0;
    if(listD != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
        {
            //printf("%d--%c\n", (*(listD+i)).numero, (*(listD+i)).letra);
            //printf("%d--%c\n", (listD+i)->numero, (listD+i)->letra);
            mostrarUno((listD+i), tam);
        }
        estado = 1;
    }
    return estado;
}

void mostrarUno(eDato* listD, int tam)
{
    printf("%d--%c\n", (listD)->numero, (listD)->letra);
}

int ordenarArray(eDato* listD, int tam)
{
    int i, j, estado = 0;
    eDato aux;
    if(listD != NULL && tam > 0)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if((listD+i)->letra > (listD+j)->letra)
                {
                    aux = *(listD+i);
                    *(listD+i) = *(listD+j);
                    *(listD+j) = aux;
                }
            }
        }
        estado = 1;
    }
    return estado;
}
/*
void swap(eDato* i, eDato* j)
{
    eDato aux;
    aux = *i;
    *i = *j;
    *j = aux;
}
*/
