#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct dl_list_node {
	struct dl_list_node *prev;
	struct dl_list_node *next;
	void *data;
	size_t data_size;
};

struct dl_list_node *create_dl_list_node (void *data, size_t data_size);

void destroy_dl_list (struct dl_list_node **head, void *free_data(void *));

void print_dl_list (struct dl_list_node *head);

int reverse_dl_list (struct dl_list_node **head);

#endif

