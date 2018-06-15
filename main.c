#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include "lista_dec.h"
#include "fila_p.h"

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
	
	for(i = 0 ; i < P ;i++)
	{
		int CPF1, CPF2, prio;
		char tarefa, bem[25];
		scanf("%d", &CPF1);
		scanf("%d", &CPF2);
		scanf("%d", &prio);
		scanf(" %c", &tarefa);
		scanf(" %[^\n]%*c", bem);
		
 //Joga essa porra na fila_p_inserir, fiklhda da putuoagruguiofgil
		fila_p_inserir(f, CPF1, CPF2, prio, tarefa, bem);
	}


	for(i = 0; i < L; i++)
	{
		imprimir_fila(f, i);
	}

	pilha_push(p, f);

	for(i = 0; i < G; i++)
	{
		imprimir_pilha(p, i);
	}
	
	return 0;
}

/*4 3 4
23 1223 1 A carritos
666 876 2 A sHacriLhos doiDAO
987 90 3 T piroca voadora
423 928 3 T MEL*/
