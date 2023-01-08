#ifndef _pila_
#define _pila_
#define TAM 100
#define FALSE 0
#define TRUE 1

typedef struct {
	int pila [TAM];
	int tope;
} pila;

typedef pila * PILA;

PILA crearPila();
void apilar (PILA S, int e);
int desapilar (PILA S);
int esPilaVacia (PILA S);
int elemTope (PILA S);


#endif