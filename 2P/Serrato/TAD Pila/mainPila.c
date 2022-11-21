#include <stdio.h>
#include <stdlib.h>

#include "Pila.h"
void insertaElem(PILA);
void llenarPilaInv(PILA, PILA);
void mostrarPilaInv(PILA);
void liberar(PILA, PILA, PILA);
void manejaMsg(int);
void main() {
   PILA S, C1, C2;
   S = crearPila();
   C1 = crearPila();
   C2 = crearPila();
   insertaElem(S);
   *C1 = *S;
   llenarPilaInv(C1, C2);
   mostrarPilaInv(C2);
   liberar(S, C1, C2);
}

void insertaElem(PILA S) {
   char letra[1];
   do {
      int e;
      printf("Inserta el dato: \n");
      scanf("%d", &e);
      apilar(S, e);
      printf("Deseas seguir insertando elementos? \n");
      printf("S=Si \n otro caracter=No\n");
      getchar();
      scanf("%c", letra);
   } while (*letra == 'S');
}

void llenarPilaInv(PILA C1, PILA C2) {
   while (es_vaciaPila(C1) != TRUE) {
      apilar(C2, (desapilar(C1)));
   }
}

void mostrarPilaInv(PILA C2) {
   int e;
   printf("Elementos insertados: \n");
   while (es_vaciaPila(C2) != TRUE) {
      e = desapilar(C2);
      printf(" %d", e);
   }
}

void liberar(PILA S, PILA C1, PILA C2) {
   free(S);
   free(C1);
   free(C2);
   manejaMsg(1);
}
