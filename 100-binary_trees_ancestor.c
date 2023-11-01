#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node.
 * If no common ancestor was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *path_first[1024]; // Assuming the maximum tree height is 1024
    binary_tree_t *path_second[1024];
    size_t i, j;

    if (first == NULL || second == NULL)
        return NULL;

    for (i = 0; i < 1024; i++)
    {
        path_first[i] = NULL;
        path_second[i] = NULL;
    }

    i = 0;
    while (first)
    {
        path_first[i++] = (binary_tree_t *)first;
        first = first->parent;
    }

    j = 0;
    while (second)
    {
        path_second[j++] = (binary_tree_t *)second;
        second = second->parent;
    }

    for (i = 0; path_first[i]; i++)
    {
        for (j = 0; path_second[j]; j++)
        {
            if (path_first[i] == path_second[j])
                return path_first[i];
        }
    }

    return NULL;
}
