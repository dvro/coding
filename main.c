#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


int main (void)
{
	struct tree_node *root = create_tree("1");
	root->left = create_tree("2");
	root->right = create_tree("3");
	root->left->left = create_tree("4");
	root->left->right = create_tree("5");
	root->right->left = create_tree("6");
	root->right->right = create_tree("7");
	root->right->right->right = create_tree("8");
	
	printf("print levels\n");
	print_levels(root);
	printf("print pre-order\n");
	print_pre_order(root);
	printf("\n");
	printf("tree_size %d\n",tree_size(root));
	delete_tree(&root);

	return 0;
}

