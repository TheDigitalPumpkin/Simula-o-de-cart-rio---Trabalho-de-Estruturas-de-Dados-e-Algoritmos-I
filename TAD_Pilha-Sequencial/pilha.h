#ifndef PILHA_H
#define PILHA_H
#ifndef TAM_PILHA
#define TAM_PILHA 40
#endif

struct pilha{
	int topo, total;
	int num[TAM_PILHA];
};
typedef struct pilha Pilha;

Pilha* criar_pilha();
void deletar_pilha(Pilha* p);
int pilha_cheia(Pilha* p);
int pilha_tamanho(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_push(Pilha* p, int x);
int pilha_pop(Pilha* p);

#endif
