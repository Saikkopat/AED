/*
    González Cárdenas Ángel Aquilez, 2CM5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct datos{
    char nombre[15];
    char ap_pater[15];
    int edad;
    char carrera[20];
} Datos;

typedef struct deportistas{
    Datos pers;
    char deportes[30];
    int medallas;
} Deportistas;

Deportistas *crearDeportistas(int n){
    Deportistas *nuevo;
    nuevo = (Deportistas *)malloc(n * sizeof(Deportistas));
    if(nuevo == NULL){
        printf("No es posible crear deportistas.\n");
        exit(0);
    }
    return nuevo;
}

void ingDeportistas(Deportistas *lista, int n){
    int i;
    printf("Ingresa la información de los deportistas:\n");
    for(i = 0; i < n; i++){
        printf(" Deportista #%d:\n", i + 1);
        printf("  Nombre: ");
        scanf(" %[^\n]", lista[i].pers.nombre);
        printf("  Apellido Paterno: ");
        scanf(" %[^\n]", lista[i].pers.ap_pater);
        printf("  Edad: ");
        scanf("%d", &lista[i].pers.edad);
        printf("  Carrera: ");
        scanf(" %[^\n]", lista[i].pers.carrera);
        printf("  Deporte: ");
        scanf(" %[^\n]", lista[i].deportes);
        printf("  Medallas: ");
        scanf("%d", &lista[i].medallas);
    }
}

void impDeportistas(Deportistas *lista, int n){
    int i;
    printf("\n");
    printf("   Lista de deportistas inscritos:\n");
    for(i = 0; i < n; i++)
        printf("    #%d: %s %s, %d, %s, %s, Medallas: %d\n", i + 1, lista[i].pers.nombre, lista[i].pers.ap_pater, lista[i].pers.edad, lista[i].pers.carrera, lista[i].deportes, lista[i].medallas);
}

float calcPromMedallas(Deportistas *lista, int n){
    float promedio = 0;
    int i;
    for(i = 0; i < n; i++)
        promedio += lista[i].medallas;
    return promedio / n;
}

int contMayorProm(Deportistas *lista, int n, float promedio){
    int i, cont = 0;
    for(i = 0; i < n; i++){
        if(lista[i].medallas > promedio)
            cont++;
    }
    return cont;
}

void intercambio(Deportistas *deportista1, Deportistas *deportista2){
    Deportistas temp = *deportista1;
    *deportista1 = *deportista2;
    *deportista2 = temp;
}

void ordenEdad(Deportistas *lista, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(lista[j].medallas < lista[j + 1].medallas)
                intercambio(&lista[j], &lista[j + 1]);
        }
    }
    printf("   Mejor galardonado: %s, %s, %s, %d Medallas.\n", lista[0].pers.nombre, lista[0].pers.ap_pater, lista[0].pers.carrera, lista[0].medallas);
    printf("   Peor galardonado: %s, %s, %s, %d Medallas.\n", lista[n-1].pers.nombre, lista[n-1].pers.ap_pater, lista[n-1].pers.carrera, lista[n-1].medallas);
}

void liberarMemoria(Deportistas *lista){
    printf("   ¡Bloque de memoria %p liberado!\n", lista);
    free(lista);
    printf("\n");
}

int main(){
    Deportistas *lista;
    int n, mayorAlProm;
    float promedio;
    printf("Ingresa la cantidad de estudiantes inscritos a registrar: ");
    scanf("%d", &n);
    lista = crearDeportistas(n);
    ingDeportistas(lista, n);
    impDeportistas(lista, n);
    printf("\n");
    promedio = calcPromMedallas(lista, n);
    printf("  Promedio de medallas obtenido: %.2f.\n", promedio);
    printf("\n");
    mayorAlProm = contMayorProm(lista, n, promedio);
    printf("  Número de deportistas con más de %.2f medallas: %d.\n", promedio, mayorAlProm);
    printf("\n");
    ordenEdad(lista, n);
    printf("\n");
    liberarMemoria(lista);
    return 0;
}