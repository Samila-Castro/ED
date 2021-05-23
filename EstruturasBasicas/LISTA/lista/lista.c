#include<stdio.h>
#include<stdlib.h>
#include "lista.h"



struct listaEstatica
{
    int *vetor;
    int cont;
    int tam;
};

LISTA *create(int n)
{
    LISTA *li = (LISTA*)malloc(sizeof(LISTA));

    if(li == NULL)
    {
        return NULL;
    }
    else
    {
        li->vetor = (int*)malloc(n * sizeof(int));
        li->tam = n;
        li->cont = 0;
        return li;

    }
}

int add(LISTA *li, int elemento)
{
    if(li!= NULL  && li->cont < li->tam)
    {
        li->vetor[li->cont] = elemento;
        li->cont++;
        return 1;
    }
    else
    {

        return 0;
    }

}

int Remove(LISTA *li, int elemento)
{
    if(li != NULL && !isEmpty(li))
    {

        if(Find(li,elemento))
        {

            int *vetorNovo = (int*)malloc(li->cont * sizeof(int));

            int x = 0;
            int contAux = li->cont;
            for(int i = 0; i < contAux; i++)
            {

                if(li->vetor[i] != elemento)
                {
                    vetorNovo[x] = li->vetor[i];
                    x++;

                }
                else
                {
                    li->cont--;
                }

            }

            free(li->vetor);
            li->vetor = vetorNovo;



            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}




int Find(LISTA *li, int elemento)
{
    for(int i = 0; i < li->tam; i++)
    {
        if(li->vetor[i] == elemento)
        {
            int pos = li->vetor[i];
            return pos;
        }
        else
        {
            return -1;
        }

    }
}

int Size(LISTA *li)
{
    if(li != NULL)
    {
        return li->cont;
    }

}


int isFull(LISTA *li)
{
    if(li->tam == li->cont)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(LISTA *li)
{
    if(li == NULL)
    {
        return 1;
    }

    if(li->cont <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void clear(LISTA *li)
{
    free(li->vetor);
    free(li);
}

void printAll(LISTA *li)
{


    for(int i = 0; i< li->cont; i++)
    {
        printf("li->vetor[%i] = %i \n", i, li->vetor[i]);
    }
}



