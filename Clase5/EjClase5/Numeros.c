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

void ordenarVector(int vecNum[], int tam) //Swap = Intercambiar
{
    int i,j,aux;
    for(i=0; i<tam-1; i++){ //Itero hasta la anteultima posicion
        for(j=i+1; j<tam; j++){ //j debe ir a la par de i
            if(vecNum[i] > vecNum[j]){ //Criterio: Ordenar menor a mayor
                aux = vecNum[i]; //Realizo los intercambios con una variable auxiliar
                vecNum[i] = vecNum[j];
                vecNum[j] = aux;
            }
        }
    }
}
