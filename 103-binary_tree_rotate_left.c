#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Description:
 * This function performs a left rotation on the binary tree rooted at 'tree'.
 * It adjusts the pointers of the nodes accordingly to maintain the binary tree
 * properties after the rotation.
 *
 * Return: A pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* If the tree is NULL or it has no right child, return the tree */
	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;

	/* If new_root has a left child, update its parent pointer to tree. */
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->parent = tree->parent;

	/**
	 * tree is the root of the entire tree?
	 * update new_root's parent and tree's parent
	 */
	if (tree->parent == NULL)
	{
		new_root->parent = NULL;
		tree->parent = new_root;
	}
	else if (tree == tree->parent->left)
		tree->parent->left = new_root;
	else
		tree->parent->right = new_root;

	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
