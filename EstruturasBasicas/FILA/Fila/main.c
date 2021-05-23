#include<stdio.h>
#include "fila.h"
#include<stdlib.h>


int main()
{
    Fila *fi = create(10);
    add(fi,5);
    add(fi, 15);
    add(fi,25);


    printf("Primeiro elemento inserido: %d\n", first(fi));
    printf("Ultimo elemento inserido: %d\n", last(fi));
    printf("Quantidade de elementos adicionados: %d\n", Size(fi));
    printAll(fi);
    pop(fi);


    printf("Primeiro elemento inserido: %d\n", first(fi));
    printf("Ultimo elemento inserido: %d\n", last(fi));

    printAll(fi);
    printf("Quantidade de elementos adicionados: %d\n", Size(fi));




}
