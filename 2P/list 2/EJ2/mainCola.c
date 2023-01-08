#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

void manejaMsg (int msg) {
	char* mensajes[4] = {"\n\tNo hay memoria disponible.\n",
								"\n\tMemoria liberada.\n",
								"\n\tCola llena.\n",
								"\n\tCola vacia.\n"};
	printf("%s", mensajes[msg]);
}

void liberarMemoria (COLA S) {
	free(S);
	manejaMsg(1);
}

void agregarDato (COLA C) {
	int c, e;
	do {
		printf("¿Deseas encolar un nuevo elemento?\n  1.Si\n  2.No\n   ");
		scanf("%d", &c);
		if (c == 1) {
			printf("   Elemento a apilar: ");
			scanf("\t%d", &e);
			encolar(C, e);
		}
	} while (c == 1);
}

void mostrar (COLA C) {
	COLA copia = crearCola();
	int cont = 0;
	*copia = *C;
	if (es_vaciaCola(copia) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	printf("\n   Elementos de la cola:\n");
	while (es_vaciaCola(copia) == FALSE) {
		printf("\t%d : %d\n", cont, (int)desencolar(copia));
		cont++;
	}
	liberarMemoria(copia);
}

int ultimoCola (COLA C) {
	PILA temp = crearPila();
	COLA copia = crearCola();
	*copia = *C;
	if (es_vaciaCola(copia) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	while (es_vaciaCola(copia) == FALSE) {
		apilar(temp, desencolar(copia));
	}
	return desapilar(temp);
}

void imprimirUltimo (int ult) {
	printf("\n\tEl último elemento de la cola es: %d.\n", ult);
}

int main () {
	COLA C1;
	C1 = crearCola();
	agregarDato(C1);
	imprimirUltimo(ultimoCola(C1));
	mostrar(C1);
	liberarMemoria(C1);
	printf("\n");
	return 0;
}