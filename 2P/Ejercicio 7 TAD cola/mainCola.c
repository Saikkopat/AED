#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg (int msg) {
   char* mensajes[6] = {"   \nNo hay memoria disponible.\n",
                        "   \nMemoria liberada.\n",
                        "   \nCola llena.\n",
                        "   \nCola vacia.\n",
                        "   \nC1 está contenida en C2.\n",
                        "   \nC1 no está contenida en C2.\n"};
   printf("%s", mensajes[msg]);
}

void liberarMemoria(COLA S) {
  free(S);
  manejaMsg(1);
}

void darElemento (COLA C) {
   int c;
   char e;
   do {
      printf("¿Quieres apilar un nuevo elemento?\n  1.Si\n  2.No\n   ");
      scanf("%d", &c);
      if (c == 1) {
         printf("   Elemento a apilar: ");
         scanf("     %c", &e);
         encolar(C, e);
      }
   } while (c == 1);
}

void mostrarCola (COLA C) {
	COLA copia = crearCola();
	int cont = 0;
    *copia = *C;
	if (es_vaciaCola(copia) == TRUE) {
		manejaMsg(3);
		exit(0);
	}
	printf("\n Elementos de la cola:\n");
    while (es_vaciaCola(copia) != TRUE) {
        printf("  %d :", cont);
        printf(" %c\n", desencolar(copia));
        cont++;
  }
  liberarMemoria(copia);
}

void contenidaCola (COLA C1, COLA C2) {
    int b = 1;
    char el;
    COLA copia1 = crearCola();
    *copia1 = *C1;
    COLA copia2 = crearCola();
    *copia2 = *C2;
    while (es_vaciaCola(copia1) != TRUE) {
        el = desencolar(copia1);
        *copia2 = *C2;
        while (es_vaciaCola(copia2) != TRUE) {
           if (el == desencolar(copia2))
            b = 1;
           else
            b = 0;
        }
    }
    if(b == 1)
        manejaMsg(4);
    else
        manejaMsg(5);
}

int main () {
    COLA C1, C2;
    printf("Ingresa valores para las colas: \n");
    printf(" COLA 1:\n");
    C1 = crearCola();
    darElemento(C1);
    printf(" COLA 2:\n");
    C2 = crearCola();
    darElemento(C2);
    printf("\n");
    contenidaCola(C1, C2);
    mostrarCola(C1);
    mostrarCola(C2);
    liberarMemoria(C1);
    liberarMemoria(C2);
    return 0;
}