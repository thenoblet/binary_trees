#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * Description:
 *   This function finds the lowest common ancestor of two nodes in
 *   a binary tree.
 *   An ancestor of a node in a binary tree is defined as any node that
 *   lies on the path from the root of the tree to that node.
 *   The lowest common ancestor of two nodes is the deepest node that
 *   is a common ancestor of both nodes.
 *
 * Parameters:
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return:
 *   - If either 'first' or 'second' is NULL, the function returns NULL,
 *   as a binary tree node cannot be an ancestor of a NULL node.
 *   - If 'first' and 'second' point to the same node, that node is
 *   returned as it is both the first and second node's ancestor.
 *   - If one node is an ancestor of the other, the ancestor node is returned.
 *   - If neither node is an ancestor of the other, but they have a common
 *   ancestor further up the tree, the lowest common ancestor of
 *   both nodes is returned.
 *   - If no common ancestor is found, the function returns NULL.
 *
 * Algorithm:
 *   - The function first checks for edge cases where either 'first' or
 *   'second' is NULL or if both nodes are the same.
 *   - Then it checks if either node is an ancestor of the other by traversing
 *     up the tree from each node separately.
 *   - If no direct ancestor is found, it traverses up the tree from each node
 *     separately and compares the paths until a common ancestor is found.
 *   - If no common ancestor is found after traversing the entire tree, the
 *     function returns NULL.
 *
 * Note:
 *   - The function assumes that the binary tree is valid and does not contain
 *     cycles. Otherwise, it may enter an infinite loop.
 *   - It also assumes that each node in the binary tree has a pointer to
 *   its parent node.
 *   - The function has a time complexity of O(n^2) in the worst case,
 *   where 'n' is the number of nodes in the binary tree.
 *   This is because in the worst case, it may have to traverse up the
 *   tree from each node separately, resulting in nested loops.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
								const binary_tree_t *second)
{
	const binary_tree_t *ancestor, *traverse_first, *traverse_second;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Check if first or second is the ancestor of the other */
	if (first == second)
		return ((binary_tree_t *)first);

	/*Check if first is an ancestor of second*/
	ancestor = second;
	while (ancestor != NULL)
	{
		if (ancestor == first)
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	/* Check if second is an ancestor of first */
	ancestor = first;
	while (ancestor != NULL)
	{
		if (ancestor == second)
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	traverse_first = first;
	while (traverse_first != NULL)
	{
		traverse_second = second;
		while (traverse_second != NULL)
		{
			if (traverse_first == traverse_second)
				return ((binary_tree_t *)traverse_first);
			traverse_second = traverse_second->parent;
		}
		traverse_first = traverse_first->parent;
	}
	return (NULL); /* If no common ancestor found */
}
