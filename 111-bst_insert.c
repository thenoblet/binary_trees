#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Description:
 * This function inserts a new node with the given value into the Binary Search
 * Tree (BST) represented by the root node pointed to by 'tree'.
 * It ensures that the BST property is maintained after insertion.
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL, *parent = NULL, *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else if (value == current->n)
			return (NULL);
	}

	new_node = binary_tree_node(NULL, value);
	if (parent == NULL)
		parent = new_node;
	else if (value < parent->n)
	{
		parent->left = new_node;
		new_node->parent = parent;
	}
	else
	{
		parent->right = new_node;
		new_node->parent = parent;
	}

	return (new_node);
}
