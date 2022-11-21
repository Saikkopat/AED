#include<stdlib.h>
#include "FraccionMixta.h"
#include<math.h>
void manejaMsg(int);
FRACCION crearFraccion(void){
 FRACCION F;
   F = (FRACCION)malloc(sizeof(FraccMixta));
   if( F == NULL){
         manejaMsg(0);
         exit(0);
    }
    return F;
}
void asignaEntero(FRACCION F, float e){
    F -> entero = e;
}

void asignaNum(FRACCION F, float n){
    F -> numerador = n;
}

void asignaDenom(FRACCION F, float d){
      F -> denominador = d;
}

float obtenNum(FRACCION F){
       return ( F -> numerador);
}

float obtenDenom(FRACCION F){
      return ( F -> denominador);
}

float obtenEntero(FRACCION F){
      return ( F -> entero);
}

FRACCION MixtaImpropia(FRACCION F){
    FRACCION F3;
    F3=crearFraccion();
    asignaNum(F3, (obtenEntero(F)*obtenDenom(F)+obtenNum(F)));
    asignaDenom(F3, obtenDenom(F));
    return F3;
}

float FraccionDecimal(FRACCION F){
    return (obtenNum(F)/obtenDenom(F));
}

FRACCION DecimalFraccion(float r){
    FRACCION F3;
    int i=1;
    float aux;
    F3=crearFraccion();
    //if(r>=1){
        asignaEntero(F3, (floor(r)));
        aux=r-obtenEntero(F3);
        while((aux-floor(aux))>0){
            aux=aux*10;
            i*=10;

        }

    //}

    asignaNum(F3, (aux));
    asignaDenom(F3, i);
    return F3;
}

FRACCION Simplificar(FRACCION F){//SIMPLIFICA LA FRACCION
    int Numint, Denomint;
    int aux=2;
    while(aux<obtenNum(F)){
        Numint=(int)obtenNum(F);
        Denomint=(int)obtenDenom(F);
        if((Numint%aux)==0){
            if((Denomint%aux)==0){
                asignaNum(F,(obtenNum(F)/aux));
                asignaDenom(F,(obtenDenom(F)/aux));
                aux=1;
            }
        }
        aux++;
        /*if(salida<=10){
            if(aux>=obtenNum(F)){
                aux=2;
                salida++;
            }
        }*/

    }
    return F;

}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
