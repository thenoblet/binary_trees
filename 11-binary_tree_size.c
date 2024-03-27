#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree, 0 should the tree be NULL.
 *
 * Description: This function computes and returns the size of the binary tree
 * rooted at a given node. The size of a binary tree is the total number of
 * nodes in the tree. If the tree is empty (tree is NULL), the size is by
 * default considered to be 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	/* Check if the tree is NULL, thus return size as 0 */
	if (!tree)
	{
		return (0);
	}

	/* Compute size recursively by summing the sizes of left and right */
	size = binary_tree_size(tree->left) + 1 +
		binary_tree_size(tree->right);

	return (size);
}
