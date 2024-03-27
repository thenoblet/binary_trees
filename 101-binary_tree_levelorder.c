#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *        The value in the node must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current = NULL;
	binary_tree_t *queue[1024]; /* queue for level-order traversal */
	int front = 0, rear = -1, size = 0;

	if (tree == NULL || func == NULL)
		return;

	/* Enqueue the root node */
	queue[++rear] = (binary_tree_t *)tree;
	size++;

	/* Perform level-order traversal */
	while (size > 0)
	{
		/* Dequeue a node from the queue */
		current = queue[front++];
		size--;

		/* Call the function with the value of the current node */
		func(current->n);

		/* Enqueue the left child, if exists */
		if (current->left != NULL)
		{
			queue[++rear] = current->left;
			size++;
		}

		/* Enqueue the right child, if exists */
		if (current->right != NULL)
		{
			queue[++rear] = current->right;
			size++;
		}
	}
}
