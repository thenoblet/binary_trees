#include "binary_trees.h"

/**
 * bst_remove - Removes a node with a specific value from a BST
 * @root: A pointer to the root node of the BST
 * @value: The value of the node to remove
 *
 * Description:
 * This function removes a node with the specified value from the Binary
 * Search Tree (BST) represented by the root node 'root'. It returns the
 * pointer to the root node of the modified tree after removal.
 *
 * Return: A pointer to the root node of the modified tree, or NULL if the
 * value is not found in the tree or the tree is empty
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
