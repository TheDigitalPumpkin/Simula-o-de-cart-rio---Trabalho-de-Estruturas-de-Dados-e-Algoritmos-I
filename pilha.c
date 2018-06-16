#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
#include "fila_p.h"

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
			ClienteSequencial* jorgim = (ClienteSequencial*) calloc(qtd_clientes,sizeof(ClienteSequencial));
			p[i].vetor_clientes = jorgim;
			p[i].tamanho = 0;
			p[i].topo = 0;
			p[i].total = 0;
			p[i].guiches = qtd_guiches;
		}
		
		return p;
	}
}

void deletar_pilha(Pilha* p)
{
	if(p != NULL)
	free(p);
}
int pilha_tamanho(Pilha* p, int guiche){
	return p[guiche].tamanho;
}

int pilha_vazia(Pilha* p)
{
	return p->tamanho == 0;
}

void atender_clientes(Pilha* p, Fila* f)
{
		int i = 0, j = 0, aux2 = 0;
		for(i = f[1].total ; i >= 0 ;i--)
		{
			int aux = f[i].tamanho;
			for(j = 0 ; j < aux ;j++)
            {
				
				if(aux2 >= p[0].guiches)
				aux2 = 0;
				

				ClienteSequencial* cliente = (ClienteSequencial*) malloc(sizeof(ClienteSequencial));
				cliente->cpf_cliente = f[i].ini->cpf_cliente;
				cliente->cpf_terceiros = f[i].ini->cpf_terceiros;
				cliente->pri = f[i].ini->pri;
				cliente->opr = f[i].ini->opr;
				strcpy(cliente->bem, f[i].ini->bem);
				if(guiche_vazio(p, aux2))
				{
					p[aux2].vetor_clientes[p[aux2].topo] = *cliente;
					p[aux2].tamanho++;
				}

				else
				{
					p[aux2].topo++;
					p[aux2].vetor_clientes[p[aux2].topo] = *cliente;
					p[aux2].tamanho++;
				}

				p[aux2].total++;
				retirar_da_fila(f,i);
				aux2++;
				free(cliente);
			}
		}

		printf("\n");

	return;
}


void guiche_pop(Pilha* p, int guiche)
{
	if(!guiche_vazio(p,guiche))
	{
		p[guiche].topo--;
		p[guiche].tamanho--;
	}
}


int guiche_vazio(Pilha* p, int guiche)
{
	return p[guiche].tamanho == 0;
}

void pilha_inserir(Pilha* p, ClienteSequencial* c)
{
	ClienteSequencial* cliente = (ClienteSequencial*) malloc(sizeof(ClienteSequencial));
	
	cliente->cpf_cliente = c->cpf_cliente;
	cliente->cpf_terceiros = c->cpf_terceiros;
	strcpy(cliente->bem, c->bem);
	cliente->opr = c->opr;
	cliente->pri = c->pri;
	
	if(pilha_vazia(p))
	{
		p->vetor_clientes[p->topo] = *cliente;
		p->tamanho++;
	}
	
	else
	{
		p->topo++;
		p->vetor_clientes[p->topo] = *cliente;
		p->tamanho++;
	}
}



void pilha_pop(Pilha* p)
{
	if(!pilha_vazia(p))
	{
		p->topo--;
		p->tamanho--;
	}
}

