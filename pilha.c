#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "fila.h"
#include "fila_p.h"

Pilha* criar_guiches(int qtd_guiches, int qtd_clientes)
{
	Pilha* p = (Pilha*) calloc(qtd_guiches, sizeof(Pilha));
	
	if(p == NULL)
	{
		printf("Memoria Insuficiente\n");
		return p;
	}
	
	else
	{
		int i = 0;
		
		for(i = 0; i < qtd_guiches; i++)
		{
			ClienteSequencial* jorgim = (ClienteSequencial*) calloc(qtd_clientes,sizeof(ClienteSequencial));
			p[i].cleiton = jorgim;
			p[i].tamanho = 0;
			p[i].topo = 0;
			p[i].total = 0;
			p[i].guiches = qtd_guiches;
		}
		
		return p;
	}
}

void deletar_pilha(Pilha* p)
{
	if(p != NULL)
	free(p);
}

void imprimir_pilha(Pilha* p, int guiche){
	int i = 0;
	int t = p[guiche].tamanho;

	printf("Tamanho do guiche %d equivale a %d.\n", guiche, p[guiche].tamanho);
	printf("Guiche %d: \n", guiche);

	for(i = 0 ; i < t ;i++)
	{
        if(guiche_vazio(p, i))
        printf("Guiche %d esta vazio!\n", i);

        else
        {
			printf("%d %d %d %c %s\n", p[guiche].cleiton[p[guiche].topo].cpf_cliente, p[guiche].cleiton[p[guiche].topo].cpf_terceiros, p[guiche].cleiton[p[guiche].topo].pri, p[guiche].cleiton[p[guiche].topo].opr,p[guiche].cleiton[p[guiche].topo].bem );
			pilha_pop(p, guiche);
		}
	}

	printf("\n");
}

void pilha_push(Pilha* p, Fila* f)
{
		int i = 0, j = 0, aux2 = 0;
        printf("Total de filas igual a %d.\n", f->total);

		for(i = f->total-1 ; i >= 0 ;i--){
			int aux = f[i].tamanho;
			for(j = 0 ; j < aux ;j++)

			{
				
				if(aux2 >= p[0].guiches)
				aux2 = 0;
				

				ClienteSequencial* cliente = (ClienteSequencial*) malloc(sizeof(ClienteSequencial));
				cliente->cpf_cliente = f[i].ini->cpf_cliente;
				cliente->cpf_terceiros = f[i].ini->cpf_terceiros;
				cliente->pri = f[i].ini->pri;
				cliente->opr = f[i].ini->opr;
				strcpy(cliente->bem, f[i].ini->bem);

				if(p[aux2].tamanho == 0)
				{
					p[aux2].cleiton[p[aux2].topo] = *cliente;
					printf("Inserindo o cliente de cpf %d no guiche %d.\n", cliente->cpf_cliente, aux2);
					p[aux2].tamanho++;
				}

				else
				{
					p[aux2].topo++;
					p[aux2].cleiton[p[aux2].topo] = *cliente;
					printf("Guiche n vazio, Inserindo o cliente de cpf %d no guiche %d.\n", cliente->cpf_cliente, aux2);
					p[aux2].tamanho++;
				}

				p[aux2].total++;
				f[i].ini = f[i].ini->prox;
				
				printf("Topo do guiche %d equivale a %d.\n", aux2, p[aux2].topo);
				printf("Joga no guiche %d: %d %d %d %c %s\n",aux2, p[aux2].cleiton[p[aux2].topo].cpf_cliente, p[aux2].cleiton[p[aux2].topo].cpf_terceiros, p[aux2].cleiton[p[aux2].topo].pri, p[aux2].cleiton[p[aux2].topo].opr, p[aux2].cleiton[p[aux2].topo].bem);
				aux2++;
				free(cliente);
			}
		}

		printf("\n");

	return;
}


void pilha_pop(Pilha* p, int guiche)
{
	if(p[guiche].topo > -1)
	{
		printf("Retirando o cliente de cpf %d do topo da pilha %d.\n", p[guiche].cleiton[p[guiche].topo].cpf_cliente, guiche);
		p[guiche].topo--;
		printf("Topo da pilha %d agora contem o cliente de cpf %d.\n", guiche, p[guiche].cleiton[p[guiche].topo].cpf_cliente);
	}

}


int guiche_vazio(Pilha* p, int guiche)
{
	return p[guiche].tamanho == 0;
}


// void atender_clientes(Pilha* p, Fila* f)
// {
//     int i = 0, destino = 0;
    
//     for(i = f->total - 1; i >= 0; i--)
//     {
//         while(!fila_vazia(f, i))
//         {
//  			if(destino > p[0].guiches - 1)
//  			destino = 0;

//  			ClienteSequencial* cliente = (ClienteSequencial*) malloc(sizeof(ClienteSequencial));
//  			cliente->cpf_cliente = f[i].ini->cpf_cliente;
//  			cliente->cpf_terceiros = f[i].ini->cpf_terceiros;
//  			cliente->pri = f[i].ini->pri;
//  			cliente->opr = f[i].ini->opr;

//  			printf("Cliente sera destinado ao guiche %d.\n", destino);

//             if(guiche_vazio(p, destino))
//             {
//             	p[destino].cleiton[p[destino].topo] = *cliente;
//             	printf("Guiche %d esta vazio, inserindo cliente de cpf %d no topo igual a %d.\n", destino, cliente->cpf_cliente, p[destino].topo);
//             	p[destino].tamanho++;
//             }

//             else
//             {
//             	p[destino].topo++;
//             	p[destino].cleiton[p[destino].topo] = *cliente;
//             	printf("Inserindo cliente de cpf %d no guiche %d, que tem topo igual a %d.\n", p[destino].cleiton[p[destino].topo].cpf_cliente, destino, p[destino].topo);
//             	p[destino].tamanho++;
//             }

//             destino++;
//             f[i].ini = f[i].ini->prox;
//             printf("Cliente de cpf %d foi inserido no guiche %d.\n", p[destino].cleiton[p[destino].topo].cpf_cliente, destino - 1);
//             free(cliente);
//         }
//     }

//     printf("\n");
// }
