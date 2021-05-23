#include<stdio.h>
#include<stdlib.h>
#include "ListaEstaticaOrdenada.h"


//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(n), LINEAR
ListaEstaticaOrdenada *create(int n)
{
    ListaEstaticaOrdenada *li = (ListaEstaticaOrdenada*)malloc(sizeof(ListaEstaticaOrdenada));

    if(li == NULL)
    {
        return NULL;
    }
    else
    {
        li->vetor = (int*) calloc(n * sizeof(int), n);
        li->tam = n;
        li->cont = 0;
        return li;

    }
}
//Complexidade temporal = O(2n), classe asintótica LINEAR
//Complexidade espacial = O(c), CONSTANTE
int add(ListaEstaticaOrdenada *li, int elemento)
{

    if(li!= NULL  && li->cont < li->tam)
    {

        int i, posicao = li->cont;

        for(i = 0; i< li->cont; i++)
        {

            if( elemento < li->vetor[i])
            {
                posicao = i;
                break;
            }
        }

        if(posicao != li->cont)
        {

            for(i = li->cont+1; i > posicao; i--)
            {

                swap(li->vetor, i - 1, i);
                printAll(li);
            }
        }

        li->vetor[posicao] = elemento;
        li->cont++;

        return 1;
    }
    else
    {

        return 0;
    }

}
//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
void swap(int* v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(N), LINEAR
int Remove(ListaEstaticaOrdenada *li, int elemento)
{
    if(li != NULL && !isEmpty(li))
    {



        int *vetorNovo = (int*)calloc(li->tam * sizeof(int), li->tam);

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





//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int Find(ListaEstaticaOrdenada *li, int elemento)

{
    for(int i = 0; i < li->tam; i++)
    {
        if(li->vetor[i] == elemento)
        {
            int pos = i;
            return pos;
        }
        else if(li->vetor[i] > elemento)
        {
            return -1;
        }
    }

    return -1;
}
//Complexidade temporal = O(log n), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int bynarySearch(ListaEstaticaOrdenada *li, int chave)
{
    int left =  0;
    int rigth = li->cont;

    while( left <= rigth)
    {
        int midlle = (left + rigth)/2;

        if(li->vetor[midlle] == chave)
        {
            return midlle;
        }
        else if(li->vetor[midlle] > chave)
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


//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int Size(ListaEstaticaOrdenada *li)
{
    if(li != NULL)
    {
        return li->cont;
    }

}

//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int isFull(ListaEstaticaOrdenada *li)
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
//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
int isEmpty(ListaEstaticaOrdenada *li)
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
//Complexidade temporal = O(c), classe asintótica CONSTANTE
//Complexidade espacial = O(c), CONSTANTE
void Clear(ListaEstaticaOrdenada *li)
{
    free(li->vetor);
    free(li);
}
//Complexidade temporal = O(n), classe asintótica LINEAR
//Complexidade espacial = O(c), CONSTANTE
void printAll(ListaEstaticaOrdenada* li)
{

    int i = 0;

    printf("\nLista ");

    if(li->cont > 0)
    {

        printf("[");

        for(i = 0 ; i < li->tam; i++)
        {
            printf(" %i ", li->vetor[i]);
        }

        printf("]\n");

    }
    else
        printf("[ ]\n");
}





