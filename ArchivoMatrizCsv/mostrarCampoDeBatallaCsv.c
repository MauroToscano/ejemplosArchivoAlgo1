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

void ponerTodosLosCasillerosVaciosEnEl(CampoDeBatalla* campoDeBatalla){
    for(int i = 0; i < campoDeBatalla->topeFila; i++){
        for(int j = 0; j < campoDeBatalla->topeColumna; j++){
            campoDeBatalla->casillero[i][j] = VACIO;
        }
    }
}

void cargarCampoDeBatalla(CampoDeBatalla* campoDeBatalla,char path[256]){
    char c;
    int i,j;
    FILE* archivoCampoDeBatalla = fopen(path, "r");
    fscanf(archivoCampoDeBatalla, "%i,%i\n",&campoDeBatalla->topeFila, &campoDeBatalla->topeColumna);
    ponerTodosLosCasillerosVaciosEnEl(campoDeBatalla);
    while(!feof(archivoCampoDeBatalla)){
        fscanf(archivoCampoDeBatalla, "%i,%i,%c\n", &i, &j, &c);
        campoDeBatalla->casillero[i][j] = c;
    }
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
    cargarCampoDeBatalla(&campoDeBatalla, "campoDeBatalla.csv");
    printCampoDeBatalla(&campoDeBatalla);
}
