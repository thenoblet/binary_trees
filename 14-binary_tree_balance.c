#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @node: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor, 0 if node is NULL.
 *
 * Description: This function computes the balance factor of a binary tree,
 * which is the difference between the height of the left subtree and the
 * height of the right subtree. A balanced tree has a balance factor of 0,
 * implying that the height of the left and right subtrees are equal. A
 * positive balance factor indicates that the left subtree is taller, while
 * a negative balance factor indicates that the right subtree is taller.
 *
 */
int binary_tree_balance(const binary_tree_t *node)
{
	int left_height;
	int right_height;

	/* Check if node is NULL, thus return 0 */
	if (!node)
	{
		return (0);
	}

	/* Calculate the height of the left subtree */
	left_height = binary_tree_height(node->left);
	/*Calcuate the height of the right subtree */
	right_height = binary_tree_height(node->right);

	/* Return the balance factor */
	return (left_height - right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @node: A pointer to the root node of the tree to measure the height.
 *
 * Return: If the node is NULL, return 0. Otherwise, return the height.
 *
 * Description: This function recursively calculates the height of a binary
 * tree, which is defined as the lenght of the longest path from the root node
 * to a leaf node. The height of an empty tree is considered to be 0.
 */
size_t binary_tree_height(const binary_tree_t *node)
{
	size_t left_height;
	size_t right_height;

	/* Check if node is NULL, thus return 0 */
	if (!node)
	{
		return (0);
	}

	/* Recursively calculate the height of the left subtree */
	left_height = binary_tree_height(node->left);
	/* Recursively calculate the height of the right subtree */
	right_height = binary_tree_height(node->right);

	/* Return the maximum height of the left or right subtree + 1 */
	return (1 + (left_height > right_height ? left_height : right_height));
}
