#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree (BST) from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Description:
 * This function constructs a binary search tree (BST) from a given array of
 * integers. It iterates through the array and inserts each unique element
 * into the BST.
 *
 * Return: A pointer to the root node of the created BST if successful.
 * NULL upon failure (e.g., memory allocation failure or if @array is NULL).
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i, j;

	/* Check if the array pointer is NULL */
	if (array == NULL)
	{
		return (NULL);
	}

	/* Iterate through the array to insert unique elements into the BST */
	for (i = 0; i < size; i++)
	{
		/* Check if the current element is already inserted */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If the current element is unique, insert it into the BST */
		if (j == i)
		{
			/* Insert the element into the BST */
			if (bst_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
