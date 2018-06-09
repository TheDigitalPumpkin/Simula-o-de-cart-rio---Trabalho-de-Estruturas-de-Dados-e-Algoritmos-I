#ifndef FILA_H
#define FILA_H

typedef struct cliente
{
    int cpf_cliente, cpf_terceiros, pri;  //P -> Prioridade.
    char bem[25], opr;
} Cliente;

typedef struct bloco
{
    Cliente* c; 
    struct bloco* prox;
} Bloco;

typedef struct fila
{
    Bloco *ini, *fim;
    int tamanho;
    int pr;  //pr = prioridade da fila
} Fila;


Fila* criar_filas(int L);
void esvaziar_fila(Fila* f);
void deletar_fila(Fila* f);
int fila_cheia(Fila* f);
int fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
Cliente* fila_front(Fila* f, int prioridade);
void fila_inserir(Fila* f, int cpf_c, int cpf_t, int pr, char opr);
void fila_retirar(Fila* f);
void imprimir_fila(Fila* f, int prioridade);

#endif
