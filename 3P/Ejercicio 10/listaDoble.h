#ifndef _listaDoble_
#define _listaDoble_

#define TRUE 1
#define FALSE 0

typedef struct nodoListaDoble {
	int dato;
	struct nodoListaDoble* siguiente;
	struct nodoListaDoble* anterior;
} nodoListaDoble;

typedef nodoListaDoble* LISTADOBLE;

LISTADOBLE crearLista();
int esVaciaLista(LISTADOBLE L);
nodoListaDoble * crearNodoLista();
LISTADOBLE insertar(LISTADOBLE L, int e);
void mostrarLista(LISTADOBLE L);
void mostrarListaInvertida(LISTADOBLE L);
void  buscarElem(LISTADOBLE L, int elem);
LISTADOBLE borrar(LISTADOBLE L, int elem);
void mensajes(int e, int msg, int p);

#endif