#include <stdio.h>
#include <stdlib.h>

#include "Fraccion.h"

void manejaMsg (int msg) {
   char* mensajes[] = {"\n   No hay memoria disponible.\n",
                       "\n   Se ha liberado la memoria.\n"};
   printf("%s", mensajes[msg]);
}
void liberarMem (FRACCION F1, FRACCION F2, FRACCION F3) {
   free(F1);
   free(F2);
   free(F3);
   manejaMsg(1);
}

void darFracciones (FRACCION F1, FRACCION F2) {
   int n, d;
	printf("Ingresa valores para las fracciones:\n");
   printf(" Fracción 1, Númerador: ");
   scanf("%d", &n);
   asignaNum(F1, n);
   printf(" Fracción 1, Denominador: ");
   scanf("%d", &d);
   asignaDenom(F1, d);
   printf(" Fracción 2, Númerador: ");
   scanf("%d", &n);
   asignaNum(F2, n);
   printf(" Fracción 1, Denominador: ");
   scanf("%d", &d);
   asignaDenom(F2, d);
}

void mostrarFraccion (FRACCION F) {
   printf("   %d / %d\n", obtenNum(F), obtenDenom(F));
}

void simplificarFraccion (FRACCION F) {
	int x, y, mod;
	x = obtenNum(F);
	y = obtenDenom(F);
	while (mod != 0) {
		mod = x % y;
		x = y;
		y = mod;
	}
	asignaNum(F, obtenNum(F) / x);
	asignaDenom(F, obtenDenom(F) / x);
}

int main () {
   FRACCION F1, F2, F3;
   F1 = crearFraccion();
   F2 = crearFraccion();
   F3 = crearFraccion();
   darFracciones(F1, F2);
   F3 = producto(F1, F2);
   printf("   Fracción 1: ");
	mostrarFraccion(F1);
	printf("   Fracción 1: ");
	mostrarFraccion(F2);
   printf("   Producto: ");
	mostrarFraccion(F3);
   if (esImpropia(F3) == 1) printf("   La fracción es impropia.\n");
   simplificarFraccion(F3);
   mostrarFraccion(F3);
   printf("   División: ");
   F3 = division(F1, F2);
	mostrarFraccion(F3);
	simplificarFraccion(F3);
	mostrarFraccion(F3);
	liberarMem(F1, F2, F3);
	printf("\n");
	return 0;
}