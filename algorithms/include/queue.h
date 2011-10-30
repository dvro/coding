#ifndef QUEUE_H
#define QUEUE_H
#include "dl_list.h"

struct queue {
	struct dl_list_node *head;
	struct dl_list_node *tail;
};

struct queue *create_queue();
void destroy_queue(struct queue **q);
int in_queue (struct queue *q, void *data, size_t data_size);
int de_queue (struct queue *q, void **data);
int is_empty (struct queue *q);

#endif

