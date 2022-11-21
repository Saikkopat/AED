#include <stdio.h>
#include "Complejo.h"
void manejaMsg(int);
void darComplejos(COMPLEJO, COMPLEJO);
void mostrarComplejosuma(COMPLEJO, COMPLEJO, COMPLEJO);
void mostrarComplejoresta(COMPLEJO, COMPLEJO, COMPLEJO);
float darEscalar();
void mostrarComplejoescalar(COMPLEJO, COMPLEJO);
void mostrarModulo(COMPLEJO, float);
void mostrarConjugado(COMPLEJO, COMPLEJO);
void mostrarPolar(COMPLEJO);
void mostrarRectangular(COMPLEJO);
void main(){
    COMPLEJO C1, C2, C3;
    float escalar1;
    float modulo1;
    C1=crearComplejo();
    C2=crearComplejo();
    C3=crearComplejo();
    darComplejos(C1, C2);
    transformarPolar(C1);
    convertirRectangular(C1);
    C3=suma(C1, C2);
    mostrarComplejosuma(C1, C2, C3);
    C3=resta(C1, C2);
    mostrarComplejoresta(C1, C2, C3);
    escalar1=darEscalar();
    C3=escalar(C1, escalar1);
    mostrarComplejoescalar(C1, C3);
    modulo1=modulo(C1);
    mostrarModulo(C1, modulo1);
    C3=conjugado(C1);
    mostrarConjugado(C1, C3);

    mostrarPolar(C1);
    mostrarRectangular(C1);
}
float darEscalar(){

	float escalar;
	printf("Dar el escalar:  \n");
    	scanf("%f", &escalar);
    	return escalar;

}

void darComplejos(COMPLEJO C1, COMPLEJO C2){
    float r, i;
    printf("Dar la parte real del complejo: 1 \n");
    scanf("%f", &r);
    asignaReal(C1, r);
    printf("Dar la parte imaginaria del complejo: 1 \n");
    scanf("%f", &i);
    asignaImaginario(C1, i);
    printf("Dar la parte real del complejo: 2 \n");
    scanf("%f", &r);
    asignaReal(C2, r);
    printf("Dar la parte imaginaria del complejo: 2 \n");
    scanf("%f", &i);
    asignaImaginario(C2, i);
}

void mostrarComplejosuma(COMPLEJO C1, COMPLEJO C2, COMPLEJO C3){
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("Complejo 2 %f + %fi \n", obtenReal(C2), obtenImaginario(C2));
    printf("La suma es %f + %fi \n", obtenReal(C3), obtenImaginario(C3));
}
void mostrarComplejoresta(COMPLEJO C1, COMPLEJO C2, COMPLEJO C3){
    printf("La resta de los numeros complejos es:  %f + %fi \n", obtenReal(C3), obtenImaginario(C3));
}

void mostrarComplejoescalar(COMPLEJO C1, COMPLEJO C3){
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("El resultado del producto escalar con el numero complejo es %f + %fi \n", obtenReal(C3), obtenImaginario(C3));
}
void mostrarModulo(COMPLEJO C1, float modulo1){
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("El modulo del numero complejo 1 es %f \n", modulo1);
}
void mostrarConjugado(COMPLEJO C1, COMPLEJO C3){
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("El numero complejo 1 conjugado es:  %f + %fi \n", obtenReal(C3), obtenImaginario(C3));
}
void manejaMsg(int msg){
    char *mensajes[]={"No hay memoria disponible..."};
    printf("%s", mensajes[msg]);
}

void mostrarPolar(COMPLEJO C1){
    printf("Complejo 1 %f + %fi \n", obtenReal(C1), obtenImaginario(C1));
    printf("La forma polar del complejo 1 es: %f (%.1lf grados)\n", obtenR(C1), obtenAlfa(C1));
}

void mostrarRectangular(COMPLEJO C){
    printf("Complejo 1 %f + %fi \n", obtenReal(C), obtenImaginario(C));
    printf("La forma rectangular del complejo 1 es: %f + i %f\n", obtenXRectangular(C), obtenYRectangular(C));
}
