//Dupla: Bruno Bacelar e Gabriel Lacerda
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criar_filas(int L)
{
	Fila* f = (Fila*) calloc(L+1, sizeof(Fila));
	
	if(f != NULL)
	{
		int i;
		
		for(i = 1; i <= L; i++)
		{
			f[i].pr = i;
			f[i].total = L;
			f[i].tamanho = 0;
			f[i].ini = NULL;
			f[i].fim = NULL;
		}

		return f;
	}

	else
	{
		printf("Filas nao puderam ser criadas!\n");
		exit(1);
	}
}


int fila_cheia(Fila* f)
{
	if(f != NULL)
	return 1;
	
	else
	return 0;
}
