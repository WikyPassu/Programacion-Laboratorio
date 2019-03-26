#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void mostrarMenu()
{
    int flag = 0;
    int seguir = 0;
    do{
        if(flag == 0){
            printf("-----------------------Calculadora-----------------------\n");
            printf("\n1. Ingresar 1er operando.");
            printf("\n2. Inresar 2do operando.");
            printf("\n3. Calcular todas las operaciones (+ - / * !)");
            printf("\n4. Informar resultados.");
            printf("\n5. Salir.");
        }
        else{
            printf("-----------------------Calculadora-----------------------\n");
            printf("\n1. Ingresar 1er operando. Actualmente: A = %d");
            printf("\n2. Inresar 2do operando. Actualmente: B = %d");
            printf("\n3. Calcular todas las operaciones (+ - / * !)");
            printf("\n4. Informar resultados.");
            printf("\n5. Salir.");
            flag = 1;
        }
        seguir = elegirOpcion();
        system("pause");
        system("cls");
    }while(seguir == 0);
}

int elegirOpcion()
{
    int opcion, a, b;
    printf("\nElija una opcion: ");
    scanf("%d",opcion);
    switch(opcion){
        case 1:
            a = ingresarNumero();
            return a;
            break;
        case 2:
            b = ingresarNumero();
            return b;
            break;
        case 3:
            printf("\nCalculando operaciones...");
            calcularOperaciones(a,b);
            break;
        case 4:
            printf("\nMostrando resultados...");
            mostrarResultados();
            break;
        case 5:
            printf("\nSaliendo...");
            return 1;
            break;
        default:
            printf("\nOpcion invalida.");
            break;
    }
}

int ingresarNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    return numero;
}
