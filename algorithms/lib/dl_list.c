#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dl_list.h>


struct dl_list_node *create_dl_list_node (void *data, size_t data_size)
{
	if (data == NULL)
		return NULL;

	struct dl_list_node *lst_node = (struct dl_list_node *) malloc(sizeof(struct dl_list_node));
	if (lst_node == NULL)
		return NULL;

	lst_node->next = NULL;
	lst_node->prev = NULL;
	lst_node->data_size = data_size;

	lst_node->data = calloc(1, data_size);
	if (lst_node->data == NULL) {
		free(lst_node);
		return NULL;
	}

	memcpy(lst_node->data, data, data_size);
	return lst_node;
}

void destroy_dl_list (struct dl_list_node **head, void *free_data(void *))
{
	if (*head == NULL)
		return;

	struct dl_list_node *it = *head;
	struct dl_list_node *tmp;
	while (it) {
		tmp = it;
		it = it->next;

		if (free_data != NULL)
			free_data(tmp->data);
		else
			free(tmp->data);

		free(tmp);
	}

	*head = NULL;
}

void print_dl_list(struct dl_list_node *head)
{
	if (head != NULL) {
		struct dl_list_node *it = head;
		while (it) {
			printf("%s", (char *)it->data);
			it = it->next;
			if (it)
				printf(" ");
		}
	}
	printf("\n");
}

int reverse_dl_list (struct dl_list_node **head)
{
	if (*head == NULL)
		return 0;

	struct dl_list_node *it = *head;
	while (it) {
		if (it->next == NULL)
			*head = it;

		struct dl_list_node *tmp = it->next;
		it->next = it->prev;
		it->prev = tmp;
		
		it = it->prev;
	}

	return 1;
}


