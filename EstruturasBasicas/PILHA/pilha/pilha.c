#include<stdio.h>
#include "pilha.h"
#include<stdlib.h>

struct pilha
{
    int tamanho;
    int count;//topo
    int *vet;

};

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(n), LINEAR
Pilha *create(int n)
{

    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));

    //pi->count = 0;

    if(pi == NULL)
    {
        return NULL;
    }

    else
    {
        pi->vet = (int*) malloc(n * sizeof(int));
        pi->tamanho = n;
        return pi;
    }

}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int add(Pilha *pi, int elemento)
{
    if( pi != NULL && pi->count < pi->tamanho)
    {
        int posicaoDaInsercao = pi->count;
        pi->vet[posicaoDaInsercao] = elemento;
        pi->count++;
        return 1;
    }

    else
    {
        exit(1);
        //return 0;
    }
}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int top(Pilha *pi)
{
    if( pi != NULL && !isEmpty(pi))
    {
        int posicaoDoUltimoInserido = pi->count - 1;
        return pi->vet[posicaoDoUltimoInserido];

    }

    else
    {
        return -1;
    }

}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int botton(Pilha *pi)
{
    if( pi != NULL && !isEmpty(pi))
    {
        return pi->vet[0];
    }
}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int isEmpty(Pilha *pi)
{
    if(pi == NULL)
    {
        return 1;
    }

    if(pi->count <= 0)
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
int isFull(Pilha *pi)
{
    if(pi->count == pi->tamanho - 1)
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
int pop(Pilha *pi)
{
    if( pi != NULL && !isEmpty(pi))
    {
        pi->count = pi->count - 1;
        return pi->vet[pi->count];
    }

    else
    {
        return 0;
    }

}


//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int Size(Pilha *pi)
{
    if( pi != NULL)
    {
        return pi->count;
    }
}


//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(c), CONSTANTE
int Find(Pilha *pi, int dado)
{
    for(int i = 0; i < pi->count; i++)
    {
        if(pi->vet[i] == dado)
        {
            int pos = i;
            return pos;
        }
    }

    return -1;

}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int Clear(Pilha *pi)
{
    free(pi->vet);
    free(pi);

}








