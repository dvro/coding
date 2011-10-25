#ifndef STACK_H
#define STACK_H

#include "sl_list.h"

struct stack {
	struct sl_list_node *head;
};

struct stack *create_stack ();
void delete_stack (struct stack **st, void *free_data(void *));
int push (struct stack *st, void *data, size_t data_size);
int pop  (struct stack *st, void **data);


#endif

