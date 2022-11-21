#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void manejaMsg(int msg) {
  char* mensajes[4] = {"   \nNo hay memoria disponible.\n",
                       "   \nMemoria liberada.\n", "   \nPila llena.\n",
                       "   \nPila vacia.\n"};
  printf("%s", mensajes[msg]);
}

void liberarMemoria(PILA S) {
  free(S);
  manejaMsg(1);
}

void darElemento(PILA P) {
  char e;
  int c;
  do {
    printf("¿Quieres apilar un nuevo elemento?\n  1.Si\n  2.No\n   ");
    scanf("%d", &c);
    if (c == 1) {
      printf("   Ingresa el elemento a apilar: ");
      getchar();
      scanf("%c", &e);
      apilar(P, e);
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

void unionPilas(PILA A, PILA B, PILA C) {
  PILA temp = crearPila();
  while (esPilaVacia(A) != TRUE) apilar(temp, desapilar(A));
  while (esPilaVacia(temp) != TRUE) apilar(C, desapilar(temp));
  while (esPilaVacia(B) != TRUE) apilar(temp, desapilar(B));
  while (esPilaVacia(temp) != TRUE) apilar(C, desapilar(temp));
  liberarMemoria(temp);
}

int main() {
  PILA A, B, C;
  printf("Ingresa valores para las pilas.\n");
  printf(" PILA A:\n");
  A = crearPila();
  darElemento(A);
  printf(" PILA B:\n");
  B = crearPila();
  darElemento(B);
  printf(" PILA A:\n");
  mostrarPila(A);
  printf(" PILA B:\n");
  mostrarPila(B);
  C = crearPila();
  unionPilas(A, B, C);
  printf(" PILA C:\n");
  mostrarPila(C);
  liberarMemoria(A);
  liberarMemoria(B);
  liberarMemoria(C);
  return 0;
}