#include <stdio.h>
#include <stdlib.h>

void mostrar(char*);
void otroMostrar(char*);

int main()
{
    void (*pFunc) (char*); ///Creo puntero a funcion. Lo que devuelve, el nombre del puntero, lo que recibe.
    pFunc = mostrar; ///Al puntero le paso la direccion de memoria de la funcion.

    pFunc("Hola"); ///Llamo a la funcion a travez del puntero.

    pFunc = otroMostrar;

    pFunc("Chau");

    return 0;
}

void mostrar(char* mensaje)
{
    printf("%s\n", mensaje);
}

void otroMostrar(char* mensaje)
{
    printf("%s\n", mensaje);
}
