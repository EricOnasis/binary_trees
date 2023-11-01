#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if
 * a binary tree is perfect.
 * @tree: A pointer to the root node
 * of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 * If the tree is NULL, return 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_full(tree))
	{
		return (check_leaves_level(tree, depth(tree)));
	}

	return (0);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
/**
 * depth - Computes the depth of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The depth of the tree.
 */

size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}

	return (d);
}

/**
 * check_leaves_level - Checks if all leaves of
 * the tree are at the same level.
 * @tree: A pointer to the root node of the tree.
 * @level: The level to compare leaves to.
 *
 * Return: 1 if all leaves are at the specified level,
 *  0 otherwise.
 */

int check_leaves_level(const binary_tree_t *tree, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (depth(tree) == level);
	}

	return (check_leaves_level(tree->left, level)
&& check_leaves_level(tree->right, level));
}
