#include <stdio.h>
#include <stdlib.h>

int ** initMultArray(int n) {
	int **pointer, c;
	pointer = (int**) malloc(n * sizeof(int *));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	for(c = 0; c < n; c++)
		pointer[c] = (int*) malloc(sizeof(int) * n);
	return pointer;
}

int * initOneDArray(int n){
	int *pointer;
	pointer = (int *)malloc(n * sizeof(int *));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	return pointer;
}

void enterData(int ** pointer, int n){
	int i, j;
	printf("Enter data for the matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf(" [%d] [%d] : ", i+1, j+1);
			scanf("%d", &pointer[i][j]);
		}
	}
}

void sigmaFunction(int **A, int *B, int n){
	int i, k;
	for(i = 0; i < n; i++){
		B[i] = 0;
		if((A[i][0] % 3) == 1){
			printf("mod 3 = 1");
			for(k = i; k < n - 1; k++){
				B[i] += A[i][k];
				printf(" i: %d, k: %d, B(%d): +A(%d)", i, k,  B[i], A[k][i]);
				}
				printf("\n");
		}
		if((A[i][0] % 3) == 2){
			printf("mod 3 = 1");
			for(k = 0; k < n - 1; k++){
				B[i] += A[k][i];
				printf(" i: %d, k: %d, B(%d): +A(%d)", i, k,  B[i], A[k][i]);
				}
				printf("\n");
			}
		if((A[i][0] % 3) == 0)
			B[i] = 0;
	}
}

void printMArray(int **A, int n){
	int i, j;
	for(i = 0; i < n; i++){
		printf("\n %d | ", i + 1);
		for(j = 0; j < n; j++){
			printf("  | %d ", A[i][j]);
		}
		printf("\n");
	}
}

void printOneArray(int *B, int n){
	int c;
	printf("\n");
	for(c = 0; c < n; c++)
		printf(" | %d", B[c]);
	printf("\n");
}

void freeMemory (int * pointer){
	free(pointer);
	printf("\n   Memory cleaned!\n");
}

int main () {
	int **A, *B, n;
	printf("Enter the size of the table (n x n): ");
	scanf("%d", &n);
	A = initMultArray(n);
	B = initOneDArray(n);
	enterData(A, n);
	printMArray(A, n);
	sigmaFunction(A, B, n);
	printOneArray(B, n);
	freeMemory(A);
	freeMemory(B);
	return 0;
}