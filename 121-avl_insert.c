#include "binary_trees.h"

/**
 * r_insert_node - Recursively inserts a node into an AVL tree
 * @tree: A double pointer to the current node in the AVL tree
 * @parent: A pointer to the parent node of the current node
 * @new: A double pointer to store the newly inserted node
 * @nval: The value to insert into the AVL tree
 *
 * Description:
 * This function recursively inserts a new node with the given value into the
 * AVL tree represented by the current node pointed to by 'tree'. It ensures
 * that the AVL tree balance is maintained after insertion.
 *
 * Return: A pointer to the current node in the AVL tree after insertion
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bval = binary_tree_balance(*tree);
	if (bval > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bval < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}


/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to insert into the AVL tree
 *
 * Description:
 * This function inserts a new node with the given value into the AVL tree
 * represented by the root node pointed to by 'tree'. It ensures that the AVL
 * tree balance is maintained after insertion.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}
