#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dl_list.h>
#include <queue.h>

struct queue *create_queue()
{
	struct queue *q = (struct queue *) malloc(sizeof(struct queue));

	if(q) {	
		q->head = NULL;
		q->tail = NULL;
	}

	return q;
}

void destroy_queue(struct queue **q)
{
	if (!*q)
		return;

	destroy_dl_list(&((*q)->head), NULL);
	free(*q);
	*q = NULL;
}

int in_queue (struct queue *q, void *data, size_t data_size)
{
	if (q == NULL)
		return 0;
	if (data == NULL)
		return 0;

	struct dl_list_node *tmp = create_dl_list_node(data, data_size);
	if (!tmp)
		return 0;

	if (!q->head) {
		q->head = tmp;
		q->tail = tmp;
	} else {
		q->tail->next = tmp;
		tmp->prev = q->tail;
		q->tail = tmp;
	}

	return 1;
}


int de_queue (struct queue *q, void **data)
{
	if (q == NULL)
		return 0;
	
	if (!q->head)
		return 0;

	struct dl_list_node *tmp = q->head;
	
	if (q->head == q->tail) {
		q->head = NULL;
		q->tail = NULL;
	} else {
		q->head = q->head->next;
		q->head->prev = NULL;
	}

	*data = tmp->data;
	free(tmp);

	return 1;
}

int is_empty (struct queue *q)
{
	return q == NULL || q->head == NULL;
}

void print_queue(struct queue *q)
{
	if (q != NULL)
		print_dl_list(q->head);
	else
		printf("\n");
}

