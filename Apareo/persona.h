#ifndef PERSONA
#define PERSONA

typedef struct TPersona TPersona;

struct TPersona{
    unsigned long long int numeroDeDgi; // Documento Galactico de Identidad
    char nombre[256];
};
#endif