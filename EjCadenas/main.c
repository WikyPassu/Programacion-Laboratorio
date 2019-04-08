#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, flag = 0;
    char nombre[20], apellido[20], apellidoNombre[50];
    printf("Ingrese nombre: ");
    gets(nombre);
    printf("Ingrese apellido: ");
    gets(apellido);

    strlwr(nombre);
    strlwr(apellido);

    for(i = 0; i < strlen(nombre); i++){
        if(flag == 0 && nombre[i] != 32){
            nombre[i] = toupper(nombre[i]);
            flag = 1;
        }
        if(nombre[i] == 32){
            flag = 0;
        }
    }
    flag = 0;
    for(i = 0; i < strlen(apellido); i++){
        if(flag == 0 && apellido[i] != 32){
            apellido[i] = toupper(apellido[i]);
            flag = 1;
        }
        if(apellido[i] == 32){
            flag = 0;
        }
    }

    strcpy(apellidoNombre,apellido);
    strcat(apellidoNombre,", ");
    strcat(apellidoNombre,nombre);

    printf("\n%s\n", apellidoNombre);

    return 0;
}

/*
int main()
{
    char nombre[15], apellido[15], auxNombre[2], auxApellido[2];

    printf("Ingrese nombre: ");
    gets(nombre);
    printf("Ingrese apellido: ");
    gets(apellido);

    strlwr(nombre);
    strlwr(apellido);
    strncpy(auxNombre,nombre,1);
    strupr(auxNombre);
    strncpy(auxApellido,apellido,1);
    strupr(auxApellido);

    nombre[0] = auxNombre[0];
    apellido[0] = auxApellido[0];

    printf("\n%s, %s\n", apellido, nombre);
    return 0;
}
*/
