#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Modo escritura

    FILE* myFile;
    char name[20] = "Alan";
    myFile = fopen("D:\\Alan Passucci\\misdatos.txt", "w"); // Primer paso: Abro el archivo para escritura de texto.
    if(myFile != NULL)
    {
        fprintf(myFile, "Su nombre es:\n%s", name);
        fclose(myFile);
        printf("Archivo escrito con exito.\n");
    }
    else
    {
        printf("Error.\n");
    }

    */ // Modo lectura

    FILE* myFile;
    char name[20];
    myFile = fopen("D:\\Alan Passucci\\misdatos.txt", "r");
    if(myFile != NULL)
    {
        while(!feof(myFile)) // Mientras no sea el final del archivo...
        {
            fgets(name, 30, myFile);
            printf("%s", name);
        }
        printf("\n");
        //fgets(name, 30, myFile); Variable donde guardo, longitud de 30 (un poco mas), mi archivo.
        //printf("%s\n", name);
        fclose(myFile);
    }
    else
    {
        printf("Error.\n");
    }

    return 0;
}
