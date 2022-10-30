#include <stdio.h>
#include <stdlib.h>

char ** initMultArray(int n, int m) {
	char **pointer;
	int c;
	pointer = (char **) malloc(n * sizeof(char **));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	for(c = 0; c < n; c++)
		pointer[c] = (char *) malloc(m * sizeof(char *));
	return pointer;
}

void enterData(char **pointer, int n, int m){
	int i, j;
	printf("Enter data for the char type matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf(" [%d][%d] : ", i+1, j+1);
			scanf(" %c", &pointer[i][j]);
		}
	}
}

void printMArray(char **A, int n, int m){
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		printf(" %d |", i);
		for(j = 0; j < m; j++){
			printf(" %c", A[i][j]);
		}
		printf(" |\n");
	}
}

void printTR(char **A, int n, int m){
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		printf(" %d |", i);
		for(j = 0; j < m; j++){
			printf(" %c", A[(n-1)-i][(m-1)-j]);
		}
		printf(" |\n");
	}
}

void freeMemory (char * pointer){
	free(pointer);
	printf("\n   Memory cleaned!\n");
}

int main(){
	char **R;
	int n, m;
	printf("Enter matrix size(m x n):\n Columns (m): ");
	scanf("%d", &m);
	printf(" Rows (n): ");
	scanf("%d", &n);
	R = initMultArray(n, m);
	enterData(R, n, m);
	printf("\n R: ");
	printMArray(R, n, m);
	printf("\n RT: ");
	printTR(R, n, m);
	freeMemory(R);
	return 0;
}