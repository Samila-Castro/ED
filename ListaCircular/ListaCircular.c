#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

ListaCircular *create()
{
    ListaCircular *lista = (ListaCircular *)malloc(sizeof (ListaCircular));

    if(lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

int add(ListaCircular *lista, int valor)
{

    No* pnovo = (No*) malloc(sizeof(No));

    if(pnovo != NULL)
    {
        pnovo->valor = valor;


        if(lista->inicio == NULL)
        {
            lista->inicio = pnovo;
            pnovo->anterior = lista->inicio;

        }
        else
        {
            lista->fim->proximo = pnovo;
            pnovo->anterior = lista->fim;
            lista->inicio->anterior = pnovo;

        }
        pnovo->proximo = lista->inicio;
        lista->fim = pnovo;
        lista->tamanho++;
        return 1;
    }

    return 0;
}


int pop(ListaCircular *lista, int chave)
{

    if (!isEmpty(lista))
    {


        No *alvo = lista->inicio;

        if( lista->tamanho == 1)
        {
            if( lista->inicio->valor == chave)
            {
                free(lista->inicio);
                lista->inicio = NULL;
                lista->fim = NULL;
                lista->tamanho = 0;
                return 1;
            }

        }
        else
        {
            do
            {
                if(alvo->valor == chave)
                {
                    alvo->anterior->proximo = alvo->proximo;
                    alvo->proximo->anterior = alvo->anterior;
                    if(lista->inicio == alvo)
                    {
                        lista->inicio = alvo->proximo;
                    }
                    if(lista->fim == alvo)
                    {
                        lista->fim = alvo->anterior;
                    }

                    lista->tamanho--;
                    free(alvo);
                    return 1;
                }
                alvo = alvo->proximo;
            }
            while(alvo != lista->inicio);

        }
    }
    return -1;
}

int Find(ListaCircular* lista, int valor)
{

    if (!isEmpty(lista))
    {

        int position = 1;
        No *alvo = lista->inicio;


        do
        {
            if(alvo->valor == valor)
            {
                return position;
            }
            position++;
            alvo = alvo->proximo;
        }
        while(alvo != lista->inicio);

    }
    return -1;

}

void Clear(ListaCircular* lista)
{

    if (!isEmpty(lista))
    {

        No *alvo = lista->inicio;

        if(lista->tamanho == 1)
        {
            free(alvo);
        }
        else
        {
            do
            {
                No *aux = alvo->proximo;
                free(alvo);
                alvo = aux;
            }
            while(alvo != lista->fim);

            free(lista->fim);
        }

        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return -1;

}


int isEmpty(ListaCircular* lista)
{
    return lista->tamanho <= 0;
}

void printListaEncadeada(ListaCircular* lista)
{

    printf("\n----------IMPRIMINDO LISTA -------------\n\n");

    printf("Lista [tamanho: %i, limite: quantidade de memoria alocavel] \n\n", lista->tamanho);

    if(isEmpty(lista))
        printf("Lista esta vazia.\n");
    else
    {
        No *alvo = lista->inicio;

        do
        {
            printNo(alvo);
            alvo = alvo->proximo;
        }
        while(alvo != lista->inicio);
    }

}

int Size(ListaCircular* lista)
{

    if(lista != NULL)
    {
        return (lista->tamanho);
    }


}
