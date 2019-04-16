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

void mostrarMenu(int);
void elegirOpcion();
void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int buscarUno(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);
void cargarEmpleado(eEmpleado [], int);
void mostrarListaEmpleados(eEmpleado [], int);
void mostrarEmpleado(eEmpleado);
void modificarDatos(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int);
