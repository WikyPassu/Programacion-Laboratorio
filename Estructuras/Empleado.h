#include "Entradas.h"
#define T 10
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idSector;
    float acumSueldo;
    int contEmpleados;
} auxSector;

typedef struct
{
    int idSector;
    char descripcion[20];
    float valor;
} eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int cantHoras;
    int idSector;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
    eSector sector;
} eEmpleado;

void mostrarMenu(int);
void elegirOpcion();
void hardcodearDatosEmpleados(eEmpleado[], int);

void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int buscarLegajo(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);
void cargarEmpleado(eEmpleado [], int, eSector[], int);
eSector pedirSector(eSector[], int);
void modificarDatos(eEmpleado[], int, eSector[], int);
void mostrarListaEmpleados(eEmpleado [], int, eSector[], int);
void mostrarEmpleado(eEmpleado, eSector[], int);

float importeMaximo(eEmpleado[], int);
void buscarMayorSueldo(eEmpleado[], int, eSector[], int);
int cantidadCarlos(eEmpleado[], int);
