#ifndef FILA_H
#define FILA_H

typedef struct bloco
{
	int info;
	struct bloco* prox;
} Bloco;

typedef struct fila
{
	Bloco *ini, *fim;
	int total;
} Fila;


Fila* criar_fila();
void esvaziar_fila(Fila* f);
void deletar_fila(Fila* f);
int fila_cheia(Fila* f);
int fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
void fila_inserir(Fila* f, int x);
void fila_retirar(Fila* f);
void imprimir_fila(Fila* f);

#endif
