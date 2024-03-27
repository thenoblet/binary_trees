#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child in a
 * binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: The number of nodes with at least one child, 0 should the tree be
 * NULL.
 *
 * This function calculates and returns the number of nodes with at least one
 * child in the binary tree rooted at the given node. If the tree is empty
 * (tree is NULL), the number of such nodes is considered as 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Check if the tree is NULL, thus return 0 nodes */
	if (!tree)
	{
		return (0);
	}

	/* If the current node has no children, return 0 */
	if (!tree->left && !tree->right)
	{
		return (0);
	}

	return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + 1);
}
