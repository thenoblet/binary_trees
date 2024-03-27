#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue = NULL, *current;
	int front = 0, rear = -1, size = 0;
	bool found_null = false;

	if (tree == NULL)
		return (0);

	/* Allocate memory for the queue */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[++rear] = tree; /* Enqueue the root node */
	size++;

	while (size > 0)
	{
		current = queue[front++]; /* Dequeue */
		size--;

		/* If a NULL node is found after a non-NULL node, tree is not complete */
		if (found_null && current != NULL)
		{
			free(queue);
			return (0);
		}

		if (current == NULL)
			found_null = true; /* Set flag if a NULL node is encountered */
		else
		{
			queue[++rear] = current->left; /* Enqueue left child */
			size++;

			queue[++rear] = current->right; /* Enqueue right child */
			size++;
		}
	}
	free(queue);
	return (1); /* If the traversal completes w/o violation, tree is complete */
}
