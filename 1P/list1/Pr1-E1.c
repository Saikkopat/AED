#include <stdio.h>
#include <stdlib.h>

int ** initMultArray(int m, int n) {
	int **pointer, c;
	pointer = (int**) malloc(m * sizeof(int *));
	if (pointer == NULL) {
		printf("Memoria no reservada.\n");
		exit(0);
	}
	for(c = 0; c < m; c++)
		pointer[c] = (int*) malloc(sizeof(int) * n);
	return pointer;
}

void enterData(int ** pointer, int m, int n){
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf(" [%d] [%d] : ", i+1, j+1);
			scanf("%d", &pointer[i][j]);
		}
	}
}

void multMatrix(int ** A, int **B, int **D, int m, int n, int p){
    int i, j, k;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            D[i][j] = 0;
            for(k = 0; k < p; k++)
					D[i][j] += A[i][k] * B[k][j];
        }
    }

}

void printMArray(int **A, int m, int n){
	int i, j;
	for(i = 0; i < m; i++){
		printf("\n %d | ", i + 1);
		for(j = 0; j < n; j++){
			printf("  | %d ", A[i][j]);
		}
	}
	printf("\n");
}

void transp(int **D, int **C, int m, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			C[i][j] = D[j][i];
		}
	}
}

int main() {

    int ** A, **B, **C, **D, ma, mb, na, nb;
    printf("Introduce los tamaños de las matrices (mxn): \n");
    printf("Matriz A: \n  m: ");
    scanf("%d", &ma);
    printf("  n: ");
    scanf("%d", &na);
    printf("Matriz B: \n  m: ");
    scanf("%d", &mb);
    printf("  n: ");
    scanf("%d", &nb);
    if(na != mb)
        printf("Los tamaños de las matrices no son compatibles.\n");
    else {
        A = initMultArray(ma, na);
        B = initMultArray(mb, nb);
		  C = initMultArray(nb, ma);
        D = initMultArray(ma, nb);		  
        printf("Ingresa los datos de la matriz A:\n");
        enterData(A, ma, na);
        printf("Ingresa los datos de la matriz B:\n");
        enterData(B, mb, nb);
        printf("\n A:\n");
        printMArray(A, ma, na);
        printf("\nB:\n");
        printMArray(B, mb, nb);
        printf("\n D = (A * B):\n");
        multMatrix(A, B, D,  ma, nb, mb);
        printMArray(D, ma, nb);
			printf("\n C = D ^ t\n");
			transp(D, C, ma, nb);
			printMArray(C, nb, ma);
    }
    return 0;
}