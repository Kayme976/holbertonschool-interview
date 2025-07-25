#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Ajout du prototype de la fonction */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * print_t - Stores recursively each level in an array of strings
 */
static void print_t(char **s, binary_tree_t *tree, int offset, int depth, int *space)
{
    char b[6];
    int width, is_left, i;

    if (!tree)
        return;

    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);

    print_t(s, tree->left, offset, depth + 1, space);

    for (i = 0; i < width; i++)
        s[depth][offset + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < *space + depth; i++)
            s[depth - 1][offset + width / 2 - i] = '-';
        s[depth - 1][offset + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < *space + depth; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset - width / 2] = '.';
    }

    print_t(s, tree->right, offset + width + *space, depth + 1, space);
}
