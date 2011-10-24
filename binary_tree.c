#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "queue.h"

struct tree_node *create_tree(char *value)
{
	if (value == NULL)
		return NULL;

	struct tree_node *tmp = (struct tree_node *)malloc(sizeof(struct tree_node));
	if (!tmp)
		return NULL;

	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = (char *)malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(tmp->data, value);

	return tmp;
}

void delete_tree(struct tree_node **root)
{
	if (*root == NULL)
		return;

	delete_tree(&((*root)->left));
	delete_tree(&((*root)->right));
	
	free((*root)->data);
	free((*root));
	*root = NULL;
}

int tree_size(struct tree_node *root)
{
	if (root == NULL)
		return 0;

	return 1 + tree_size(root->left) + tree_size(root->right);
}

void print_pre_order(struct tree_node *root)
{
	if (!root)
		return;

	print_pre_order(root->left);
	printf("%s", root->data);
	print_pre_order(root->right);
}

void print_levels(struct tree_node *root)
{
	if (root == NULL) {
		printf("\n");
		return;
	}

	int last_level = 0;
	int *current_level = (int *) malloc(sizeof(int));

	struct queue *node_q = create_queue();
	in_queue(node_q, root, sizeof(struct tree_node));

	struct queue *level_q = create_queue();
	in_queue(level_q, &last_level, sizeof(int));
	
	while (!is_empty(node_q)) {
		
		struct tree_node *tmp;
		de_queue(node_q, (void **) &tmp);
		de_queue(level_q, (void **) &current_level);

		if (*current_level != last_level) {
			printf(";\n");
			last_level = *current_level;
		}
		printf("%s", tmp->data);

		*current_level = *current_level + 1;

		if (tmp->left) {
			in_queue(node_q, tmp->left, sizeof(struct tree_node));
			in_queue(level_q, (void *)current_level, sizeof(int));
		}

		if (tmp->right) {
			in_queue(node_q, tmp->right,sizeof(struct tree_node));
			in_queue(level_q, (void *)current_level, sizeof(int));
		}

		free(tmp->data);
		free(tmp);
	}

	free(current_level);
	destroy_queue(&node_q);
	destroy_queue(&level_q);
	
	printf(";\n");
}









	


