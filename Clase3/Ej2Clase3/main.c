#include <stdio.h>
#include <stdlib.h>
//Caso 1 Donde recibo parametros pero no devuelvo
void sumar(int, int);

int main()
{
    int numero, numero2;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    printf("Ingrese otro numero: ");
    scanf("%d",&numero2);
    sumar(numero,numero2);
    return 0;
}

void sumar(n1, n2){
    int resultado;
    resultado = n1 + n2;
    printf("El resultado de sumar %d + %d = %d",n1,n2,resultado);
}
