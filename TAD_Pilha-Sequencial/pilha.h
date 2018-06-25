//Dupla: Bruno Bacelar e Gabriel Lacerda
#include "fila.h"
#include "fila_p.h"
#ifndef PILHA_H
#define PILHA_H

typedef struct cliente_sequencial
{
	int cpf_cliente, cpf_terceiros, pri;
    char bem[25], opr;
} ClienteSequencial;

typedef struct pilha
{
	ClienteSequencial* vetor_clientes;
	int topo, total, tamanho;
	int guiches;	
} Pilha;

void atender_clientes(Pilha* p, Fila* f);
Pilha* criar_guiches(int qtd_guiches, int qtd_clientes);
void deletar_pilha(Pilha* p);
int pilha_vazia(Pilha* p);
int pilha_tamanho(Pilha* p, int guiche);
int guiche_vazio(Pilha* p, int guiche);
void pilha_inserir(Pilha* p, ClienteSequencial* c);
void guiche_pop(Pilha* p, int guiche);
void pilha_pop(Pilha* p);

#endif
