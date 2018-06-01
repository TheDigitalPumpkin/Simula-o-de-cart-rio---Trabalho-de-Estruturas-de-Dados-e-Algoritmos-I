#include <stdlib.h>
#include <stdio.h>
#include "fila_p.h"

No* criar_fila_p()
{
	No *fila_p = (No*) malloc(sizeof(No));
	
	if(fila_p == NULL)
	{
		printf("Erro, memoria insuficiente!\n");
		exit(1);
	}
	
	else
	{
		fila_p->info = 0;
		fila_p->prioridade = 0;
		fila_p->prox = NULL;
		return fila_p;
	}
}




No* novo_no_fila_p(int p, int valor)      //Fun��o para inserirmos um novo n� na fila de prioridade
{
	No* novo = (No*) malloc(sizeof(No));  //Alocamos um novo n�
	novo->info = valor;                   //Atribuimos o valor do input do usu�rio ao campo "info" do novo n�
	novo->prioridade = p;                 //Atribumos a prioridade 'p' do input do usu�rio ao novo n�
	novo->prox = NULL;                    //E fazemos com que o ponteiro para o pr�ximo n� aponte para NULL
	
	return novo;                          //Retornamos o novo n� criado
}




int fila_p_front(No** cabeca)             //Fun��o que retorna o primeiro elemento da fila
{
	return (*cabeca)->info;               //Como a cabe�a da lista equivale ao primeiro elemento, retornamos o campo "info" da cabe�a
}




void imprime_fila_p(No** cabeca)
{
	if(fila_p_vazia(&cabeca))             //Caso a fila esteja vazia, imprimimos tal estado
	printf("Fila de prioridade esta vazia.\n");
	
	else                                  //Caso a fila n�o esteja vazia,
	{
		No *aux = (*cabeca);              //Declaramos um n� auxiliar
		
		while(aux != NULL)                //Percorremos a fila de prioridade, imprimindo cada elemento e sua prioridade
		{
			printf("Elemento %d, com prioridade %d\n", aux->info, aux->prioridade);
			aux = aux->prox;
		}
		
		printf("\n");
	}
}




void fila_p_retirar(No** cabeca)          //Fun��o para retirar o elemento de maior prioridade da fila, ou seja, a cabe�a
{
	No* excluido = *cabeca;               //Criamos um novo n� e o igualamos a cabe�a da fila
	(*cabeca) = (*cabeca)->prox;          //Fazemos cabe�a apontar para o pr�ximo n�, ou seja, a nova cab�ea da fila ser� o pr�ximo n�
	free(excluido);                       //Por fim, liberamos a antiga cabe�a, que agora est� em "excluido" da mem�ria
}




void fila_p_inserir(No** cabeca, int p, int valor)
{
	No *inserido = novo_no_fila_p(p, valor);  //Utilizamos a fun��o de criar n�s para criar o novo n� a ser insreido na fila
	No *inicio = (*cabeca);                   //Criamos um n� auxiliar igual a cabe�a da fila
	
	while(inicio->prox != NULL && inicio->prox->prioridade < p)  //Percorremos a fila para encontrar a posi��o correta para inserir o n�
	{
		inicio = inicio->prox;
	}
	
	inserido->prox = inicio->prox;        //Inserimos o n� na devida posi��o
	inicio->prox = inserido;
}



int fila_p_vazia(No** cabeca)
{
	if((*cabeca) == NULL) return 1;
	
	else return 0;
}




