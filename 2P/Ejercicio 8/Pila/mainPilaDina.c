#include "pilaDina.h"
#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int msg) {
	char *mensajes[4] = {"\n   No hay memoria disponible.\n",
								"\n   Memoria liberada.",
								"\n   Pila llena.\n",
								"\n   Pila vacia.\n"};
	printf("%s", mensajes[msg]);
}

void liberarMemoria(PILA S) {
	free(S);
	manejaMsg(1);
}

void llenarPila(PILA P) {
	int pos = 0;
	char cadena[100];
	printf("\tIngresa los caracteres: ");
	while ((cadena[pos++] = getchar()) != '\n');
	cadena[--pos] = '\0';
	pos = 0;
	while (cadena[pos] != '\0') {
		apilar(P, cadena[pos]);
		pos++;
	};
}

void mostrarPila(PILA S) {
	PILA temp = crearPila();
	int cont = 0;
	char e;
	while (es_vaciaPila(S) == FALSE)
		apilar(temp, desapilar(S));
	printf("\n  Elementos de la pila:\n");
	while (es_vaciaPila(temp) == FALSE) {
		e = desapilar(temp);
		printf("   %d :", cont);
		printf(" %c\n", e);
		apilar(S, e);
		cont++;
	}
	liberarMemoria(temp);
}

PILA mezclar (PILA A, PILA B) {
	PILA cA, C;
	C = crearPila();
	cA = crearPila();
	while (es_vaciaPila(A) == FALSE)
		apilar(cA, desapilar(A));
	while (es_vaciaPila(cA) == FALSE) {
		apilar(C, desapilar(cA));
		if (es_vaciaPila(B) == FALSE)
			apilar(C, desapilar(B));
	}
	while (es_vaciaPila(B) == FALSE)
		apilar(C, desapilar(B));
	liberarMemoria(cA);
	return C;
}

int main () {
	PILA A, B, C;
	A = crearPila();
	printf("\tPila A:\n");
	llenarPila(A);
	printf("\tPila B:\n");
	B = crearPila();
	llenarPila(B);
	mostrarPila(A);
	mostrarPila(B);
	C = mezclar(A, B);
	mostrarPila(C);
	liberarMemoria(A);
	liberarMemoria(B);
	liberarMemoria(C);
	printf("\n");
	return 0;
}
