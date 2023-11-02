#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 * If the tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, countNodes(tree)));
}

/**
 * is_complete - Helper function to check if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The current index of the node.
 * @count: The total number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, count) &&
			is_complete(tree->right, 2 * index + 2, count));
}

/**
 * countNodes - Helper function to count the total
 * number of nodes in a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The total number of nodes in the tree.
 */
int countNodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + countNodes(tree->left) + countNodes(tree->right));
}
