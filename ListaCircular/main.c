#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	ListaCircular * lista = create();

	printListaEncadeada(lista);

	add(lista, 10);

	printListaEncadeada(lista);

	add(lista, 5);

	printListaEncadeada(lista);

	add(lista, 15);

	add(lista, 25);

	add(lista, 50);

	printListaEncadeada(lista);

    printf("%d",pop(lista, 15));

	printListaEncadeada(lista);

	return 0;
}
