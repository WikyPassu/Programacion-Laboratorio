#include <stdio.h>
#include <stdlib.h>
#include "Entradas.h"
#define T 3
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

void mostrarMenu();
void elegirOpcion();
void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int buscarUno(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);
void cargarEmpleado(eEmpleado [], int);
void mostrarListaEmpleados(eEmpleado [], int);
void mostrarEmpleado(eEmpleado);

int main()
{
    elegirOpcion();
    return 0;
}

void mostrarMenu()
{
    system("cls");
    printf("-----------------------------------\n");
    printf("\n 1. Dar de alta a un empleado.");
    printf("\n 2. Dar de baja a un empleado.");
    printf("\n 3. Mostrar todos los empleados.");
    printf("\n 4. Salir.\n\n");
    printf("-----------------------------------\n\n");
}

void elegirOpcion()
{
    eEmpleado lista[T];
    mostrarMenu();
    inicializarEmpleados(lista, T);
    int opcion, aBorrar, borrado;
    char seguir = 's';
    do{
        mostrarMenu();
        opcion = getEntero("una opcion: ");
        switch(opcion){
            case 1:
                printf("\n");
                cargarEmpleado(lista, T);
                system("pause");
                break;
            case 2:
                printf("\n");
                aBorrar = getEntero("el legajo del empleado a dar de baja: ");
                borrado = borrarUno(lista, T, aBorrar);
                if(borrado != 0){
                    printf("\nSe ha dado de baja al empleado exitosamente.\n\n");
                }
                else{
                    printf("\nError: Empleado no encontrado.\n\n");
                }
                system("pause");
                break;
            case 3:
                mostrarListaEmpleados(lista, T);
                system("pause");
                break;
            case 4:
                printf("\nSaliendo...\n\nPrograma terminado.\n\n");
                seguir = 'n';
                system("pause");
                break;
            default:
                printf("\nError: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    }while(seguir == 's');
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++){
        lista[i].estado = LIBRE;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i, posLibre = -1;
    for(i=0; i<tam; i++){
        if(lista[i].estado == LIBRE){
            posLibre = i;
        }
    }
    return posLibre;
}

int buscarUno(eEmpleado lista[], int tam, int legajo)
{
    int i, pos = -1;
    for(i=0; i<tam; i++){
        if(lista[i].legajo == legajo){
            pos = i;
        }
    }
    return pos;
}

int borrarUno(eEmpleado lista[], int tam, int legajo)
{
    int sePudo = 0, pos = buscarUno(lista, tam, legajo);
    if(pos != -1){
        lista[pos].estado = LIBRE;
        sePudo = 1;
    }
    return sePudo;
}

void cargarEmpleado(eEmpleado lista[], int tam)
{
    int pos;
    pos = buscarLibre(lista, tam);
    if(pos != -1){
        lista[pos].legajo = getEntero("legajo: ");
        getCadena("nombre: ", lista[pos].nombre, 20);
        lista[pos].sexo = getCaracter("sexo: ");
        lista[pos].sueldoBruto = getFlotante("sueldo bruto: ");
        lista[pos].sueldoNeto = lista[pos].sueldoBruto*0.85;
        lista[pos].estado = OCUPADO;
    }
    else{
        printf("Error: No hay mas espacio libre.\n\n");
    }
    printf("\n");
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    printf("\n");
    for(i=0; i<tam; i++){
        if(lista[i].estado == OCUPADO){
            mostrarEmpleado(lista[i]);
        }
    }
    printf("\n");
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d - %s - %c - %.2f - %.2f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}
