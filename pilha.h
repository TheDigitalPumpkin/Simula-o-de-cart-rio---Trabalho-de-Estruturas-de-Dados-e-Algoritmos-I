#include "fila.h"
#include "fila_p.h"
#ifndef PILHA_H
#define PILHA_H

typedef struct cliente_sequencial
{
	int cpf_cliente, cpf_terceiros, pri;  //P -> Prioridade.
    char bem[25], opr;
} ClienteSequencial;

typedef struct pilha
{
	ClienteSequencial* cleiton;
	int topo, total, tamanho;
	int guiches;
	
} Pilha;

void atender_clientes(Pilha* p, Fila* f);
Pilha* criar_guiches(int qtd_guiches, int qtd_clientes);           //Durante a simulação, serão alocadas M pilhas. 
void deletar_pilha(Pilha* p);
int pilha_cheia(Pilha* p);
int pilha_tamanho(Pilha* p);
int guiche_vazio(Pilha* p, int guiche);
void pilha_push(Pilha* p, Fila* f);
void imprimir_pilha(Pilha* p, int guiche);
void pilha_pop(Pilha* p, int guiche);

#endif
