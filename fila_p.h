#include "fila.h"
#ifndef FILA_P_H
#define FILA_P_H

typedef struct no //Implementaremos a fila de prioridade como uma lista encadeada
{
	Cliente* c;
	struct no *prox;
} No;

No* criar_fila_p();                   //Fun��o para criar a fila
No* novo_no_fila_p(Cliente c); 
void converte_string(char d[]);
int fila_p_front(No** cabeca);        //Fun��o que retorna o primeiro elemento da fila
void imprime_fila_p(No** cabeca);     //Fun��o que imprime a fila de prioridade
void fila_p_retirar(No** cabeca);     //Fun��o para retirar um elemento da frente da fila
void fila_p_inserir(Fila *f, int cpf_client, int cpf_terceiro, int prioridade, char op, char d[]);  //Fun��o para inserir um n� na fila de acordo com a prioridade
int fila_p_vazia(No** cabeca);        //Fun��o que retorna 1 (true) caso a lista esteja vazia e 0 (false) caso contr�rio

#endif
