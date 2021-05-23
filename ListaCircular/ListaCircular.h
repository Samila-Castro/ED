
 #include <stdio.h>
#include <stdlib.h>
#include "No.h"

typedef struct {
	 No *inicio;
	 No *fim;
	 int tamanho;
} ListaCircular;

ListaCircular* create();

int add(ListaCircular* lista, int valor);

int pop(ListaCircular *lista, int chave);

int isEmpty(ListaCircular* lista);

void printListaEncadeada(ListaCircular* lista);

