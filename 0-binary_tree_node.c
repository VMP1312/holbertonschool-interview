#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node:.
 *
 * @parent: Parent.
 * @value: Value.
 * Return: New node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *Nnode;

Nnode = malloc(sizeof(binary_tree_t));
if (Nnode == NULL)
return (NULL);
Nnode->n = value;
Nnode->parent = parent;
Nnode->left = NULL;
Nnode->right = NULL;
return (Nnode);
}
