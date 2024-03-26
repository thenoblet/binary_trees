#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, 0 should the tree be NULL.
 *
 * Description: This function calculates and returns the height of the binary
 * tree rooted at the given node. The height of a binary tree is the length of
 * the longest path from the root node to a leaf node. If the tree is empty
 * (tree is NULL), the height is considered as 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* If the tree is NULL, return 0 as the height */
	if (!tree)
	{
		return (0);
	}

	/* Calculate the height of the left subtree recursively */
	if (tree->left)
	{
		left_height = binary_tree_height(tree->left) + 1;
	}

	/* Calculate the height of the right subtree recursively */
	if (tree->right)
	{
		right_height = binary_tree_height(tree->right) + 1;
	}

	/* Return the maximum height between left and right subtrees */
	return (left_height >= right_height ? left_height : right_height);
}
