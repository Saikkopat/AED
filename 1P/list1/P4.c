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
		printf(" %d | ", i + 1);
		for(j = 0; j < m; j++){
			printf(" | %d", A[i][j]);
		}
		printf(" |\n");
	}
	printf("\n");
}

void multCMatrix(int **A, int **B, int **C, int n, int m, int p, int q, int op){
   int i, j, k;
		switch(op){
			case 1:
				for(i = 0; i < n; i++){
					for(j = 0; j < m; j++){
						C[i][j] = (p * A[i][j]) + (q * B[i][j]);
					}
				}
			break;
			case 2:
				for(i = 0; i < n; i++){
					for(j = 0; j < m; j++){
						C[i][j] = (q * A[i][j]) - (p * B[i][j]);
					}
				}
			break;
			case 3:
				for(i = 0; i < n; i++){
					for(j = 0; j < m; j++){
						C[i][j] = 0;
						for(k = 0; k < m; k++)
							C[i][j] += (p * A[i][k]) * (q * B[k][j]);
					}
				}
			break;
		}
	printf("\nA:\n");
	printMArray(A, n , m);
	printf("B:\n");
	printMArray(B, n , m);
	printf("C:\n");
	printMArray(C, n , m);
}

void freeMemory (int * pointer){
	free(pointer);
	printf("\n   Memory cleaned!\n");
}

int main() {
	int **A, **B, **C, n, m, p, q, o;
	printf("Enter matrix sizes for A & B (m x n):\n Columns (m): ");
	scanf("%d", &m);
	printf(" Rows (n): ");
	scanf("%d", &n);
	A = initMultArray(n, m);
	printf("For matrix A: \n");
	enterData(A, n, m);
	B = initMultArray(n, m);
	printf("For matrix B: \n");
	enterData(B, n, m);
	C = initMultArray(n, m);
	printf("Enter values for:\n p:");
	scanf("%d", &p);
	printf(" q: ");
	scanf("%d", &q);
	do {
		printf("   Select an option:\n");
		printf("   1. pA + qB\n");
		printf("   2. qA - pB\n");
		if(m != n)
			printf("   Matrix multiplication pA * qB unavailable for incompatible matrix sizes.\n");
		else
			printf("   3. pA * qB\n");
		printf("   ");
		scanf("%d", &o);
		switch(o){
			case 1:
				multCMatrix(A, B, C, n, m, p, q, o);
			break;
			case 2:
				multCMatrix(A, B, C, n, m, p, q, o);
			break;
			case 3:
				multCMatrix(A, B, C, n, m, p, q, o);
			break;
			default:
				printf("    Non an option!\n");
			break;
		}
		printf("   Continue? (1. Yes, 2. No): ");
		scanf("%d", &o);
	} while(o != 2);
	freeMemory(A);
	freeMemory(B);
	freeMemory(C);
	return 0;
}