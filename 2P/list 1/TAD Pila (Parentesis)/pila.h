#ifndef _pila_
#define _pila_
#define TAM 100
#define FALSE 0
#define TRUE 1

typedef struct {
	char pila [TAM];
	int tope;
} pila;

typedef pila * PILA;

PILA crearPila();
void apilar (PILA S, char e);
char desapilar (PILA S);
int esPilaVacia (PILA S);
char elemTope (PILA S);


#endif