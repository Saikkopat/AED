#ifndef _fraccion_
#define _fraccion_
#define FALSE 0
#define TRUE 1

typedef struct {
   int numerador;
   int denominador;
} Fraccion;

typedef Fraccion * FRACCION;


FRACCION crearFraccion(void);
void asignaNum(FRACCION F, int n);
void asignaDenom(FRACCION F, int d);
int obtenNum(FRACCION F);
int obtenDenom(FRACCION F);
FRACCION producto(FRACCION F1, FRACCION F2);
FRACCION division(FRACCION F1, FRACCION F2);
int esImpropia(FRACCION F1);

#endif
