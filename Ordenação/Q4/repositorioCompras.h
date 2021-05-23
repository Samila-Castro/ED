#include <stdio.h>
#include <stdlib.h>
#include "compra.h"

typedef struct
{
    Compra **repositorio;
    int cont;
    int tam;
} RepoCompras;


RepoCompras *create(int n);

Compra* tratar(RepoCompras *repo);

int add(RepoCompras* repo, Compra* comp);

void esvaziarRepo(RepoCompras *repo);

int tamanho(RepoCompras *repo);

int pesquisarValor(RepoCompras *repo, float valor);

int pesquisarCodigo(RepoCompras *repo, int codigo);

int estaVazio(RepoCompras *repo);

int estaCheio(RepoCompras *repo);

void printRepoCompras(RepoCompras *repo);

RepoCompras* Merge(RepoCompras *repo, int inicio, int meio, int fim);

void mergeSort(RepoCompras *repo, int inicio, int fim);



