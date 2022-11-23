#ifndef _vector_
#define _vector_
#define FALSE 0
#define TRUE 1

typedef struct {
	int * vec;
	int tam;
} vector;

typedef vector * VECTOR;

VECTOR crearVector (int t);
int obtenComponente (VECTOR V, int p);
void ponComponente (VECTOR V, int p, int e);
int tamano(VECTOR V);

#endif