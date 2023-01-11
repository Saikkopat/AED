#include <stdio.h>
#include <stdlib.h>

#include "listaDoble.h"

void manejaError(int msg);

// Creación de una lista vacía.
LISTADOBLE crearLista() {
	LISTADOBLE L;
	L = NULL;
	return L;
}

// Verifica si está vacía la lista.
int esVaciaLista(LISTADOBLE L) {
	if (L == NULL)
		return TRUE;
	else
		return FALSE;
}

// Crea un elemento de la lista.
nodoListaDoble *crearNodoLista() {
	nodoListaDoble *nvo;
	nvo = (nodoListaDoble *)malloc(sizeof(nodoListaDoble));
	if (nvo == NULL) {
		manejaError(0);
		exit(0);
	}
	nvo -> siguiente = NULL;
	nvo -> anterior = NULL;
	return nvo;
}


// Agregar un elemento a la lista.
LISTADOBLE insertar(LISTADOBLE L, int e) {
	nodoListaDoble *nvo;
	nodoListaDoble *aux, *aux2;
	nvo = crearNodoLista();
	nvo -> dato = e;
	if (esVaciaLista(L) == TRUE) {
		L = nvo;
	} else {
		aux = L;
		while (aux != NULL) {
		aux2 = aux;
		aux = aux -> siguiente;
		}
		aux2 -> siguiente = nvo;
		nvo -> anterior = aux2;
	}
	return L;
}

// Mostrar los elementos de la lista.
void mostrarLista(LISTADOBLE L) {
	nodoListaDoble *aux;
	int pos;
	aux = L;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	pos = 1;
	mensajes(0, 3, 0);
	while (aux != NULL) {
		mensajes(aux -> dato, 1, pos);
		pos++;
		aux = aux -> siguiente;
	}
}

// Buscar un elemento de la lista.
void buscarElem(LISTADOBLE L, int elem) {
	nodoListaDoble *aux;
	int pos = 1;
	aux = L;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	while (aux != NULL && aux -> dato != elem) {
		aux = aux -> siguiente;
		pos++;
	}
	pos++;
	if (aux == NULL)
		mensajes(elem, 0, 0); //No se encuentra el elemento.
	else
		mensajes(elem, 2, pos); //Indica la posición.
}

//Borrar un elemento de la lista.
LISTADOBLE borrar(LISTADOBLE L, int elem) {
	nodoListaDoble *aux, *aux2;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	aux = L;
	aux2 = L;
	while (aux != NULL && elem != aux -> dato) {
		aux2 = aux;
		aux = aux -> siguiente;
	}
	if (aux == NULL)
		mensajes(elem, 0, 0); //No se encontró.
	else if (aux2 == aux) {
		L = aux2 -> siguiente; //Elemento se encuentra al inicio
		if (aux2 -> siguiente != NULL) 
			L -> anterior = NULL;
		free(aux2);
	} else {
		aux2 -> siguiente = aux -> siguiente; //Elemento se encuentra en cualquier otra posición.
		if (aux -> siguiente != NULL)
			aux -> siguiente -> anterior = aux -> anterior;
		free(aux);
	}
	return L;
}

void mostrarListaInvertida(LISTADOBLE L){
	nodoListaDoble *aux, *aux2;
	int pos;
	aux = L;
	if (esVaciaLista(L) == TRUE) {
		manejaError(1); //Lista vacía.
		exit(0);
	}
	pos = 1;
	mensajes(0, 4, 0);
	while (aux != NULL) {
		pos++;
		aux2 = aux;
		aux = aux -> siguiente;
	}
	aux = aux2;
	while (aux != NULL) {
		pos--;
		mensajes(aux -> dato, 1, pos);
		aux = aux -> anterior;
	}
}


void mensajes(int e, int msg, int p) {
	switch (msg) {
		case 0:
			printf("\n  El elemento %d no se encuentra en la lista doble.\n", e);
			break;
		case 1:
			printf("   Nodo #%d = %d\n",p,e);
			break;
		case 2:
			printf("\n  El elemento %d se encuentra en la posición #%d\n", e, p);
			break;
		case 3:
			printf("\n  Elementos de la Lista Doble:\n");
			break;
		case 4:
			printf("\n  Elementos de la Lista Doble Invertidos:\n");
			break;
		default:
			printf("\n\n  Opción no válida.\n");
			break;
	}
}