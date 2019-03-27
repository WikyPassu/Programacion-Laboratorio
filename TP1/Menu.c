#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

void mostrarMenu()
{
    //int menu = 0, flag = 0, estadoA = 0, estadoB = 0, estadoVariables, opcion, a, b;
    int menu = 0;
    //char seguir = 's';
    //do{
        if(menu == 0){
            printf("-----------------------Calculadora-----------------------\n");
            printf("\n1. Ingresar 1er operando.");
            printf("\n2. Ingresar 2do operando.");
            printf("\n3. Calcular todas las operaciones (+ - / * !)");
            printf("\n4. Informar resultados.");
            printf("\n5. Salir.\n\n");
            printf("---------------------------------------------------------\n");
            menu = 1;
        }
        elegirOpcion();
        /*printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                a = ingresarNumero();
                system("cls");
                if(flag == 0){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando.");
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                    flag = 1;
                }
                else{
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                estadoA = 1;
                break;
            case 2:
                b = ingresarNumero();
                system("cls");
                if(flag == 0){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando.");
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                    flag = 1;
                }
                else{
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                estadoB = 1;
                break;
            case 3:
                estadoVariables = comprobarEstado(estadoA, estadoB);
                if(estadoVariables == 1){
                    //llamo a la funcion que calcula todo
                }
                else{
                    printf("\nError: Primero deben ingresarse A y B.\n");
                break;
                }
            case 4:
            case 5:
                printf("\nSaliendo...\n\nGracias por utilizar esta Calculadora!!!\n\n");
                seguir = 'n';
                system("pause");
                break;
            default:
                printf("\nError: Opcion invalida.\n\n");
                system("pause");
                system("cls");
                break;
        }*/
    //}while(seguir == 's');
}

char elegirOpcion()
{
    int flag = 0, estadoA = 0, estadoB = 0, estadoVariables, opcion, a, b;
    char seguir = 's';
    do{
    printf("\nElija una opcion: ");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            a = ingresarNumero();
            system("cls");
            if(flag == 0){
                printf("-----------------------Calculadora-----------------------\n");
                printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                printf("\n2. Ingresar 2do operando.");
                printf("\n3. Calcular todas las operaciones (+ - / * !)");
                printf("\n4. Informar resultados.");
                printf("\n5. Salir.\n\n");
                printf("---------------------------------------------------------\n");
                flag = 1;
            }
            else{
                printf("-----------------------Calculadora-----------------------\n");
                printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                printf("\n3. Calcular todas las operaciones (+ - / * !)");
                printf("\n4. Informar resultados.");
                printf("\n5. Salir.\n\n");
                printf("---------------------------------------------------------\n");
                }
                estadoA = 1;
                break;
        case 2:
            b = ingresarNumero();
            system("cls");
            if(flag == 0){
                printf("-----------------------Calculadora-----------------------\n");
                printf("\n1. Ingresar 1er operando.");
                printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                printf("\n3. Calcular todas las operaciones (+ - / * !)");
                printf("\n4. Informar resultados.");
                printf("\n5. Salir.\n\n");
                printf("---------------------------------------------------------\n");
                flag = 1;
            }
            else{
                printf("-----------------------Calculadora-----------------------\n");
                printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                printf("\n3. Calcular todas las operaciones (+ - / * !)");
                printf("\n4. Informar resultados.");
                printf("\n5. Salir.\n\n");
                printf("---------------------------------------------------------\n");
            }
            estadoB = 1;
            break;
        case 3:
            estadoVariables = comprobarEstado(estadoA, estadoB);
            if(estadoVariables == 1){
                //llamo a la funcion que calcula todo
            }
            else{
                printf("\nError: Primero deben ingresarse A y B.\n");
            break;
            }
        case 4:
        case 5:
            printf("\nSaliendo...\n\nGracias por utilizar esta Calculadora!!!\n\n");
            seguir = 'n';
            system("pause");
            break;
        default:
            printf("\nError: Opcion invalida.\n\n");
            system("pause");
            system("cls");
            break;
    }
    }while(seguir == 's');
}


int ingresarNumero()
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d",&numero);
    return numero;
}

int comprobarEstado(int est_a, int est_b)
{
    if(est_a == 1 && est_b == 1){
        return 1;
    }
    else{
        return 0;
    }
}
