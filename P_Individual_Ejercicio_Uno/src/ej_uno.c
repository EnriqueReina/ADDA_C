#include "../includes/ej_uno.h"

//Metodo auxiliar que me cuenta el numero de minusculas
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


//Me devuelve el elemento con el mayor numero de minsuculas
char *stringMasLargoIterativo(char* lista[])
{
	int a = sizeof(lista);
	int b = sizeof(lista[0]);
	int tam = a/b;

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


//LLama al recursivo que de verdad
char *stringMasLargoRecursivoFinalReal(char* lista[])
{
	int a = sizeof(lista);
	int b = sizeof(lista[0]);
	int tam = a/b;

	char *res = "";
	return stringMasLargoRecursivoFinal(lista,0,0,0,tam,res);
}

//Metodo auxliar en recursivo
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


//Me devuelve el elemento con el mayor numero de minsuculas recursivo
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

