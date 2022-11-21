#ifndef _complejo_
#define _complejo_
typedef struct{
    float r;
    float alfa;
}Polar;

typedef struct{
    float x;
    float y;
}Rectangular;

typedef struct{
    float real;
    float imaginario;
    Polar forma;
    Rectangular forma2;
}complejo;
typedef complejo *COMPLEJO;
//operaciones
COMPLEJO crearComplejo();
void asignaReal(COMPLEJO C, float r);
void asignaImaginario(COMPLEJO C, float i);
void asignaR(COMPLEJO C, float R);
void asignaAlfa(COMPLEJO C, float a);
void asignaImaginario(COMPLEJO C, float i);
void asignaXRectangular(COMPLEJO C, float x);
void asignaYRectangular(COMPLEJO C, float y);
float obtenReal(COMPLEJO C);
float obtenImaginario(COMPLEJO C);
float obtenR(COMPLEJO C);
float obtenAlfa(COMPLEJO C);
float obtenXRectangular(COMPLEJO C);
float obtenYRectangular(COMPLEJO C);
COMPLEJO suma(COMPLEJO C1, COMPLEJO C2);
COMPLEJO resta(COMPLEJO C1, COMPLEJO C2);
COMPLEJO escalar(COMPLEJO C1, float escalar);
float modulo(COMPLEJO C1);
COMPLEJO conjugado(COMPLEJO C1);
void transformarPolar(COMPLEJO C);
void convertirRectangular(COMPLEJO C);
#endif
