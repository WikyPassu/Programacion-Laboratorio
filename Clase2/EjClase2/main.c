/*
Se ingresan numeros enteros distintos de cero hasta que el usuario quiera. Informar:
a) Cantidad de numeros ingresados.
b) Cantidad de pares.
c) Suma de los positivos.
d) Promedio de los negativos.
e) Maximo y minimo.
f) De los positivos el mas chico.
g) De los negativos el mas grande.
h) Cantidad de numeros que se encuentran entre el -10 y 50.
i) Promedio total.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numero,max,min,minPos,maxNeg;
    int flag=0,flag2=0,flag3=0,contNum=0,acumNum=0,pares=0,sumaPos=0,sumaNeg=0,cantNeg=0,cantRango=0;
    float promNeg,promedio;
    char resp;
    do{
        printf("Ingrese un numero entero distinto de cero: ");
        scanf("%d",&numero);
        while(numero == 0){
            printf("Error. Ingrese un numero entero distinto de cero: ");
            scanf("%d",&numero);
        }
        if(numero % 2 == 0){
            pares++;
        }
        if(numero > 0){
            sumaPos += numero;
        }
        else{
            sumaNeg += numero;
            cantNeg++;
        }
        if(numero > max || flag == 0){
            max = numero;
        }
        if(numero < min || flag == 0){
            min = numero;
            flag = 1;
        }
        if(numero < minPos || flag2 == 0){
            if(numero > 0){
                minPos = numero;
                flag2 = 1;
            }
        }
        if(numero > maxNeg || flag3 == 0){
            if(numero < 0){
                maxNeg = numero;
                flag3 = 1;
            }
        }
        if(numero >= -10 && numero <= 50){
            cantRango++;
        }
        acumNum += numero;
        contNum++;
        printf("¿Desea seguir ingresando numeros? ");
        fflush(stdin);
        scanf("%c",&resp);
    }while(resp == 's');
    promNeg = sumaNeg / (float)cantNeg;
    promedio = acumNum / (float)contNum;
    if(isnan(promNeg)){
        promNeg = 0;
    }
    if(cantNeg == 0){
        maxNeg = 0;
    }
    printf("\na) Cantidad de numeros ingresados: %d\n",contNum);
    printf("b) Cantidad de pares: %d\n",pares);
    printf("c) Suma de los positivos: %d\n",sumaPos);
    printf("d) Promedio de los negativos: %.2f\n",promNeg);
    printf("e) Maximo y minimo: %d, %d\n",max,min);
    printf("f) De los positivos el mas chico: %d\n",minPos);
    printf("g) De los negativos el mas grande: %d\n",maxNeg);
    printf("h) Cantidad de numeros que se encuentran entre el -10 y 50: %d\n",cantRango);
    printf("i) Promedio total: %.2f\n",promedio);
    getch();
    return 0;
}
