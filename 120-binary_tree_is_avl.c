#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: A pointer to the root node of the binary tree
 *
 * Description:
 * This function checks if the given binary tree satisfies the properties of
 * an AVL tree, including:
 *  - The heights of the left and right subtrees of every node
 * differ by at most 1
 *  - Both the left and right subtrees must also be AVL trees
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - Helper function to recursively check AVL tree properties
 * @tree: A pointer to the current node in the binary tree
 * @min: The minimum allowed value for nodes in the subtree
 * @max: The maximum allowed value for nodes in the subtree
 *
 * Description:
 * This function recursively checks if the subtree rooted at the given node
 * satisfies the properties of an AVL tree, including:
 *  - The heights of the left and right subtrees of every node
 * differ by at most 1
 *  - Both the left and right subtrees must also be AVL trees
 * It also performs a BST check to ensure that all nodes in
 * the subtree have values
 * within the specified range.
 *
 * Return: 1 if the subtree is an AVL tree, 0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the binary tree
 *
 * Description:
 * This function recursively calculates the height of the binary tree
 * rooted at the given node 'tree'.
 *
 * Return: The height of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
