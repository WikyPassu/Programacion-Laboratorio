#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* // Modo escritura
    FILE* myFile;
    int* x = (int*) malloc(sizeof(int));
    *x = 4;
    myFile = fopen("D:\\Alan Passucci\\datos.txt", "wb");

    if(myFile != NULL)
    {
        fwrite(x, sizeof(int), 1, myFile); // Direccion, tamaño del dato, cantidad que quiero escribir, mi archivo.
        fclose(myFile);
        printf("Archivo escrito con exito.\n");
    }
    else
    {
        printf("Error.\n");
    }
    */

    // Modo lectura
    FILE* myFile;
    int* x = (int*) malloc(sizeof(int));

    myFile = fopen("D:\\Alan Passucci\\datos.txt", "rb");

    if(myFile != NULL)
    {
        fread(x, sizeof(int), 1, myFile); // Leer, mismos parametros que fwrite.
        fclose(myFile);
        printf("%d\n", *x);
    }
    else
    {
        printf("Error.\n");
    }

    return 0;
}
