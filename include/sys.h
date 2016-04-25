#ifndef SYS_H
#define SYS_H
#include <stdlib.h>

#define LINKED_LIST_SIZE (255)


/**
 * \brief Linked list node
 */
typedef struct ll_node_t
{
	void *data; /**< Pointer to data*/
	struct ll_node_t *next; /**< Pointer to next node */
} ll_node_t;

/**
 * \brief Linked list
 *
 * Please don't access to members directly. Use provided functions instead.
 */
typedef struct linked_list_t
{
	ll_node_t *tail; /**< Tail of list*/	
	ll_node_t *head; /**< Head of list*/	
} linked_list_t;

/**
 * Init linked list.
 *
 * MUST be called, otherwise you will get a nice buffer overflow.
 * @param linked_list Pointer to linked list
 */
static inline void linked_list_init(linked_list_t *linked_list)
{
	linked_list->head = NULL;
	linked_list->tail = NULL;
}


/**
 * Add an element to linked list
 *
 * @param linked_list Pointer to linked list where the new element will be stored.
 * @param data Data to store
 */
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


/**
 * Count number of elements of given linked list
 *
 * @param linked_list Pointer to linked list
 */
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
/**
 * Get first element of linked list
 *
 * @param linked_list Pointer to linked list
 */
static inline void *linked_list_get_head_obj(linked_list_t *linked_list)
{
	if(linked_list != NULL)
	{
		if (linked_list->head != NULL)
		{
			return linked_list->head->data;
		}
	}
	return NULL;
}

/** 
 * Get next object of node
 *
 * @param obj Pointer to object
 * @return Pointer to the next object
 */
static inline ll_node_t *linked_list_obj_next(ll_node_t *obj)
{
	return obj->next;
}

#endif
