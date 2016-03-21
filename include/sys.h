#ifndef SYS_H
#define SYS_H
#include <stdlib.h>

#define LINKED_LIST_SIZE (255)


typedef struct ll_node_t
{
	void *data;
	struct ll_node_t *next;
} ll_node_t;

typedef struct linked_list_t
{
	ll_node_t *tail;		
	ll_node_t *head;		
} linked_list_t;

static inline void linked_list_init(linked_list_t *linked_list)
{
	linked_list->head = NULL;
	linked_list->tail = NULL;
}
static inline void linked_list_add(linked_list_t *linked_list, void *data)
{
	if(linked_list->tail == NULL)
	{
		linked_list->head = (ll_node_t*) malloc(sizeof(ll_node_t));
		linked_list->head->next = NULL;
		linked_list->head->data = data;
		linked_list->tail = linked_list->head;
	}
	else
	{
		linked_list->tail->next = (ll_node_t*) malloc(sizeof(ll_node_t));
		linked_list->tail = linked_list->tail->next;
		linked_list->tail->next = NULL;
		linked_list->tail->data = data;
	}
}
//static inline void linked_list_remove_element(linked_list_t linked_list, void *data);
//static inline void *linked_list_pop(linked_list_t linked_list);
static inline int linked_list_count_elem(linked_list_t *linked_list)
{
	ll_node_t *ptr;
	ptr = linked_list->head;

	int n=0;
	while(ptr != NULL)
	{
		ptr = ptr->next;
		n += 1;
	}
	return n;
}

#endif
