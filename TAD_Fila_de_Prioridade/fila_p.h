#ifndef FILA_P_H
#define FILA_P_H

typedef struct no //Implementaremos a fila de prioridade como uma lista encadeada
{
	int info;
	int prioridade;
	struct no *prox;
} No;

No* criar_fila_p();                   //Funcao para criar a fila
No* novo_no_fila_p(int p, int valor); //Funcao para criar um novo no.
int fila_p_front(No** cabeca);        //Funcao que retorna o primeiro elemento da fila
void imprime_fila_p(No** cabeca);     //Funcao que imprime a fila de prioridade
void fila_p_retirar(No** cabeca);     //Funcao para retirar um elemento da frente da fila
void fila_p_inserir(No** cabeca, int p, int valor);  //Funcao para inserir um no na fila de acordo com a prioridade
int fila_p_vazia(No** cabeca);        //Funcao que retorna 1 (true) caso a lista esteja vazia e 0 (false) caso contrario

#endif
