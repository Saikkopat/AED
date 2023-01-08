#include <stdio.h>
#include <stdlib.h>

int ** initMultArray(int n, int m) {
	int **pointer, c;
	pointer = (int**) malloc(n * sizeof(int *));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	for(c = 0; c < n; c++)
		pointer[c] = (int*) malloc(m * sizeof(int *));
	return pointer;
}

int * initVector(int x){
	int *pointer;
	pointer = (int *)malloc(x * sizeof(int *));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	return pointer;
}

void enterData(int ** pointer, int n, int m){
	int i, j;
	printf("Enter data for the matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf(" [%d] [%d] : ", i+1, j+1);
			scanf("%d", &pointer[i][j]);
		}
	}
}

void printMArray(int **A, int n, int m){
	int i, j;
	for(i = 0; i < n; i++){
		printf("\n %d | ", i + 1);
		for(j = 0; j < m; j++){
			printf(" | %d", A[i][j]);
		}
		printf(" |\n");
	}
}

void printOneArray(int *B, int n){
	int c;
	printf("\n");
	for(c = 0; c < n; c++)
		printf(" | %d", B[c]);
	printf(" |\n");
}

void calculateVectors(int **A, int n, int m, int *col, int *row){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			row[i] += A[i][j];
			col[j] += A[i][j];
		}
	}
}

void freeMemory (int * pointer){
	free(pointer);
	printf("\n   Memory cleaned!\n");
}

int main () {
	int **A, *vCol, *vRow, n, m;
	printf("Enter matrix size (m x n):\n Columns (m): ");
	scanf("%d", &m);
	printf(" Rows (n): ");
	scanf("%d", &n);
	A = initMultArray(n, m);
	vCol = initVector(m);
	vRow = initVector(n);
	enterData(A, n, m);
	printMArray(A, n, m);
	calculateVectors(A, n, m, vCol, vRow);
	printf("\nColumn Vector: ");
	printOneArray(vCol, m);
	printf("\nRow Vector: ");
	printOneArray(vRow, n);
	freeMemory(A);
	freeMemory(vCol);
	freeMemory(vRow);
	return 0;
}