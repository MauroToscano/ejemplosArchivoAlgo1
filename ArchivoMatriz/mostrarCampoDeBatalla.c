#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "campoDeBatalla.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void cargarCampoDeBatalla(CampoDeBatalla* campoDeBatalla,char path[256]){
    FILE* archivoCampoDeBatalla = fopen(path, "r");
    fread(campoDeBatalla, sizeof(CampoDeBatalla), 1, archivoCampoDeBatalla);
    fclose(archivoCampoDeBatalla);
}

void otroCargarCampoDeBatalla(CampoDeBatalla* campoDeBatalla,char path[256]){
    FILE* archivoCampoDeBatalla = fopen(path, "r");
    fread(&campoDeBatalla->topeFila, sizeof(int), 1, archivoCampoDeBatalla);
    fread(&campoDeBatalla->topeColumna, sizeof(int), 1, archivoCampoDeBatalla);
    fread(campoDeBatalla->casillero, sizeof(campoDeBatalla->casillero), 1, archivoCampoDeBatalla);
    fclose(archivoCampoDeBatalla);
}

void printCampoDeBatalla(CampoDeBatalla* campoDeBatalla){   
    for(int i = 0; i < campoDeBatalla->topeFila; i++){
        for(int j = 0; j < campoDeBatalla->topeColumna; j++){
            switch(campoDeBatalla->casillero[i][j]){
                case JEDI:
                    printf("%sO",KBLU);
                    break;
                case SITH:
                    printf("%sO",KRED);
                    break;
                default: printf("%sX",KWHT);
            }
            
        }
        printf("\n");
    }
}

int main(){
    CampoDeBatalla campoDeBatalla;
    otroCargarCampoDeBatalla(&campoDeBatalla, "campoDeBatalla.dat");
    printCampoDeBatalla(&campoDeBatalla);
}
