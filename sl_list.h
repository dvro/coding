#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

struct sl_list_node {
	struct sl_list_node *next;
	void *data;
	size_t data_size;
};

struct sl_list_node *create_sl_list_node (void *data, size_t data_size);
void destroy_sl_list_node (struct sl_list_node **head);

#endif

