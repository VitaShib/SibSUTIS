#include <stdlib.h>

#include "bstree.h"

/*Структура*/
struct bstree *bstree_create(char *key, int value)
{
	int key;	/* Ключ */
	char *value;	/* Данные */
	struct bstree *left;
	struct bstree *right;
}

/*Создание элемента BST*/
struct bstree *bstree_create(int key, char *value)
{
	struct bstree *node;
	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

/*Добавление элемента в BST*/
void bstree_add(struct bstree *tree, char *key, int value)
{
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
	/* Отыскиваем листовой узел */
	for (parent = tree; tree != NULL; )
	{
		parent = tree;
		//FIXME земенить на strcmp
		if (key < tree->key)
			tree = tree->left;
		else 
			if (key > tree->key)
				tree = tree->right;
			else
				return;
	}
	/* Создаем элемент и связываем с узлом */
	node = bstree_create(key, value);
	if (key < parent->key)
		parent->left = node;
	else
		parent->right = node;
}

/*Поиск элемента в BST*/
struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
	while (tree != NULL)
	{
		if (key == tree->key)
		{
			return tree;
		}
		else 
			if (key < tree->key)
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
