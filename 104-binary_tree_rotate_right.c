#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Description:
 * This function performs a right rotation on the binary tree rooted at 'tree'.
 * It adjusts the pointers of the nodes accordingly to maintain the binary tree
 * properties after the rotation.
 *
 * Return: A pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *new_root = NULL;

	/* If the tree is NULL or it has no left child, return the tree. */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right != NULL)
		new_root->right->parent = tree;

	new_root->parent = tree->parent;

	if (tree->parent == NULL)
	{
		new_root->parent = NULL;
		tree->parent = new_root;
	}
	else if (tree == tree->parent->right)
		tree->parent->right = new_root;
	else
		tree->parent->left = new_root;

	new_root->right = tree;
	tree->parent = new_root;

	return (new_root); /* Return the new root of the rotated tree.*/
}
