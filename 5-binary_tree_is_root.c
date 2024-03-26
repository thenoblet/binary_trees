#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root in a binary tree.
 * @node: A pointer to the node to be checked.
 *
 * Return: 1 if the node is a root, 0 otherwise.
 *
 * Description: This function returns 1 if the given node is a root node in the
 * binary tree, meaning it has no parent. If the node is NULL, the function
 * returns 0 by default, considering it is not a root.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* If the node is NULL, it is definitely not a root */
	if (!node)
	{
		return (0);
	}

	/* Check if the node has no parent */
	if (!node->parent)
	{
		return (1); /* The node is a root */
	}

	return (0); /* Not passing the condition means it is not a root */
}
