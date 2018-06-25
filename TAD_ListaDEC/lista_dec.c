//Dupla: Bruno Bacelar e Gabriel Lacerda
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista_dec.h"
#include <string.h>

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
		l->tamanho = 0;
		l->fim_relatorio = NULL;
		l->ini_relatorio = NULL;
		l->quantidade = 0;
		l->prox = NULL;
		l->ant = NULL;
		l->cabeca = NULL;
		l->cauda = NULL;
		return l;
	}
}

void inserir_lista_dec_fim(Lista_dec* l, Lista_dec* novo_no, int x)
{
	Lista_dec* aux = l->cauda;
	
	while(1)
	{
		if(novo_no->cpf_generico != l->cauda->cpf_generico)
		{
			Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
			strcpy(fim_vetor->bem, novo_no->bem);
			
			if(x == 1)
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '+';
				
				else
				fim_vetor->simbolo = '-';				
			}
			
			else
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '-';
				
				else
				fim_vetor->simbolo = '+';				
			}
			
			fim_vetor->prox = NULL;
			novo_no->ini_relatorio = fim_vetor;
			novo_no->fim_relatorio = novo_no->ini_relatorio;
			l->cauda->prox = novo_no;
			novo_no->ant = l->cauda;
			l->cauda = novo_no;
			novo_no->prox = l->cabeca;
			l->cabeca->ant = novo_no;
			l->tamanho++;
			l->quantidade++;
			break;
		}
		
		else
		{
			Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
			strcpy(fim_vetor->bem, novo_no->bem);
			
			if(x == 1)
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '+';
				
				else
				fim_vetor->simbolo = '-';				
			}
			
			else
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '-';
				
				else
				fim_vetor->simbolo = '+';				
			}
			
			fim_vetor->prox = NULL;
			aux->fim_relatorio->prox = fim_vetor;
			aux->fim_relatorio = aux->fim_relatorio->prox;
			aux->quantidade++;
			break;
		}
	}
}

void inserir_lista_dec_inicio(Lista_dec* l, Lista_dec* novo_no, int x)
{
	if(l->tamanho == 0)
	{
		Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
		strcpy(fim_vetor->bem, novo_no->bem);
		
		if(x == 1)
		{
			if(novo_no->opr == 'A')
			fim_vetor->simbolo = '+';
			
			else
			fim_vetor->simbolo = '-';			
		}
		
		else
		{
			if(novo_no->opr == 'A')
			fim_vetor->simbolo = '-';
			
			else
			fim_vetor->simbolo = '+';			
		}
		
		fim_vetor->prox = NULL;
		novo_no->ini_relatorio = fim_vetor;
		novo_no->fim_relatorio = novo_no->ini_relatorio;
		l->cabeca = novo_no;
		l->cauda = novo_no;
		novo_no->prox = novo_no;
		novo_no->ant = novo_no;
		l->tamanho++;
		l->quantidade++;		
	}
	
	else
	{
		Lista_dec* aux = l->cabeca;
		
		while(1)
		{
			if(novo_no->cpf_generico != l->cabeca->cpf_generico)
			{
				Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
				strcpy(fim_vetor->bem, novo_no->bem);
				
				if(x == 1)
				{
					if(novo_no->opr == 'A')
					fim_vetor->simbolo = '+';
					
					else
					fim_vetor->simbolo = '-';
					
				}
				
				else
				{
					if(novo_no->opr == 'A')
					fim_vetor->simbolo = '-';
					
					else
					fim_vetor->simbolo = '+';				
				}
				
				fim_vetor->prox = NULL;
				novo_no->ini_relatorio = fim_vetor;
				novo_no->fim_relatorio = novo_no->ini_relatorio;
				l->cabeca->ant = novo_no;
				novo_no->prox = l->cabeca;
				l->cabeca = novo_no;
				novo_no->ant = l->cauda;
				l->cauda->prox = l->cabeca;
				l->tamanho++;
				l->quantidade++;
				break;
			}
			
			else
			{
				Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
				strcpy(fim_vetor->bem, novo_no->bem);
				
				if(x == 1)
				{
					if(novo_no->opr == 'A')
					fim_vetor->simbolo = '+';
					
					else
					fim_vetor->simbolo = '-';					
				}
				
				else
				{
					if(novo_no->opr == 'A')
					fim_vetor->simbolo = '-';
					
					else
					fim_vetor->simbolo = '+';					
				}
				
				fim_vetor->prox = NULL;
				aux->fim_relatorio->prox = fim_vetor;
				aux->fim_relatorio = aux->fim_relatorio->prox;
				aux->quantidade++;
				break;
			}
		}
	}
}

int buscar_lista(Lista_dec* l, int cpf_generico)
{	
	Lista_dec* aux = l->cabeca;
	
	while(1)
	{
		if(aux->cpf_generico == l->cauda->cpf_generico)
		{
			if((cpf_generico != aux->cpf_generico))
			{
				if((cpf_generico != aux->cpf_generico))
				return 0;
				
				else
				return 1;
			}
			
			else
			return 1;
		}
		
		if((cpf_generico != aux->cpf_generico))
		{
			if((cpf_generico != aux->cpf_generico))
			aux = aux->prox;
			
			else
			return 1;
		}
		
		else
		return 1;	
	}
}

