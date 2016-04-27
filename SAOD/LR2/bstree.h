#ifndef myBSTree
#define myBSTree

#include <string.h>
#include <stdlib.h>
/*
struct bstree 
{
	char *key;		//Ключ 
	int value;		// Данные 
	struct bstree *left;
	struct bstree *right;
};

struct bstree *bstree_create(char *key, int value);
void bstree_add(struct bstree *tree, char *key, int value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);
struct bstree *bstree_min(struct bstree *tree);
struct bstree *bstree_max(struct bstree *tree);
*/




typedef struct nodedata
{
    char *key;
    int value;
} Data;


typedef struct bstree
{
    struct bstree *left;
    struct bstree *right;
    Data data;
} BSTree;

BSTree *bstree_create(char *key, int value);
BSTree *bstree_add(BSTree * tree, char *key, int value);
BSTree *bstree_lookup(BSTree * tree, char *key);
BSTree *bstree_min(BSTree * tree);
BSTree *bstree_max(BSTree * tree);



#endif
