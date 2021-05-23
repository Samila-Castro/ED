
  #include <stdio.h>
 #include <stdlib.h>
 #include "No.h"

 No* createNo(int v, No* anterior, No* proximo){

 	No * n = (No*) malloc(sizeof(No));

 	n->valor = v;
 	n->anterior = anterior;
 	n->proximo = proximo;

 	return n;

 }

 void printNo(No* n){

 	if(n != NULL && n->anterior != NULL &&  n->proximo != NULL)
 		printf("No [valor: %i, anterior: %i, proximo: %i]\n", n->valor, n->anterior->valor, n->proximo->valor);
 	else if(n != NULL && n->anterior != NULL)
 		printf("No [valor: %i, anterior: %i, proximo: NULL]\n", n->valor, n->anterior->valor);
 	else if(n != NULL && n->proximo != NULL)
 		printf("No [valor: %i, anterior: NULL, proximo: %i]\n", n->valor, n->proximo->valor);
 	else if(n != NULL)
 		printf("No [valor: %i, anterior: NULL, proximo: NULL]\n", n->valor);
 	else
 		printf("NULL\n");

 }

 void freeNo(No* n){
 	free(n);
 }

