#include "Recursividad.h"

int factorial(int n)
{
    int resultado;
    if (n == 0 || n == 1){
        resultado = 1;
    }
    else{
        resultado = n * factorial(n - 1);
    }
    return resultado;
}
