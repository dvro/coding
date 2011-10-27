#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

struct sl_list_node {
	struct sl_list_node *next;
	void *data;
	size_t data_size;
};

struct sl_list_node *create_sl_list_node (void *data, size_t data_size);

void destroy_sl_list_node (struct sl_list_node **head);

int add_node (struct sl_list_node **head, void *data);

int rem_node (struct sl_list_node **head, void *data, int *compare(void *, void *));

struct sl_list_node *find_m_to_last (struct sl_list_node *head, int m);

struct sl_list_node *find_middle (struct sl_list_node *head);

int has_cicle (struct sl_list_node *head);

struct sl_list_node *find_cicle (struct sl_list_node *head);

int reverse_sl_list (struct sl_list_node **head);

#endif

