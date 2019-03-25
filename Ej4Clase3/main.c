#include <stdio.h>
#include <stdlib.h>
//Caso 3 Donde no recibo parametros ni devuelvo

void sumar();

int main()
{
    sumar();
    return 0;
}

void sumar(){
    int n1, n2, resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&n1);
    printf("Ingrese otro numero: ");
    scanf("%d",&n2);
    resultado = n1 + n2;
    printf("El resultado de sumar %d + %d = %d",n1, n2, resultado);
}
