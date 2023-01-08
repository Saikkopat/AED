#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void manejaMsg(int msg) {
char * mensajes[7] = {"\n   No hay memoria disponible.\n",
							"\n   Memoria liberada.\n",
							"\n   Pila llena.\n",
							"\n   Pila vacia.\n",
							"\n   Caracter no valido introducido.\n",
							"\n   Parentesis no equilibrados.\n",
							"\n  Parentesis equilibrados.\n",};
	printf("%s", mensajes[msg]);
}

void liberarMemoria(PILA S) {
	free(S);
	manejaMsg(1);
}

void leerExpresion (char * exp) {
	int pos = 0;
	printf("\n\tEvaluacion de equilibrio de parentesis.\n");
	printf("\n\n Introduzca los parentesis: ");
	while ((exp[pos++] = getchar()) != '\n');
	exp[--pos] = '\0';
}

int checarParentesis (PILA S, char * exp) {
	int pos = 0;
	char op[1];
	while (exp[pos] != '\0') {
		*op = exp[pos++];
		switch (*op) {
			case '{':
				apilar(S, exp[pos]);
			break;
			case '[':
				apilar(S, exp[pos]);
			break;
			case '(':
				apilar(S, exp[pos]);
			break;
			case '}':
				desapilar(S);
			break;
			case ']':
				desapilar(S);
			break;
			case ')':
				desapilar(S);
			break;
			default:
				manejaMsg(4);
				exit(0);
			break;
		}
	}
	if (esPilaVacia(S)) return TRUE;
	else return FALSE;
}

void mostrarSalida(char * exp) {
	printf("\n\t %s \n", exp);
}

void mostrar (int val) {
	if (val)
		manejaMsg(6);
	else
		manejaMsg(5);
}



int main() {
	PILA P;
	char exp[TAM];
	P = crearPila();
	leerExpresion(exp);
	mostrarSalida(exp);
	mostrar(checarParentesis(P, exp));
	printf("\n");
	return 0;
}