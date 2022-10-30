/*
    González Cárdenas Ángel Aquilez, 2CM5
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Punto;

Punto *newPoint(void){
    Punto *newp;
    newp = (Punto *)malloc(sizeof(Punto));
    if(newp == NULL){
        printf("   Memory not allocated!");
        exit(0);
    }
    return newp;
}

void enterData(Punto *pointer){
    printf(" Enter values for:\n  X : ");
    scanf("%f", &pointer -> x);
    printf("  Y : ");
    scanf("%f", &pointer -> y);
    printf("\n");
}

void printData(Punto *pointer){
    printf("(%f, %f)", pointer -> x, pointer -> y);
}

void freeMemo(Punto *pointer){
    printf("   Memory block %p released!\n", pointer);
    free(pointer);
}

void midPoint(Punto *A, Punto *B){
    Punto *midP = newPoint();
    midP -> x = (A -> x + B -> x) / 2;
    midP -> y = (A -> y + B -> y) / 2;
    printf("   Mid Point: %f,%f.\n", midP -> x, midP -> y);
    free(midP);
}

void distance(Punto *A, Punto *B){
    float dPaPb = 0;
    dPaPb = sqrt(pow(B -> x - A -> x, 2) + pow(B -> y - A -> y, 2));
    printf("   Distance: %f.\n", dPaPb);
}


int main(){
    Punto *A, *B;
    char resp;
    int op;
    A = newPoint();
    B = newPoint();
    printf("Enter values for points\n A(X1, Y1):\n");
    enterData(A);
    printf(" B(X2, Y2):\n");
    enterData(B);
    do{
        printf("   1. Calculate mid point.\n");
        printf("   2. Calculate distance.\n");
        printf("   Enter option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                midPoint(A, B);
                break;
            case 2:
                distance(A, B);
                break;
            default:
                printf("   Error: Not a valid option!");
                break;
        }
        printf("    Do you like to continue? [Y/N]\n    ");
        scanf(" %c", &resp);
        printf("\n");
    } while(resp == 'Y' || resp == 'y');
    freeMemo(A);
    freeMemo(B);
    printf("\n");
    return 0;
}