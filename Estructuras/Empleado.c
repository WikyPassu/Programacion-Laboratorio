#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"
#include "Empleado.h"

void mostrarMenu(int tipoMenu)
{
    system("cls");
    if(tipoMenu == 0)
    {
        printf("--------------------------------------\n");
        printf("\n 1. Dar de alta a un empleado.");
        printf("\n 2. Dar de baja a un empleado.");
        printf("\n 3. Modificar datos.");
        printf("\n 4. Mostrar todos los empleados.");
        printf("\n 5. Informar mayor/es sueldo/s bruto.");
        printf("\n 6. Salir.\n\n");
        printf("--------------------------------------\n\n");
    }
    if(tipoMenu == 1)
    {
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
    eSector sectores[3] = {{1,"Contabilidad",100},{2,"Sistemas",200},{3, "RRHH", 150}};
    inicializarEmpleados(lista, T);
    hardcodearDatosEmpleados(lista, T);
    int opcion, contEmpleados = 6, aBorrar, borrado;
    char seguir = 's';
    do
    {
        mostrarMenu(0);
        opcion = getInt("una opcion: ");
        switch(opcion)
        {
            case 1:
                printf("\n");
                cargarEmpleado(lista, T, sectores, 3);
                contEmpleados++;
                system("pause");
                break;
            case 2:
                printf("\n");
                if(contEmpleados > 0)
                {
                    aBorrar = getInt("el legajo del empleado a dar de baja: ");
                    borrado = borrarUno(lista, T, aBorrar);
                    if(borrado != 0)
                    {
                        printf("\nSe ha dado de baja al empleado exitosamente.\n\n");
                        contEmpleados--;
                    }
                    else
                    {
                        printf("\nError: Empleado no encontrado.\n\n");
                    }
                }
                else
                {
                    printf("Error: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 3:
                if(contEmpleados > 0)
                {
                    modificarDatos(lista, T);
                }
                else
                {
                    printf("\nError: No hay empleados cargados en el sistema.\n\n");
                    system("pause");
                }
                break;
            case 4:
                if(contEmpleados > 0)
                {
                    mostrarListaEmpleados(lista, T, sectores, 3);
                }
                else
                {
                    printf("\nError: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 5:
                buscarMayorSueldo(lista, T, sectores, 3);
                printf("\nSe llaman Carlos y tienen sueldo mayor a $20k: %d\n\n", cantidadCarlos(lista, T));
                system("pause");
                break;
            case 6:
                printf("\nSaliendo...\n\nPrograma terminado.\n\n");
                seguir = 'n';
                system("pause");
                break;
            default:
                printf("\nError: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    }
    while(seguir == 's');
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i, posLibre = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            posLibre = i;
            break;
        }
    }
    return posLibre;
}

int buscarLegajo(eEmpleado lista[], int tam, int legajo)
{
    int i, pos = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].legajo == legajo && lista[i].estado == OCUPADO)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int borrarUno(eEmpleado lista[], int tam, int legajo)
{
    int sePudo = 0, pos = buscarLegajo(lista, tam, legajo);
    if(pos != -1)
    {
        lista[pos].estado = LIBRE;
        sePudo = 1;
    }
    return sePudo;
}

void cargarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int pos;
    pos = buscarLibre(lista, tam);
    if(pos != -1)
    {
        lista[pos].legajo = getInt("legajo: ");
        getString("nombre: ", lista[pos].nombre, 20);
        lista[pos].sexo = getChar("sexo: ");
        lista[pos].cantHoras = getInt("cantidad de horas trabajadas: ");
        lista[pos].idSector = getInt("id del sector (1-Contabilidad, 2-Sistemas, 3-RRHH): ");
        switch(lista[pos].idSector){
            case 1:
                lista[pos].sueldoBruto = lista[pos].cantHoras * sectores[0].valor;
                break;
            case 2:
                lista[pos].sueldoBruto = lista[pos].cantHoras * sectores[1].valor;
                break;
            case 3:
                lista[pos].sueldoBruto = lista[pos].cantHoras * sectores[2].valor;
                break;
        }
        lista[pos].sueldoNeto = lista[pos].sueldoBruto * 0.85;
        lista[pos].estado = OCUPADO;
    }
    else
    {
        printf("Error: No hay mas espacio libre.\n");
    }
    printf("\n");
}

void modificarDatos(eEmpleado lista[], int tam)
{
    printf("\n");
    int legajo = getInt("legajo del empleado: ");
    int opcion, pos = buscarLegajo(lista, tam, legajo);
    char modificar;
    eEmpleado auxLista[T];
    if(pos != -1 && lista[pos].estado == 1)
    {
        do
        {
            mostrarMenu(1);
            opcion = getInt("una opcion: ");
            switch(opcion)
            {
            case 1:
                printf("\n");
                getString("nuevo nombre: ", auxLista[pos].nombre, 20);
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    strcpy(lista[pos].nombre, auxLista[pos].nombre);
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                }
                else
                {
                    printf("\nModificacion cancelada.\n\n");
                }
                system("pause");
                break;
            case 2:
                printf("\n");
                auxLista[pos].sexo = getChar("nuevo sexo: ");
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    lista[pos].sexo = auxLista[pos].sexo;
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                }
                else
                {
                    printf("\nModificacion cancelada.\n\n");
                }
                system("pause");
                break;
            case 3:
                printf("\n");
                auxLista[pos].sueldoBruto = getFloat("nuevo sueldo bruto: ");
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    lista[pos].sueldoBruto = auxLista[pos].sueldoBruto;
                    lista[pos].sueldoNeto = lista[pos].sueldoBruto * 0.85;
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                }
                else
                {
                    printf("\nModificacion cancelada.\n\n");
                }
                system("pause");
                break;
            case 4:
                break;
            default:
                printf("\nError: Opcion invalida.\n\n");
                system("pause");
                break;
            }
        }
        while(opcion != 4);
    }
    else
    {
        printf("\nError: Empleado no encontrado.\n\n");
        system("pause");
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    printf("\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }
    }
    printf("\n");
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{
    int i;
    char descripcionSector[20];
    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector == sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    printf("%d - %s - %c - %.2f - %.2f - %s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto, descripcionSector);
}

float importeMaximo(eEmpleado lista[], int tam)
{
    int i, flag = 0;
    float maximo;
    for(i=0; i<tam; i++){
        if(lista[i].estado == OCUPADO){
            if(lista[i].sueldoBruto > maximo || flag == 0){
                    maximo = lista[i].sueldoBruto;
                    flag = 1;
            }
        }
    }
    return maximo;
}

void buscarMayorSueldo(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    float maximo = importeMaximo(lista, tam);
    printf("\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == OCUPADO){
            if(lista[i].sueldoBruto == maximo)
            {
                mostrarEmpleado(lista[i], sectores, 3);
            }
        }
    }
}

int cantidadCarlos(eEmpleado lista[], int tam)
{
    int i, cont = 0;
    for(i=0; i<tam; i++){
        if(lista[i].estado == OCUPADO){
            if(stricmp(lista[i].nombre, "carlos") == 0 && lista[i].sueldoBruto > 5000){
                cont++;
            }
        }
    }
    return cont;
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[] = {1,8,9,7,2,4};
    char nombres[][50] = {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char sexo[] = {'M','F','M','M','M','M'};
    float sueldosBruto[] = {2500,5600,5100,2500,10400,9600};
    int horas[] = {25,28,34,25,52,48};
    int sector[] = {1,2,3,1,2,2};
    for(i=0; i<tam-4; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
        lista[i].cantHoras = horas[i];
    }
}
