#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg (int msg) {
   char* mensajes[4] = {"\n   No hay memoria disponible.\n",
                        "\n   Memoria liberada.\n",
                        "\n   Cola llena.\n",
                        "\n   Cola vacia.\n"};
   printf("%s", mensajes[msg]);
}

void liberarMemoria(COLA S) {
  free(S);
  manejaMsg(1);
}

void agregarDato (COLA C) {
   int c;
   char e;
   do {
      printf("¿Deseas encolar un nuevo elemento?\n  1.Si\n  2.No\n   ");
      scanf("%d", &c);
      if (c == 1) {
         printf("   Elemento a apilar: ");
         scanf("     %c", &e);
         encolar(C, e);
      }
   } while (c == 1);
}

void imprimirTam (int tam) {
    printf("\n\tLa cola tiene un tamaño de: %d.\n", tam);
}

void tamCola (COLA C) {
    COLA copia = crearCola();
	int cont = 0;
    *copia = *C;
	if (es_vaciaCola(copia) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
    while (es_vaciaCola(copia) == FALSE) {
        desencolar(copia);
        cont++;
    }
    liberarMemoria(copia);
    imprimirTam(cont);
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
        printf("\t%d :", cont);
        printf(" %c\n", desencolar(copia));
        cont++;
  }
  liberarMemoria(copia);
}


int main () {
    COLA C1;
    C1 = crearCola();
    agregarDato(C1);
    tamCola(C1);
    mostrar(C1);
    liberarMemoria(C1);
    printf("\n");
    return 0;
}