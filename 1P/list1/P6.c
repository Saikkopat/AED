#include <stdio.h>
#include <stdlib.h>

int ** initMultArray(int n){
	int **pointer, c;
	pointer = (int**) malloc(n * sizeof(int *));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	for(c = 0; c < n; c++)
		pointer[c] = (int*) malloc(2 * sizeof(int *));
	return pointer;
}

void enterData(int ** pointer, int n){
	int i;
	printf("Enter axis numbers:\n");
	for(i = 0; i < n; i++){
		printf(" X%d: ", i);
		scanf("%d", &pointer[i][0]);
		printf(" Y%d: ", i);
		scanf("%d", &pointer[i][1]);
	}
}

void printMArray(int **A, int n){
	int i;
	for(i = 0; i < n; i++)
		printf("  (X%d, Y%d) : %d, %d\n",i, i, A[i][0], A[i][1]);
	printf("\n");
}

void lPoly(int * n){
	printf(" Enter polygon side number (n > 3 & n < 10): ");
	scanf("%d", n);
}

void cArea(int **A, int n){
	int area, i;
	for(i = 0; i < n - 1; i++){
		area += (A[i][0] + A[i+1][0]) * (A[i][1] + A[i+1][1]);
		printf("   %d,%d & %d,%d, %d,%d\n", A[i][0], A[i][1], A[i+1][0], A[i+1][1], A[i][0] + A[i+1][0], A[i][1] - A[i+1][1]);
		}
	area += (A[i][0] + A[0][0]) * (A[i][1] + A[0][1]);
	printf("  Polygon area: %d\n", area);
}

int main(){
	int ** A, n;
	lPoly(&n);
	A = initMultArray(n);
	enterData(A, n);
	printMArray(A, n);
	cArea(A, n);
	return 0;
}