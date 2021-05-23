#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(int argc, char *argv[]) {

	ListaEncadeada * lista = create();

	printListaEncadeada(lista);

	add(lista, 10);

	printListaEncadeada(lista);

	add(lista, 5);

	printListaEncadeada(lista);

	add(lista, 15);

	add(lista, 25);

	add(lista, 50);

	printListaEncadeada(lista);

	pop(lista, 10);

	printListaEncadeada(lista);

	printf("Find 15: %d",Find(lista, 15));

	printf("Find 35: %d",Find(lista, 35));

   	Clear(lista);

	printListaEncadeada(lista);

    add(lista, 10);

	printListaEncadeada(lista);


	//printListaEncadeada(lista);

	//pop(lista, 25);

	//printListaEncadeada(lista);

	//pop(lista, 5);

	//printListaEncadeada(lista);



	return 0;
}
