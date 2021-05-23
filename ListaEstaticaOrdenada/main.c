#include <stdio.h>
#include <stdlib.h>
#include "ListaEstaticaOrdenada.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	ListaEstaticaOrdenada* lista = create(10);

	printAll(lista);

	add(lista, 10);

	printAll(lista);

	add(lista, 5);

	printAll(lista);

	add(lista, 2);

	printAll(lista);

	add(lista, 1);

	printAll(lista);

	add(lista, 25);

	printAll(lista);

	add(lista, 20);

	printAll(lista);

	add(lista, 8);

	printAll(lista);

	add(lista, -1);

	printAll(lista);

	add(lista, 30);

	printAll(lista);

	add(lista, -1);

	printAll(lista);




	return 0;
}
