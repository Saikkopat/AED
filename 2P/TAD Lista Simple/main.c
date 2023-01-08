#include <stdio.h>
#include <stdlib.h>

#include "listaSimple.h"

void manejaError(int msg) {
	char *mensajes[2] = {"\n   No hay memoria disponible.\n",
								"\n   Lista vacía.\n"};
	printf("%s", mensajes[msg]);
}

LISTA ingresaElementos (LISTA L) {
	printf("\n Ingresa elementos a la lista:\n");
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
	LISTA L1;
	L1 = crearLista();
	L1 = ingresaElementos(L1);
	mostrarLista(L1);
	L1 = borrar(L1, 1);
	mostrarLista(L1);
	printf("\n");
	return 0;
}

