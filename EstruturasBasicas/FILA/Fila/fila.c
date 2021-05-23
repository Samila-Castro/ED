#include<stdio.h>
#include "fila.h"
#include<stdlib.h>


struct fila
{
    int inicio;
    int fim;
    int tam;
    int *vetor;
    int numeroItens;
};


//Complexidade temporal = O(c), classe assintótica CONSTANTE
//Complexidade espacial = O(n), LINEAR

Fila *create(int n)
{
    Fila *fi = (Fila*)malloc(sizeof(Fila));

    if(fi == NULL)
    {
        return NULL;
    }

    else
    {
        fi->vetor = (int*)malloc(n * sizeof(int));//n
        fi->tam = n;
        fi->inicio = 0;
        fi->fim = -1;
        fi->numeroItens = 0;
        return fi;
    }
}

//Complexidade temporal = O(c), classe assintótica CONSTANTE
//Complexidade espacial = O(c), constante
int add(Fila *fi, int elemento)
{
    if(fi != NULL && !isFull(fi))
    {
        fi->fim++;
        fi->vetor[fi->fim] = elemento;
        fi->numeroItens++;

        return 1;
    }

    else
    {

        return 0;

    }
}

int pop(Fila *fi)
{


    /*
        if(fi != NULL && !isEmpty(fi)){
        int aux = fi->vetor[fi->inicio++];


            fi->numeroItens--;
            //return aux;
            return 1;
        }

        else {
            return 0;
        }

    }
    */

    //Complexidade temporal = O(n), classe assintótica LINEAR
    //Complexidade espacial = O(c), constante

    if(fi != NULL && !isEmpty(fi))
    {
        int i = 0;

        int k = 0;

        int *novoVetor = (int*) malloc(fi->tam * sizeof(int));


        for(i = 1; i< fi->numeroItens; i++)
        {

            novoVetor[k] = fi->vetor[i];
            k++;
        }

        fi->numeroItens--;
        fi->fim--;
        free(fi->vetor);
        fi->vetor = novoVetor;

        return 1;

    }

    else
    {
        return 0;
    }
}


//Complexidade temporal = O(c), classe assintótica CONSTANTE
//Complexidade espacial = O(c), constante
int first(Fila *fi)
{

    if( fi != NULL && !isEmpty(fi))
    {
        int posicaoDoPrimeiroInserido = fi->inicio;
        return fi->vetor[posicaoDoPrimeiroInserido];
    }

    else
    {
        return -1;
    }
}



//Complexidade temporal = O(c), classe assintótica CONSTANTE
//Complexidade espacial = O(c) , constante
int last(Fila *fi)
{

    if( fi != NULL && !isEmpty(fi))
    {
        int posicaoDoUltimoInserido = fi->fim;
        return fi->vetor[posicaoDoUltimoInserido];
    }

    else
    {
        return -1;
    }


}

//Complexidade temporal = O(c), classe assintótica CONSTANTE

int Size(Fila *fi)
{
    if( fi != NULL)
    {
        return fi->numeroItens;
    }
}

//Complexidade temporal = O(c), classe assintótica CONSTANTE

int isFull(Fila *fi)
{
    if(fi->numeroItens == fi->tam)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

//Complexidade temporal = O(c), classe assintótica CONSTANTE

int isEmpty(Fila *fi)
{
    if(fi == NULL)
    {
        return 1;
    }

    if(fi->numeroItens <= 0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

//Complexidade temporal = O(c) , classe assintótica CONSTANTE


void clear(Fila *fi)
{
    free(fi->vetor);
    free(fi);
}


//Complexidade temporal = O(2n) = O(n), classe assintótica LINEAR
//Complexidade espacial = O(c), constante

void printAll(Fila *fi)
{


    for(int i = 0; i< fi->numeroItens; i++)//n
    {
        printf("fi->vetor[%i] = %i \n", i,fi->vetor[i]);//n
    }
}


