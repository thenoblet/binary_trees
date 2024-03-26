#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a new node as the right child of a given
 * node in a binary tree.
 * @parent: A pointer to the node to insert the right child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly inserted node, On error or Parent is NULL,
 * return NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent node is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);

	/* Check if new node creation was a success */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Insert the new node as the right child of the parent */
	if (parent->right != NULL)
	{
		/* If parent already has a right child, adjust pointers */
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
