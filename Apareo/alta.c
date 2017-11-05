#include <stdio.h>
#include "persona.h"
#include <string.h>

int main(){
    FILE* archivoAlta;
    FILE* archivoPersonas;
    File* archivoNuevo;
    TPersona personaADarDeAlta;
    Tpersona personaYaExistente;
    
    archivoAlta = fopen("r", "archivoAlta.dat");
    archivoPersonas = fopen("r", "archivoPersonas.dat");
    archivoNuevo = fopen("w", "archivoNuevo.dat");
    
    fread(&personaYaExistente, sizeof(Persona), 1, archivoPersonas);
    fread(&personaADarDeAlta, sizeof(Persona), 1, archivoAlta);

    while(!eof(personaADarDeAlta)){
        while(personaYaExistente.codigoDeDgi < personaADarDeAlta.codigoDeDgi &&
                !eof(archivoPersonas)){
            fwrite(&personaYaExistente, sizeof(Persona), 1, archivoNuevo);
            fread(&personaYaExistente, sizeof(Persona), 1, archivoPersonas);
        }
        
        fwrite(&personaADarDeAlta, sizeof(Persona), 1, archivoNuevo);
        fread(&personaADarDeAlta, sizeof(Persona), 1, archivoAlta);
    }
    
    while(!eof(archivoPersonas)){
        fwrite(&personaYaExistente, sizeof(Persona), 1, archivoNuevo);
        fread(&personaYaExistente, sizeof(Persona), 1, archivoPersonas);
    }
    
    fclose(archivoAlta);
    fclose(archivoPersonas);
    fclose(archivoNuevo);
    
    remove("archivoPersonas.dat");
    rename("archivoNuevo.dat", "archivoPersonas.dat");
}

/*blanco con amarillo arriba
 * blanco con rojo a la derecha y naranja a la izquierda
 * Anotado en mente de Delfi