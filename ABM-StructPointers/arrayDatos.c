#include <stdio.h>
#include <stdlib.h>
#include "arrayDatos.h"

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
