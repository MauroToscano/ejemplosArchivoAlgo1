#include <stdio.h>
#include <string.h>
#include "persona.h"

int main(){
    FILE* archivoModificaciones;
    FILE* archivoPersonas;
    FILE* archivoNuevo;
    TPersona personaAModificar;
    TPersona personaYaExistente;
    
    archivoModificaciones = fopen("archivoModificaciones.dat", "r");
    archivoPersonas = fopen("archivoPersonas.dat","r");
    archivoNuevo = fopen("archivoNuevo.dat", "w");
    
    fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    fread(&personaAModificar, sizeof(TPersona), 1, archivoModificaciones);

    //Mientras me queden personas por modificar
    while(!feof(archivoModificaciones)){
        
        //Mientras que no encontre a la primera persona con igual numeroDeDgi
        //y si todavia tengo personas del archivo original
        //Debo seguir grabando las personas que ya estaban en el archivo original
        
        while(personaYaExistente.numeroDeDgi != personaAModificar.numeroDeDgi &&
                !feof(archivoPersonas)){
            
            fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
            fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
        
        }
        
        //Cuando ya encontre a la persona que voy a modificar
        
        fwrite(&personaAModificar, sizeof(TPersona), 1, archivoNuevo);
        fread(&personaAModificar, sizeof(TPersona), 1, archivoModificaciones);
        fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    }
    
    
    //Puede que haya dado de altas todas las personas que queria, y queden mas de las originales
    //Entonces si no se termino el archivo personas, grabo las que me quedan.
    while(!feof(archivoPersonas)){
        fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
        fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    }
    
    fclose(archivoModificaciones);
    fclose(archivoPersonas);
    fclose(archivoNuevo);
    
    remove("archivoPersonas.dat");
    rename("archivoNuevo.dat", "archivoPersonas.dat");
}