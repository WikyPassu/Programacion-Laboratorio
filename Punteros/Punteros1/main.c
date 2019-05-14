#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x = NULL;
    int v = 10;
    x = &v;
    //Mostrar valor de v.
    printf("%d\n", v);
    //Mostrar direccion de memoria de la variable v.
    printf("%p\n", &v);
    //Mostrar direccion de memoria del puntero x.
    printf("%p\n", &x);
    //Mostrar el valor de x.
    printf("%p\n", x);
    //Mostrar el valor al que apunta x.
    printf("%d\n", *x);

    return 0;
}
