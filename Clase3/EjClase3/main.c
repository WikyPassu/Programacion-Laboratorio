#include <stdio.h>
#include <stdlib.h>
//Caso x Donde recibo parametros y devuelvo
int sumarNumero (int, int);

int main()
{
    int numeroUno, numeroDos, resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese otro numero: ");
    scanf("%d",&numeroDos);
    resultado = sumarNumeros(numeroUno, numeroDos);
    printf("El resultado es: %d",resultado);
    return 0;
}

int sumarNumeros (int unNumero, int otroNumero)
{
    int resultado;
    resultado = unNumero + otroNumero;
    return resultado;
}
