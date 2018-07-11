//Dupla: Bruno Bacelar e Gabriel Lacerda
#ifndef LISTA_DEC_H
#define LISTA_DEC_H

typedef struct relatorio
{
	char bem[25];
	char simbolo;
	struct relatorio* prox;
} Relatorio;

typedef struct lista 
{
	int tamanho;
	int cpf_generico;
	char bem[25], opr;
	int quantidade;
	Relatorio *ini_relatorio, *fim_relatorio;
	struct lista *prox;
	struct lista *ant;
	struct lista *cabeca;
	struct lista *cauda;
} Lista_dec;

Lista_dec* criar_lista_dec();
void gerar_relatorio_final(Lista_dec *l, Pilha* p);
void inserir_lista_dec_fim(Lista_dec* l, Lista_dec* novo_no, int x);
void inserir_lista_dec_inicio(Lista_dec* l, Lista_dec* novo_no, int x);
int buscar_lista(Lista_dec* l, int cpf_generico);
void inserir_lista_dec_posicao(Lista_dec* l, Lista_dec* novo_no, int x);
int struct_cmp(const void *a, const void *b);
void deletar_lista_dec(Lista_dec* l);

#endif
