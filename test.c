#include "include/sys.h"
#include <stdio.h>

int main()
{
	linked_list_t lista;
	linked_list_init(&lista);
	int h=3;
	int o=4;
	linked_list_add(&lista,&h);
	linked_list_add(&lista,&o);
	int n = linked_list_count_elem(&lista);
	printf("El numero de elementos es: %i\n",n);
	printf("El valor de head es: %i\n", (int) *((int*) (lista.head->data)));
}
