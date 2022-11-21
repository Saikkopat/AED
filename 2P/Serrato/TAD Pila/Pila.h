#ifndef _Pila_
#define _Pila_
#define TAM 100
#define TRUE 1
#define FALSE 0
typedef struct {
   int pila[TAM];
   int tope;
} Pila;
typedef Pila *PILA;
PILA crearPila();
void apilar(PILA S, int e);
int desapilar(PILA S);
int es_vaciaPila(PILA S);
int elemTope(PILA S);
#endif  // PILA_H_INCLUDED
