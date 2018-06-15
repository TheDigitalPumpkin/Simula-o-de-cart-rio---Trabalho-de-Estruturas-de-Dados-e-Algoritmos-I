#ifndef LISTA_DEC_H
#define LISTA_DEC_H

typedef struct lista 
{
	int tam;
	int info;
	struct lista *prox;
	struct lista *ant;
} Lista_dec;

Lista_dec* criar_lista_dec();
void inserir_lista_dec_inicio(Lista_dec **l, int valor);
void inserir_lista_dec_fim(Lista_dec *l, int valor);
void inserir_lista_dec_posicao(Lista_dec *l, int pos, int valor);

#endif
