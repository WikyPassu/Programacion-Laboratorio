#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabra[10]; //Siempre necesito uno mas para la finalizacion "\0"
    printf("Ingrese nombre y apellido: ");
    //scanf("%s", palabra); Se frena cuando encuentra un espacio
    //scanf("[^\n]", palabra); Funciona en W y L
    //fgets(palabra, 10, stdin); Funciona en W y L
    gets(palabra); //Solo funciona en Windows
    printf("\n%s\n", palabra);
    return 0;
}
