/*
 ============================================================================
 Name        : Ejercicio Cuatro
 Author      : Enrique Reina
 Version     :
 Copyright   :
 Description : Fusion Listas
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/ej_cuatro.h"

int main(void) {

	int_list l1 = empty_int_list(5);
	int_list l2 = empty_int_list(9);

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
	l2.data[5] = 25;
	l2.data[6] = 26;
	l2.data[7] = 30;
	l2.data[8] = 35;


	int_list iterativo = ordenaIterativo(l1,l2);

	int_list recursivoFinal = ordenaRecursivoFinal(l1,l2);

	puts("Ordena lista iterativo: ");
	imprime_lista_enteros(iterativo, '[',',',']');

	printf("\n");

	puts("Ordena lista recursivo final: ");
	imprime_lista_enteros(recursivoFinal, '[',',',']');

	return EXIT_SUCCESS;
}
