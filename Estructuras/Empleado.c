#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"
#include "Empleado.h"

void mostrarMenu(int tipoMenu)
{
    system("cls");
    if(tipoMenu == 0){
        printf("-----------------------------------\n");
        printf("\n 1. Dar de alta a un empleado.");
        printf("\n 2. Dar de baja a un empleado.");
        printf("\n 3. Modificar datos.");
        printf("\n 4. Mostrar todos los empleados.");
        printf("\n 5. Salir.\n\n");
        printf("-----------------------------------\n\n");
    }
    if(tipoMenu == 1){
        printf("-----------------------------------\n");
        printf("\n 1. Modificar nombre.");
        printf("\n 2. Modificar sexo.");
        printf("\n 3. Modificar sueldo bruto.");
        printf("\n 4. Salir.\n\n");
        printf("-----------------------------------\n\n");
    }
}

void elegirOpcion()
{
    eEmpleado lista[T];
    inicializarEmpleados(lista, T);
    int opcion, contEmpleados = 0, aBorrar, borrado;
    char seguir = 's';
    do{
        mostrarMenu(0);
        opcion = getEntero("una opcion: ");
        switch(opcion){
            case 1:
                printf("\n");
                cargarEmpleado(lista, T);
                contEmpleados++;
                system("pause");
                break;
            case 2:
                printf("\n");
                if(contEmpleados > 0){
                    aBorrar = getEntero("el legajo del empleado a dar de baja: ");
                    borrado = borrarUno(lista, T, aBorrar);
                    if(borrado != 0){
                        printf("\nSe ha dado de baja al empleado exitosamente.\n\n");
                        contEmpleados--;
                    }
                    else{
                        printf("\nError: Empleado no encontrado.\n\n");
                    }
                }
                else{
                    printf("Error: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 3:
                if(contEmpleados > 0){
                    modificarDatos(lista, T);
                }
                else{
                    printf("\nError: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 4:
                if(contEmpleados > 0){
                    mostrarListaEmpleados(lista, T);
                }
                else{
                    printf("\nError: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 5:
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
            break;
        }
    }
    return posLibre;
}

int buscarUno(eEmpleado lista[], int tam, int legajo)
{
    int i, pos = -1;
    for(i=0; i<tam; i++){
        if(lista[i].legajo == legajo && lista[i].estado == OCUPADO){
            pos = i;
            break;
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
        printf("Error: No hay mas espacio libre.\n");
    }
    printf("\n");
}

void modificarDatos(eEmpleado lista[], int tam)
{
    printf("\n");
    int legajo = getEntero("legajo del empleado: ");
    int opcion, pos = buscarUno(lista, tam, legajo);
    if(pos != -1 && lista[pos].estado == 1){
        do{
            mostrarMenu(1);
            opcion = getEntero("una opcion: ");
            switch(opcion){
                case 1:
                    printf("\n");
                    getCadena("nuevo nombre: ", lista[pos].nombre, 20);
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                    system("pause");
                    break;
                case 2:
                    printf("\n");
                    lista[pos].sexo = getCaracter("nuevo sexo: ");
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                    system("pause");
                    break;
                case 3:
                    printf("\n");
                    lista[pos].sueldoBruto = getFlotante("nuevo sueldo bruto: ");
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                    system("pause");
                    break;
                case 4:
                    break;
                default:
                    printf("\nError: Opcion invalida.\n\n");
                    system("pause");
                    break;
            }
        }while(opcion != 4);
    }
    else{
        printf("\nError: Empleado no encontrado.\n\n");
    }
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

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={1,8,9,7,2,4};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char sexo[]={'F','M','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000,6000};
    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
    }
}
