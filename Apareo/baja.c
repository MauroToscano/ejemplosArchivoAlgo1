#include <stdio.h>
#include <string.h>
#include "persona.h"

int main(){
    FILE* archivoBajas;
    FILE* archivoPersonas;
    FILE* archivoNuevo;
    TPersona personaADarDeBaja;
    TPersona personaYaExistente;
    
    archivoBajas = fopen("archivoBajas.dat", "r");
    archivoPersonas = fopen("archivoPersonas.dat","r");
    archivoNuevo = fopen("archivoNuevo.dat", "w");
    
    fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    fread(&personaADarDeBaja, sizeof(TPersona), 1, archivoBajas);

    //Mientras me queden personas a dar de baja
    while(!feof(archivoBajas)){
        
        //Mientras que no encontre a la primera persona a dar de baja
        //Grabo a las personas que tienen que seguir estando
        
        while(personaYaExistente.numeroDeDgi != personaADarDeBaja.numeroDeDgi){
            
            fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
            fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
        
        }
        //Si encontre a la persona a dar de baja, paso a la siguiente y no la grabo
        
        fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
        fread(&personaADarDeBaja, sizeof(TPersona), 1, archivoBajas);
    }
    
    
    //Puede que haya dado de baja a todas las personas que queria, y queden mas de las originales
    //Entonces si no se termino el archivo personas, grabo las que me quedan.
    while(!feof(archivoPersonas)){
        fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
        fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    }
    
    fclose(archivoBajas);
    fclose(archivoPersonas);
    fclose(archivoNuevo);
    
    remove("archivoPersonas.dat");
    rename("archivoNuevo.dat", "archivoPersonas.dat");
}