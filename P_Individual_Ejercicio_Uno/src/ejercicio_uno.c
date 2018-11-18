/*
 ============================================================================
 Name        : P_Individual.c
 Author      : Enrique Reina
 Version     :
 Copyright   : Illo no te copie por favoh
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#define NULL ( (void *) 0)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cuentaCaracteres(char *s);
char *stringMasLargoIterativo(char* lista[],int tam);
char *stringMasLargoRecursivoFinalReal(char* lista[], int tam);
int cuentaCaracterRecursivo(char *str, int i, int res);
char *stringMasLargoRecursivoFinal(char* lista[], int i, int acu, int a, int tam, char *res);


int main() {


	char *s1 = "qwerty";
	char *s2 = "qwertY";
	char *s3 = "qwerTY";
	char *s4 = "qweRTY";
	char *s5 = "qwERTY";
	char *s6 = "qWERTY";
	char *s7 = "QWERTY";
	char* lista[7] = {s1,s2,s3,s4,s5,s6,s7};

	int a = sizeof(lista);
	int b = sizeof(lista[0]);
	int tam = a/b;

	printf("De la lista de strings: \n");
	for(int i = 0; i < 7; i++)
	{
		printf("%s\n",lista[i]);
	}
	//Iterativo
	char *res = stringMasLargoIterativo(lista,tam);
	int x = cuentaCaracteres(res);
	printf("\nEl string más largo (Iterativo): \n");
	printf("%s --> %d caracteres en minusculas\n",res,x);
	//Recursivo
	printf("\n");
	printf("El string más largo (Recursivo Final): \n");
	printf("%s --> %d caracteres en minusculas\n",stringMasLargoRecursivoFinalReal(lista,tam),x);


   return (0);
}


int cuentaCaracteres(char *s)
{
	int lower = 0;
	int i = 0;

	while (i < strlen(s))
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			lower++;
	      i++;
	}

	return lower;
}

char *stringMasLargoIterativo(char* lista[],int tam)
{
	int i = 0;
	int acu = 0;
	char *mayor;
	while(i < tam)
	{
		if(cuentaCaracteres(lista[i]) > acu)
		{
			acu = cuentaCaracteres(lista[i]);
			mayor = lista[i];
		}

		i++;
	}

	return mayor;
}

char *stringMasLargoRecursivoFinalReal(char* lista[], int tam)
{
	char *res = "";
	return stringMasLargoRecursivoFinal(lista,0,0,0,tam,res);
}





int cuentaCaracterRecursivo(char *str, int i, int res)
{

	if(i >= strlen(str))
		return res;
	else
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return cuentaCaracterRecursivo(str,i+1,res+1);
		else
			return cuentaCaracterRecursivo(str,i+1,res);
	}
}

char *stringMasLargoRecursivoFinal(char* lista[], int i, int acu, int a, int tam, char *res)
{
	if(i == tam)
		return res;
	else
	{
		int temp = cuentaCaracterRecursivo(lista[i],0,0);
		if(temp > acu)
		{
			acu = temp;
			a = i;
		}
		return stringMasLargoRecursivoFinal(lista,i+1,acu,a,tam,lista[a]);
	}
}






