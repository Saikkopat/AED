#ifndef _Ecuacion_
#define _Ecuacion_
#include<stdbool.h>
typedef struct{
    float a;
    float b;
    float c;
    float x1;
    float x2;
    float ptR;
    float ptImag;
    float dosA;

}Ecuacion;
typedef Ecuacion *ECUACION;
ECUACION CrearEcuacion();
void asignaA(ECUACION E, float A);
void asignaB(ECUACION E, float B);
void asignaC(ECUACION E, float C);
void asignaC(ECUACION E, float C);
void asignaX1(ECUACION E, float X1);
void asignaX2(ECUACION E, float X2);
void asignaPtReal(ECUACION E, float r);
void asignaPtImag(ECUACION E, float i);
void asignaDosA(ECUACION E, float dos);
float obtenA(ECUACION E);
float obtenB(ECUACION E);
float obtenC(ECUACION E);
float obtenX1(ECUACION E);
float obtenX2(ECUACION E);
float obtenPtReal(ECUACION E);
float obtenPtImag(ECUACION E);
float obtenDosA(ECUACION E);
ECUACION Chicharronera(ECUACION E);
bool verificador(ECUACION E);
ECUACION controlador(ECUACION E);
ECUACION asignaImaginario(ECUACION E);

#endif
