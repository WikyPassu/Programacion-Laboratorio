#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entradas.h"
#include "Empleado.h"

int main()
{
    elegirOpcion();
    return 0;
}

void mostrarMenu(int tipoMenu)
{
    system("cls");
    if(tipoMenu == 0)
    {
        printf("--------------------------------------\n");
        printf("\n 1. Dar de alta a un empleado.");
        printf("\n 2. Dar de baja a un empleado.");
        printf("\n 3. Modificar datos.");
        printf("\n 4. Informar sobre...");
        printf("\n 5. Informar mayor/es sueldo/s bruto.");
        printf("\n 6. Salir.\n\n");
        printf("--------------------------------------\n\n");
    }
    else if(tipoMenu == 1)
    {
        printf("-----------------------------------\n");
        printf("\n 1. Modificar nombre.");
        printf("\n 2. Modificar sexo.");
        printf("\n 3. Modificar cantidad de horas.");
        printf("\n 4. Modificar sector.");
        printf("\n 5. Salir.\n\n");
        printf("-----------------------------------\n\n");
    }
    else if(tipoMenu == 2){
        printf("---------------------------------------------\n");
        printf("\n 1. Mostrar todos los empleados.");
        printf("\n 2. Mostrar todos los empleados por sector.");
        printf("\n 3. Mostrar total de sueldos por sector.");
        printf("\n 4. Mostrar el sector con mas empleados.");
        printf("\n 5. Salir.\n\n");
        printf("---------------------------------------------\n\n");
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
                    modificarDatos(lista, T, sectores, 3);
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
                    system("pause");
                }

                break;
            case 5:
                buscarMayorSueldo(lista, T, sectores, 3);
                printf("\nSe llaman Carlos y tienen sueldo mayor a $5000: %d\n\n", cantidadCarlos(lista, T));
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
