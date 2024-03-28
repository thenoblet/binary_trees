#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Description: This function finds the uncle of a given node in a binary tree.
 * The uncle of a node is defined as the sibling of its parent node.
 * If the provided node is NULL, or if it does not have a parent or a
 * grandparent, it means the node has no uncle, and NULL is returned.
 *
 * @node: Pointer to the node for which to find the uncle.
 *
 * Return:
 * If the provided node is NULL or has no uncle, the function returns NULL.
 * Otherwise, it returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the provided node its parent, or its grandparent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	/* Determine the uncle node by returning the sibling of parent node */
	{
		return (node->parent->parent->left == node->parent ?
				node->parent->parent->right :
				node->parent->parent->left);
	}
}
