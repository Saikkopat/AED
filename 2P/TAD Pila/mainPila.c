#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void manejaMsg (int msg) {
   char* mensajes[4] = {"   \nNo hay memoria disponible.\n",
                        "   \nMemoria liberada.\n",
                        "   \nPila llena.\n",
                        "   \nPila vacia.\n"};
   printf("%s", mensajes[msg]);
}

void liberarMemoria (PILA S) {
	free(S);
	manejaMsg(1);
}

void darElemento (PILA S1) {
   int e, c;
   do {
      printf("¿Quieres apilar un nuevo elemento?\n  1.Si\n  2.No\n   ");
      scanf("%d", &c);
      if (c == 1) {
         printf("   Ingresa el elemento a apilar: ");
         scanf("     %d", &e);
         apilar(S1, e);
      }
   } while (c == 1);
}

void mostrarPila(PILA S) {
  PILA copia = crearPila();
  *copia = *S;
  if (esPilaVacia(copia) == TRUE) {
    manejaMsg(3);
    exit(0);
  }
  printf("\n Elementos de la pila:\n");
  while (esPilaVacia(copia) != TRUE) {
    printf("  %d :", elemTope(copia));
    printf(" %c\n", desapilar(copia));
  }
  liberarMemoria(copia);
}

PILA invertirPila (PILA S) {
	PILA copia = crearPila(), temp = crearPila();
	*copia = *S;
	liberarMemoria(S);
	while(esPilaVacia(copia) == FALSE)
		apilar(temp, desapilar(copia));
	liberarMemoria(copia);
	return temp;
}

int main () {
   PILA S1;
   S1 = crearPila();
   darElemento(S1);
	mostrarPila(S1);
   S1 = invertirPila(S1);
	printf("\n   Pila invertida:\n");
	mostrarPila(S1);
   return 0;
}
