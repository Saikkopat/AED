#include<stdlib.h>
#include "Ecuacion.h"
#include<math.h>
#include<stdbool.h>
void manejaMsg(int);
ECUACION CrearEcuacion(){
    ECUACION E;
    E=(ECUACION)malloc(sizeof(Ecuacion));
     if(E == NULL){
         manejaMsg(0);
         exit(0);
    }
    return E;
}

void asignaA(ECUACION E, float A){
    E->a=A;
}
void asignaB(ECUACION E, float B){
    E->b=B;
}
void asignaC(ECUACION E, float C){
    E->c=C;
}
void asignaX1(ECUACION E, float X1){
    E->x1=X1;
}
void asignaX2(ECUACION E, float X2){
    E->x2=X2;
}
void asignaPtReal(ECUACION E, float r){
    E->ptR=r;
}
void asignaPtImag(ECUACION E, float i){
    E->ptImag=i;
}

void asignaDosA(ECUACION E, float dos){
    E->dosA=dos;
}
float obtenA(ECUACION E){
    return (E->a);
}
float obtenB(ECUACION E){
    return (E->b);
}
float obtenC(ECUACION E){
    return (E->c);
}

float obtenX1(ECUACION E){
    return (E->x1);
}
float obtenX2(ECUACION E){
    return (E->x2);
}
float obtenPtReal(ECUACION E){
    return (E->ptR);
}
float obtenPtImag(ECUACION E){
    return (E->ptImag);
}

float obtenDosA(ECUACION E){
    return (E->dosA);
}
ECUACION Chicharronera(ECUACION E){
    float pt1, pt2;
    pt1=((-1)*(obtenB(E))+sqrt(pow((obtenB(E)), 2)-4*(obtenA(E))*(obtenC(E))))/(2*(obtenA(E)));
    pt2=((-1)*(obtenB(E))-sqrt((pow((obtenB(E)), 2))-4*(obtenA(E))*(obtenC(E))))/(2*(obtenA(E)));
    asignaX1(E, pt1);
    asignaX2(E, pt2);
    return E;
}

bool verificador(ECUACION E){
    float comprobador;
    comprobador=(pow((obtenB(E)), 2))-4*(obtenA(E))*(obtenC(E));
    if(comprobador>=0){
        return true;
    }
    return false;
}

ECUACION controlador(ECUACION E){
    ECUACION E2;
    E2=CrearEcuacion();
    bool resp;
    resp=verificador(E);
    if(resp==true){
        E2=Chicharronera(E);
    }else{
        E2=asignaImaginario(E);
    }
    return E2;
}
ECUACION asignaImaginario(ECUACION E){
    float comprobador;
    comprobador=(pow((obtenB(E)), 2))-4*(obtenA(E))*(obtenC(E));
    asignaPtReal(E, (obtenB(E)/2*(obtenA(E))));
    asignaPtImag(E, comprobador);
    asignaDosA(E, (2*(obtenA(E))));
    return E;
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
