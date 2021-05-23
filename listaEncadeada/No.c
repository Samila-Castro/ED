#include <stdio.h>
 #include <stdlib.h>
 #include "No.h"



  No* createNo(int elemento, No* proximo){

 	No * pno = (No*) malloc(sizeof(No));

 	pno->valor = elemento;
 	pno->proximo = proximo;

 	return pno;

 }

 void printNo(No* pno){

 	if(pno != NULL && pno->proximo != NULL)
 		printf("No [valor: %i, proximo: %i]\n", pno->valor, pno->proximo->valor);
 	else if(pno != NULL)
 		printf("No [valor: %i, proximo: NULL]\n", pno->valor);
 	else
 		printf("NULL\n");

 }

 void freeNo(No* pno){
 	free(pno);
 }


