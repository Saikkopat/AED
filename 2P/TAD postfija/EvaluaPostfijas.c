#include<stdio.h>
#include<stdlib.h>

#define TAM 100


float pila[TAM];
int tope=-1;   

void manejaError(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n"};
  printf("%s", errores[e]);
}

/* Anadir un elemento a la Pila*/
void apilar(float x){
  if(tope == TAM -1){
     manejaError(1);
     exit(0);
 }
  tope++;
  pila[tope]=x;
}
int es_vaciaPila( ){
    if(tope<0)
	return 1;
    return 0;
}

/* Sacar un elemento de la Pila */
float desapilar(){
  float x;
  // Se verifica que la Pila no este vacia
  if (es_vaciaPila()==1){    
     manejaError(2);
     exit(0);
  }
  x=pila[tope];
  tope--;
  return x;
}

/* Lee una expresión en Postfija */
void lee(char *ent){

  int pos=0;
  
  printf("\n\tEvaluacion de expresiones Postfijas\n");
  printf("Operaciones Basicas: Suma, Resta, Producto y Division\n\n");
  printf("\n\n Introduzca la expresion en Postfija: ");
  while( (ent[pos++] = getchar()) != '\n');
  ent[--pos]='\0';
}


/*Evalua la expresion*/
float evalua(char *ent){
  float a,b;
  double conv;
  int pos=0;
  char op[1];

  while(ent[pos] != '\0'){
      *op = ent[pos++];
      
      switch(*op){
        case '+': b=desapilar();
                  a=desapilar();
                  apilar(a+b);
                  break;
       case '-': b=desapilar();
                 a=desapilar();
                 apilar(a-b);
                 break;
       case '*': b=desapilar();
                 a=desapilar();
                 apilar(a*b);
                 break;
       case '/': b=desapilar();
                 a=desapilar();
                 if(b==0){
					printf("\n\n Division por CERO\n");
                    exit(0);
                }
                apilar(a/b);
                break;
      default: conv = atof(op);//convierte un caracter a float
               apilar(conv); //Almacena el valor (numero) en la pila

      }
  }
return (desapilar());
}

void mostrarSalida(char * ent, float ev){
   printf("\n\n\t %s = %.2f \n\n", ent, ev);
}
/*Programa Principal*/
void main(){
  float ev;
  char ent[TAM];
  
  lee(ent);
  ev = evalua(ent);
  mostrarSalida(ent, ev);  
}

