#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a binary tree.
 * @root: Root.
 * @value: Value.
 * Return: New node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	heap_t *low = NULL;

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (!(*root))
		*root = new;
		return (new);

	low = insert_new_node(*root);
	if (!low->left)
		low->left = new;

	else
		low->right = new;

	new->parent = low;
	return (swapper(new));
}
/**
 * insertNnode - Inserts a new node.
 * @root: Root.
 * Return: New Node.
 */
heap_t *insertNnode(heap_t *root)
{
	space_t tmp;

	tmp = tree_size(root);
	return (tmp.p);
}

/**
 * swapper - Swap.
 * @node: Node to change.
 * Return: New.
 */
heap_t *swapper(heap_t *node)
{
	int tmp;
	heap_t *Nnode = node;

	while (Nnode->parent)
	{
		if (Nnode->n > Nnode->parent->n)
		{
			tmp = Nnode->n;
			Nnode->n = Nnode->parent->n;
			Nnode->parent->n = tmp;

			Nnode = Nnode->parent;
			continue;
		}
		return (Nnode);
	}
	return (Nnode);
}

/**
 * tree_size - Finds the tree's size.
 * @node: Idx.
 * Return: Size.
 */
space_t tree_size(heap_t *node)
{
	space_t tmp;
    space_t left;
    space_t right;

	tmp.n = 0;
	tmp.p = node;

	if (!node->left || !node->right)
		return (tmp);

	left = tree_size(node->left);
	right = tree_size(node->right);
	if (left.n <= right.n)
	{
		left.n += 1;
		return (left);
	}

	else
	{
		right.n += 1;
		return (right);
	}
}
