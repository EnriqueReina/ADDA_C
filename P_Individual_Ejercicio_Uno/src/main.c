/*
 ============================================================================
 Name        : Ejercicio Uno
 Author      : Enrique Reina
 Version     :
 Copyright   :
 Description : Devuelve cadena con mayor número de minúsculas
 ============================================================================
 */

#define NULL ( (void *) 0)

#include <stdio.h>
#include <stdlib.h>
#include "../includes/ej_uno.h"

int main() {


	char *s1 = "qwerty";
	char *s2 = "qwertY";
	char *s3 = "qwerTY";
	char *s4 = "qweRTY";
	char *s5 = "qwERTY";
	char *s6 = "qWERTY";
	char *s7 = "QWERTY";
	char* lista[7] = {s1,s2,s3,s4,s5,s6,s7};

	printf("De la lista de strings: \n");
	for(int i = 0; i < 7; i++)
	{
		printf("%s\n",lista[i]);
	}
	//Iterativo
	char *res = stringMasLargoIterativo(lista);
	int x = cuentaCaracteres(res);
	printf("\nEl string más largo (Iterativo): \n");
	printf("%s --> %d caracteres en minusculas\n",res,x);
	//Recursivo
	printf("\n");
	printf("El string más largo (Recursivo Final): \n");
	printf("%s --> %d caracteres en minusculas\n",stringMasLargoRecursivoFinalReal(lista),x);


   return (0);
}
