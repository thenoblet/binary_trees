#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a
 * valid Binary Search Tree (BST)
 * @tree: A pointer to the root node of the tree to check
 *
 * Description:
 * This function checks if the given binary tree satisfies the properties
 * of a Binary Search Tree (BST), which include:
 *  - The left subtree of a node contains only nodes with values less than
 *  the node’s value
 *  - The right subtree of a node contains only nodes with values
 *  greater than the node’s value
 *  - Both the left and right subtrees must also be BSTs
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* check if the tree is a valid BST */
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST
 * @tree: A pointer to the current root node of the tree
 * @min: The minimum value the current node's value can be
 * @max: The maximum value the current node's value can be
 *
 * Description:
 * This helper function recursively checks if the given binary tree satisfies
 * the properties of a Binary Search Tree (BST). It ensures that each node's
 * value falls within the valid range defined by min and max values, and
 * recursively checks the left and right subtrees.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	/* Base case: an empty tree is a valid BST */
	if (tree == NULL)
		return (1);

	/*  Check if the current node's value is within the valid range */
	if (tree->n < min || tree->n > max)
		return (0)
	/**
	 * Recursively check the left and right subtrees
	 * Left subtree's max value is the current node's value - 1
	 * Right subtree's min value is the current node's value + 1
	 */
	return (is_bst_util(tree->left, min, tree->n - 1) &&
			is_bst_util(tree->right, tree->n + 1, max));
}
