#include <stdio.h>
#include <stdlib.h>
#include "repositorioCompras.h"


//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(n), LINEAR
RepoCompras* create(int n)
{
    RepoCompras *repo = (RepoCompras*)malloc(sizeof(RepoCompras));
    repo->tam = n;
    repo->cont = 0;

    repo->repositorio = (Compra**)malloc(sizeof(Compra*) * n);

    return repo;
}

//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(c), CONSTANTE
int add(RepoCompras *repo, Compra *comp)
{

    if(repo!= NULL  && repo->cont < repo->tam)
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


        return 1;
    }
    else
    {

        return 0;
    }

}

/*
    Partição
*/
int Quick(RepoCompras *repo, int inicio, int fim)
{



    Compra *pivot = repo->repositorio[fim];

    int i = (inicio - 1);

    for(int j = inicio; j <= fim - 1; j++)
    {
        if(repo->repositorio[j]->valor < pivot->valor)
        {
            i++;
            Swap(repo, i, j);
        }
    }

    Swap(repo, i+1, fim);
    return (i+1);
}
/*
    Esse método foi criado pelo cientista da computação Tony Hoare em 1960 e publicado em 1962. A idéia básica do Quick sort é dividir o problema de ordenar um conjunto com n itens em dois sub-problemas menores. Os problemas menores são ordenados independentement e os resultados são combinados para produzir a solução final. A parte I do problema é onde é feita uma partição no conjunto de elementos e feita uma ordenação dos elementos com base na escolha de um pivô, onde todos os elementos menores que esse pivô serão ordenados à esquerda desse pivô e os elementos  maiores que esse pivô, são ordenados mais a direita desse pivô. Há formas de efetuar a escolha desse pivÔ, pode ser o primeior elemento do conjunto, pode ser oúltimo, ou pode ocorrer uma escolha aleatória no conjunto. Nesta implementação, o último elemento será escolhido como pivô.
Complexidade: pior caso -> O(n²), classe assintótica Quadrática, espacial O(n)
              melhor caso -> O(n log n)
              
*/
RepoCompras* QuickSort(RepoCompras *repo, int inicio, int fim)
{
    if(inicio < fim)
    {
        int pivot = Quick(repo,inicio,fim);

        QuickSort(repo,inicio, pivot - 1);
        QuickSort(repo,pivot + 1, fim);
    }


}




//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(n), LINEAR
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

//Complexidade temporal = O(n), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
void Swap(RepoCompras *repo, int i, int j)
{
    Compra* aux = repo->repositorio[i];
    repo->repositorio[i] = repo->repositorio[j];
    repo->repositorio[j] = aux;
}

//Complexidade temporal = O(n), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int tamanho(RepoCompras *repo)
{
    if(repo != NULL)
    {
        return repo->cont;
    }
}

//Complexidade temporal = O(log (n)), classe asintótica LOGARITMICA
//Complexidade espacial = O(c), CONSTANTE
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

//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(c), CONSTANTE
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


//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
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

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
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

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
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


