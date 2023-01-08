#include <stdio.h>
#include <stdlib.h>
#include "pilaDina.h"

void manejaMsg(int);

PILA crearPila () {
	PILA S;
	S = (PILA)malloc(sizeof(Pila));
	if (S == NULL) {
		manejaMsg(0);
		exit(0);
	}
	S->tope = NULL;
	return S;
}

// ESTA VACÍA LA PILA
int es_vaciaPila (PILA S) {
	if (S->tope == NULL)
		return TRUE;
	else
		return FALSE;
}

// CREA UN ELEMENTO DE LA PILA
nodoPila *crearNodoPila () {
	nodoPila *nvo;
	nvo = (nodoPila *)malloc(sizeof(nodoPila));
	if (nvo == NULL) {
		manejaMsg(0);
		exit(0);
	}
	return nvo;
}

// CONSULTAR EL ELEMENTO DEL TOPE LA PILA

char elemTope (PILA S) {
	char v;
	if (es_vaciaPila(S) == TRUE) {
		manejaMsg(3);  //PILA VACIA
		exit(0);
	}
	v = S->tope->dato;
	return v;
}

// AGREGAR ELEMENTOS A LA PILA
void apilar (PILA S, char e) {
	nodoPila *nvo;
	nvo = crearNodoPila();
	nvo -> dato = e;
	nvo -> anterior = S -> tope;
	S -> tope = nvo;
}

// ELIMINAR UN ELEMENTO DE LA PILA
char desapilar (PILA S) {
	char v;
	nodoPila *aux;
	if (es_vaciaPila(S) == TRUE) {
		manejaMsg(3);  //PILA VACIA
		exit(0);
	}
	aux = crearNodoPila();
	aux = S -> tope;
	v = aux -> dato;
	S -> tope = aux -> anterior;
	free(aux);
	return v;
}