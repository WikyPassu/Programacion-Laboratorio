#include <stdio.h>
#include <stdlib.h>
#include "Numeros.h"

void cargarVector(int vecNum[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("Ingrese un numero: ");
        scanf("%d",&vecNum[i]);
    }
}

void mostrarVector(int vecNum[],int tam)
{
    int i;
    for(i=0;i<tam;i++){
        printf("%d ",vecNum[i]);
    }
}

int buscarMax(int vecNum[], int tam)
{
    int i, max, flag = 0;
    for(i=0;i<tam;i++){
        if(vecNum[i] > max || flag == 0){
            max = vecNum[i];
            flag = 1;
        }
    }
    return max;
}

int buscarValor(int vecNum[], int tam, int valor)
{
    int i;
    for(i=0;i<tam;i++){
        if(valor == vecNum[i]){
            return i;
        }
    }
    return -1;
}
