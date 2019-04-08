#include <stdio.h>
#include <stdlib.h>
#include "Numeros.h"
#define T 5
#define V 7

int main()
{
    int numeros[T], maximo, posicion;
    cargarVector(numeros,T);
    printf("\n");
    mostrarVector(numeros,T);
    printf("\n");
    maximo = buscarMax(numeros,T);
    printf("\nMaximo numero ingresado: %d\n",maximo);
    posicion = buscarValor(numeros,T,V);
    if(posicion != -1){
        printf("\nValor encotrado en la posicion [%d]\n",posicion);
    }
    else{
        printf("\nValor no encontrado dentro del vector.\n");
    }
    return 0;
}

