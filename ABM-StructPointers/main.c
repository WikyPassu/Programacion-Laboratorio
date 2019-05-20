#include <stdio.h>
#include <stdlib.h>
#include "arrayDatos.h"

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
