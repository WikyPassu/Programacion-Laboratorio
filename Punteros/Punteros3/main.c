#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p; //Variable p.
    int* q; //Puntero a int.
    int* r; //Puntero a int.
    p = 10; //Asigno un valor a p.
    q = &p; //Le asigno la direccion de memoria de p a q.
    r = q; //Le asigno la direccion de memoria de q a r.

    printf("%p\n", q); //Apunta la posicion de memoria de p.
    printf("%p\n", r);  //Apunta la posicion de memoria de p.
    printf("%d\n", *q); //Apunta el valor de p.
    printf("%d\n", *r); //Apunta el valor de p.

    return 0;
}
