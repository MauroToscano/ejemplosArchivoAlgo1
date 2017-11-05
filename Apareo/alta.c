#include <stdio.h>
#include <string.h>
#include "persona.h"

int main(){
    FILE* archivoAlta;
    FILE* archivoPersonas;
    FILE* archivoNuevo;
    TPersona personaADarDeAlta;
    TPersona personaYaExistente;
    
    archivoAlta = fopen("archivoAltas.dat", "r");
    archivoPersonas = fopen("archivoPersonas.dat","r");
    archivoNuevo = fopen("archivoNuevo.dat", "w");
    
    fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    fread(&personaADarDeAlta, sizeof(TPersona), 1, archivoAlta);

    //Mientras me queden personas a dar de alta
    while(!feof(archivoAlta)){
        
        //Mientras que no encontre a la primera persona con mayor numeroDeDgi
        //y si todavia tengo personas del archivo original
        //Debo seguir grabando las personas que ya estaban en el archivo original
        
        while(personaYaExistente.numeroDeDgi < personaADarDeAlta.numeroDeDgi &&
                !feof(archivoPersonas)){
            
            fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
            fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
        
        }
        
        //Cuando ya encontre a la persona que tiene mayor DGI, o no quedan mas de las originales
        //grabo la que iba a dar de alta.
        
        fwrite(&personaADarDeAlta, sizeof(TPersona), 1, archivoNuevo);
        fread(&personaADarDeAlta, sizeof(TPersona), 1, archivoAlta);
    }
    
    
    //Puede que haya dado de altas todas las personas que queria, y queden mas de las originales
    //Entonces si no se termino el archivo personas, grabo las que me quedan.
    while(!feof(archivoPersonas)){
        fwrite(&personaYaExistente, sizeof(TPersona), 1, archivoNuevo);
        fread(&personaYaExistente, sizeof(TPersona), 1, archivoPersonas);
    }
    
    fclose(archivoAlta);
    fclose(archivoPersonas);
    fclose(archivoNuevo);
    
    remove("archivoPersonas.dat");
    rename("archivoNuevo.dat", "archivoPersonas.dat");
}