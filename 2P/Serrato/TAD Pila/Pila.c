#include<stdlib.h>
#include "Pila.h"
#include<stdio.h>

void manejaMsg(int);

PILA crearPila(){
    PILA S;
    S=(PILA)malloc(sizeof(Pila));
    if(S== NULL){
         manejaMsg(0);
         exit(0);
    }
    S->tope=-1;
    return S;
}

int es_vaciaPila(PILA S){
    if(S->tope==-1){
       return TRUE;
    }
    return FALSE;
}

void apilar(PILA S, int e){
    if(S->tope==TAM-1){
        manejaMsg(2);
        exit(0);
    }
    (S->tope)++;
    S->pila[S->tope]=e;
}

int desapilar(PILA S){
    int a;
    if(es_vaciaPila(S)==TRUE){
        manejaMsg(3);
        exit(0);
    }
    a=S->pila[S->tope];
    (S->tope)--;
    return a;

}
int elemTope(PILA S){
    int a;
    if(es_vaciaPila(S)==TRUE){
        manejaMsg(3);
        exit(0);
    }
    a=S->pila[S->tope];
    return a;
}
void manejaMsg(int msg){
     char * mensajes[] = {"\nNo hay memoria disponible . . .", "\n Se ha liberado la memoria . . .  ", "\n La pila esta llena", "\n La pila esta vacia"};
     printf("%s", mensajes[msg] );
}
