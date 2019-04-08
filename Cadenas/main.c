#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int len;
    char palabra[20]; //Siempre necesito uno mas para la finalizacion '\0'
    printf("Ingrese nombre y apellido: ");
    //gets(palabra); //Solo funciona en Windows
    fgets(palabra, 20, stdin);
    len = strlen(palabra);
    palabra[len] = '\0';

    //len = strlen(palabra); //Permite conocer el tamaño en bytes de una cadena
    printf("\nLa palabra es: %s\nCantidad de caracteres: %d", palabra, len);
    return 0;
}

//scanf("%s", palabra); Se frena cuando encuentra un espacio

//scanf("[^\n]", palabra); Funciona en W y L

//fgets(palabra, 10, stdin); Funciona en W y L, pensada para leer lineas de un archivo. Al usar strlen, lee tambien el \n
//len = strlen(palabra);
//palabra[len] = '\0'
