#include "binary_trees.h"

size_t binary_tree_size(const heap_t *tree);
void bubble_up(heap_t *node, heap_t **root);
void insert_node(heap_t *root, heap_t *new_node, size_t path);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert
 * Return: pointer to inserted node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;
    size_t size;

    if (!root)
        return (NULL);

    if (!*root)
        return (*root = binary_tree_node(NULL, value));

    size = binary_tree_size(*root) + 1;
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    insert_node(*root, new_node, size >> 1);
    bubble_up(new_node, root);

    return (new_node);
}

/**
 * insert_node - insert node based on binary path
 * @root: root of heap
 * @new_node: node to insert
 * @path: binary path to follow (ignores highest bit)
 */
void insert_node(heap_t *root, heap_t *new_node, size_t path)
{
    while (path > 1)
    {
        root = (path & 1) ? root->right : root->left;
        path >>= 1;
    }

    if (path & 1)
        root->right = new_node;
    else
        root->left = new_node;
    new_node->parent = root;
}

/**
 * bubble_up - move node up to maintain heap property
 * @node: newly inserted node
 * @root: pointer to heap root
 */
void bubble_up(heap_t *node, heap_t **root)
{
    int tmp;

    while (node->parent && node->n > node->parent->n)
    {
        tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
    if (!node->parent)
        *root = node;
}

/**
 * binary_tree_size - calculates size of binary tree
 * @tree: tree root
 * Return: size
 */
size_t binary_tree_size(const heap_t *tree)
{
    if (!tree)
        return (0);
    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}