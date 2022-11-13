#include <stdio.h>
#include <stdlib.h>
#include "Fraccion.h"

void manejaMsg (int);

FRACCION crearFraccion (void) {
   FRACCION F;
   F = (FRACCION)malloc(sizeof(Fraccion));
   if (F == NULL) {
      manejaMsg(0);
      exit(0);
   }
   return F;
}
void asignaNum (FRACCION F, int n) { F->numerador = n; }

void asignaDenom (FRACCION F, int d) { F->denominador = d; }

int obtenNum (FRACCION F) { return (F->numerador); }

int obtenDenom (FRACCION F) { return (F->denominador); }

FRACCION producto (FRACCION F1, FRACCION F2) {
   FRACCION prod = crearFraccion();
   asignaNum(prod, obtenNum(F1) * obtenNum(F2));
   asignaDenom(prod, obtenDenom(F1) * obtenDenom(F2));
   return prod;
}

FRACCION division (FRACCION F1, FRACCION F2) {
   FRACCION F3;
   F3 = crearFraccion();
   asignaNum(F3, obtenNum(F1) * obtenDenom(F2));
   asignaDenom(F3, obtenDenom(F1) * obtenNum(F1));
   return F3;
}

int esImpropia (FRACCION F1) {
   if (obtenNum(F1) > obtenDenom(F1))
      return TRUE;
   else
      return FALSE;
}
