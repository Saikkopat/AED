#include <stdio.h>
#include <stdlib.h>

#include "listaSimple.h"

void manejaError(int msg);

// Creación de una lista vacía.
LISTA crearLista() {
	LISTA L;
	L = NULL;
	return L;
}

// Verifica si está vacía la lista.
int esVaciaLista(LISTA L) {
	if (L == NULL)
		return TRUE;
	else
		return FALSE;
}

// Crea un elemento de la lista.
nodoLista *crearNodoLista() {
	nodoLista *nvo;
	nvo = (nodoLista *)malloc(sizeof(nodoLista));
	if (nvo == NULL) {
		manejaError(0);
		exit(0);
	}
	return nvo;
}


// Agregar un elemento a la lista.
LISTA insertar(LISTA L, int e) {
	nodoLista *nvo;
	nodoLista *actual, *anterior;
	nvo = crearNodoLista();
	nvo -> dato = e;
	if (esVaciaLista(L) == TRUE) {
		nvo -> siguiente = NULL;
		L = nvo;
	} else {
		actual = L;
		while (actual != NULL) {
		anterior = actual;
		actual = actual -> siguiente;
		}
		nvo -> siguiente = NULL;
		anterior -> siguiente = nvo;
	}
	return L;
}

// Mostrar los elementos de la lista.
void mostrarLista(LISTA L) {
	nodoLista *actual;
	int pos;
	actual = L;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	pos = 1;
	mensajes(0, 3, 0);
	while (actual != NULL) {
		mensajes(actual -> dato, 1, pos);
		pos++;
		actual = actual -> siguiente;
	}
}

// Buscar un elemento de la lista.
void buscarElem(LISTA L, int elem) {
	nodoLista *actual;
	int pos = 1;
	actual = L;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	while (actual != NULL && actual -> dato != elem) {
		actual = actual -> siguiente;
		pos++;
	}
	pos++;
	if (actual == NULL)
		mensajes(elem, 0, 0); //No se encuentra el elemento.
	else
		mensajes(elem, 2, pos); //Indica la posición.
}

//Borrar un elemento de la lista.
LISTA borrar(LISTA L, int elem) {
	nodoLista *actual, *anterior;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	actual = L;
	anterior = L;
	while (actual != NULL && elem != actual -> dato) {
		anterior = actual;
		actual = actual -> siguiente;
	}
	if (actual == NULL)
		mensajes(elem, 0, 0); //No se encontró.
	else if (anterior == actual) {
		L = anterior -> siguiente; //Elemento se encuentra al inicio
		free(anterior);
	} else {
		anterior -> siguiente = actual -> siguiente; //Elemento se encuentra en cualquier otra posición.
		free(actual);
	}
	return L;
}

void mensajes(int e, int msg, int p) {
	switch (msg) {
		case 0:
			printf("\n  El elemento %d no se encuentra en la lista\n", e);
			break;
		case 1:
			printf("   Nodo %d = %d\n",p,e);
			break;
		case 2:
			printf("\n  El elemento %d se encuentra en la posición %d\n", e, p);
			break;
		case 3:
			printf("\n  Elementos de la lista:\n");
			break;
		default:
			printf("\n\n  Opción no válida.\n");
			break;
	}
}