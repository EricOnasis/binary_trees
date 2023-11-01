#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t *queue[1024];
    size_t front = 0, rear = 0;

    if (tree == NULL || func == NULL)
        return;

    queue[rear] = (binary_tree_t *)tree;
    rear++;

    while (front < rear)
    {
        binary_tree_t *current = queue[front];
        front++;

        func(current->n);

        if (current->left)
        {
            queue[rear] = current->left;
            rear++;
        }

        if (current->right)
        {
            queue[rear] = current->right;
            rear++;
        }
    }
}
