#include <stdio.h>
#include <stdlib.h>
#include "FraccionMixta.h"
void manejaMsg(int);
void darFracciones(FRACCION);
void mostrarImpropia(FRACCION);
void mostrarDecimal(float);
void SolDec(float *);
void mostrarDecimal2(FRACCION);
void main(){
    FRACCION F1, F2;
    float dec, dec2;
    F1=crearFraccion();
    F2=crearFraccion();
    darFracciones(F1);
    F2=MixtaImpropia(F1);
    mostrarImpropia(F2);
    dec=FraccionDecimal(F2);
    mostrarDecimal(dec);
    SolDec(&dec2);
    F2=DecimalFraccion(dec2);
    F2=Simplificar(F2);
    mostrarDecimal2(F2);



}

void darFracciones(FRACCION F1){
     float e, n, d;
     printf("Dar el entero de la fraccion 1: \n");
     scanf("%f", &e);
     asignaEntero(F1, e);
     printf("Dar el numerador de la fraccion 1\n");
     scanf("%f", &n);
     asignaNum(F1, n);
     printf("Dar el denominador de la fraccion 1\n");
     scanf("%f", &d);
     asignaDenom(F1, d);
}


void mostrarImpropia(FRACCION F){
    printf("La fraccion impropia es %f/%f \n", obtenNum(F), obtenDenom(F));
}

void mostrarDecimal(float dec){
    printf("El decimal de la fraccion impropia es %f \n", dec);
}

void SolDec(float *dec){
    printf("Escribe el decimal que quieres convertir: \n");
    scanf("%f", dec);
}

void mostrarDecimal2(FRACCION F){
    printf("La fraccion impropia es %.1lf %.1lf/%.1lf \n", obtenEntero(F), obtenNum(F), obtenDenom(F));
}
