#include <stdio.h>
#include <stdlib.h>
#include "compra.h"


Compra* createCompra(int codigo, float valor)
{
    Compra *comp = (Compra*)malloc(sizeof(Compra));

    comp->codigo = codigo;
    comp->valor = valor;

    return comp;
}

void printCompra(Compra *comp)
{

    if(comp != NULL)
    {
        printf("-----------------------\n");
        printf("Compra  cod: %i\n \tvalor: %2.f \n", comp->codigo, comp->valor);
    }
}
