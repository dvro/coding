#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sl_list.h"

struct sl_list_node *create_sl_list_node(void *data, size_t data_size)
{
	if (data == NULL)
		return NULL;

	struct sl_list_node *lst_node = (struct sl_list_node *) malloc(sizeof(struct sl_list_node));

	if (lst_node == NULL)
		return NULL;

	lst_node->next = NULL;
	lst_node->data_size = data_size;

	lst_node->data = calloc(1, data_size);
	if (lst_node->data == NULL) {
		free(lst_node);
		return NULL;
	}

	memcpy(lst_node->data, data, data_size);
	return lst_node;
}

void destroy_sl_list (struct sl_list_node **head, void *free_data(void *))
{
	if (!(*head))
		return;

	struct sl_list_node *it = *head;
	struct sl_list_node *tmp;
	while(it != NULL) {
		tmp = it;
		it = it->next;
		if (free_data == NULL)
			free_data(tmp->data);
		else
			free(tmp->data);
		free(tmp);
	}
}



