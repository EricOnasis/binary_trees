#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

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

	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0;
	int non_complete_flag = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		front++;

		if (current == NULL)
		{
			non_complete_flag = 1;
		}
		else
		{
			if (non_complete_flag)
				return (0);

			queue[rear] = current->left;
			rear++;

			queue[rear] = current->right;
			rear++;
		}
	}

	return (1);
}
