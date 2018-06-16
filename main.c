#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "lista_dec.h"
#include "fila_p.h"

void relatorio_parcial(Pilha* p, int G)
{
	int i = 0;
	
	printf("-:| RELATORIO PARCIAL |:-\n");
	printf("%d\n", G);
	
	for(i = 0; i < G; i++)
	{
		Pilha* auxiliar = criar_guiches(1,pilha_tamanho(p,i));
		ClienteSequencial* novo = (ClienteSequencial*) malloc(pilha_tamanho(p,i)*sizeof(ClienteSequencial));
		printf("Guiche %d: %d\n", i+1, pilha_tamanho(p,i));
		
		while(!guiche_vazio(p, i))
		{
			
			novo->cpf_cliente = p[i].vetor_clientes[p[i].topo].cpf_cliente;
			novo->cpf_terceiros = p[i].vetor_clientes[p[i].topo].cpf_terceiros;
			novo->opr = p[i].vetor_clientes[p[i].topo].opr;
			strcpy(novo->bem, p[i].vetor_clientes[p[i].topo].bem);
			pilha_inserir(auxiliar, novo);
			guiche_pop(p, i);
		}
		
		while(!pilha_vazia(auxiliar))
		{
			printf("[%d,%d,%c,%s]\n", auxiliar->vetor_clientes[auxiliar->topo].cpf_cliente, auxiliar->vetor_clientes[auxiliar->topo].cpf_terceiros, auxiliar->vetor_clientes[auxiliar->topo].opr, auxiliar->vetor_clientes[auxiliar->topo].bem);
			pilha_pop(auxiliar);
		}
		
		free(auxiliar);
		free(novo);
	}
}

void ler_fila(Fila* f, int todas_pessoas){
	int i;
	for(i = 1 ; i <= todas_pessoas ;i++)
	{
		int CPF1, CPF2, prio;
		char tarefa, bem[25];
		scanf("%d", &CPF1);
		scanf("%d", &CPF2);
		scanf("%d", &prio);
		scanf(" %c", &tarefa);
		scanf(" %[^\n]%*c", bem);
		fila_p_inserir(f, CPF1, CPF2, prio, tarefa, bem);
	}
	
}

int main()
{
	int i = 0;
	
	int G, P, L;
	
	scanf("%d", &L);
	scanf("%d", &G);
	scanf("%d", &P);

	Fila *f = criar_filas(L);
	Pilha *p = criar_guiches(G, P);
	printf("\n");
	
	ler_fila(f,P);
    atender_clientes(p, f);
	relatorio_parcial(p,G);
	
	Fila* limpa = f;
	free(f);
	return 0;
}


/*4 3 4
23 1223 1 A carritos
666 876 2 A sHacriLhos doiDAO
987 90 3 T piroca voadora
423 928 3 T MEL*/
