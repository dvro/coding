#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sl_list.h"
#include "stack.h"

struct stack *create_stack ()
{
	struct stack *st = (struct stack *) malloc(sizeof(struct stack));
	if (!st)
		return NULL;

	st->head = NULL;
	return st;
}

void delete_stack (struct stack **st, void *free_data(void *))
{
	if (*st == NULL)
		return;


	struct sl_list_node *it = (*st)->head;
	struct sl_list_node *tmp;
	while (it) {
		tmp = it;
		it = it->next;
		if (free_data != NULL)
			free_data(tmp->data);
		else
			free(tmp->data);
		free(tmp);
	}
	free(*st);
	*st = NULL;
}

int push (struct stack *st, void *data, size_t data_size)
{
	if (st == NULL)
		return 0;

	if (data == NULL)
		return 0;

	
	struct sl_list_node *tmp = create_sl_list_node(data, data_size);
	if (!tmp)
		return 0;

	tmp->next = st->head;
	st->head = tmp;
	return 1;
}

int pop  (struct stack *st, void **data)
{
	if (st == NULL)
		return 0;

	if (data == NULL)
		return 0;

	if (!st->head)
		return 0;

	struct sl_list_node *tmp = st->head;
	st->head = tmp->next;

	*data = tmp->data;
	free(tmp);
}


