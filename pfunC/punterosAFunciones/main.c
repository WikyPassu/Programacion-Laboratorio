#include <stdio.h>
#include <stdlib.h>

int mostrar(void);
int otroMostrar(void);

void central(int(*pFunc)(void));

int main()
{
    int r;

    int (*funcion)();
    funcion = mostrar;

    central(funcion);

    funcion = otroMostrar;
    central(funcion);

    return 0;
}

int mostrar()
{
    printf("HOLA\n");
    return 1;
}

int otroMostrar()
{
    printf("CHAU\n");
    return 5;
}

void central(int(pFunc)(void))
{
    int r = pFunc();
    printf("Retorno:%d\n", r);
}


