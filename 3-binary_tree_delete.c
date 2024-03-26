#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree rooted at the given
 * node.
 * @tree: A pointer to the root node of the tree to be deleted.
 *
 * Description: This function recursively deletes all nodes in the binary
 * tree starting from the given root node. It frees the memory allocated
 * for each node and its children. If the tree is empty, ie (tree is NULL),
 * the function returns without doing anything.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* If the tree is empty, do nothing and return */
	if (!tree)
	{
		return;
	}

	/* Recursively delete the left subtree */
	if (tree->left)
	{
		binary_tree_delete(tree->left);
	}

	/* Recursively delete the right subtree */
	if (tree->right)
	{
		binary_tree_delete(tree->right);
	}

	/* Free the memory allocated for the current node */
	free(tree);
}
