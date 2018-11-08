#include "../includes/int_list.h"
#include <stdio.h>
#include <stdlib.h>

int_list create_int_list(int * data, int tam, int size){
	int_list r = {tam,size,data};
	return r;
}

int_list empty_int_list(int tam){
	int * d = (int *) malloc(tam*sizeof(int));
	int_list r = {tam,0,d};
	return r;
}

void imprime_list_int(int_list ls, char * s, char * p, char * f) { //problema 50
	int n = 0;
	printf("%s", p);
	for (int i = 0; i < ls.size; i++) {
		int e = ls.data[i];
		if (n == 0){
			printf("%d", e);
			n++;
		} else
		{
			printf("%s", s);
			printf("%d", e);
		}
	}
	printf("%s", f);
}
