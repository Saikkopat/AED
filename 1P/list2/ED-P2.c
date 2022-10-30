/*
    González Cárdenas Ángel Aquilez, 2CM5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int edad;
    char nombre[15];
    char direccion[30];
    char telefono[10];
} Persona;

Persona *crearCenso(int n){
    Persona *nuevo;
    nuevo = (Persona*)malloc(n * sizeof(Persona));
    if (nuevo == NULL){
        printf("No es posible crear personas.\n");
        exit(0);
    }
    return nuevo;
}

void censar(Persona *censo, int n){
    int i;
    printf("Ingresa la información de las personas a censar:\n");
    for(i = 0; i < n; i++){
        printf(" Persona #%d:\n", i + 1);
        printf("  Nombre: ");
        scanf(" %[^\n]", censo[i].nombre);
        printf("  Edad: ");
        scanf("%d", &censo[i].edad);
        printf("  Dirección: ");
        scanf(" %[^\n]", censo[i].direccion);
        printf("  Teléfono: ");
        scanf(" %[^\n]", censo[i].telefono);
    }
}

void impPersonas(Persona *censo, int n){
    int i;
    printf("\n");
    printf("   Censo:\n");
    for(i = 0; i < n; i++)
        printf("   Persona #%d: %s, %d, %s, %s.\n", i + 1, censo[i].nombre, censo[i].edad, censo[i].direccion, censo[i].telefono);
}

void intercambio(Persona *persona1, Persona *persona2){
    Persona temp = *persona1;
    *persona1 = *persona2;
    *persona2 = temp;
}

void ordenEdad(Persona *censo, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(censo[j].edad < censo[j + 1].edad)
                intercambio(&censo[j], &censo[j + 1]);
        }
    }
}

void liberarMemoria(Persona *censo){
    printf("   ¡Bloque de memoria %p liberado!\n", censo);
    free(censo);
    printf("\n");
}

int main(){
    Persona *censo;
    int n;
    printf("Introduce la cantidad de personas a censar: ");
    scanf("%d", &n);
    censo = crearCenso(n);
    censar(censo, n);
    impPersonas(censo, n);
    ordenEdad(censo, n);
    impPersonas(censo, n);
    printf("\n");
    liberarMemoria(censo);
    return 0;
}