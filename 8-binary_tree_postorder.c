#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to the function to call for each node.
 *
 * Description: This function performs a post-order traversal of the binary
 * tree starting from the given root node. For each visited node, the
 * specified function is called. If the tree is empty (tree is NULL) or the
 * function pointer is NULL, the function returns withoud doing anything.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Check if the tree or the function pointer is NULL */
	if (!func || !tree)
	{
		return;
	}

	/* Traverse the left subtree recursively */
	binary_tree_postorder(tree->left, func);

	/* Traverse the right subtree recursively */
	binary_tree_postorder(tree->right, func);

	/* Call the function for the current node */
	func(tree->n);
}
