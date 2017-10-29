#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "campoDeBatalla.h"

bool hayUnSithEn(int x, int y, int topeCol){
    bool haySith = false;
    if(y < (topeCol*0.20)){
        haySith = (rand() % 1000 < 200);
    }
    return haySith;
}

bool hayUnJediEn(int x, int y, int topeCol){
    bool hayJedi = false;
    if(y > topeCol*0.80){
        hayJedi = ((rand() % 1000) < 200);
    }
    return hayJedi;
}

void crearCampoDeBatalla(CampoDeBatalla* campoDeBatalla){
    srand(time(NULL));
    campoDeBatalla->topeFila = 20;
    campoDeBatalla->topeColumna = 60;
    for(int i = 0; i < campoDeBatalla->topeFila; i++){
        for(int j = 0; j < campoDeBatalla->topeColumna; j++){
            if(hayUnSithEn(i,j,campoDeBatalla->topeColumna)){
                campoDeBatalla->casillero[i][j] = SITH;
            }else if(hayUnJediEn(i,j,campoDeBatalla->topeColumna)){
                campoDeBatalla->casillero[i][j] = JEDI;
            }else{
                campoDeBatalla->casillero[i][j] = VACIO;
            }
        }
    }
}

void guardarCampoDeBatalla(CampoDeBatalla* campoDeBatalla){
    FILE* archivoCampoDeBatalla;
    archivoCampoDeBatalla = fopen("campoDeBatalla.dat","w");
    fwrite(campoDeBatalla, sizeof(*campoDeBatalla),1,archivoCampoDeBatalla);
    fclose(archivoCampoDeBatalla);
}

int main(){
    CampoDeBatalla campoDeBatalla;
    crearCampoDeBatalla(&campoDeBatalla);
    guardarCampoDeBatalla(&campoDeBatalla);
}
