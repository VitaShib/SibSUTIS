#include "bstree.h"
/*
//Создание узла
struct bstree *bstree_create (char *key, int value)//T Create = O(1)
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

//Добавление элемента в BST
void bstree_add(struct bstree *tree, char *key, int value)//T Add = O(h)
{
	int cmp;
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
//	 Создаем элемент
	node = bstree_create(key, value);

//	 Отыскиваем листовой узел 
	for (parent = tree; tree != NULL; )
	{
		parent = tree;
		//FIXME земенить на strcmp
//		if (key < tree->key)
		int cmp = strcmp(key, tree->key);
		if (cmp < 0)
		{
			tree = tree->left;
			parent->left = node;
			printf("l %s\n",key);
		}
		else 
			if (cmp > 0)
			{
				tree = tree->right;
				parent->right = node;
				printf("r \t%s\n",key);
			}
			else
			{
				// Это повтор. их быть не должно
				free(node);
				printf("//////////////\n",key);
				return;
			}
	}
}

void bstree_add(struct bstree *tree, char *key, int value)//T Add = O(h)
{
	
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
	int cmp = strcmp(key, tree->key);
	// Отыскиваем листовой узел 
	for (parent = tree; tree != NULL; )
	{
		parent = tree;
		if (cmp < 0)
		{
			tree = tree->left;
			printf("%s\n",key);
		}
		else
			if (cmp > 0)
			{
				tree = tree->right;
				printf("\t%s\n",key);
			}
			else
				return;
	}
	// Создаем элемент и связываем с узлом 
	node = bstree_create(key, value);
	if (cmp < 0)
		parent->left = node;
	else
		parent->right = node;
}


void bstree_add (struct bstree *tree, char *key, int value)
{
	struct bstree *parent, *nome;
	if (tree == NULL)
		return;
	int cmp = strcmp(key, tree->key);
	for (parent = tree; tree != NULL; )
	{
 		parent = tree;
		if (cmp < 0)
		{
			tree = tree->left;
			printf("%s\n",key);
		}
		else if (cmp > 0)
		{
			tree = tree->right;
			printf("\t%s\n",key);
		}
		else
			return;
	}
	nome = bstree_create (key, value);
	if (cmp < 0)
		parent->left = nome;
	else
		parent->right = nome;
}


//Поиск элемента в BST
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

struct bstree *bstree_lookup (struct bstree *tree, char *key)
{
	int cmp = strcmp(key, tree->key);
	while(tree != NULL) {
		if (cmp == 0) {
			return tree;
		}
		else if (key < tree->key)
		{
			tree = tree->left;
		//	printf("%s\n",key);
		}
		else 
		{
			tree = tree->right;
		//	printf("\t%s\n",key);
		}
	}
	return tree;
}


//Поиск минимального элемента в BST
struct bstree *bstree_min(struct bstree *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

//Поиск максимального элемента в BST
struct bstree *bstree_max(struct bstree *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}*/

int compare(char *one, size_t onelen, char *two, size_t twolen)
{
    int max = onelen <= twolen ? twolen : onelen;
    int dif = memcmp(one, two, max);

    if (dif)
        return dif;

    if (onelen == twolen)
        return 0;

    return onelen > twolen ? 1 : -1;
}

BSTree *bstree_create(char *key, int value)
{
    BSTree *node;

    node = malloc(sizeof(BSTree));
    if (node == NULL) {
        return node;
    }

    node->left = NULL;
    node->right = NULL;
    node->data.key = key;
    node->data.value = value;

    return node;
}

BSTree *bstree_add(BSTree * tree, char *key, int value)
{

    if (tree == NULL) {
        tree = bstree_create(key, value);
    } else {
        int is_left = 0;
        int cmp = 0;
        BSTree *cursor = tree;
        BSTree *prev = NULL;

        while (cursor != NULL) {
            cmp =
                compare(key, strlen(key), cursor->data.key,
                        strlen(cursor->data.key));
            prev = cursor;
            if (cmp < 0) {
                is_left = 1;
                cursor = cursor->left;
            } else if (cmp > 0) {
                is_left = 0;
                cursor = cursor->right;
            } else {
                tree->data.value = value;
                return tree;
            }

        }
        if (is_left)
            prev->left = bstree_create(key, value);
        else
            prev->right = bstree_create(key, value);

    }
    return tree;
}

BSTree *bstree_lookup(BSTree * tree, char *key)
{

    while (tree != NULL) {
        int cmp =
            compare(key, strlen(key), tree->data.key, strlen(tree->data.key));
        if (cmp == 0) {
            return tree;
        } else if (cmp < 0) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return NULL;
}

BSTree *bstree_min(BSTree * tree)
{
    if (!tree) {
        return NULL;
    }

    if (tree->left == NULL)
        return tree;

    return bstree_min(tree->left);
}

BSTree *bstree_max(BSTree * tree)
{
    if (!tree) {
        return NULL;
    }

    if (tree->right == NULL)
        return tree;

    return bstree_max(tree->right);
}
