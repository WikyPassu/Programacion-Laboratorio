#include <stdio.h>
#include <stdlib.h>
#define T 5

void cargarVector(int vecNum[], int tam);
void mostrarVector(int vecNum[], int tam);

int main()
{
    int numeros[T];
    cargarVector(numeros,T);
    printf("\n");
    mostrarVector(numeros,T);
    printf("\n");
    return 0;
}

void cargarVector(int vecNum[],int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&vecNum[i]);
    }
}

void mostrarVector(int vecNum[],int tam)
{
    int i;
    for(i = 0;i < tam; i++){
        printf("%d ",vecNum[i]);
    }
}
