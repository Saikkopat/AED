#include <stdio.h>
#include <stdlib.h>
#include "Ecuacion.h"
#include<stdbool.h>
void manejaMsg(int);
void mostrarRaices(ECUACION);
void solicitarDatos(ECUACION);
void decision(ECUACION, bool);
void imprimirReal(ECUACION);
void imprimirImag(ECUACION);
void liberar(ECUACION);
void main(){
    ECUACION E1;
    bool resp;
    E1=CrearEcuacion();
    solicitarDatos(E1);
    E1=controlador(E1);
    resp=verificador(E1);
    decision(E1, resp);
    liberar(E1);


}

void mostrarRaices(ECUACION E1){
    printf("El resultado de la raiz 1 es %.1lf", obtenX1(E1));
    printf("El resultado de la raiz 2 es %.1lf", obtenX2(E1));
}

void solicitarDatos(ECUACION E1){
    float coef1, coef2, coef3;
    printf("Inserta el coeficiente de A: \n");
    scanf("%f", &coef1);
    asignaA(E1, coef1);
    printf("Inserta el coeficiente de B: \n");
    scanf("%f", &coef2);
    asignaB(E1, coef2);
    printf("Inserta el coeficiente de C: \n");
    scanf("%f", &coef3);
    asignaC(E1, coef3);
}

void decision(ECUACION E, bool resp){
    if(resp==true){
        imprimirReal(E);
    }else{
        imprimirImag(E);
    }
}

void imprimirReal(ECUACION E){
    printf("El resultado de la raiz 1 es %.1lf \n", obtenX1(E));
    printf("El resultado de la raiz 2 es %.1lf \n", obtenX2(E));
}

void imprimirImag(ECUACION E){
    printf("El resultado de la raiz 1 es %.1lf + raiz(%.1lf)/ %.1lf \n", obtenPtReal(E), obtenPtImag(E), obtenDosA(E));
    printf("El resultado de la raiz 1 es %.1lf - raiz(%.1lf)/ %.1lf \n", obtenPtReal(E), obtenPtImag(E), obtenDosA(E));
}

void liberar(ECUACION E){
    free(E);
    manejaMsg(1);
}
