#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha* criar_guiches(int qtd_guiches, int qtd_clientes)
{
	Pilha* p = (Pilha*) calloc(qtd_guiches, sizeof(Pilha));
	
	if(p == NULL)
	{
		printf("Memoria Insuficiente\n");
		return p;
	}
	
	else
	{
		int i = 0;
		
		for(i = 0; i < qtd_guiches; i++)
		{
			p[i].topo = 0;
			p[i].total = 0;
			p[i].num = NULL;
		}
		
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
	return p->topo == 0;
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
