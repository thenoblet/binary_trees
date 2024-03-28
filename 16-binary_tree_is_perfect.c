#include "binary_trees.h"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * A perfect binary tree is a binary tree in which all interior nodes have
 * two children and all leaves have the same depth or same level.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 *
 * Description: This function determines wether a binary tree is perfect or
 * not. A perfect binary tree is defined as a binary tree which all interior
 * nodes have two children and all leaves have the same depth./
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	/* Check if tree is NULL, thus it is perfect */
	if (tree == NULL)
	{
		return (1);
	}

	/* Check if the tree is balanced */
	if (binary_tree_balance(tree) != 0)
	{
		return (0);
	}

	/* Check the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* If heights are equal and left and right subtrees are perfect, return 1 */
	if (left_height == right_height &&
			binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
		return (1);

	/* Otherwise, return 0 */
	return (0);
}
