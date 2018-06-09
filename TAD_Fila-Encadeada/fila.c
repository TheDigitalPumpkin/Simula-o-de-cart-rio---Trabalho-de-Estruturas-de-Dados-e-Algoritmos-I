#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criar_filas(int L)
{
	Fila* f = (Fila*) calloc(L, sizeof(Fila));
	
	if(f != NULL)
	{
		int i;
		
		for(i = 0; i < L; i++)
		{
		    f[i].pr = i;
		    f[i].tamanho = 0;
		    f[i].ini = NULL;
		    f[i].fim = NULL;
		}
		
		f->tamanho = L;
		
		return f;
	}
}

void esvaziar_fila(Fila* f)
{
	Bloco *bloco_deletar, *prox_bloco;
	
	if(f != NULL)
	{
		prox_bloco = f->ini;
		
		while(prox_bloco != NULL)
		{
			bloco_deletar = prox_bloco;
			prox_bloco = prox_bloco->prox;
			free(bloco_deletar);
		}
		
		f->ini = NULL;
		f->fim = NULL;
		f->total = 0;
	}
}

void deletar_fila(Fila* f)
{
	if(f != NULL)
	{
		esvaziar_fila(f);
		free(f);
	}
}

int fila_cheia(Fila* f)
{
	if(f != NULL)
	return 1;
	
	else
	return 0;
}

int fila_vazia(Fila* f)
{
	if(f->total == 0)
	return 1;
	
	else
	return 0;
}

int fila_tamanho(Fila* f)
{
    if(f != NULL)
    return f->total;
}

Cliente* fila_front(Fila* f, int prioridade)
{
	return f[prioridade].ini->c;
}

void fila_inserir(Fila* f, int x)
{
	Bloco *p = (Bloco*) malloc(sizeof(Bloco));
	
	if(f != NULL)
	{
		f->total++;
		p->info = x;
		p->prox = NULL;
		
		if(f->ini == NULL)
		f->ini = p;
		
		else
		f->fim->prox = p;
		
		f->fim = p;
	}
}

void fila_retirar(Fila* f)
{
	if(!fila_vazia(f))
	{
		Bloco *p = f->ini;
		f->total--;
		f->ini = f->ini->prox;
		
		if(f->ini != NULL)
		f->fim = NULL;
		
		free(p);
	}
}

void imprimir_fila(Fila* f, int prioridade)
{
	if(fila_vazia(f))
	printf("Fila vazia.\n");
	
	else
	{
		Bloco *aux = f->ini;
		int i = 0, j = 1;
		
		for(i = 0; i < f->tamanho; i++)
		{                                           //Falta a verificação de caso a fila de prioridade desejada esteja nula.
			if(f[i].pr == prioridade)
			{	
				printf("Fila %d\n", i);
				
				while(aux != NULL)
				{
					printf("Cliente %d: ", j);
					printf("%d %d %c %d\n", aux->c->cpf_cliente, aux->c->cpf_terceiros, aux->c->opr, aux->c->pri);
					j++;
					aux = aux->prox;
				}
			}
		}
		
		printf("\n");
	}
}
