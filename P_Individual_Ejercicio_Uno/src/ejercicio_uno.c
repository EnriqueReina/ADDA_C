/*
 ============================================================================
 Name        : P_Individual.c
 Author      : Enrique Reina
 Version     :
 Copyright   : Illo no te copie por favoh
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/int_list.h"

int myIndex;

int_list ordenaRecursivo(int_list l1, int_list l2,int i, int j, int k, int_list *res);
int_list ordenaIterativo(int_list l1, int_list l2);
int_list ordenaRecursivoFinal(int_list l1, int_list l2);
void imprime_lista_enteros(int_list ls, char principio, char entre, char fin);

int main(void) {

	int_list l1 = empty_int_list(5);
	int_list l2 = empty_int_list(5);

	l1.data[0] = 1;
	l1.data[1] = 4;
	l1.data[2] = 8;
	l1.data[3] = 10;
	l1.data[4] = 12;

	l2.data[0] = -6;
	l2.data[1] = 5;
	l2.data[2] = 7;
	l2.data[3] = 20;
	l2.data[4] = 24;

	int_list iterativo = ordenaIterativo(l1,l2);
	int_list recursivoFinal = ordenaRecursivoFinal(l1,l2);

	puts("Ordena lista iterativo: ");
	imprime_lista_enteros(iterativo, '[',',',']');
	puts("");
	puts("Ordena lista recursivo final: ");
	imprime_lista_enteros(recursivoFinal, '[',',',']');

	return EXIT_SUCCESS;
}

int_list ordenaIterativo(int_list l1, int_list l2)
{
	int_list res = empty_int_list(20);
	int i = 0;
	int j = 0;

	int k = 0;

	while(i < l1.tam && j < l2.tam)
	{
		int first = l1.data[i];
		int second = l2.data[j];

		if(first > second)
		{
			res.data[k] = second;
			j++;
		}
		else if(first == second)
		{
			res.data[k] = first;
			i++;
			j++;
		}
		else
		{
			res.data[k] = first;
			i++;
		}

		k++;
	}

	if(i != l1.tam)
	{
		for(int x = i; x < l1.tam; x++)
		{
			res.data[k] = l1.data[x];
			k++;
		}
	}

	if(j != l2.tam)
	{
		for(int x = j; x < l2.tam; x++)
		{
			res.data[k] = l2.data[x];
			k++;
		}
	}

	myIndex = k;
	return res;
}

int_list ordenaRecursivoFinal(int_list l1, int_list l2)
{
	int_list res = empty_int_list(l1.tam+l2.tam);
	return ordenaRecursivo(l1,l2,0,0,0,&res);
}

int_list ordenaRecursivo
(int_list l1, int_list l2,int i, int j, int k, int_list *res)
{
	if(i == l1.tam && j == l2.tam)
		return *res;
	else
	{
		if(i == l1.tam)
		{
			res->data[k] = l2.data[j];
			return ordenaRecursivo(l1,l2,i,j+1,k+1,res);
		}
		else if(j == l2.tam)
		{
			res->data[k] = l1.data[i];
			return ordenaRecursivo(l1,l2,i+1,j,k+1,res);
		}
		else
		{
			if(l1.data[i] > l2.data[j])
			{
				res->data[k] = l2.data[j];
				return ordenaRecursivo(l1,l2,i,j+1,k+1,res);
			}
			else if(l1.data[i] == l2.data[j])
			{
				res->data[k] = l1.data[i];
				return ordenaRecursivo(l1,l2,i+1,j+1,k+1,res);
			}
			else
			{
				res->data[k] = l1.data[i];
				return ordenaRecursivo(l1,l2,i+1,j,k+1,res);
			}
		}
	}
}

void imprime_lista_enteros(int_list ls, char principio, char entre, char fin)
{
	printf("%c",principio);
	for(int i = 0; i < myIndex; i++)
	{
		if(i == myIndex-1)
			printf("%d", ls.data[i]);
		else
			printf("%d%c ", ls.data[i], entre);
	}
	printf("%c",fin);
	printf("\n");
}


