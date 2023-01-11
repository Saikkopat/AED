#include <stdio.h>
#include <stdlib.h>

#include "listaDoble.h"

void manejaError(int msg) {
	char *mensajes[2] = {"\n   No hay memoria disponible.\n",
								"\n   Lista doble vacía.\n"};
	printf("%s", mensajes[msg]);
}

LISTADOBLE ingresaElementos (LISTADOBLE L) {
	printf("\n Ingresa elementos a la lista doble:\n");
	int res;
	do{
		printf("  Elemento: ");
		scanf("%d", &res);
		L = insertar(L, res);
		printf("  ¿Deseas agregar otro elemento?\n   1. Sí\n   2. No\n   ");
		scanf("%d", &res);
	} while(res == 1);
	return L;
}

int main() {
	LISTADOBLE L1;
	L1 = crearLista();
	L1 = ingresaElementos(L1);
	mostrarLista(L1);
	mostrarListaInvertida(L1);
	printf("\n");
	return 0;
}