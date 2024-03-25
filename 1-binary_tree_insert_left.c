#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of a given
 * node in a binary tree.
 * @parent: A pointer to the node to insert the left child in.
 * @value: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly inserted node, On error or parent is NULL,
 * return NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent node is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* Create a new node with the given value */
	new_node = binary_tree_node(parent, value);

	/* Check if new node creation was a success */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Insert the new node as the left child of the parent */
	if (parent->left != NULL)
	{
		/* If parent already has a left child, adjust the pointers */
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
