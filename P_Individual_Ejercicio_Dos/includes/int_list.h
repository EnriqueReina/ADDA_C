
#ifndef INT_LIST_H_
#define INT_LIST_H_

typedef struct {
	int tam;
	int size;
	int * data;
}int_list;

int_list create_int_list(int * data, int tam, int size);

int_list empty_int_list(int tam);

void imprime_list_int(int_list, char * s, char * p, char * f);

#endif
