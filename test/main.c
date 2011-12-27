#include <stdio.h>
#include <stdlib.h>
#include <binary_tree.h>

int main(void)
{
	struct tree_node *root = create_tree("5");
	root->left = create_tree("2");
	root->left->left = create_tree("1");
	root->left->right = create_tree("3");
	root->left->right->right = create_tree("4");
	
	root->right = create_tree("10");
	root->right->left = create_tree("7");
	root->right->left->left = create_tree("6");
	root->right->left->right = create_tree("8");
	root->right->left->right->right = create_tree("9");


	int i;
	for (i = 0; i < 15; i++) {
		struct tree_node *tmp = get_kth_smallest_element(root, i);
		if (tmp == NULL)
			printf("NULL\n");
		else
			printf("%s\n", tmp->data);

	}

	delete_tree(&root);

	return 0;
}


