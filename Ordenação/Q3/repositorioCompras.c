
#include <stdio.h>
#include <stdlib.h>
#include "repositorioCompras.h"



RepoCompras* create(int n)
{
    RepoCompras *repo = (RepoCompras*)malloc(sizeof(RepoCompras));
    repo->tam = n;
    repo->cont = 0;



    repo->repositorio = (Compra**)malloc(sizeof(Compra*) * n);

    return repo;
}


int add(RepoCompras *repo, Compra *comp)
{

    if(repo!= NULL  && repo->cont < repo->tam)
    {

        repo->repositorio[repo->cont] = comp;
        repo->cont++;

        return 1;
    }
    else
    {
        return 0;
    }

}


/*A ideia deste algoritimo é sempre iterar toda o vetor de itens quantas vezes forem necessárias, até que os itens estejam na ordem correta.
Durante a iteração, o algoritmo deve comparar e ordenar pares de valores: O item que se está iterando e o seu vizinho à direita.
A complexidade temporal desse algotritmo é:
pior caso -> O(n²), Classe assintôtica Quadrática, e espacial -> O(c), Constante.
*/
RepoCompras* bubbleSort(RepoCompras *repo)
{

    if(repo!= NULL)
    {
        int i,j, aux;

        for(i = 0; i < repo->cont - 1; i++)
        {
            for(j = 0; j < repo->cont - i - 1; j++)
            {
                if(repo->repositorio[j]->valor > repo->repositorio[j + 1]->valor)
                {
                    aux = repo->repositorio[j];
                    repo->repositorio[j] = repo->repositorio[j + 1];
                    repo->repositorio[j + 1] = aux;
                }
            }
        }

    }

    return repo;

}



    Compra* tratar(RepoCompras *repo)
    {
        if(repo != NULL && !estaVazio(repo))
        {



            Compra** NovoRepositorio = (Compra**)malloc(repo->cont * sizeof(Compra));

            int j = 0;
            int contAux = repo->cont;



            Compra *maiorValor = repo->repositorio[contAux-1];
            //printf("Posição da compra de Maior valor: %d\n", *maiorValor);

            for(int i = 0; i < contAux-1; i++)
            {
                NovoRepositorio[j] = repo->repositorio[i];
                j++;


            }
            repo->cont--;



            free(repo->repositorio);
            repo->repositorio = NovoRepositorio;

            return maiorValor;

        }
        return NULL;
    }




    int tamanho(RepoCompras *repo)
    {
        if(repo != NULL)
        {
            return repo->cont;
        }
    }

    int pesquisarValor(RepoCompras *repo, float valor)
    {
        int left =  0;
        int rigth = repo->cont;

        while( left <= rigth)
        {
            int midlle = (left + rigth)/2;

            if(repo->repositorio[midlle]->valor == valor)
            {
                return midlle;
            }
            else if(repo->repositorio[midlle]->valor > valor)
            {
                rigth = midlle - 1;
            }
            else
            {
                left = midlle + 1;
            }
        }
        return -1;

    }

    int pesquisarCodigo(RepoCompras *repo, int codigo)

    {
        for(int i = 0; i < repo->cont; i++)
        {

            if(repo->repositorio[i]->codigo == codigo )
            {
                return i;

            }
        }

        return -1;
    }


    int estaCheio(RepoCompras *repo)
    {
        if(repo->tam == repo->cont)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

    int estaVazio(RepoCompras *repo)
    {
        if(repo == NULL)
        {
            return 1;
        }

        if(repo->cont <= 0)
        {
            return 1;
        }

        else
        {
            return 0;
        }

    }

    void esvaziarRepo(RepoCompras *repo)
    {
        free(repo->repositorio);
        free(repo);
    }

    void printRepoCompras(RepoCompras *repo)
    {

        if(repo != NULL && repo->cont > 0)
        {

            printf("\n!! Printando Repositotio de compras !!\n");

            int i = 0;

            for(i = 0; i < repo->cont; i++)
            {
                if(repo->repositorio[i]!=NULL)
                {
                    Compra *comp = repo->repositorio[i];
                    printCompra(comp);
                }
            }

        }
        else
            printf("!!Repositorio vazio !!\n");

    }



