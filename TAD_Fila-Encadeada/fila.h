//Dupla: Bruno Bacelar e Gabriel Lacerda
#ifndef FILA_H
#define FILA_H

typedef struct cliente
{
    int cpf_cliente, cpf_terceiros, pri;  //P -> Prioridade.
    char bem[25], opr;
    struct cliente* prox;
} Cliente;

typedef struct fila
{
    Cliente *ini, *fim;
    int tamanho;
    int total;
    int pr;  //pr = prioridade da fila
} Fila;

Fila* criar_filas(int L);
int fila_cheia(Fila* f);


#endif
