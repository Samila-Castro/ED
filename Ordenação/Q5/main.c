#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>
#include "repositorioCompras.h"
    int main()
    {

        RepoCompras* repo = create(6);

        Compra *comp =  createCompra(1, 8);
        Compra *comp1 = createCompra(2, 10);

        Compra *comp2 = createCompra(3, 1);

        Compra *comp3 = createCompra(4, 16);

        Compra *comp4 = createCompra(5, 13);
        Compra *comp5 = createCompra(6, 4);




        add(repo,comp);
        add(repo,comp1);
        add(repo,comp2);
        add(repo,comp3);
        add(repo,comp5);
        add(repo,comp4);


        printRepoCompras(repo);


        QuickSort(repo,0,5);

        printRepoCompras(repo);


        return 0;
    }
