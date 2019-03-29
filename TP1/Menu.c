#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
// Tengo que hacer condiciones para negativos en los factoriales y usar la funcion mostrarMenu para refrescar cada vez que se elige una opcion
void mostrarMenu()
{
        int menu = 0;
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

}

void elegirOpcion()
{
    int estadoA = 0, estadoB = 0, flag = 0, estadoVariables, opcion, a, b;
    int suma, resta, div, multi, factA, factB, indeterminacion = 0;
    char seguir = 's';
    do{
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                a = ingresarNumero();
                estadoA = 1;
                system("cls");
                if(estadoA == 1 && estadoB == 1){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                else if(estadoA == 1){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando.");
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                break;
            case 2:
                b = ingresarNumero();
                estadoB = 1;
                system("cls");
                if(estadoA == 1 && estadoB == 1){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando. Actualmente: A = %d",a);
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - / * !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                else if(estadoB == 1){
                    printf("-----------------------Calculadora-----------------------\n");
                    printf("\n1. Ingresar 1er operando.");
                    printf("\n2. Ingresar 2do operando. Actualmente: B = %d",b);
                    printf("\n3. Calcular todas las operaciones (+ - * / !)");
                    printf("\n4. Informar resultados.");
                    printf("\n5. Salir.\n\n");
                    printf("---------------------------------------------------------\n");
                }
                break;
            case 3:
                estadoVariables = comprobarEstados(estadoA, estadoB);
                if(estadoVariables == 1){
                    printf("\nCalculando operaciones...");
                    suma = sumar(a,b);
                    resta = restar(a,b);
                    multi = multiplicar(a,b);
                    if(b == 0){
                        indeterminacion = 1;
                    }
                    else{
                        div = dividir(a,b);
                    }
                    factA = sacarFactorial(a);
                    factB = sacarFactorial(b);
                    printf("\nTodas las operaciones han sido calculadas con exito!\n");
                    flag = 1;
                }
                else{
                    printf("\nError: Primero deben ingresarse A y B para realizar todas las operaciones.\n");
                }
                break;
            case 4:
                estadoVariables = comprobarEstados(estadoA, estadoB);
                if(estadoVariables == 1 && flag == 1){
                    printf("\n-------------Resultados-------------");
                    printf("\n %d + %d = %d",a,b,suma);
                    printf("\n %d - %d = %d",a,b,resta);
                    printf("\n %d * %d = %d",a,b,multi);
                    if(indeterminacion != 0){
                        printf("\nError: No es posible dividir por cero.");
                    }
                    else{
                        printf("\n %d / %d = %d",a,b,div);
                    }
                    printf("\n %d! = %d",a,factA);
                    printf("\n %d! = %d",b,factB);
                    printf("\n------------------------------------\n");
                }
                else{
                    printf("\nError: Primero deben ingresarse A y B o calcular todas las operaciones para mostrar los resultados.\n");
                }
                break;
            case 5:
                printf("\nSaliendo...\nGracias por utilizar esta Calculadora!!!\n\n");
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

int comprobarEstados(int est_a, int est_b)
{
    if(est_a == 1 && est_b == 1){
        return 1;
    }
    return 0;
}
