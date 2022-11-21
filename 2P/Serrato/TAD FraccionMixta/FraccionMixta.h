#ifndef _FraccionMixta_
#define _FraccionMixta_
typedef struct{
    float entero;
    float numerador;
    float denominador;
}FraccMixta;
typedef FraccMixta *FRACCION;
//operaciones
FRACCION crearFraccion(void);
void asignaEntero(FRACCION F, float e);
void asignaNum(FRACCION F,  float n);
void asignaDenom(FRACCION F, float d);
float obtenNum(FRACCION F);
float obtenDenom(FRACCION F);
float obtenEntero(FRACCION F);
FRACCION MixtaImpropia(FRACCION F);
float FraccionDecimal(FRACCION F);
FRACCION DecimalFraccion(float r);
FRACCION Simplificar(FRACCION F);
#endif
 // FRACCIONMIXTA_H_INCLUDED
