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

RepoCompras* Merge(RepoCompras *repo, int inicio, int meio, int fim)
{
    int i, j, k;
    int tamVetorEsq = meio - inicio + 1;
    int tamVetorDireito = fim - meio;

    Compra** vetorEsquerdo = (Compra**)malloc(tamVetorEsq * sizeof(Compra));
    Compra** vetorDireito = (Compra**)malloc(tamVetorDireito * sizeof(Compra));


    for (i = 0; i < tamVetorEsq; i++){
        vetorEsquerdo[i] = repo->repositorio[inicio + i];
    }

    for (j = 0; j < tamVetorDireito; j++){
        vetorDireito[j] = repo->repositorio[meio + 1 + j];
    }


    i = 0;
    j = 0;
    k = inicio;
    while (i < tamVetorEsq && j < tamVetorDireito) {
        if (vetorEsquerdo[i]->valor <= vetorDireito[j]->valor) {
            repo->repositorio[k] = vetorEsquerdo[i];
            i++;
        }
        else {
            repo->repositorio[k] = vetorDireito[j];
            j++;
        }
        k++;
    }


    while (i < tamVetorEsq) {
        repo->repositorio[k] = vetorEsquerdo[i];
        i++;
        k++;
    }


    while (j < tamVetorDireito) {
        repo->repositorio[k] = vetorDireito[j];
        j++;
        k++;
    }
}

/*
    Mergesort é um método de ordenação que utiliza a ideia de 
    dividir para conquistar. Este método foi criado pelo matemático John Von Neumann    
A lógica desse método é basicamente dividir o vetor não classificado em n subvetores, cada um contendo um elemento. Depois que esse vetor estiver classificado, ou seja, todos os subvetores contiverem apenas um elemento, ocorrerá a fusão desses subvetores para produzir novos subvetores ordenados até que haja apenas um vetor restante e este será o vetor restante e ordenado.
Sua complexidade temporal é classificada em notação Big O como O(n log n)/pior caso, classe assintótica Linear logaritmica, e espacial O(n), Linear.
    

*/
void mergeSort(RepoCompras *repo, int inicio, int fim)
{
    if (inicio < fim) {

        int meio = inicio + (fim - inicio) / 2;

        mergeSort(repo, inicio, meio);
        mergeSort(repo, meio + 1, fim);

        Merge(repo, inicio, meio, fim);
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

