#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    binary_tree_t *queue[1024];
    size_t front = 0, rear = 0;
    int hasNullChild = 0;

    if (tree == NULL)
        return (0);

    queue[rear] = (binary_tree_t *)tree;

    rear++;

    while (front < rear)
    {
        binary_tree_t *current = queue[front];

        front++;

        if (current == NULL)
        {
            hasNullChild = 1;
        }
        else
        {
            if (hasNullChild)
                return 0;

            queue[rear] = current->left;
            rear++;
            queue[rear] = current->right;
            rear++;
        }
    }

    return (1);
}