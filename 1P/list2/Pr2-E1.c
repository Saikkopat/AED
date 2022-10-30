/*
    González Cárdenas Ángel Aquilez, 2CM5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia, mes, anio;
} Info_fecha;

typedef struct{
    char * nombre;
    int edad;
    Info_fecha * fe;
} Alumno;

Alumno *crearAlumno(int n){
    Alumno *nuevo;
    int i;
    nuevo = (Alumno *)malloc(n * sizeof(Alumno));
    if(nuevo == NULL){
        printf("No es posible crear alumnos.\n");
        exit(0);
    }
    for(i = 0; i < n; i++){
        nuevo[i].nombre = (char *)malloc(40 * sizeof(char));
        nuevo[i].fe = (Info_fecha *)malloc(2 * sizeof(Info_fecha));
    }
    return nuevo;
}

void ingAlumno(Alumno *inscritos, int n){
    int i;
    printf("Ingresa la información de los alumnos:\n");
    for(i = 0; i < n; i++){
        printf(" Alumno #%d:\n", i + 1);
        printf("  Nombre: ");
        scanf(" %[^\n]", inscritos[i].nombre);
        printf("  Edad: ");
        scanf("%d", &inscritos[i].edad);
        printf("  Fecha de nacimiento:\n   Día: ");
        scanf("%d", &inscritos[i].fe[0].dia);
        printf("   Mes: ");
        scanf("%d", &inscritos[i].fe[0].mes);
        printf("   Año: ");
        scanf("%d", &inscritos[i].fe[0].anio);
        printf("  Fecha de ingreso:\n   Día: ");
        scanf("%d", &inscritos[i].fe[1].dia);
        printf("   Mes: ");
        scanf("%d", &inscritos[i].fe[1].mes);
        printf("   Año: ");
        scanf("%d", &inscritos[i].fe[1].anio);
    }
}

void impAlumnos(Alumno *inscritos, int n){
    int i;
    printf("\n");
    printf("   Lista de Alumnos inscritos:\n");
    for(i = 0; i < n; i++){
        printf("  Alumno %d\n   %s\n   %d\n   Fecha:\n    %d  %d\n    %d  %d\n    %d  %d",i+1, inscritos[i].nombre, inscritos[i].edad, inscritos[i].fe[0].dia, inscritos[i].fe[1].dia, inscritos[i].fe[0].mes, inscritos[i].fe[1].mes, inscritos[i].fe[0].anio, inscritos[i].fe[1].anio);
        printf("\n");
        }
}

void intercambio(Alumno *A, Alumno *B){
    printf("     %p, %p", A, B);
    Alumno  temp = *A;
    *A = *B;
    *B = temp;
}

Alumno * ordenaApe(Alumno *A, int num){
    Alumno * B;
	 int i, j, k;
    B = crearAlumno(num);
	 for (i = 0; i < num; i++){
		B[i] = A[i];
	 }
    printf("\n");
    for(i = 0; i < num; i++){
        for(j = 0; j < num - i - 1; j++){
            for(k = 0; k < strlen(B[j].nombre); k++){
					if((int)B[j].nombre[k] != (int)B[j + 1].nombre[k]){
						if((int)B[j].nombre[k] > (int)B[j + 1].nombre[k]){
						intercambio(&B[j], &B[j + 1]);
                }
					 k = strlen(B[j].nombre);
					}
            }
        }
    }
    return B;
}

void liberarMemoria(Alumno *inscritos){
	printf("   ¡Bloque de memoria %p liberado!\n", inscritos);
   free(inscritos);
   printf("\n");
}

int main() {
    Alumno *A, *B;
    int num;
    printf("Ingresa la cantidad de alumnos a ingresar: ");
    scanf("%d", &num);
    A = crearAlumno(num);
    ingAlumno(A, num);
    printf("\n");
    impAlumnos(A, num);
    B = ordenaApe(A, num);
    printf("\n");
	 printf("   Lista de alumnos ordenada alfabeticamente: \n");
    impAlumnos(B, num);
    printf("\n");
    liberarMemoria(A);
    liberarMemoria(B);
    return 0;
}