
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

int add(RepoCompras *repo, Compra *comp);

void selectionSort(RepoCompras* repo);

void esvaziarRepo(RepoCompras *repo);

void Swap(RepoCompras *repo, int i, int j);

int tamanho(RepoCompras *repo);

int pesquisarValor(RepoCompras *repo, float valor);

int pesquisarCodigo(RepoCompras *repo, int codigo);

int estaVazio(RepoCompras *repo);

int estaCheio(RepoCompras *repo);

void printRepoCompras(RepoCompras *repo);
