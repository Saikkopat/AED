//Hacer un programa que a partir de dos matrices creadas dinámicamente A y B de nxm (donde 
// n es igual a m, es decir son cuadradas), obtenga un arreglo C unidimensional creado
// dinámicamente donde cada uno de los elementos de C será igual al valor promedio de los elementos
// de la fila A, multiplicado por el menor elemento de la columna de B elevado a la suma de la 
// posición que ocupa.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ** initMultArray(int n, int m) {
	float **pointer;
	int c;
	pointer = (float**) malloc(n * sizeof(float *));
	if (pointer == NULL) {
		printf("   ¡Memoria no reservada!\n");
		exit(0);
	}
	for(c = 0; c < n; c++)
		pointer[c] = (float*) malloc(m * sizeof(float *));
	return pointer;
}

float * initUnArray(int n) {
	float * pointer;
	pointer = (float *)malloc(n * sizeof(float));
	if (pointer == NULL) {
		printf("   ¡Memoria no reservada!\n");
		exit(0);
	}
	return pointer;
}

void enterData(float ** pointer, int n, int m){
	int i, j;
	printf("Ingresa los datos de la matriz: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf(" [%d] [%d] : ", i+1, j+1);
			scanf("%f", &pointer[i][j]);
		}
	}
}

void printMArray(float **A, int n, int m){
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		printf(" %d | ", i + 1);
		for(j = 0; j < m; j++){
			printf(" | %f", A[i][j]);
		}
		printf(" |\n");
	}
	printf("\n");
}

void printUnArray(float *A, int n){
	int i;
	printf("\n");
	for(i = 0; i < n; i++)
		printf(" | %f", A[i]);
	printf("|\n\n");
}

void libMemMultA(float **A, int n){
	int i;
	for(i = 0; i < n; i++)
		free(A[i]);
	free(A);
	printf("   ¡Memoria liberada de un arreglo multidimensional!\n");
}

void libMemUnA(float *A){
	free(A);
	printf("   ¡Memoria liberada de un arreglo unidimensional!\n");
}

float promedioFila(float **A, int n, int m){
	int i;
	float prom = 0;
	for(i = 0; i < m; i++)
		prom += A[n][i];
	return prom = prom / m;
}

float menorB(float **B, int n, int m){
	float menor = 0;
	int i, poten = 0;
	for(i = 0; i < m-1; i++){
		if(B[i][n] < B[i+1][n]){
			menor = B[i][n];
			poten = i + n;
			}
		printf("    %d, %f, %d", i, menor, poten);
	}
	return powf(menor, poten);
}

void calcArrayC(float **A, float **B, float *C, int n){
	int i;
	for(i = 0; i < n; i++)
		C[i] = promedioFila(A, i, n) * menorB(B, i, n);
}

int main(){
	int n, m;
	float **A, **B, *C;
	printf("Ingresa el valor de n y m (matriz cuadrada): \n  n: ");
	scanf("%d", &n);
	printf("  m: ");
	scanf("%d", &m);
	A = initMultArray(n, m);
	B = initMultArray(n, m);
	C = initUnArray(n);
	printf("  Matriz A:\n");
	enterData(A, n, m);
	printf("  Matriz B:\n");
	enterData(B, n, m);
	printMArray(A, n, m);
	printMArray(B, n, m);
	calcArrayC(A, B, C, n);
	printUnArray(C, n);
	libMemMultA(A, n);
	libMemMultA(B, n);
	libMemUnA(C);
	return 0;
}