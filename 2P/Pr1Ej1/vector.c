#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void manejaMsg(int);

VECTOR crearVector (int t) {
	VECTOR V;
	V = (VECTOR) malloc (sizeof(vector));
	if (V == NULL) {
		manejaMsg(0);
		exit(0);
	}
	V -> vec = (int *) malloc (t * sizeof(int));
	V -> tam = t;
	return V;
}

void ponComponente (VECTOR V, int p, int e) {
    V -> vec[p] = e;
}

int obtenComponente (VECTOR V, int p) {
    if (V == NULL) {
		manejaMsg(0);
		exit(0);
	}
    return V -> vec[p];
}

int tamano(VECTOR V) {
	if (V == NULL) {
		manejaMsg(0);
		exit(0);
	}
	return V -> tam;
}
