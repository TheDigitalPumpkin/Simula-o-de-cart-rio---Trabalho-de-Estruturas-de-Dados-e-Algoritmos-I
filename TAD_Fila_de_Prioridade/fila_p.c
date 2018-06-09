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




No* novo_no_fila_p(int p, int valor)      //Função para inserirmos um novo nó na fila de prioridade
{
	No* novo = (No*) malloc(sizeof(No));  //Alocamos um novo nó
	novo->info = valor;                   //Atribuimos o valor do input do usuário ao campo "info" do novo nó
	novo->prioridade = p;                 //Atribumos a prioridade 'p' do input do usuário ao novo nó
	novo->prox = NULL;                    //E fazemos com que o ponteiro para o próximo nó aponte para NULL
	
	return novo;                          //Retornamos o novo nó criado
}




int fila_p_front(No** cabeca)             //Função que retorna o primeiro elemento da fila
{
	return (*cabeca)->info;               //Como a cabeça da lista equivale ao primeiro elemento, retornamos o campo "info" da cabeça
}




void imprime_fila_p(No** cabeca)
{
	if(fila_p_vazia(&cabeca))             //Caso a fila esteja vazia, imprimimos tal estado
	printf("Fila de prioridade esta vazia.\n");
	
	else                                  //Caso a fila não esteja vazia,
	{
		No *aux = (*cabeca);              //Declaramos um nó auxiliar
		
		while(aux != NULL)                //Percorremos a fila de prioridade, imprimindo cada elemento e sua prioridade
		{
			printf("Elemento %d, com prioridade %d\n", aux->info, aux->prioridade);
			aux = aux->prox;
		}
		
		printf("\n");
	}
}




void fila_p_retirar(No** cabeca)          //Função para retirar o elemento de maior prioridade da fila, ou seja, a cabeça
{
	No* excluido = *cabeca;               //Criamos um novo nó e o igualamos a cabeça da fila
	(*cabeca) = (*cabeca)->prox;          //Fazemos cabeça apontar para o próximo nó, ou seja, a nova cabçea da fila será o próximo nó
	free(excluido);                       //Por fim, liberamos a antiga cabeça, que agora está em "excluido" da memória
}




void fila_p_inserir(Fila *f, int cpf_client, int cpf_terceiro, char op, int prioridade)
{	
    int i = 0;
    
	for(i = 0; i < f->tamanho; i++)  //Percorremos a fila para encontrar a posição correta para inserir o nó
	{
		if(f[i].ini->c->pri == prioridade);
		{
			Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
			cliente->cpf_cliente = cpf_client;
			cliente->cpf_terceiros = cpf_terceiro;
			cliente->opr = op;
			cliente->pri = prioridade;
			Bloco* novo_cliente = (Bloco*) malloc(sizeof(Bloco));
			
			f[i].tamanho++;
	        novo_cliente->c = cliente;
			novo_cliente->prox = NULL;
				
			if(f[i].ini == NULL)
			f[i].ini = novo_cliente;
				
			else
			f[i].ini->prox = novo_cliente;
				
			f[i].fim = novo_cliente;
			
			return;
		}
	}
}



int fila_p_vazia(No** cabeca)
{
	if((*cabeca) == NULL) return 1;
	
	else return 0;
}




