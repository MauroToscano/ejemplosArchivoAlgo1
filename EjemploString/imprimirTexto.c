#include <stdio.h>
/*
void cargarUn(char texto[1024], char ruta[256]){
    FILE* archivoTexto = fopen(ruta, "r");
    fscanf(archivoTexto, "%s", texto);
    fclose(archivoTexto);
}
*/

/*
void cargarUn(char texto[1024], char ruta[256]){
    FILE* archivoTexto = fopen(ruta, "r");
    fscanf(archivoTexto, "%[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz, \n]", texto);
    fclose(archivoTexto);
}
*/

/*
void cargarUn(char texto[1024], char ruta[256]){
    FILE* archivoTexto = fopen(ruta, "r");
    fscanf(archivoTexto, "%[^ETX]", texto);
    fclose(archivoTexto);
}*/

void cargarUn(char texto[1024], char ruta[256]){
    FILE* archivoTexto = fopen(ruta, "r");
    fscanf(archivoTexto, "%[^\n]", texto);
    fclose(archivoTexto);
}

int main(){
    char texto[1024];
    cargarUn(texto, "texto.txt");
    printf("%s", texto);
}

