#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node to find the sibling of.
 *
 * Description: This function finds the sibling of a given node in a binary
 * tree. If the node has no sibling (i.e., it is the only child of its parent),
 * NULL is returned.
 *
 * Return: A pointer to the sibling node, or NULL if no sibling exists.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL, or if the node is root */
	if (!node || !node->parent || (!node->parent->left &&
				!node->parent->right))
	{
		return (NULL);
	}
	/* Return the sibling of the node (the other child of its parent) */
	return (node->parent->left == node ? node->parent->right :
			node->parent->left);
}
