/*
	Hecho por Gónzalez Cárdenas Ángel Aquilez, 2CM5.
	Escrito en Visual Studio Code, compilado con gcc (GCC) 12.1.1 20220730.
	Comando utilzado: gcc Ejercicio3_Gonzalez_Cardenas_AngelAquilez_2CM5.c -Wall -o opt, ./opt
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *nombre[30];
    int *edad;
    char sexo;
    char *departamento[40];
    int salario;
} Empleado;

Empleado *crearEmpleado(int num){
    Empleado *nuevo;
    nuevo = (Empleado*)malloc(num * sizeof(Empleado));
    if (nuevo == NULL){
        printf("No es posible crear empleado.\n");
        exit(0);
    }
    return nuevo;
}

void ingEmpleado(Empleado *pointer, int num){
    int i;
    for(i = 0; i < num; i++){
        printf(" Introduce la información del Empleado #%d:\n Nombre: ", i);
        *pointer[i].nombre = (char *)malloc(sizeof(char));
		  scanf("%s", *pointer[i].nombre);
        printf(" Edad: ");
		  pointer[i].edad = (int *)malloc(sizeof(int));
        scanf("%d", &(*pointer[i].edad));
        printf(" Sexo (F/M): ");
        scanf("%s", &pointer[i].sexo);
        printf(" Departamento: ");
		  *pointer[i].departamento = (char *)malloc(sizeof(char));
        scanf("%s", *pointer[i].departamento);
        printf(" Salario: ");
        scanf("%d", &pointer[i].salario);
    }
}

void imprimirEmpleados(Empleado * pointer, int num){
	int i;
	for(i = 0; i < num; i++){
		printf("%d", i);
		printf("   Empleado #%d : %s, %d, %c, Departamento: %s, $%d\n", i, *pointer[i].nombre, *pointer[i].edad, pointer[i].sexo, *pointer[i].departamento, pointer[i].salario);
	}
}

void liberarMemoria(Empleado * pointer){
	free(pointer);
	printf("\n¡Memoria liberada!\n");
}

void intercambio(Empleado *emp1, Empleado *emp2){
	Empleado tempo = *emp1;
	*emp1 = *emp2;
	*emp2 = tempo;
}

void comparacionSalarios(Empleado *pointer, int num){
    int i, j;
	 for(i = 0; i < num - 1; i++){
		for(j = 0; j < num - i - 1; j++){
			if(pointer[j].salario > pointer[j + 1].salario)
				intercambio(&pointer[j], &pointer[j + 1]);
		}
	 }
	 printf("\n  El que mas gana: %s, %d.\n", *pointer[num - 1].nombre, pointer[num - 1].salario);
	 printf("  El que menos gana: %s, %d.\n", *pointer[0].nombre, pointer[0].salario);
}

int main(){
   Empleado *nomina;
   int num;
   printf("Introduce el número de empleados a ingresar: ");
   scanf("%d", &num);
   nomina = crearEmpleado(num);
   ingEmpleado(nomina, num);
	printf("\n\n"); 
	imprimirEmpleados(nomina, num);
	comparacionSalarios(nomina, num);
	liberarMemoria(nomina);
	return 0;
}