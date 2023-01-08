#include "postfija.h"

#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int);

PILA crearPila () {
	PILA S;
	S = (PILA) malloc (sizeof(pila));
	if(S == NULL) {
		manejaMsg(0);
		exit(0);
	}
	S -> tope = -1;
	return S;
}

/* Anadir un elemento a la Pila*/
void apilar (PILA S, float x) {
	if (S -> tope == TAM - 1) {
		manejaMsg(1);
		exit(0);
	}
	S -> tope++;
	S -> pila[S -> tope] = x;
}

int esPilaVacia (PILA S) {
	if(S -> tope == -1)	{
		return TRUE;
	}
	return FALSE;
}

/* Sacar un elemento de la Pila */
float desapilar (PILA S) {
	float a;
	if (esPilaVacia(S) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	a = S -> pila[S -> tope];
	(S -> tope)--;
	return a;
}