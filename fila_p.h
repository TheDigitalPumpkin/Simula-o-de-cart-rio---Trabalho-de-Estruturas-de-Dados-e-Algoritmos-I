#include "fila.h"
#ifndef FILA_P_H
#define FILA_P_H

void converte_string(char d[]);
void fila_p_inserir(Fila *f, int cpf_client, int cpf_terceiro, int prioridade, char op, char d[]);  //Função para inserir um nó na fila de acordo com a prioridade
void retirar_da_fila(Fila* f, int prioridade);
int fila_vazia(Fila* f, int x);
Cliente* fila_front(Fila* f, int prioridade);
int fila_tamanho(Fila* f,int prioridade);

#endif
