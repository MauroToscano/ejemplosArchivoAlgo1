#include <stdio.h>
#include "persona.h"
#include <string.h>

void crearArchivoPersonas(){
    FILE* archivoPersonas = fopen("archivoPersonas.dat", "w");
    TPersona persona;
    
    strcpy(persona.nombre, "Palpatine");
    persona.numeroDeDgi = 66;
    fwrite(&persona,sizeof(TPersona), 1, archivoPersonas);
    
    strcpy(persona.nombre, "Obi Juan");
    persona.numeroDeDgi = 80; 
    fwrite(&persona,sizeof(TPersona), 1, archivoPersonas);
    
    strcpy(persona.nombre, "Yoda");
    persona.numeroDeDgi = 90; 
    fwrite(&persona,sizeof(TPersona), 1, archivoPersonas);
    
    fclose(archivoPersonas);
}

void crearArchivoAltas(){
    FILE* archivoAltas = fopen("archivoAltas.dat", "w");
    TPersona persona;
    
    strcpy(persona.nombre, "Anakin");
    persona.numeroDeDgi = 81; 
    fwrite(&persona,sizeof(TPersona), 1, archivoAltas);
    
    strcpy(persona.nombre, "Leia");
    persona.numeroDeDgi = 100; 
    fwrite(&persona,sizeof(TPersona), 1, archivoAltas);
    
    fclose(archivoAltas);
}

void crearArchivoBajas(){
    FILE* archivoBajas = fopen("archivoBajas.dat", "w");
    TPersona persona;
    
    strcpy(persona.nombre, "Obi Juan");
    persona.numeroDeDgi = 80; 
    fwrite(&persona,sizeof(TPersona), 1, archivoBajas);
    
    strcpy(persona.nombre, "Leia");
    persona.numeroDeDgi = 100; 
    fwrite(&persona,sizeof(TPersona), 1, archivoBajas);
    
    fclose(archivoBajas);
}

void crearArchivoModificaciones(){
    FILE* archivoModificaciones = fopen("archivoModificaciones.dat", "w");
    TPersona persona;
    
    strcpy(persona.nombre, "Darth Sidious");
    persona.numeroDeDgi = 66;
    fwrite(&persona,sizeof(TPersona), 1, archivoModificaciones);
    
    strcpy(persona.nombre, "Darth Vader");
    persona.numeroDeDgi = 81; 
    fwrite(&persona,sizeof(TPersona), 1, archivoModificaciones);
    
    fclose(archivoModificaciones);
}

int main(){
    crearArchivoPersonas();
    crearArchivoAltas();
    crearArchivoBajas();
    crearArchivoModificaciones();
}