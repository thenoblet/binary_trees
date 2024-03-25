#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node with the given parent and
 * value.
 * @parent: A pointer to the parent node of the new node.
 * @value: The integer value to be stored in the new node.
 *
 * Return: A pointer to the newly created node, otherwise NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));

	/* Check if the memory allocatino was successful */
	if (!new_node)
	{
		return (NULL);
	}

	/* Initialize the new node with the given values */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
