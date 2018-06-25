//Dupla: Bruno Bacelar e Gabriel Lacerda
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
		printf("Guiche %d: %d\n", i + 1, pilha_tamanho(p, i));
		Pilha* aux = criar_guiches(1, pilha_tamanho(p, i));
		aux[0] = p[i];
		
		while(!guiche_vazio(aux, 0))
		{
			printf("[%d,%d,%c,%s]\n", aux[0].vetor_clientes[aux[0].topo].cpf_cliente, aux[0].vetor_clientes[aux[0].topo].cpf_terceiros, aux[0].vetor_clientes[aux[0].topo].opr, aux[0].vetor_clientes[aux[0].topo].bem);
			guiche_pop(aux,0);
		}
		
		free(aux);
	}
	
	printf("\n");
}

void ler_fila(Fila* f, int qtd_clientes)
{
	int i;
	
	for(i = 1; i <= qtd_clientes; i++)
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
	int G = 0, P = 0, L = 0;
	
	scanf("%d", &L);
	scanf("%d", &G);
	scanf("%d", &P);

	Fila *f = criar_filas(L);
	Pilha *p = criar_guiches(G, P);
	Lista_dec *l = criar_lista_dec();
	
	printf("\n");
	
	ler_fila(f, P);
    atender_clientes(p, f);
	relatorio_parcial(p, G);
    
    gerar_relatorio_final(l, p);
    
    free(f);
    deletar_pilha(p);
    deletar_lista_dec(l);
    
	return 0;
}
