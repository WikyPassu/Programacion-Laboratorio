#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* pLetter = NULL; //Declaro puntero a char.
    char letter; //Declaro variable char.
    pLetter = &letter; //Obtengo la posicion de memoria.
    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf("%c", pLetter); //Recibe la direccion de memoria de la letra.
    printf("\nLetra ingresada: %c\n", letter);

    return 0;
}
