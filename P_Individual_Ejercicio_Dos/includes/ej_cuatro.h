#ifndef EJ_
#define EJ_CUATRO_H_CUATRO_H_

#include "../includes/int_list.h"

int_list ordenaIterativo(int_list l1, int_list l2);

int_list ordenaRecursivoFinal(int_list l1, int_list l2);
int_list ordenaRecursivo(int_list l1, int_list l2,int i, int j, int k, int_list *res);

void imprime_lista_enteros(int_list ls, char principio, char entre, char fin);




#endif
