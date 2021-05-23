#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main()
{

    Pilha *p = create(5);

    add(p,2);
    add(p,9);
    add(p,3);
    add(p,11);


    printf("Topo: %d\n",top(p));
    printf("Base: %d\n",botton(p));

    printf("Quantidade de elementos inseridos na pilha: %d\n",Size(p));

    pop(p);

 printf("Posicao: %d", Find(p, 11));


    printf("Novo Topo: %d\n",top(p));

    printf("Quantidade de elementos inseridos na pilha: %d\n",Size(p));

    printf("Pilha cheia: %d\n",isFull(p));



    Clear(p);

    printf("\nNovo Topo: %d\n",top(p));
    printf("Quantidade de elementos inseridos na pilha: %d\n",Size(p));

    return 0;


}
