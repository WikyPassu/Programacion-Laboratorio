#include <stdio.h>
#include <stdlib.h>
//Caso 2 Donde no recibo parametros pero devuelvo
int sumar();

int main()
{
    int resultado;
    resultado = sumar();
    printf("El resultado es: %d",resultado);
    return 0;
}

int sumar(){
    int n1, n2, resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&n1);
    printf("Ingrese un numero: ");
    scanf("%d",&n2);
    resultado = n1 + n2;
    return resultado;
}
