#include "Entradas.h"
#define T 6
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char descripcion[20];
}eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
    eSector sector;
} eEmpleado;

void mostrarMenu(int);
void elegirOpcion();
void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int buscarLegajo(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);
void cargarEmpleado(eEmpleado [], int);
void mostrarListaEmpleados(eEmpleado [], int);
void mostrarEmpleado(eEmpleado);
void modificarDatos(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int);
float importeMaximo(eEmpleado[], int);
void buscarMayorSueldo(eEmpleado[], int);
int cantidadCarlos(eEmpleado[], int);
