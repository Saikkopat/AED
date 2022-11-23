#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void manejaMsg (int msg) {
   char* mensajes[4] = {"   \n No hay memoria disponible.\n",
                        "   \n Memoria liberada.\n",
                        "   \n Pila llena.\n",
                        "   \n Pila vacia.\n"};
   printf("%s", mensajes[msg]);
}

void liberarMemoria (VECTOR V) {
	free(V);
	manejaMsg(1);
}

void llenarVector (VECTOR V, int t) {
    int i, temp;
    printf(" Ingresa los valores para el vector:\n");
    for (i = 0; i < t; i++) {
        printf("  [ %d ] : ", i);
        scanf("%d", &temp);
        ponComponente(V, i, temp);
    }
    printf("\n");
}

void mostrarVector (VECTOR V, int t) {
    int i;
    for (i = 0; i < t; i++)
        printf("[ %d ] ", obtenComponente(V, i));
}

VECTOR elimRepetidos (VECTOR V, int t) {
	VECTOR temp = crearVector(t);
	*temp = *V;
	int i, j, k, cont = 0;
	for (i = 0;i < t;i++){
		for (j = i + 1; j < t; j++) {
			if (obtenComponente(temp, i) == obtenComponente(temp, j)) {
				for (k = j; k < t; k++)
					ponComponente(temp, k, obtenComponente(temp, k + 1));
			j--;
			t--;
			cont++;
      }
    }
   }
	VECTOR B = crearVector(cont);
	for (i = 0; i < cont; i++)
		ponComponente(B, i, obtenComponente(temp, i));
	liberarMemoria(temp);
	return B;
}

int main () {
    VECTOR A, B;
    int cantVal;
    printf("Ingresa el tamaño del vector A: ");
    scanf("%d", &cantVal);
    A = crearVector(cantVal);
    llenarVector(A, cantVal);
    printf("  Vector A: ");
    mostrarVector(A, cantVal);
    printf("\n");
    B = elimRepetidos(A, cantVal);
	 printf("\n");
	 printf("  Vector B: ");
	 mostrarVector(B, tamano(B));
	 printf("\n");
	 liberarMemoria(A);
	 liberarMemoria(B);
	 printf("\n");
    return 0;
}