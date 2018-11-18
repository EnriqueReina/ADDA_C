#include "../includes/ej_cuatro.h"


int myIndex;

//MergeSort en iterativo
int_list ordenaIterativo(int_list l1, int_list l2){
	int_list res = empty_int_list(20);
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < l1.tam && j < l2.tam){
		int first = l1.data[i];
		int second = l2.data[j];

		if(first > second){
			res.data[k] = second;
			j++;
		}
		else if(first == second){
			res.data[k] = first;
			i++;
			j++;
		}
		else{
			res.data[k] = first;
			i++;
		}

		k++;
	}
	if(i != l1.tam){
		while(i < l1.tam){
			res.data[k] = l1.data[i];
			i++;
			k++;
		}
	}
	if(j != l2.tam){
		while(j < l2.tam){
			res.data[k] = l2.data[j];
			j++;
			k++;
		}
	}
	myIndex = k;
	return res;
}

//LLama al verdadero método recursivo
int_list ordenaRecursivoFinal(int_list l1, int_list l2)
{
	int_list res = empty_int_list(l1.tam+l2.tam);
	return ordenaRecursivo(l1,l2,0,0,0,&res);
}

int_list ordenaRecursivo (int_list l1, int_list l2,int i, int j, int k, int_list *res)
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


