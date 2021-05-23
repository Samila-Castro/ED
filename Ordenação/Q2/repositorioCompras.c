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

/*
    Selection Sort é um método em que o menor item dentro vetor
    e colocá-lo na primeira posição, selecionar o segundo menor
    e colocá-lo na segunda posição, repetindo esse procedimento
    até que sobre apenas um elemento. Sua complexidade temporal é
    classificada em notação Big O como pior caso -> O(n²),
    Quadrática, e espacial -> O(c), Constante.

*/

void selectionSort(RepoCompras *repo)
{

    int i,j, posicaoMin;


    for(i = 0; i< repo->cont - 1; i++)
    {
        posicaoMin = i;
        for(j = i + 1; j < repo->cont; j++)
        {
            if(repo->repositorio[j]->valor < repo->repositorio[posicaoMin]->valor)
            {
                posicaoMin = j;
            }


        }

        if  ( posicaoMin  !=  i )
        {
            Swap(repo,i, posicaoMin);
        }

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


