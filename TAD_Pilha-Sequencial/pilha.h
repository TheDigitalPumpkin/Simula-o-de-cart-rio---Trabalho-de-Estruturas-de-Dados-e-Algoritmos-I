#include "fila.h"
#ifndef PILHA_H
#define PILHA_H
#ifndef TAM_PILHA
#define TAM_PILHA 40
#endif

typedef struct pilha
{
	int topo, total;
	Cliente* num[TAM_PILHA];
} Pilha;

Pilha* criar_guiches(int qtd_guiches, int qtd_clientes);
void deletar_pilha(Pilha* p);
int pilha_cheia(Pilha* p);
int pilha_tamanho(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_push(Pilha* p, int x);
int pilha_pop(Pilha* p);

#endif
