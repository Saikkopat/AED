#include<stdlib.h>
#include "Complejo.h"
#include<math.h>

void manejaMsg(int);
COMPLEJO crearComplejo(){
    COMPLEJO C;
    C=(COMPLEJO)malloc(sizeof(complejo));
    if(C==NULL){
       manejaMsg(0);
       exit(0);
    }
    return C;
}

void asignaReal(COMPLEJO C, float r){
    C->real=r;
}

void asignaImaginario(COMPLEJO C, float i){
    C->imaginario=i;
}

void asignaR(COMPLEJO C, float R){
    C->forma.r=R;
}

void asignaAlfa(COMPLEJO C, float a){
    C->forma.alfa=a;
}

void asignaXRectangular(COMPLEJO C, float x){
    C->forma2.x=x;
}
void asignaYRectangular(COMPLEJO C, float y){
    C->forma2.y=y;
}

float obtenReal(COMPLEJO C){
    return(C->real);
}

float obtenImaginario(COMPLEJO C){
    return(C->imaginario);
}
float obtenR(COMPLEJO C){
    return(C->forma.r);
}
float obtenAlfa(COMPLEJO C){
    return(C->forma.alfa);
}
float obtenXRectangular(COMPLEJO C){
    return(C->forma2.x);
}
float obtenYRectangular(COMPLEJO C){
    return(C->forma2.y);
}
COMPLEJO suma(COMPLEJO C1, COMPLEJO C2){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3, obtenReal(C1)+obtenReal(C2));
    asignaImaginario(C3, obtenImaginario(C1)+obtenImaginario(C2));
    return C3;
}
COMPLEJO resta(COMPLEJO C1, COMPLEJO C2){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3, obtenReal(C1)-obtenReal(C2));
    asignaImaginario(C3, obtenImaginario(C1)-obtenImaginario(C2));
    return C3;
}

COMPLEJO escalar(COMPLEJO C1, float escalar){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3, obtenReal(C1)*escalar);
    asignaImaginario(C3, obtenImaginario(C1)*escalar);
    return C3;
}
float modulo(COMPLEJO C1){
    return (sqrt((pow(obtenReal(C1), 2))+(pow(obtenImaginario(C1), 2))));
}
COMPLEJO conjugado(COMPLEJO C1){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3, obtenReal(C1));
    asignaImaginario(C3, obtenImaginario(C1)*(-1));
    return C3;
}

void transformarPolar(COMPLEJO C){
    double tan, aux2;
    tan=((obtenImaginario(C))/(obtenReal(C)));
    asignaR(C, (modulo(C)));
    aux2=atan(tan);
    aux2=aux2*57.2958;
    asignaAlfa(C, aux2);

}

void convertirRectangular(COMPLEJO C){
    asignaXRectangular(C, ((obtenR(C))*(cos((obtenAlfa(C))))));
    asignaYRectangular(C, ((obtenR(C))*(sin((obtenAlfa(C))))));
}

