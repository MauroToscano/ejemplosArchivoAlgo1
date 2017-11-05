#include "persona.h"
#include <stdio.h>

void imprimirMenu(){
    printf("Ingrese P para ver la tabla de personas\n");
    printf("Ingrese A para ver la tabla de altas\n");
    printf("Ingrese B para ver la tabla de bajas\n");
    printf("Ingrese M para ver la tabla de modificaciones\n\n");
}

FILE* abrirArchivoSegun(char unCaracterIngresado){
    FILE* archivo;
    
    switch ( unCaracterIngresado){
        case 'A':
            archivo = fopen("archivoAltas.dat", "r");
            break;
        case 'P':
            archivo = fopen("archivoPersonas.dat", "r");
            break;
        case 'M':
            archivo = fopen("archivoModificaciones.dat", "r");
            break;
        case 'B':
            archivo = fopen("archivoBajas.dat", "r");
            break;
    }
    
    return archivo;
}

int main(){
    char caracterIngresado;
    imprimirMenu();
    scanf("%c", &caracterIngresado);
    FILE* archivo = abrirArchivoSegun(caracterIngresado);
    
    TPersona persona;
    fread(&persona,sizeof(persona),1,archivo);
    while(!feof(archivo)){
        printf("\nDGI: %llu \n Nombre: %s\n", persona.numeroDeDgi, 
                persona.nombre);
        fread(&persona,sizeof(persona),1,archivo);
    }
    
    fclose(archivo);
}