void inserir_lista_dec_posicao(Lista_dec* l, Lista_dec* novo_no, int x)
{
	Lista_dec* auxiliar = l->cauda;
	
	while(1)
	{
		if(auxiliar->cpf_generico > novo_no->cpf_generico)
		auxiliar = auxiliar->ant;
		
		else if(auxiliar->cpf_generico != novo_no->cpf_generico)
		{
			Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
			strcpy(fim_vetor->bem, novo_no->bem);
			
			if(x == 1)
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '+';
				
				else
				fim_vetor->simbolo = '-';				
			}
			
			else
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '-';
				
				else
				fim_vetor->simbolo = '+';				
			}
			
			fim_vetor->prox = NULL;
			novo_no->ini_relatorio = fim_vetor;
			novo_no->fim_relatorio = novo_no->ini_relatorio;
			novo_no->prox = auxiliar->prox;
			auxiliar->prox->ant = novo_no;
			auxiliar->prox = novo_no;
			novo_no->ant = auxiliar;
			l->tamanho++;
			l->quantidade++;
			break;
		}
		
		else
		{
			Relatorio* fim_vetor = (Relatorio*) malloc(sizeof(Relatorio));
			strcpy(fim_vetor->bem, novo_no->bem);
			
			if(x == 1)
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '+';
				
				else
				fim_vetor->simbolo = '-';				
			}
			
			else
			{
				if(novo_no->opr == 'A')
				fim_vetor->simbolo = '-';
				
				else
				fim_vetor->simbolo = '+';				
			}
				
			fim_vetor->prox = NULL;
			auxiliar->fim_relatorio->prox = fim_vetor;
			auxiliar->fim_relatorio = auxiliar->fim_relatorio->prox;
			auxiliar->quantidade++;
			break;
		}
	}
}

int struct_cmp(const void *a, const void *b)
{
 	struct relatorio *ia = (struct relatorio *)a;
 	struct relatorio *ib = (struct relatorio *)b;
 	return strcmp(ia->bem, ib->bem);
} 

void gerar_relatorio_final(Lista_dec *l, Pilha* p)
{	
	int i = 0;
	
	for(i = 0 ; i < p->guiches ;i++)
	{	
		while(!guiche_vazio(p, i))
		{
			Lista_dec* novo_no = criar_lista_dec();
			Lista_dec* novo_no2 = criar_lista_dec();
			novo_no->cpf_generico = p[i].vetor_clientes[p[i].topo].cpf_cliente;
			novo_no->opr = p[i].vetor_clientes[p[i].topo].opr;
			strcpy(novo_no->bem, p[i].vetor_clientes[p[i].topo].bem);
		
		    	if(l->tamanho == 0)
		    	inserir_lista_dec_inicio(l, novo_no, 1);
					
			else if(novo_no->cpf_generico >= l->cauda->cpf_generico)
			inserir_lista_dec_fim(l, novo_no, 1);
						
			else if(novo_no->cpf_generico <= l->cabeca->cpf_generico)
			inserir_lista_dec_inicio(l, novo_no, 1);
					
			else
			inserir_lista_dec_posicao(l, novo_no, 1);
				
			novo_no2->cpf_generico = p[i].vetor_clientes[p[i].topo].cpf_terceiros;
			novo_no2->opr = p[i].vetor_clientes[p[i].topo].opr;
			strcpy(novo_no2->bem, p[i].vetor_clientes[p[i].topo].bem);
        
        		if(novo_no2->cpf_generico >= l->cauda->cpf_generico)
			inserir_lista_dec_fim(l, novo_no2, 2);
					
			else if(novo_no2->cpf_generico <= l->cabeca->cpf_generico)
			inserir_lista_dec_inicio(l, novo_no2, 2);			
			
			else
			inserir_lista_dec_posicao(l, novo_no2, 2);			
		
			guiche_pop(p, i);			
	    }
	}
	
	Lista_dec* aux = l->cabeca;
	Lista_dec* ldec = l->cabeca;
	printf("-:| RELATORIO FINAL |:-\n");
	printf("%d\n", l->tamanho);
	
	while(1)
	{
		printf("-:[ %d: %d\n", aux->cpf_generico, aux->quantidade + 1);
		int i, j;
		
		while(1)
		{
			
			int flag = aux->quantidade + 1;
			Relatorio* bens = (Relatorio*) malloc(flag * sizeof(Relatorio));
			
			for(j = 0 ; j < flag ;j++)
			{
				strcpy(bens[j].bem, ldec->ini_relatorio->bem);
				
				bens[j].simbolo = ldec->ini_relatorio->simbolo;
				
				ldec->ini_relatorio = ldec->ini_relatorio->prox;
			}
			
			qsort(bens, flag, sizeof(struct relatorio), struct_cmp);
			
			for(i = 0 ; i < flag ;i++)
			{
				printf("    %c%s\n", bens[i].simbolo, bens[i].bem);
			}
			
			ldec = ldec->prox;
			free(bens);
			
			if(aux->ini_relatorio == NULL)
			break;			
		}
		
		aux = aux->prox;
		
		if(aux == l->cabeca)
		break;		
	}
}

void deletar_lista_dec(Lista_dec* l)
{
	if(l->tamanho == 1)
	free(l->cabeca);
	
	else if(l->tamanho == 0)
	free(l);
	
	else
	{
		Lista_dec* auxiliar;
		
		while(l->cabeca != l->cauda)
		{
			auxiliar = l->cabeca;
			l->cabeca = l->cabeca->prox;
			free(auxiliar);
		}
	}	
}

