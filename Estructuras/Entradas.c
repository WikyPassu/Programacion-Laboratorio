#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"

int getInt(char mensaje[])
{
    int entero;
    printf("Ingrese %s", mensaje);
    scanf("%d", &entero);
    return entero;
}

float getFloat(char mensaje[])
{
    float flotante;
    printf("Ingrese %s", mensaje);
    scanf("%f", &flotante);
    return flotante;
}

char getChar(char mensaje[])
{
    char caracter;
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}

void getString(char mensaje[], char cadena[], int tam)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validateStringSize(mensaje, cadena, tam);
}

void validateStringSize(char mensajeError[], char cadena[], int tam)
{
    while(strlen(cadena)>tam)
    {
        printf("Reingrese %s", mensajeError);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}
