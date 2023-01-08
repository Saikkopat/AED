#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void manejaMsg (int msg) {
   char* mensajes[4] = {"   \nNo hay memoria disponible.\n",
                        "   \nMemoria liberada.\n",
                        "   \nCola llena.\n",
                        "   \nCola vacia.\n"};
   printf("%s", mensajes[msg]);
}



int main () {
    
    return 0;
}