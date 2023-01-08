#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

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

int esPilaVacia (PILA S) {
	if(S -> tope == -1)	{
		return TRUE;
	}
	return FALSE;
}

void apilar (PILA S, char e) {
	if (S -> tope == TAM - 1) {
		manejaMsg(2);
		exit(0);
	}
	(S -> tope)++;
	S -> pila[S -> tope] = e;
}

char desapilar (PILA S) {
	char a;
	if (esPilaVacia(S) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	a = S -> pila[S -> tope];
	(S -> tope)--;
	return a;
}

char elemTope (PILA S) {
	char a;
	if (esPilaVacia(S) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	a = S -> pila[S -> tope];
	return a;
}