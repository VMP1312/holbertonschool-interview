#include "binary_trees.h"

/**
 *binary_tree_node - Creates a binary tree node
 *@parent: Parent.
 *@value: Value
 *Return: Pointer
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
   binary_tree_t *NNode = (binary_tree_t *) malloc(sizeof(binary_tree_t));

   if (!NNode)
     return (NULL);

   NNode->n = value;
   NNode->parent = parent;
   NNode->left = NULL;
   NNode->right = NULL;
   return (NNode);
}
