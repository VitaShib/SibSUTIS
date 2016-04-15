#include "bstree.h"

/*Создание узла*/
struct bstree *bstree_create(char *key, int value)//T Create = O(1)
{
	// Обнуление ошибки
//	Error err = NO_ERROR;

	struct bstree *node;

	// Выделение памяти под узел
	node = malloc(sizeof(*node));
	// Если что-то пошло не так
	if (node == NULL)
	{
//		err = ERROR_MALLOC;
		return NULL;
	}
	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*Добавление элемента в BST*/
void bstree_add(struct bstree *tree, char *key, int value)//T Add = O(h)
{
	int cmp;
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
	/* Создаем элемент*/
	node = bstree_create(key, value);

	/* Отыскиваем листовой узел */
	for (parent = tree; tree != NULL; )
	{
		parent = tree;
		//FIXME земенить на strcmp
//		if (key < tree->key)
		cmp = strcmp(key, tree->key);
		if (cmp < 0)
		{
			tree = tree->left;
			parent->left = node;
		}
		else 
			if (cmp > 0)
			{
				tree = tree->right;
				parent->right = node;
			}
			else
			{
				// Это повтор. их быть не должно
				free(node);
				return;
			}
	}
}

/*Поиск элемента в BST*/
struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
	int cmp;
	while (tree != NULL)
	{
		cmp = strcmp(key, tree->key);//TODO
//		if (key == tree->key)
		if (cmp == 0)
		{
			return tree;
		}
		else 
//			if (key < tree->key)
			if (cmp < 0)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}
	}
	return tree;
}

/*Поиск минимального элемента в BST*/
struct bstree *bstree_min(struct bstree *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

/*Поиск максимального элемента в BST*/
struct bstree *bstree_max(struct bstree *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}
