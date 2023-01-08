#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "postfija.h"

void manejaMsg (int msg) {
	char* mensajes[5] = {"   \nNo hay memoria disponible.\n",
								"   \nMemoria liberada.\n",
								"   \nPila llena.\n",
								"   \nPila vacia.\n",
								"   \nDivisión entre cero.\n\n"};
   printf("%s", mensajes[msg]);
}


/* Lee una expresión en Postfija */
void lee (char *ent) {
	int pos = 0;
	printf("\n\tEvaluacion de expresiones Postfijas\n");
	printf("Operaciones Basicas: Suma, Resta, Producto y Division\n\n");
	printf("\n\n Introduzca la expresion en Postfija: ");
	while ((ent[pos++] = getchar()) != '\n');
	ent[--pos] = '\0';
}

float potencia (float a, float b) { return pow(a, b); }

void divisionCero (float b) {
	if (b == 0) {
		manejaMsg(4);
		exit(0);
	}
}

/*Evalua la expresion*/
float evalua (PILA P, char *ent) {
	float a, b;
	double conv;
	int pos = 0;
	char op[1];

	while (ent[pos] != '\0') {
		*op = ent[pos++];
		switch (*op) {
			case '+':
				b = desapilar(P);
				a = desapilar(P);
				apilar(P, a + b);
				break;
			case '-':
				b = desapilar(P);
				a = desapilar(P);
				apilar(P, a - b);
				break;
			case '*':
				b = desapilar(P);
				a = desapilar(P);
				apilar(P, a * b);
				break;
			case '/':
				b = desapilar(P);
				a = desapilar(P);
				divisionCero(b);
				apilar(P, a / b);
				break;
			case '^':
				b = desapilar(P);
				a = desapilar(P);
				apilar(P, potencia(a, b));
			break;
			default:
				conv = atof(op);	// convierte un caracter a float
				apilar(P, conv);		// Almacena el valor (numero) en la pila
		}
	}
	return (desapilar(P));
}

void mostrarSalida(char *ent, float ev) {
	printf("\n\n\t %s = %.2f \n\n", ent, ev);
}


int main() { 
	PILA P;
	float ev;
	char ent[TAM];
	lee(ent);
	P = crearPila();
	ev = evalua(P, ent);
	mostrarSalida(ent, ev);  
	return 0;
}