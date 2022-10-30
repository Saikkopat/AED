#include <stdio.h>
#include<stdlib.h>

int * initMemory() {
	int * pointer;
	pointer = (int*)malloc(3*sizeof(int));
	if (pointer == NULL) {
		printf("Memory not allocated!\n");
		exit(0);
	}
	return pointer;
}

void enterData(int * pointer) {
	printf("  i: ");
	scanf("%d", &pointer[0]);
	printf("  j: ");
	scanf("%d", &pointer[1]);
	printf("  k: ");
	scanf("%d", &pointer[2]);
}

void printData(int * pointer) {
	printf("   [%d, %d, %d]\n", pointer[0], pointer[1], pointer[2]);
}

int calculateVolumen(int * A, int * B, int * C) {
	int det = (A[0] * (B[1]*C[2] - B[2]*C[1])) - (A[1] * (B[0]*C[2] - B[2]*C[0])) + (A[2] * (B[0]*C[1] - B[1]*C[0]));
	free(A);
	free(B);
	free(C);
	if (det < 0){
		det = det * -1;
	}
	return det;
}

void freeMemory (int * pointer){
	free(pointer);
	printf("\n   Memory cleaned!\n");
}

int main(void) {
	int * A, * B, * C;
	int R;
	printf("Enter information for vectors\n A:\n");
	A = initMemory();
	enterData(A);
	printf(" B:\n");
	B = initMemory();
	enterData(B);
	printf(" C:\n");
	C = initMemory();
	enterData(C);
	printData(A);
	printData(B);
	printData(C);
	R = calculateVolumen(A, B, C);
	printf("   The volume of the figure is: %d.\n", R);
	freeMemory(A);
	freeMemory(B);
	freeMemory(C);
	return 0;
}