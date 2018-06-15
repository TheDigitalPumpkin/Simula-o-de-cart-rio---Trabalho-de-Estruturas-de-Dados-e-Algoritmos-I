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
			f[i].total = L;
			f[i].tamanho = 0;
			f[i].ini = NULL;
			f[i].fim = NULL;
		}

		return f;
	}

	else
	{
		printf("Filas nao puderam ser criadas!\n");
		exit(1);
	}
}


int fila_cheia(Fila* f)
{
	if(f != NULL)
	return 1;
	
	else
	return 0;
}

int fila_vazia(Fila* f, int x)
{
	return f[x].tamanho == 0;
}


Cliente* fila_front(Fila* f, int prioridade)
{
	return f[prioridade].ini;
}

void imprimir_fila(Fila* f, int prioridade)
{
	if(f[prioridade].tamanho == 0){
		printf("Fila vazia.\n");
	}
	
	else
	{
		if(f[prioridade].ini == NULL){
			return;
		}
		Cliente* aux = f[prioridade].ini;
		int i = 0, j = 0;
		for(i = 0; i < f->total; i++)
		{
			if(f[i].pr == prioridade)
			{	

				printf("Fila %d:\n", i);
				
				for(j = 0 ; j < f[i].tamanho ;j++)
				{
					printf("Cliente %d: ", j+1);
					printf("%d %d %d %c %s\n", aux->cpf_cliente, aux->cpf_terceiros, aux->pri, aux->opr ,aux->bem);
					aux = aux->prox;
				}
			}
		}
		
		printf("\n");
	}
}
