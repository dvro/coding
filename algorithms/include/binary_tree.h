#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct tree_node {
	struct tree_node *left;
	struct tree_node *right;
	char *data;
};

struct tree_node *create_tree(char *value);
void delete_tree(struct tree_node **root);

int tree_size (struct tree_node *root);
int tree_height (struct tree_node *root);
int is_balanced(struct tree_node *root);

void print_pre_order(struct tree_node *root);
void print_levels (struct tree_node *root);

int add_node (struct tree_node **root, char *data);
int rem_node (struct tree_node **root, struct tree_node *to_remove);

int add_node_balance (struct tree_node **root, char *data);
int rem_node_balance (struct tree_node **root, struct tree_node *to_remove);

struct tree_node *get_kth_smallest_element(struct tree_node *root, int k);

#endif

