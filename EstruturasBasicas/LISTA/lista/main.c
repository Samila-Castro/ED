#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    LISTA *li = create(6);

    add(li, 7);
    add(li, 2);
    add(li, 3);
    add(li, 7);

    printf("Qtd de itens adicionados: %d\n", Size(li));
    Remove(li,3);
    printf("Qtd de itens adicionados: %d\n", Size(li));
    add(li, 5);
    printf("Qtd de itens adicionados: %d\n", Size(li));

    printAll(li);
    return 0;
}
