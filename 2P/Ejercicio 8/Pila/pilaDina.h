#ifndef pilaDina
#define pilaDina

#define TRUE 1
#define FALSE 0

typedef struct nodoPila {
	char dato;
	struct nodoPila* anterior;
} nodoPila;

typedef struct {
	nodoPila* tope;
} Pila;
typedef Pila* PILA;

PILA crearPila();
int es_vaciaPila (PILA S);
nodoPila *crearNodoPila ();
char elemTope (PILA S);
void apilar (PILA S, char e);
char desapilar (PILA S);

#endif