#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a given node is a leaf in a binary tree.
 * @node: A pointer to the node to be checked.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 *
 * Description: This function returns 1 if the given node is a leaf node in
 * the binary tree, meaning it has no children (neigher left nor right child).
 * If the node is NULL, the function return 0 by default, considering that it
 * is not a leaf.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* If the node is NULL, it is definitely not a leaf */
	if (!node)
	{
		return (0);
	}

	/* Check if the node has no children */
	if (!node->left && !node->right)
	{
		return (1); /* Thus, it is a lead node */
	}

	return (0); /* Not passing the condition means it is not a leaf */
}
