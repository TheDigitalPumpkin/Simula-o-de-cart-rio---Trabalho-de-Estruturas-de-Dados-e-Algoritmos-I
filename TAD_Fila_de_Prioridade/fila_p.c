//Dupla: Bruno Bacelar e Gabriel Lacerda
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fila_p.h"
#include "fila.h"

void fila_p_inserir(Fila *f, int cpf_client, int cpf_terceiro, int prioridade, char op, char d[])
{	
    int i = 1;
	for(i = 1; i <= f[1].total; i++)  //Percorremos a fila para encontrar a posição correta para inserir o nó
	{
		if(f[i].pr == prioridade)
		{
			converte_string(d);
			Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
			cliente->cpf_cliente = cpf_client;
			cliente->cpf_terceiros = cpf_terceiro;
			cliente->opr = op;
			cliente->pri = prioridade;
			strcpy(cliente->bem, d);
			
			f[i].tamanho++;
			cliente->prox = NULL;
				
			if(fila_front(f, i) == NULL)
			{
				f[i].ini = cliente;
				f[i].fim = f[i].ini;
			}
			
			else
			{
				f[i].fim->prox = cliente;
				f[i].fim = f[i].fim->prox;
			}
			
			return;
		}
	}
}

void converte_string(char d[])
{
	unsigned int i = 0;

	for(i = 0; i < strlen(d); i++)
	{
		if(d[i] >= 97 && d[i] <= 122)
		d[i] -= 32;
		
		if(d[i] == ' ')
		d[i] = '_';
	}

	return;
}

void retirar_da_fila(Fila* f, int prioridade)
{
	Cliente* aux = fila_front(f,prioridade);
	f[prioridade].ini = f[prioridade].ini->prox;
	f[prioridade].tamanho--;
	
	if(fila_vazia(f,prioridade))
	{
		for(aux = f[prioridade].ini ; aux != NULL ;aux = aux->prox)
		{
			free(aux);
		}
	}
}

int fila_vazia(Fila* f, int x)
{
	return fila_tamanho(f, x) == 0;
}

int fila_tamanho(Fila* f, int prioridade){
	return f[prioridade].tamanho;
} 

Cliente* fila_front(Fila* f, int prioridade)
{
	return f[prioridade].ini;
}
