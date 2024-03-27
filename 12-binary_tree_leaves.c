#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves of the tree, 0 if the tree is NULL.
 *
 * This function calculates and returns the number of leaf nodes in the binary
 * tree rooted at the given node. A leaf node is a node with no children.
 * If the tree is empty (tree is NULL), the number of leaves is considered 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Check if the tree is NULL, thus return 0 leaves */
	if (!tree)
	{
		return (0);
	}

	/* If the current node is a leaf, return 1 */
	if (!tree->right && !tree->left)
	{
		return (1);
	}

	/* Recursively count the leaves in the left and right subtrees */
	return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
