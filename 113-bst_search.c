#include "binary_trees.h"

/**
 * bst_search - Searches for a node with a specific value in a BST
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search for
 *
 * Description:
 * This function searches for a node with the specified value in the Binary
 * Search Tree (BST) represented by the root node 'tree'.
 *
 * Return: A pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current = NULL;

	if (tree == NULL)
		return (NULL);

	current = tree;

	/* Traverse the tree to find the node with the specified value */
	while (current != NULL)
	{
		if (current->n == value)
			return ((bst_t *)current);
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	return (NULL); /* value not found */
}
