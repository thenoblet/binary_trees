#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Description: This function determines whether a given node is a leaf in
 * a binary tree, meaning it has no children.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * calculate_depth - Calculates the depth of a given node in a binary tree.
 * @node: A pointer to the node to measure the depth of.
 *
 * Description: This function calculates the depth of a given node in a binary
 * tree by traversing up to its parent recursively.
 *
 * Return: The depth of the node.
 */
size_t calculate_depth(const binary_tree_t *node)
{
	/* Check if the node has no left and right children */
	return (node->parent != NULL ? 1 + calculate_depth(node->parent) : 0);
}

/**
 * find_first_leaf - Finds and returns the first encountered leaf of a binary
 * tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Description: This function traverses the binary tree to find and return
 * the first encountered leaf node, which is a node without any children.
 *
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *find_first_leaf(const binary_tree_t *tree)
{
	/* If the current node is a leaf, return it */
	if (is_leaf(tree))
	{
		return (tree);
	}

	return (tree->left ? find_first_leaf(tree->left) :
			find_first_leaf(tree->right));
}

/**
 * check_perfection - Recursively checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * @leaf_depth: The depth of a leaf node in the tree.
 * @current_level: The current level of the tree.
 *
 * Description: This function recursively checks if a binary tree is perfect,
 * meaning all non-leaf nodes have two children and all leaves are at the same
 * depth.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int check_perfection(const binary_tree_t *tree, size_t leaf_depth,
		size_t current_level)
{
	/* If the current node is a leaf, if its depth matches leaf depth */
	if (is_leaf(tree))
	{
		return (current_level == leaf_depth ? 1 : 0);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (0);
	}

	/* Recursively check the left and right subtrees */
	return (check_perfection(tree->left, leaf_depth, current_level + 1) &&
			check_perfection(tree->right, leaf_depth, current_level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Description: This function checks whether a binary tree is perfect or not.
 * A perfect binary tree is one in which all non-leaf nodes have two children
 * and all leaves are at the same depth.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_depth;

	/* If the tree is NULL, it is not perfect */
	if (tree == NULL)
	{
		return (0);
	}

	leaf_depth = calculate_depth(find_first_leaf(tree));

	/* Calculate the depth of the first encountered leaf node */
	return (check_perfection(tree, leaf_depth, 0));
}
