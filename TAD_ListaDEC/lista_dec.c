#include <stdio.h>
#include <stdlib.h>
#include "lista_dec.h"

Lista_dec* criar_lista_dec()
{
	Lista_dec *l = (Lista_dec*) malloc(sizeof(Lista_dec));
	
	if(l == NULL)
	{
		printf("Erro, memoria insuficiente.\n");
		return l;
	}
	
	else
	{
		l->tam = 0;
		l->prox = NULL;
		l->ant = NULL;
		return l;
	}
}

void inserir_lista_dec_inicio(Lista_dec **l, int valor)
{
	Lista_dec *ultimo = (*l)->ant;
	
	Lista_dec* novo_no = (Lista_dec*) malloc(sizeof(Lista_dec));
	
	novo_no->info = valor;
	(*l)->tam++;
	
	novo_no->prox = *l;
	novo_no->ant = ultimo;
	
	ultimo->prox = (*l)->ant = novo_no;
	*l = novo_no;
}
