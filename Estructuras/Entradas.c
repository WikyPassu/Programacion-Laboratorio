#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"

int getEntero(char mensaje[])
{
    int entero;
    printf("Ingrese %s", mensaje);
    scanf("%d", &entero);
    return entero;
}

float getFlotante(char mensaje[])
{
    float flotante;
    printf("Ingrese %s", mensaje);
    scanf("%f", &flotante);
    return flotante;
}

char getCaracter(char mensaje[])
{
    char caracter;
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}

void getCadena(char mensaje[], char cadena[], int tam)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarTamCadena(mensaje, cadena, tam);
}

void validarTamCadena(char mensajeError[], char cadena[], int tam)
{
    while(strlen(cadena)>tam)
    {
        printf("Reingrese %s", mensajeError);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}
