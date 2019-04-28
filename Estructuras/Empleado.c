#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"
#include "Empleado.h"

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
    eSector sector;
    pos = buscarLibre(lista, tam);
    if(pos != -1)
    {
        lista[pos].legajo = getInt("legajo: ");
        getString("nombre: ", lista[pos].nombre, 20);
        lista[pos].sexo = getChar("sexo: ");
        lista[pos].cantHoras = getInt("cantidad de horas trabajadas: ");
        sector = pedirSector(sectores, ts);
        lista[pos].idSector = sector.idSector;
        lista[pos].sueldoBruto = lista[pos].cantHoras * sector.valor;
        lista[pos].sueldoNeto = lista[pos].sueldoBruto * 0.85;
        lista[pos].estado = OCUPADO;
        printf("\nSe ha dado de alta al empleado exitosamente.\n");
    }
    else
    {
        printf("Error: No hay mas espacio libre.\n");
    }
    printf("\n");
}

eSector pedirSector(eSector sectores[], int ts)
{
    int i, sector;
    eSector sectorReturn;
    for(i=0; i<ts; i++)
        {
            printf("\n%d. %s", sectores[i].idSector, sectores[i].descripcion);
        }
    printf("\n\n");
    sector = getInt("id del sector: ");
    for(i=0; i<ts; i++)
    {
        if(sectores[i].idSector == sector)
        {
            sectorReturn = sectores[i];
            break;
        }
    }
    return sectorReturn;
}

void modificarDatos(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    printf("\n");
    int legajo = getInt("legajo del empleado: ");
    int opcion, pos = buscarLegajo(lista, tam, legajo);
    char modificar;
    eSector sector;
    eEmpleado auxLista[T];
    if(pos != -1 && lista[pos].estado == OCUPADO)
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
                auxLista[pos].cantHoras = getInt("nueva cantidad de horas: ");
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    lista[pos].cantHoras = auxLista[pos].cantHoras;
                    sector = pedirSector(sectores, ts);
                    lista[pos].idSector = sector.idSector;
                    lista[pos].sueldoBruto = lista[pos].cantHoras * sector.valor;
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
                sector = pedirSector(sectores, ts);
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    lista[pos].idSector = sector.idSector;
                    lista[pos].sueldoBruto = lista[pos].cantHoras * sector.valor;
                    lista[pos].sueldoNeto = lista[pos].sueldoBruto * 0.85;
                    printf("\nLa modificacion ha sido exitosa.\n\n");
                }
                else
                {
                    printf("\nModificacion cancelada.\n\n");
                }
                system("pause");
                break;
            case 5:
                break;
            default:
                printf("\nError: Opcion invalida.\n\n");
                system("pause");
                break;
            }
        }
        while(opcion != 5);
    }
    else
    {
        printf("\nError: Empleado no encontrado.\n\n");
        system("pause");
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i, j, opcion, maxEmp, flag = 0, flag2 = 0;
    auxSector auxListaSector[3];
    do
    {
        mostrarMenu(2);
        opcion = getInt("una opcion: ");
        switch(opcion)
        {
        case 1:
            printf("\n");
            for(i=0; i<tam; i++)
            {
                if(lista[i].estado == OCUPADO)
                {
                    mostrarEmpleado(lista[i], sectores, ts);
                }
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            for(i=0; i<ts; i++){
                printf("\n%s:\n\n", sectores[i].descripcion);
                for(j=0; j<tam; j++){
                    if(lista[j].idSector == sectores[i].idSector && lista[j].estado == OCUPADO){
                        printf("%d - %s - %c - %.2f - %.2f\n", lista[j].legajo, lista[j].nombre, lista[j].sexo, lista[j].sueldoBruto, lista[j].sueldoNeto);
                    }
                }
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            for(i=0; i<ts; i++){
                printf("\n%s:\n\n", sectores[i].descripcion);
                auxListaSector[i].idSector = sectores[i].idSector;
                for(j=0; j<tam; j++){
                    if(lista[j].idSector == sectores[i].idSector && lista[j].estado == OCUPADO && flag == 0){
                        auxListaSector[i].acumSueldo += lista[j].sueldoNeto;
                    }
                }
                printf("Total de sueldos: %.2f\n", auxListaSector[i].acumSueldo);
            }
            flag = 1;
            printf("\n");
            system("pause");
            break;
        case 4:
            for(i=0; i<ts; i++){
                auxListaSector[i].idSector = sectores[i].idSector;
                auxListaSector[i].contEmpleados = 0;
                for(j=0; j<tam; j++){
                    if(lista[j].idSector == sectores[i].idSector && lista[j].estado == OCUPADO){
                        auxListaSector[i].contEmpleados++;
                    }
                    if(auxListaSector[i].contEmpleados > maxEmp || flag2 == 0){
                        maxEmp = auxListaSector[i].contEmpleados;
                        flag2 = 1;
                    }
                }
                printf("\nEl sector %s tiene %d empleados.", sectores[i].descripcion, auxListaSector[i].contEmpleados);
            }
            printf("\n\nSector/es con mayor cantidad de empleados:\n");
            for(i=0; i<ts; i++){
                if(auxListaSector[i].contEmpleados == maxEmp){
                    printf("\n%s - %d empleados.", sectores[i].descripcion, maxEmp);
                }
            }
            printf("\n\n");
            system("pause");
            break;
        case 5:
            break;
        default:
            printf("\nError: Opcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(opcion != 5);
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
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].sueldoBruto > maximo || flag == 0)
            {
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
        if(lista[i].estado == OCUPADO)
        {
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
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(stricmp(lista[i].nombre, "carlos") == 0 && lista[i].sueldoBruto > 5000)
            {
                cont++;
            }
        }
    }
    return cont;
}
