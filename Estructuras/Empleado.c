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

void modificarDatos(eEmpleado lista[], int tam, eSector sectores[], int ts)
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
                auxLista[pos].cantHoras = getInt("nueva cantidad de horas: ");
                printf("\n");
                modificar = getChar("la letra 's' si desea llevar a cabo la modificacion: ");
                if(modificar == 's')
                {
                    lista[pos].cantHoras = auxLista[pos].cantHoras;
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
