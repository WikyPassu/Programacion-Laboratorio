//Fuimos haciendo funcion por funcion para luego unificarlas todas en un ejercicio.

#include <stdio.h>
#include <stdlib.h>

int pedirNota();
float sacarPromedio(int suma, int cantidad);
int aprobarMateria(int notaMinima, int nota);
void ejercicioUno();

int main()
{
    /*float promedio;
    int valorUno, valorDos, datoRecibido;
    datoRecibido = pedirNota();
    printf("Nota recibida: %d\n",datoRecibido);
    promedio = sacarPromedio(15,2);
    printf("Promedio: %d\n",promedio);
    valorUno = aprobarMateria(6,2);
    printf("Valor1: %d\n",valorUno);
    valorDos = aprobarMateria(6,8);
    printf("Valor2: %d\n",valorUno);*/
    ejercicioUno();
    return 0;
}

int pedirNota(){
    int nota;
    do{
        printf("Ingrese una nota (0-10): ");
        scanf("%d",&nota);
    }while(nota < 0 || nota > 10);
    return nota;
}

float sacarPromedio(suma,cantidad){
    float retorno;
    retorno = (float)suma / cantidad;
    return retorno;
}

int aprobarMateria(notaMinima, nota){
    if (nota > notaMinima){
        return 1;
    }
    return 0;
}

void ejercicioUno(){
    int i, nota, aprobados = 0, desaprobados = 0, acumApro = 0, acumDesapro = 0, promAprobados, promDesaprobados, valor;
    for(i = 1 ; i <= 5 ; i++){
        nota = pedirNota();
        valor = aprobarMateria(6,nota);
        if(valor == 1){
            acumApro += nota;
            aprobados++;
        }
        else{
            acumDesapro += nota;
            desaprobados++;
        }
    }
    promAprobados = sacarPromedio(acumApro, aprobados);
    promDesaprobados = sacarPromedio(acumDesapro, desaprobados);
    printf("\nCantidad de aprobados: %d\nPromedio de notas de aprobados: %d\nPromedio de notas de no aprobados: %d\n",aprobados,promAprobados,promDesaprobados);
}
