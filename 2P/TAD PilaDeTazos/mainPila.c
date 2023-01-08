#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void manejaMsg(int msg) {
char * mensajes[4] = {					"\n   No hay memoria disponible.\n",
							"\n   Memoria liberada.\n",
							"\n   Pila llena.\n",
							"\n   Pila vacia.\n"};
	printf("%s", mensajes[msg]);
}

void liberarMemoria(PILA S) {
	free(S);
	manejaMsg(1);
}

void ingresarTazos (PILA T) {
	int pos = 0;
	char tazos[TAM];
	printf("\n\tCarlitos, ingresa los tazos que ganaste: ");
	while ((tazos[pos++] = getchar()) != '\n');
	tazos[--pos] = '\0';
	pos = 0;
	while(tazos[pos] != '\0') {
		apilar(T, tazos[pos]); 
		pos++;
	};
	
	
}

void imprimirTazo (char tazo) {
	printf("%c", tazo);
}

void imprimirResultado (int m, int p) {
	printf(" tazos  métalicos: %d tazos plástico %d\n", m, p);
}

void contarTazos (PILA T) {
	char act;
	int m = 0, p = 0;
	printf("\n\t");
	while (esPilaVacia(T) == FALSE) {
		act = desapilar(T);
		imprimirTazo(act);
		if (act == 'm')
			m++;
		if (act == 'p')
			p++;
	}
	imprimirResultado(m, p);
}



int main() {
	PILA T;
	T = crearPila();
	ingresarTazos(T);
	contarTazos(T);
	printf("\n");
	return 0;
}
