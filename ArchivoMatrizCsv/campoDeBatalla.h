#define MAX_FILA 1024
#define MAX_COLUMNA 1024

#define JEDI 'J'
#define SITH 'S'
#define VACIO 0

typedef struct CampoDeBatalla CampoDeBatalla;
struct CampoDeBatalla{
    int topeFila;
    int topeColumna;
    char casillero[MAX_FILA][MAX_COLUMNA];
};