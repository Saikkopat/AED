#ifndef _listaSimple_
#define _listaSimple_

#define TRUE 1
#define FALSE 0

typedef struct nodoLista {
	int dato;
	struct nodoLista* siguiente;
} nodoLista;

typedef nodoLista* LISTA;

LISTA crearLista();
int esVaciaLista(LISTA L);
nodoLista * crearNodoLista();
LISTA insertar(LISTA L, int e);
void mostrarLista(LISTA L);
void  buscarElem(LISTA L, int elem);
LISTA borrar(LISTA L, int elem);
void mensajes(int e, int msg, int p);

#endif