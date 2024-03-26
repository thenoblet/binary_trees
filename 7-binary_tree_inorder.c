#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to the function to call for each node.
 *
 * Description: This function performs an in-order traversal of the binary
 * tree starting from the given root node. For each visited node, the specified
 * function is called. If the tree is empty (tree is NULL) or the function
 * pointer is NULL, the function returns without doing anything.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if the tree or the function pointer is NULL */
	if (!func || !tree)
	{
		return;
	}

	/* Traverse the left subtree recursivley */
	binary_tree_inorder(tree->left, func);

	/* Call the function for the current node */
	func(tree->n);

	/* Traverse the right subtree recursively */
	binary_tree_inorder(tree->right, func);
}
