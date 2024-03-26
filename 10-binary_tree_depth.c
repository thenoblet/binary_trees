#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node, 0 should the tree be NULL.
 *
 * Description: This function calculates and returns the depth of the given
 * node in the binary tree. The depth of a node is the number of edges from
 * the node to the root of the tree. If the tree is empty (tree is NULL), the
 * depth is considered 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	/* If the tree is NULL, return depth as 0 */
	if (!tree)
	{
		return (0);
	}

	/* Calculate the depth by traversing up the root */
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
