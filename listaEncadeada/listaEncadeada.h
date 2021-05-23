#include <stdio.h>
#include <stdlib.h>
#include "No.h"

typedef struct {
	 No *inicio;
	 No *fim;
	 int tam;
} ListaEncadeada;

ListaEncadeada* create();

int add(ListaEncadeada* lista, int valor);

int pop(ListaEncadeada *lista, int chave);

int isEmpty(ListaEncadeada* lista);

int Size(ListaEncadeada* lista);

void Clear(ListaEncadeada* lista);

int Find(ListaEncadeada* lista, int valor);

void printListaEncadeada(ListaEncadeada* listaEncadeada);
