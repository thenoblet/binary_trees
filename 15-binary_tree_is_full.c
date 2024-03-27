#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full, return 1. Otherwise return 0.
 *
 * Description: This function determines whether a binary tree is a full
 * binary tree. A binary tree is considered full if every node has either
 * zero or two children. If a node has two children, both children must also
 * be full trees themselves. An empty tree is considered full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Check if the tree is empty, thus it is considered full */
	if (!tree)
	{
		return (1);
	}

	/* If both children are NULL, it is considered full */
	if (!tree->left && !tree->right)
	{
		return (1);
	}

	/* If only one child is NULL, it is not full */
	if (!tree->left || !tree->right)
	{
		return (0);
	}

	/* Recursively check both left and right subtrees */
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}
