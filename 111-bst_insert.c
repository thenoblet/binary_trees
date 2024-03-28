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
	bst_t *new_node, *current, *parent;

	if (tree == NULL)
		return (NULL);

	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	current = *tree;
	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
		{
			free(new_node);
			return (NULL);
		}
	}

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;
	return (new_node);
}
