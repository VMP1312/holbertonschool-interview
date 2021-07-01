#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: Root
 * Return:Value
 */
int heap_extract(heap_t **root)
{
	heap_t *prevNode = NULL, *parent  = NULL;
	size_t bwsd = 0, size = 0;
	int val = 0;

	size = tSize(*root);

	if (!root || size == 0)
		return (0);

	bwsd = bitwiser(size) >> 1;

	if (size == 1)
	{
		val = (*root)->n;
		free(*root);
		*root = NULL;
		return (val);
	}

	for (prevNode = *root; bwsd; bwsd >>= 1)
		prevNode = (bwsd & size) ? prevNode->right : prevNode->left;

	val = (*root)->n;
	(*root)->n = prevNode->n;
	parent  = prevNode->parent;
	free(prevNode);

	if ((size--) & 1)
		parent->right = NULL;

	else
		parent->left = NULL;

	resct(*root);
	return (val);
}

/**
 * tSize - Get tree size
 * @root: root
 * Return: Size
 */
size_t tSize(heap_t *root)
{
	if (!root)
		return (0);

	return (tSize(root->left) + tSize(root->right) + 1);
}

/**
 * bitwiser - Bitwiser
 * @num: Number
 * Return: setted num
 */
size_t bitwiser(size_t num)
{
	num |= num >> 1;
	num |= num >> 2;
	num |= num >> 4;
	num |= num >> 8;
	num |= num >> 16;
	num = num + 1;
	return (num >> 1);
}

/**
 * resct - Reestruc the tree
 * @root: root
 */
void resct(heap_t *root)
{
	int tmp;
	heap_t *temp = root, *node = NULL;

	while (1)
	{
		if (!temp->left)
			break;

		if (!temp->right)
			node = temp->left;

		else
			node = (temp->left->n - temp->right->n) >= 0
						? temp->left
						: temp->right;

		if ((temp->n - node->n) > 0)
			break;

		tmp = temp->n;
		temp->n = node->n;
		node->n = tmp;
		temp = node;
	}
}
