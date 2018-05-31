#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* criar_pilha()
{
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	
	if(p == NULL)
	{
		printf("Memoria Insuficiente\n");
		return p;
	}
	
	else
	{
		p->topo = 0;
		p->total = 0;
		return p;
	}
}

void deletar_pilha(Pilha* p)
{
	if(p != NULL)
	free(p);
}

int pilha_cheia(Pilha* p)
{
	if(p->topo == TAM_PILHA)
	return 1;
	
	else return 0;
}

int pilha_vazia(Pilha* p)
{
	if(p->topo == 0)
	return 1;
	
	else return 0;
}

int pilha_tamanho(Pilha *p)
{
	return p->topo;
}

void pilha_push(Pilha *p, int x)
{
	if(!pilha_cheia(p))
	{
		p->total++;
		p->topo++;
		p->num[p->topo] = x;
	}
}

int pilha_pop(Pilha* p)
{
	if(!pilha_vazia(p))
	{
		int x;
		x = p->num[p->topo];
		p->topo--;
		return x;
	}
}
